#![allow(unused_variables)]

pub fn str_slice() {
    let s = String::from("hello world");

    // String slice type:
    let slice: &str = &s[..];

    // String literals are slices too
    let literal = "Hello World!";

    // From 0 (included) up to 5 (included)
    let hello = &s[0..=4];
    // Also works
    let also_hello = &s[..4];

    // From 6 (included) up to 11 (not included)
    let world = &s[6..11];
    // Also works
    let also_world = &s[..11];

    // Entire string
    let entire_string = &s[..];

    println!("{} {}", hello, world);

    let lorem = String::from("Lorem ipsum dolor sit amet");
    println!("First word of lorem {}", first_word(&lorem[..]));
    println!("First word of string literal {}", first_word(literal));
}

//fn first_word(s: &String) -> &str {
fn first_word(slice: &str) -> &str {
    let bytes = slice.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &slice[..i];
        }
    }

    &slice[..]
}