mod control_flow;
mod data_types;
mod functions;
mod guess_game;
mod hello;
mod implementation;
mod loops;
mod ownership0;
mod ownership1;
mod ownership2;
mod reference;
mod return_multiple_values;
mod slices;
mod str_slice;
mod structs;
mod tuple_structs;

fn main() {
    control_flow::control_flow();
    data_types::data_types();
    functions::functions();
    guess_game::guess_game();
    hello::hello();
    implementation::implementation();
    loops::loops();
    ownership0::ownership0();
    ownership1::ownership1();
    ownership2::ownership2();
    reference::reference();
    return_multiple_values::return_multiple_values();
    slices::slices();
    str_slice::str_slice();
    structs::structs();
    tuple_structs::tuple_structs();

    println!("Hello, world!");
}
