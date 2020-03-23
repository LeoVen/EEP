#[macro_use]
extern crate diesel;
extern crate dotenv;

pub mod models;
pub mod schema;

use diesel::pg::PgConnection;
use diesel::prelude::*;
use dotenv::dotenv;
use models::appuser::{AppUser, NewAppUser};
use std::env;

fn main() {
    let x = NewAppUser {
        username: String::from("Vincent"),
        password: String::from("hello"),
        detail: String::from("None"),
        email: String::from("vincent@email.com"),
        firstname: String::from("Vincent"),
        lastname: String::from("van Gogh"),
    };

    dotenv().ok();

    let database_url = env::var("DATABASE_URL").expect("DATABASE_URL must be set");
    let conn = PgConnection::establish(&database_url)
        .expect(&format!("Error connecting to {}", database_url));

    if AppUser::insert(x, &conn) {
        println!("Success");
    } else {
        println!("Failure");
    }

    let user = AppUser::get(1, &conn);

    println!("{:?}", user)
}
