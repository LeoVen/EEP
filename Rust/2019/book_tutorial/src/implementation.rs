#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

// Various impl for the same struct can be separated
impl Rectangle {
    // Reading method
    fn print(&self) {
        println!("[{}, {}] - A: {}", self.width, self.height, self.area());
    }

    // Reading method
    fn area(&self) -> u32 {
        self.width * self.height
    }

    // Mutating method
    fn double_sides(&mut self) {
        self.width *= 2;
        self.height *= 2;
    }

    // Consuming method
    fn consume_it(self) -> Rectangle {
        Rectangle {
            width: self.width,
            height: self.height,
        }
    } // self is dropped

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }

    // An associated function
    fn new(width: u32, height: u32) -> Rectangle {
        Rectangle { width, height }
    }
}

pub fn implementation() {
    let s0 = Rectangle {
        width: 6,
        height: 4,
    };

    s0.print();

    let mut s1 = Rectangle {
        width: 12,
        height: 8,
    };

    println!("\nOriginal");
    s1.print();
    println!("Sides being doubled");
    s1.double_sides();
    s1.print();
    println!("");

    let s2 = s1.consume_it();
    s2.print();
    // s1 was borrowed, the following no longer works
    // s1.print();

    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };
    let rect2 = Rectangle {
        width: 10,
        height: 40,
    };
    let rect3 = Rectangle {
        width: 60,
        height: 45,
    };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));

    // Using an associated function
    let assoc0 = Rectangle::new(20, 10);
    let assoc1 = Rectangle::new(15, 45);

    assoc0.print();
    assoc1.print();
}
