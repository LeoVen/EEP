-- Your SQL goes here

CREATE TABLE "appuser" (
    "id" SERIAL PRIMARY KEY,
    "username" VARCHAR NOT NULL,
    "password" VARCHAR NOT NULL,
    "detail" VARCHAR NOT NULL,
    "email" VARCHAR NOT NULL,
    "firstname" VARCHAR NOT NULL,
    "lastname" VARCHAR NOT NULL
);
