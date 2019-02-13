// A type composed by fields
struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

#[derive(Debug)]
struct Square {
    width: u32,
    height: u32,
}

pub fn structs() {
    // Not mutable, not any of its fields
    let user0 = build_user(
        String::from("someone@example.com"),
        String::from("someusername123"),
    );

    // Mutable, even its own fields
    let mut user2 = User {
        email: String::from("somebody@example.com"),
        username: String::from("someusername456"),
        active: false,
        sign_in_count: 2,
    };

    user2.active = true;

    // struct update syntax
    let user1 = User {
        email: String::from("another@example.com"),
        username: String::from("anotherusername567"),
        // active: user1.active,
        // sign_in_count: user1.sign_in_count,
        ..user0
    };

    println!(
        "{}, {}, {}, {}",
        user1.username, user1.email, user1.active, user1.sign_in_count
    );

    let s0 = Square {
        width: 4,
        height: 3,
    };
    let s1 = Square {
        width: 2,
        height: 7,
    };

    // Debug format
    println!("{:?}", 11);

    print_square(&s0);
    print_square(&s1);
    debug_square(&s0);
    debug_square(&s1);
}

fn build_user(email: String, username: String) -> User {
    User {
        username, // Field init shorthand
        email,    // When the parameter name is the same as the field
        active: true,
        sign_in_count: 1,
    }
}

fn print_square(s: &Square) {
    println!("[{}, {}]", s.width, s.height);
}

fn debug_square(s: &Square) {
    println!("{:?}", s);
}
