// intervals.rs
// 2020/07/23
// Leonardo Vencovsky https://github.com/LeoVen
//
// This file uses https://github.com/DanielKeep/cargo-script
//
// Interval Arithmetic
// https://en.wikipedia.org/wiki/Interval_arithmetic

// For every arithmetic operation 'op':
//     [Lower, Upper]
//     [X1, X2] op [Y1, Y2] = [min(X1 op Y1, X1 op Y2, X2 op Y1, X2 op Y2), min(X1 op Y1, X1 op Y2, X2 op Y1, X2 op Y2)]
//
// But some operations can be simplified. For example, for addition and subtraction:
//     Add: [X1, X2] + [Y1, Y2] = [X1 + Y1, X2 + Y2]
//     Sub: [X1, X2] - [Y1, Y2] = [X1 - Y2, X2 - Y1]
//
// http://web.mit.edu/hyperbook/Patrikalakis-Maekawa-Cho/node45.html

use std::cmp;
use std::fmt;
use std::ops::{Add, Div, Mul, Sub};

#[derive(Clone, Copy)]
struct Interval {
    upper: f64,
    lower: f64,
}

impl Interval {
    fn new(lower: f64, upper: f64) -> Self {
        Self { lower, upper }
    }

    fn empty() -> Self {
        Self {
            lower: 0.0,
            upper: 0.0,
        }
    }

    fn intersects(self, other: Self) -> bool {
        !(self.lower > other.upper || self.upper < other.lower)
    }

    fn union(self, other: Self) -> Self {
        Self {
            lower: self.lower.min(other.lower),
            upper: self.upper.max(other.upper),
        }
    }

    fn intersection(self, other: Self) -> Self {
        if self.intersects(other) {
            Self {
                lower: self.lower.max(other.lower),
                upper: self.upper.min(other.upper),
            }
        } else {
            Interval::empty()
        }
    }

    fn contains(self, value: f64) -> bool {
        self.lower <= value && self.upper >= value
    }

    fn width(self) -> f64 {
        self.upper - self.lower
    }
}

impl Add for Interval {
    type Output = Self;

    fn add(self, rhs: Self) -> Self::Output {
        Self {
            lower: self.lower + rhs.lower,
            upper: self.upper + rhs.upper,
        }
    }
}

impl Sub for Interval {
    type Output = Self;

    fn sub(self, rhs: Self) -> Self::Output {
        Self {
            lower: self.lower - rhs.upper,
            upper: self.upper - rhs.lower,
        }
    }
}

impl Mul for Interval {
    type Output = Self;

    fn mul(self, rhs: Self) -> Self::Output {
        let res: [f64; 4] = [
            self.lower * rhs.lower,
            self.lower * rhs.upper,
            self.upper * rhs.lower,
            self.upper * rhs.upper,
        ];

        Self {
            lower: res
                .iter()
                .fold(f64::INFINITY, |left, &right| left.min(right)),
            upper: res
                .iter()
                .fold(f64::NEG_INFINITY, |left, &right| left.max(right)),
        }
    }
}

impl Div for Interval {
    type Output = Self;

    fn div(self, rhs: Self) -> Self::Output {
        let res: [f64; 4] = [
            self.lower / rhs.lower,
            self.lower / rhs.upper,
            self.upper / rhs.lower,
            self.upper / rhs.upper,
        ];

        Self {
            lower: res
                .iter()
                .fold(f64::INFINITY, |left, &right| left.min(right)),
            upper: res
                .iter()
                .fold(f64::NEG_INFINITY, |left, &right| left.max(right)),
        }
    }
}

impl fmt::Display for Interval {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "[{}, {}]", self.lower, self.upper)
    }
}

fn main() {
    let lhs = Interval::new(2.0, 4.0);
    let rhs = Interval::new(3.0, 5.0);
    println!("{} + {} = {}", lhs, rhs, lhs + rhs);
    println!("{} - {} = {}", lhs, rhs, lhs - rhs);
    println!("{} * {} = {}", lhs, rhs, lhs * rhs);
    println!("{} / {} = {}", lhs, rhs, lhs / rhs);
    println!("{} ∪ {} = {}", lhs, rhs, lhs.union(rhs));
    println!("{} ∩ {} = {}", lhs, rhs, lhs.intersection(rhs));
    println!("{} ⊃ {{ {} }} = {}", lhs, 3.0, lhs.contains(3.0));
    println!("|{}| = {}", lhs + rhs, (lhs + rhs).width());
}
