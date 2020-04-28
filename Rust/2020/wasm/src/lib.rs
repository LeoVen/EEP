#![allow(unreachable_code)]

extern crate wasm_bindgen;

use wasm_bindgen::prelude::*;

#[wasm_bindgen]
extern "C" {
    fn alert(s: &str);

    type HTMLDocument;
    type Element;

    static document: HTMLDocument;

    #[wasm_bindgen(method)]
    fn createElement(this: &HTMLDocument, tagName: &str) -> Element;

    #[wasm_bindgen(method, getter)]
    fn body(this: &HTMLDocument) -> Element;

    #[wasm_bindgen(method, js_name = appendChild)]
    fn append(this: &Element, item: Element);

    #[wasm_bindgen(method, setter = innerHTML)]
    fn set_inner(this: &Element, html: &str);
}

#[wasm_bindgen]
pub fn run_alert(item: &str) {
    alert(&format!("This is WASM and {}", item));
}

#[wasm_bindgen]
pub fn create_stuff() {
    let div = document.createElement("div");
    let p = document.createElement("p");

    p.set_inner("Hello from WASM in Rust!");
    div.append(p);

    document.body().append(div);
}

pub fn is_prime(n: u64) -> bool {
    if n <= 1 {
        return false;
    }

    if n <= 3 {
        return true;
    }

    if n % 2 == 0 || n % 3 == 0 {
        return false;
    }

    let mut i: u64 = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 {
            return false;
        }
        i += 6;
    }

    true
}

#[wasm_bindgen]
pub fn nth_prime(nth: u64) -> u64 {
    if nth == 0 {
        return 0;
    }

    if nth == 1 {
        return 2;
    }

    let mut i: u64 = 3;
    let mut total: u64 = 1;

    loop {
        if is_prime(i) {
            total += 1;
            if total == nth {
                return i;
            }
        }
        i += 2;
    }

    unreachable!()
}
