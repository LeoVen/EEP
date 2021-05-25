use std::{
    fs::{self, Metadata},
    io,
    path::PathBuf,
};

use futures::{select, StreamExt};
use humansize::{file_size_opts, FileSize};
use tokio_stream::wrappers::ReadDirStream;

use futures::stream::FuturesUnordered;

/// Sync calculation
pub fn calculate_sync(path: PathBuf) -> io::Result<(u64, u64, u64)> {
    let mut paths = vec![path];
    let mut size = 0;
    let mut files = 0;
    let mut dirs = 1;

    while let Some(path) = paths.pop() {
        let meta = fs::symlink_metadata(&path)?;
        let ft = meta.file_type();

        if ft.is_dir() {
            let entries = fs::read_dir(&path)?;
            for entry in entries {
                paths.push(entry?.path());
            }
            dirs += 1;
        } else if ft.is_file() {
            size += meta.len();
            files += 1;
        }
    }

    Ok((files, dirs, size))
}

/// Using async but sequentially
pub async fn calculate_async_seq(path: PathBuf) -> io::Result<(u64, u64, u64)> {
    let mut paths = vec![path];
    let mut size = 0;
    let mut files = 0;
    let mut dirs = 1;

    while let Some(path) = paths.pop() {
        let meta = tokio::fs::symlink_metadata(&path).await?;
        let ft = meta.file_type();

        if ft.is_dir() {
            let mut entries = tokio::fs::read_dir(&path).await?;
            while let Some(entry) = entries.next_entry().await? {
                paths.push(entry.path());
            }
            dirs += 1;
        } else if ft.is_file() {
            size += meta.len();
            files += 1;
        }
    }

    Ok((files, dirs, size))
}

/// Using async with parallel tasks
pub async fn calculate_async_par(path: PathBuf) -> io::Result<(u64, u64, u64)> {
    let mut meta_queue = FuturesUnordered::new();
    meta_queue.push(metadata(path));
    let mut entry_queue = FuturesUnordered::new();
    let mut size = 0;
    let mut files = 0;
    let mut dirs = 1;

    loop {
        select! {
            resolved = meta_queue.select_next_some() => {
                let (path, meta) = resolved?;
                let ft = meta.file_type();
                if ft.is_dir() {
                    let entries_stream = ReadDirStream::new(tokio::fs::read_dir(path).await?);
                    entry_queue.push(entries_stream.into_future());
                    dirs += 1;
                } else if ft.is_file() {
                    size += meta.len();
                    files += 1;
                }
            },
            (entry, tail) = entry_queue.select_next_some() => {
                if let Some(Ok(entry)) = entry {
                    entry_queue.push(tail.into_future());
                    meta_queue.push(metadata(entry.path()))
                }
            },
            complete => break,
        }
    }

    Ok((files, dirs, size))
}

async fn metadata(path: PathBuf) -> io::Result<(PathBuf, Metadata)> {
    let meta = tokio::fs::symlink_metadata(&path).await?;
    Ok((path, meta))
}

macro_rules! time_it {
    ($expr:expr) => {{
        let now = ::std::time::Instant::now();
        $expr;
        (::std::time::Instant::now() - now).as_millis()
    }};
}

fn main() {
    fn get_path() -> PathBuf {
        let args = std::env::args().into_iter().skip(1).next();
        let folder =
            args.expect("Expected one positional argument containing a file or folder path.");
        PathBuf::from(folder)
    }

    let rt = tokio::runtime::Runtime::new().unwrap();
    let path = get_path();

    println!(
        "calculate_sync : {} milliseconds",
        time_it!({
            match calculate_sync(path.clone()) {
                Ok((files, dirs, size)) => println!(
                    "Files : {}\nDirs  : {}\nSize  : {}",
                    files, dirs,
                    size.file_size(file_size_opts::CONVENTIONAL).unwrap()
                ),
                Err(e) => eprintln!("{}", e),
            }
        })
    );
    println!(
        "calculate_async_seq : {} milliseconds",
        time_it!({
            match rt.block_on(async { calculate_async_seq(path.clone()).await }) {
                Ok((files, dirs, size)) => println!(
                    "Files : {}\nDirs  : {}\nSize  : {}",
                    files, dirs,
                    size.file_size(file_size_opts::CONVENTIONAL).unwrap()
                ),
                Err(e) => eprintln!("{}", e),
            }
        })
    );
    println!(
        "calculate_async_par : {} milliseconds",
        time_it!({
            match rt.block_on(async { calculate_async_par(path.clone()).await }) {
                Ok((files, dirs, size)) => println!(
                    "Files : {}\nDirs  : {}\nSize  : {}",
                    files, dirs,
                    size.file_size(file_size_opts::CONVENTIONAL).unwrap()
                ),
                Err(e) => eprintln!("{}", e),
            }
        })
    );
}
