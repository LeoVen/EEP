use std::env;
use std::io::{self, Write};
use std::net::{IpAddr, TcpStream};
use std::process;
use std::str::FromStr;
use std::sync::mpsc::{channel, Sender};
use std::thread;

const MAX: u16 = std::u16::MAX;

struct Arguments {
    ipaddr: IpAddr,
    threads: u16,
}

fn help_message(x: &str) -> String {
    String::from(format!("Usage:\n -j to select how many threads you want\n -h or --help to show this message\n\nExample: {} -j 100 192.168.1.1\n", x))
}

impl Arguments {
    fn new(args: &[String]) -> Result<Arguments, &'static str> {
        if args.len() < 2 {
            return Err("Not enough arguments");
        } else if args.len() > 4 {
            return Err("Too many arguments");
        }

        let f = args[1].clone();

        if let Ok(ipaddr) = IpAddr::from_str(&f) {
            // case program.exe 192.168.1.1
            return Ok(Arguments { ipaddr, threads: 4 });
        } else {
            let flag = args[1].clone();

            if flag.contains("-h") || flag.contains("--help") && args.len() == 2 {
                // case program.exe --help or program.exe -h
                println!("{}", help_message(&args[0]));

                // Return an error just so the program may not continue
                return Err("Help displayed");
            } else if flag.contains("-h") || flag.contains("--help") {
                // case where there is some other argument together with --help or -h
                return Err("Too many arguments");
            } else if flag.contains("-j") {
                // case where -j is specified
                let ipaddr = match IpAddr::from_str(&args[3]) {
                    Ok(s) => s,
                    Err(_) => return Err("Not a valid IpAddr. Must be IPv4 or IPv6"),
                };

                let threads = match args[2].parse::<u16>() {
                    Ok(s) => s,
                    Err(_) => return Err("Failed to parse thread number"),
                };

                return Ok(Arguments { threads, ipaddr });
            } else {
                return Err("Invalid syntax");
            }
        }
    }
}

fn scan(tx: Sender<u16>, start_port: u16, addr: IpAddr, num_threads: u16) {
    let mut port: u16 = start_port + 1;
    loop {
        match TcpStream::connect((addr, port)) {
            Ok(_) => {
                print!(".");
                io::stdout().flush().unwrap();
                tx.send(port).unwrap();
            }
            Err(_) => {}
        }

        if (MAX - port) <= num_threads {
            break;
        }

        port += num_threads;
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let program = args[0].clone();
    let arguments = Arguments::new(&args).unwrap_or_else(|err| {
        if err.contains("help") {
            process::exit(0);
        } else {
            eprintln!("{} problem parsing arguments: {}", program, err);
            process::exit(0);
        }
    });

    let num_threads = arguments.threads;
    let addr = arguments.ipaddr;
    let (tx, rx) = channel();

    for i in 0..num_threads {
        let tx = tx.clone();

        thread::spawn(move || {
            scan(tx, i, addr, num_threads);
        });
    }

    let mut out = vec![];

    drop(tx);

    for p in rx {
        out.push(p);
    }

    println!("");
    out.sort();
    for v in out {
        println!("{} is open", v);
    }
}
