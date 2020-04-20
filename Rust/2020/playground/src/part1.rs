fn run<F>(f: F)
where
    F: Fn(),
{
    f();
}

// OR
// fn add3<F: Fn(i32) -> i32>(f: F) -> i32
fn add3<F>(f: F) -> i32
where
    F: Fn(i32) -> i32,
{
    f(3)
}

pub fn main() {
    println!("\n\n\npart1.rs");
    box_example();
    clojure_example();
}

fn box_example() {
    let x = 4;
    let y = &x;
    let z = Box::new(x);

    if *y == *z {
        println!("y and z are equal");
    }
}

fn clojure_example() {
    let f = |i| i + 1;

    println!("\n\nClojure {}", f(10));
    let p = || println!("This is a clojure");

    p();

    let mut c = 0;

    let mut inc = || {
        c += 1;
        println!("Incremented by 1 : {}", c);
    };

    inc();
    inc();
    inc();

    run(p);
    println!("Result of executed clojure : {}", add3(f));
}
