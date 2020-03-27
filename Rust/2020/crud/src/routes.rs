use super::db::PgConn as DbConn;
use super::models::{Book, NewBook};
use rocket_contrib::json::Json;
use serde_json::Value;

#[get("/books", format = "application/json")]
pub fn index(conn: DbConn) -> Json<Value> {
    let books = Book::all(&conn);

    Json(json!({
        "status": 200,
        "result": books,
    }))
}

#[post("/books", format = "application/json", data = "<new_book>")]
pub fn new(conn: DbConn, new_book: Json<NewBook>) -> Json<Value> {
    Json(json!({
        "status": if Book::insert(new_book.into_inner(), &conn) { 200 } else { 500 },
        "result": Book::all(&conn).first(),
    }))
}

#[get("/books/<id>", format = "application/json")]
pub fn get(conn: DbConn, id: i32) -> Json<Value> {
    let result = Book::get(id, &conn);
    let status = if result.is_empty() { 404 } else { 200 };

    Json(json!({
        "status": status,
        "result": result.get(0)
    }))
}

#[put("/books/<id>", format = "application/json", data = "<book>")]
pub fn update(conn: DbConn, id: i32, book: Json<NewBook>) -> Json<Value> {
    let status = if Book::update(id, &conn, book.into_inner()) {
        200
    } else {
        404
    };

    Json(json!({
        "status": status,
        "result": null,
    }))
}

#[delete("/books/<id>")]
pub fn delete(conn: DbConn, id: i32) -> Json<Value> {
    let status = if Book::delete(id, &conn) { 200 } else { 404 };

    Json(json!({
        "status": status,
        "result": null,
    }))
}

#[get("/books/author/<author>", format = "application/json")]
pub fn author(conn: DbConn, author: String) -> Json<Value> {
    Json(json!({
        "status": 200,
        "result": Book::author(author, &conn),
    }))
}

#[catch(404)]
pub fn not_found() -> Json<Value> {
    Json(json!({
        "status": "error",
        "reason": "Resource was not found"
    }))
}
