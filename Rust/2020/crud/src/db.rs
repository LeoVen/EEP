use diesel::pg::PgConnection;
use diesel::r2d2;
use diesel::r2d2::{ConnectionManager, Pool, PooledConnection};
use rocket::http::Status;
use rocket::request::{self, FromRequest};
use rocket::{Outcome, Request, State};
use std::ops::Deref;

pub type PgPool = Pool<ConnectionManager<PgConnection>>;
pub type PgPooledConnection = PooledConnection<ConnectionManager<PgConnection>>;

pub fn init_pool(db_url: String) -> PgPool {
    let manager = ConnectionManager::<PgConnection>::new(db_url);
    r2d2::Pool::new(manager).expect("DB Pool Failure")
}

pub struct PgConn(pub PgPooledConnection);

impl<'a, 'r> FromRequest<'a, 'r> for PgConn {
    type Error = ();

    fn from_request(request: &'a Request<'r>) -> request::Outcome<PgConn, ()> {
        let pool = request.guard::<State<PgPool>>()?;

        match pool.get() {
            Ok(conn) => Outcome::Success(PgConn(conn)),
            Err(_) => Outcome::Failure((Status::ServiceUnavailable, ())),
        }
    }
}

impl Deref for PgConn {
    type Target = PgConnection;

    #[inline(always)]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}
