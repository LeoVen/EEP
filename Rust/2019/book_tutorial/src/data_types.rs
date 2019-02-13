#![allow(unused_variables, dead_code)]

// Example of a constant
// It can't be the result of a function and must be annotated
const MAX_POINTS: u32 = 100_000;

pub fn data_types() {

    // Compiles
    // let spaces = "   ";
    // let spaces = spaces.len();

    // Doesn't
    // let mut spaces = "   ";
    // spaces = spaces.len();

    // -- Integer types
    // 8 bits
    let bit_i8: i8 = -128;
    let bit_u8: u8 = 255;
    // 16 bits
    let bit_i16: i16 = -32_768;
    let bit_u16: u16 = 65535;
    // 32 bits
    let bit_i32: i32 = -2147483648;
    let bit_u32: u32 = 4294967295;
    // 64 bits
    let bit_i64: i64 = -9223372036854775808;
    let bit_u64: u64 = 18446744073709551615;
    // 128 bits
    let bit_i128: i128 = -170141183460469231731687303715884105728;
    let bit_u128: u128 = 340282366920938463463374607431768211455;
    // arch (depends on the architecture)
    let bit_iarch: isize = 0;
    let bit_uarch: usize = 0;

    // -- Floating point
    let float: f32 = 32.0;
    let double: f64 = 64.0;

    // -- Boolean
    let my_bool: bool = true;

    // -- Character
    let my_char: char = 'C';

    // -- Literals
    let my_decimal = 98_222;
    let my_hex = 0xfff;
    let my_oct = 0o777;
    let my_bin = 0b1111_0000;
    let my_byte = b'A';
    let my_unsigned_hex = 0xfffu64;

    // -- Operations
    // addition
    let sum = 5 + 10;

    // subtraction
    let difference = 95.5 - 4.3;

    // multiplication
    let product = 4 * 30;

    // division
    let quotient = 56.7 / 32.2;

    // remainder
    let remainder = 43 % 5;

    // -- Tuple
    let my_tup: (i32, f64, bool) = (500, 6.4, true);
    // Destructuring
    let (x, y, z) = my_tup;
    let five_hundred = my_tup.0;
    let six_point_four = my_tup.1;
    let one = my_tup.2;
    // Not possible
    // let k = my_tup[2];

    // -- Array
    let arr: [i32; 8] = [1, 2, 3, 4, 5, 6, 7, 8];
    let first = arr[0];
    let second = arr[1];
}