#![allow(unused_variables)]

// see str_slice.rs
pub fn slices() {
    let array: [u32; 8] = [1, 2, 3, 4, 5, 6, 7, 8];

    // Array slice
    let slice: &[u32] = &array[1..5];
}