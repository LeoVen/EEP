#[derive(Debug)]
struct Color(i32, i32, i32);
#[derive(Debug)]
struct Point(i32, i32, i32);

pub fn tuple_structs() {
    // white and center are different types
    let white = Color(255, 255, 255);
    let center = Point(0, 0, 0);

    println!("{:?}", white);
    println!("{:?}", center);
}
