use diesel;
use diesel::pg::PgConnection;
use diesel::prelude::*;

use super::schema::books;
use super::schema::books::dsl::books as books_table;

#[derive(Serialize, Queryable, Debug, Clone)]
pub struct Book {
    pub id: i32,
    pub title: String,
    pub author: String,
    pub published: bool,
}

#[derive(Serialize, Deserialize, Insertable)]
#[table_name = "books"]
pub struct NewBook {
    pub title: String,
    pub author: String,
    pub published: bool,
}

impl Book {
    pub fn get(id: i32, conn: &PgConnection) -> Vec<Book> {
        books_table
            .find(id)
            .load::<Book>(conn)
            .expect("Error Loading Books")
    }

    pub fn all(conn: &PgConnection) -> Vec<Book> {
        books_table
            .order(books::id.desc())
            .load::<Book>(conn)
            .expect("Error Loading Books")
    }

    pub fn update(id: i32, conn: &PgConnection, book: NewBook) -> bool {
        use crate::schema::books::dsl::{author as a, published as p, title as t};

        let NewBook {
            title,
            author,
            published,
        } = book;

        diesel::update(books_table.find(id))
            .set((a.eq(author), p.eq(published), t.eq(title)))
            .get_result::<Book>(conn)
            .is_ok()
    }

    pub fn insert(book: NewBook, conn: &PgConnection) -> bool {
        diesel::insert_into(books::table)
            .values(&book)
            .execute(conn)
            .is_ok()
    }

    pub fn delete(id: i32, conn: &PgConnection) -> bool {
        if Book::get(id, conn).is_empty() {
            return false;
        }

        diesel::delete(books_table.find(id)).execute(conn).is_ok()
    }

    pub fn author(author: String, conn: &PgConnection) -> Vec<Book> {
        books_table
            .filter(books::author.eq(author))
            .load::<Book>(conn)
            .expect("Error Loading Books")
    }
}
