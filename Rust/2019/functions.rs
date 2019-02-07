fn main() {
    let x = 10;
    let y = 20;

    let z = {
        let z = sum(x, sub(y, x));
        z + x + y
    };

    println!("The sum of {} and {} is {}", x, y, sum(x, y));
    println!("The value of Z is {}", z);

	// Shadowing
    let mut z = z;
    // Sending by reference
	inc(&mut z);

    println!("Z incremented by one {}", z);
}

fn sum(a: i32, b: i32) -> i32 {
    return a + b;
}

fn sub(a: i32, b: i32) -> i32 { a - b }

fn inc(a: &mut i32) {*a += 1}