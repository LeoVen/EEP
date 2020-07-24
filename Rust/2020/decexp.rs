// decexp.rs
// 2020/07/24
// Leonardo Vencovsky https://github.com/LeoVen
//
// This file uses https://github.com/DanielKeep/cargo-script
//
// Decimal Expansion With Repetition Detection
// https://en.wikipedia.org/wiki/Decimal_representation

use std::collections::HashMap;
use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 3 {
        println!("Example\ncargo script decexp.rs -- [numerator/denominator] [decimal cases]");
        return;
    }

    let values : Vec<&str> = args[1].split("/").collect();

    if values.len() != 2 {
        eprintln!("Invalid argument {}", args[1]);
        return;
    }

    let numerator = values[0].trim().parse::<f64>().expect(&format!("Invalid numerator {}", values[0]));
    let denominator = values[1].trim().parse::<f64>().expect(&format!("Invalid denominator {}", values[1]));

    let decimals = args[2].parse::<usize>().expect(&format!("Invalid decimal cases {}", args[2]));

    if denominator == 0.0 {
        eprintln!("Denominator can't be 0");
        return;
    }

    let mut result = String::new();

    let whole = (numerator / denominator).abs() as usize;

    result.push_str(&(whole.to_string() + "."));

    let len_before = result.len();

    let mut rem = numerator % denominator;
    let mut num = numerator;

    // Map the number to its decimal index
    // whole.012345...
    let mut seen_pairs = HashMap::new();

    for i in 0..decimals {
        num = (rem * 10.0) / denominator;
        rem = (rem * 10.0) % denominator;
        let digit = num.trunc().to_string();

        let key = num.to_string() + " " + &rem.to_string();

        if seen_pairs.contains_key(&key) {
            let index = seen_pairs[&key];
            // Whole part + decimal point + non-repeating numbers
            let before = len_before + index;
            // Where the repetition starts
            let rep_start = seen_pairs[&key] + before;

            result = result[..before].to_string() + "[" + &result[rep_start..].to_string() + "]";
            break;
        }

        seen_pairs.insert(key.clone(), i);

        result.push_str(&digit);
    }

    // Printed out in the form:
    // {whole part}.{non-repeating}[{repeating}]
    println!("{} / {} = {}", numerator, denominator, result);
}
