
fn foo(input: Option<i32>) -> Option<i32> {
    input.filter(|&i| i >= 0)
    // input.and_then(|i| {
    //     if i < 0 {
    //         return None;
    //     }

    //     Some(i)
    // })
}

fn bar(input: Option<i32>) -> Result<i32, &'static str> {
    foo(input).ok_or("Error")
}

pub fn main() {
    match bar(Option::from(32)) {
        Ok(i) => println!("Ok({})", i),
        Err(e) => println!("Err({})", e),
    }
}
