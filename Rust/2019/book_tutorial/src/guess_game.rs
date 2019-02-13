use std::io;
use rand::Rng;
use std::cmp::Ordering;

pub fn guess_game() {

    println!("Welcome to the guessing game. Take a guess");

    let secret_number = rand::thread_rng().gen_range(1, 101);

    loop {

        // Growable string
        let mut guess = String::new();

        io::stdin().read_line(&mut guess)
            .expect("Failed to read line");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        //    let guess = guess.trim().parse::<u32>()
        //        .expect("Please type a number!");

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            },
        }
    }
}
