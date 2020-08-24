// The first 1000 Palindrome Primes

type PrimeInner = usize;

struct Prime(PrimeInner);

impl Prime {
    pub fn new() -> Self {
        Self(1)
    }

    pub fn is_prime(n: PrimeInner) -> bool {
        if n < 2 {
            return false;
        } else if n <= 3 {
            return true;
        }

        if n % 2 == 0 || n % 3 == 0 {
            return false;
        }

        for i in (5..((n as f64).powf(0.5) + 1.0) as PrimeInner).step_by(6) {
            if n % i == 0 || n % (i + 2) == 0 {
                return false;
            }
        }

        true
    }
}

impl Iterator for Prime {
    type Item = PrimeInner;

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

fn is_palindrome(s: &String) -> bool {
    let l = s.len();
    for i in 0..(l / 2) {
        if s.chars().nth(i) != s.chars().nth(l - 1 - i) {
            return false;
        }
    }
    true
}

fn main() {
    for prime in Prime::new().map(|n| n.to_string()).filter(|s| is_palindrome(s)).take(1000) {
        println!("{}", prime);
    }
}
