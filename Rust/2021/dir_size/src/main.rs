use std::{
    error::Error,
    fs, io,
    path::{Path, PathBuf},
};

use humansize::{file_size_opts, FileSize};

fn main() -> Result<(), Box<dyn Error>> {
    let args = std::env::args().into_iter().skip(1).next();

    let folder = args.expect("Expected one positional argument containing a file or folder path.");

    match calculate(&PathBuf::from(folder)) {
        Ok(size) => println!(
            "Calculated size: {}",
            size.file_size(file_size_opts::CONVENTIONAL)?
        ),
        Err(e) => eprintln!("{}", e),
    }

    Ok(())
}

fn calculate(path: &Path) -> io::Result<u64> {
    let mut paths = vec![path.to_path_buf()];
    let mut size = 0;

    while let Some(path) = paths.pop() {
        let meta = fs::symlink_metadata(&path)?;
        let ft = meta.file_type();

        if ft.is_dir() {
            let entries = fs::read_dir(&path)?;
            for entry in entries {
                paths.push(entry?.path());
            }
        } else if ft.is_file() {
            size += meta.len();
        }
    }

    Ok(size)
}
