fn main() {

    // Clone data type
    let s1 = String::from("Hello World!");

    // Copy data type
    let simple = 10;
    // The variable is automatically copied
    let simple2 = simple;

    // Shallow copy
    // s1 is moved to s2
    let s2 = s1;

    // Deep copy
    // s2 is copied to s3
    let s3 = s2.clone();
}
