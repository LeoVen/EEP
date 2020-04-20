use std::collections::BTreeMap;

pub fn main() {
    let vec0 : Vec<i32> = vec![0, 1, 2, 3];
    let vec1 : Vec<i32> = vec0.iter().map(|x| x * 2).collect();
    let vec2 : Vec<&i32> = vec0.iter().chain(vec1.iter()).collect();

    let map: BTreeMap<_, _> = vec2.iter().enumerate().map(|v| (v.1, v.0)).collect();

    for (k, v) in map {
        println!("{} : {}", k, v);
    }

    print!("\n");

    let vec3 = vec![3, 2, 1, 0];

    for (v, i) in vec3.iter().enumerate().map(|c| (c.1, c.0)) {
        println!("{} : {}", v, i);
    }
}