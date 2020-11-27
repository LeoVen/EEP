// cargo-deps: rug = "1.11"

// This file uses https://github.com/DanielKeep/cargo-script to run

// https://en.wikipedia.org/wiki/Formula_for_primes#A_function_that_represents_all_primes
// 2.920050977316

extern crate rug;

use std::env;
use rug::Float;

struct Prime(u128);

impl Prime {
    pub fn new() -> Self {
        Self(1)
    }

    pub fn is_prime(n: u128) -> bool {
        if n < 2 {
            return false;
        } else if n <= 3 {
            return true;
        }

        if n % 2 == 0 || n % 3 == 0 {
            return false;
        }

        for i in (5..((n as f64).powf(0.5) + 1.0) as u128).step_by(6) {
            if n % i == 0 || n % (i + 2) == 0 {
                return false;
            }
        }

        true
    }
}

impl Iterator for Prime {
    type Item = u128;

    fn next(&mut self) -> Option<Self::Item> {
        self.0 += 1;

        for i in self.0.. {
            if Self::is_prime(i) {
                self.0 = i;
                return Some(i);
            }
        }

        unreachable!();
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let mut iters = 1000; // Default
    let mut prec = 1000; // Default

    if args.len() > 1 {
        if let Ok(value) = str::parse::<u32>(&args[1]) {
            iters = value;
        }
    }

    if args.len() > 2 {
        if let Ok(value) = str::parse::<u32>(&args[2]) {
            prec = value;
        }
    }

    let mut C = Float::with_val(prec, 0.0);

    // Generate primes

    let mut primes: Vec<u128> = Prime::new().take(iters as usize).collect();

    for i in 0..iters as usize {
        let nth_prime = Float::with_val(prec, primes[i]);
        let nth_mult = primes.iter().take(i).fold(Float::with_val(prec, 1.0), |acc, v| acc * Float::with_val(prec, *v));

        C += (nth_prime - 1.0) / nth_mult;
    }

    println!("Precision: {}", prec);
    println!("Iterations: {}", iters);
    println!("Constant: {}", C);
}
