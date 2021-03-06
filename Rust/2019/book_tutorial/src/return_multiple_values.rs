pub fn return_multiple_values() {
    let s1 = String::from("hello");

    // Ownership gets transfered back to s2, from s1
    let (s2, len) = calculate_length(s1);

    println!("The length of '{}' is {}.", s2, len);
}

fn calculate_length(s: String) -> (String, usize) {
    let length = s.len(); // len() returns the length of a String

    (s, length)
}