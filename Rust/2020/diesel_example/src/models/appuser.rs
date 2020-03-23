use diesel;
use diesel::pg::PgConnection;
use diesel::prelude::*;

use crate::schema::appuser;
use crate::schema::appuser::dsl::appuser as appuser_table;

// AppUser - A user that has access to the application

#[derive(Queryable)]
pub struct AppUser {
    pub id: i32,
    pub username: String,
    pub password: String,
    pub detail: String,
    pub email: String,
    pub firstname: String,
    pub lastname: String,
}

#[derive(Insertable)]
#[table_name = "appuser"]
pub struct NewAppUser {
    pub username: String,
    pub password: String,
    pub detail: String,
    pub email: String,
    pub firstname: String,
    pub lastname: String,
}

impl AppUser {
    pub fn all(conn: &PgConnection) -> Vec<AppUser> {
        appuser_table
            .order(appuser::id.desc())
            .load::<AppUser>(conn)
            .expect("Error Loading AppUser in AppUser::all")
    }

    pub fn get(id: i32, conn: &PgConnection) -> AppUser {
        appuser_table
            .find(id)
            .first::<AppUser>(conn)
            .expect("Error Loading AppUser in AppUser::get")
    }

    pub fn insert(user: NewAppUser, conn: &PgConnection) -> bool {
        diesel::insert_into(appuser_table)
            .values(&user)
            .execute(conn)
            .is_ok()
    }
}

impl std::fmt::Debug for AppUser {
    fn fmt(&self, fmt: &mut std::fmt::Formatter) -> std::fmt::Result {
        fmt.debug_struct("AppUser")
            .field("username", &self.username)
            .field("password", &self.password)
            .field("detail", &self.detail)
            .field("email", &self.email)
            .field("firstname", &self.firstname)
            .field("lastname", &self.lastname)
            .finish()
    }
}
