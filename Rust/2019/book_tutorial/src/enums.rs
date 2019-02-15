enum InternetProtocolVersion {
    IPV4,
    IPV6,
}

// The following can be simplified
struct IpAddr {
    kind: InternetProtocolVersion,
    address: String,
}

// Simplification
enum IpAddress {
    V4(String),
    V6(String),
}

// Also valid enum
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

// You can also add impl to enums
impl Message {
    fn call(&self) {
        println!("Hey there!");
    }
}

// Enums can also have multiple associated data
enum IP {
    V4(u8, u8, u8, u8),
    V6(String),
}
pub fn enums() {
    let ipv4 = InternetProtocolVersion::IPV4;
    let ipv6 = InternetProtocolVersion::IPV6;

    let home = IP::V4(127, 0, 0, 1);

    let loopback = IP::V6(String::from("::1"));
}

//fn printIPVersion(i: InternetProtocolVersion) {
//    match i {}
//}
