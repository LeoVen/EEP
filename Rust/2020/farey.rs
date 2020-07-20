// This file uses https://github.com/DanielKeep/cargo-script
// Based on https://www.johndcook.com/blog/2010/10/20/best-rational-approximation/
use std::env;
use std::fmt;

struct Fraction {
    pub numerator: f64,
    pub denominator: f64,
}

impl Fraction {
    fn new(numerator: f64, denominator: f64) -> Self {
        Self {
            numerator,
            denominator,
        }
    }

    // a/b mediant c/d == (a + c) / (b + d)
    fn mediant(lhs: &Fraction, rhs: &Fraction) -> Fraction {
        Fraction {
            numerator: lhs.numerator + rhs.numerator,
            denominator: lhs.denominator + rhs.denominator,
        }
    }

    fn value(&self) -> f64 {
        self.numerator as f64 / self.denominator as f64
    }
}

impl fmt::Display for Fraction {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{:.0} / {:.0}", self.numerator, self.denominator)
    }
}

struct Farey {
    pub limit: f64,
}

impl Farey {
    fn new(limit: f64) -> Self {
        Farey {
            limit, // The denominator limit
        }
    }

    pub fn calc(&self, number: f64) -> Fraction {
        let integer = number.trunc();
        let fraction = number.fract();

        let farey = self.farey(fraction);

        return Fraction {
            numerator: integer * farey.denominator + farey.numerator,
            denominator: farey.denominator,
        }
    }

    fn farey(&self, number: f64) -> Fraction {
        let limit = self.limit as f64;

        let integer = number.trunc();
        let fraction = number.fract();

        let mut lower = Fraction::new(0.0, 1.0);
        let mut upper = Fraction::new(1.0, 1.0);

        let mut iters = 0;
        while lower.denominator <= limit && upper.denominator <= limit {

            let mediant = Fraction::mediant(&lower, &upper);

            if number == mediant.value() {
                if lower.denominator + upper.denominator <= limit {
                    return Fraction::mediant(&upper, &lower);
                } else if upper.denominator > lower.denominator {
                    return upper;
                } else {
                    return lower;
                }
            } else if number > mediant.value() {
                lower = mediant;
            } else {
                upper = mediant;
            }
        }

        if lower.denominator > limit {
            return upper;
        } else {
            return lower;
        }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 3 {
        println!("Example\ncargo script farey.rs -- [rational number] [denominator limit]");
        return;
    }

    let number: f64 = match args[1].parse::<f64>() {
        Ok(num) => num,
        Err(e) => {
            eprintln!("Could not parse {}\n{}", args[1], e);
            return;
        },
    };

    let limit: f64 = match args[2].parse::<f64>() {
        Ok(lim) => lim,
        Err(e) => {
            eprintln!("Could not parse {}\n{}", args[2], e);
            return;
        }
    };

    let farey = Farey::new(limit);

    let integer = number.trunc();
    let fraction = number.fract();

    println!("   Integer Part: {}", integer);
    println!("Fractional Part: {}", fraction);
    println!("       Fraction: {}", farey.calc(number));
}
