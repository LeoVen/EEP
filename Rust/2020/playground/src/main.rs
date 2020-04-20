mod part1;
mod part2;
mod part3;

use std::ops::Mul;

trait Shape<T> {
    fn area(&self) -> T;
}

struct Rectangle<T: Mul> {
    x: T,
    y: T,
}

// OR (without the 'where')
// impl <T: Mul<Output = T> + Copy> Shape<T> for Rectangle<T>
impl<T: Copy> Shape<T> for Rectangle<T>
where
    T: Mul<Output = T>,
{
    fn area(&self) -> T {
        self.x * self.y
    }
}

#[derive(Debug)]
struct Vec2D {
    x: f64,
    y: f64,
}

impl Vec2D {
    pub fn origin() -> Self {
        Vec2D { x: 0.0, y: 0.0 }
    }
}

pub type Matrix<T> = Vec<Vec<T>>;

struct Fib {
    c: u128,
    n: u128,
}

impl Fib {
    pub fn new() -> Fib {
        Fib { c: 1, n: 1 }
    }
}

impl Iterator for Fib {
    type Item = u128;

    fn next(&mut self) -> Option<Self::Item> {
        let n = self.c + self.n;
        self.c = self.n;
        self.n = n;

        Some(self.c)
    }
}

fn main() {
    let ri = Rectangle { x: 10, y: 20 };
    let rf = Rectangle { x: 10.1, y: 20.2 };

    println!("{} {}", ri.area(), rf.area());

    let a: i8 = rand::random();

    println!("Random i8: {}", a);

    let b: f32 = rand::random();

    println!("Random f32: {}", b);

    let c = Vec2D::origin();

    println!("{:?}", c);

    let d: Matrix<i32> = Matrix::from(Vec::default());

    println!("{:?}", d);

    println!("100 First Fibonacci numbers:");

    for (i, x) in Fib::new().enumerate().take(20) {
        println!("Fib[{}] : {}", i, x);
    }

    part1::main();
    part2::main();
    part3::main();
}
