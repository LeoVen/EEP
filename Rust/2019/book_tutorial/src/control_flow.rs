use rand::Rng;

pub fn control_flow() {
    let r = rand::thread_rng().gen_range(1, 100);

    if r < 20 {
        println!("The random number is really small");
    } else if r < 80 {
        println!("The random number is average");
    } else {
        println!("The random number is pretty big");
    }

    let phrase = if r < 20 {
        "The number is really small"
    } else if r < 80 {
        "The number is average"
    } else {
        "The number is pretty big"
    };

    println!("{}", phrase);
}