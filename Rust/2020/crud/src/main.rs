#![allow(proc_macro_derive_resolution_fallback, unused_attributes)]
#![feature(plugin, const_fn, decl_macro, proc_macro_hygiene)]

#[macro_use]
extern crate diesel;
extern crate dotenv;
#[macro_use]
extern crate rocket;
extern crate rocket_contrib;
#[macro_use]
extern crate serde_derive;
#[macro_use]
extern crate serde_json;

mod db;
mod models;
mod routes;
mod schema;
mod static_files;

use dotenv::dotenv;
use std::env;

fn rocket() -> rocket::Rocket {
    dotenv().ok();

    let database_url = env::var("DATABASE_URL").expect("Set DATABASE_URL in .env");

    let pool = db::init_pool(database_url);

    rocket::ignite()
        .manage(pool)
        .mount(
            "/api/v1/",
            routes![
                routes::index,
                routes::new,
                routes::get,
                routes::delete,
                routes::author,
                routes::update
            ],
        )
        .mount("/", routes![static_files::all, static_files::index])
        .register(catchers![routes::not_found])
}

fn main() {
    rocket().launch();
}
