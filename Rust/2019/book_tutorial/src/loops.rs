pub fn loops() {
    loop {
        // This will never stop


        break; // Now it will
    }

    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            // Returns the value
            break counter * 2;
        }
    };

    assert_eq!(result, 20);

    let mut number = 3;

    while number != 0 {
        println!("{}!", number);

        number = number - 1;
    }

    println!("LIFTOFF!!!");

    let a = [10, 20, 30, 40, 50];
    let mut index = 0;

    // This
    while index < 5 {
        println!("the value is: {}", a[index]);

        index = index + 1;
    }
    // Or this
    for element in a.iter() {
        println!("the value is: {}", element);
    }

    for number in 1..10 {
        println!("This goes upwards {}", number);
    }
    for number in (1..10).rev() {
        println!("This goes downwards {}", number);
    }
}