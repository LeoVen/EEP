#[allow(unused_variables)]

pub fn reference() {
    let mut s1 = String::from("hello");

    let len = calculate_length(&s1);
    let len = mutate_string_and_return_length(&mut s1);

    println!("The length of '{}' is {}.", s1, len);
}

// Doesn't takes ownership over the string
fn calculate_length(s: &String) -> usize {
    s.len()
} // string isn't dropped

fn mutate_string_and_return_length(s: &mut String) -> usize {
    s.push_str(", world");
    return s.len();
} // string isn't dropped and is mutated

// Dangling reference
//  fn main() {
//     let reference_to_nothing = dangle();
// }
//
// fn dangle() -> &String {
//     let s = String::from("hello");
//
//     &s
// } // s gets dropped here. Problem!
