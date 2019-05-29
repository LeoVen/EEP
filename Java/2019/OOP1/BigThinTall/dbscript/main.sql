CREATE DATABASE IF NOT EXISTS oopcrud;

CREATE TABLE IF NOT EXISTS oopcrud.users
(
    id INT UNSIGNED NOT NULL AUTO_INCREMENT,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(200),
    password CHAR(40) NOT NULL,
    PRIMARY KEY (id)
);

CREATE TABLE IF NOT EXISTS oopcrud.categories
(
	name VARCHAR(50) NOT NULL,
	userid INT UNSIGNED NOT NULL,
	PRIMARY KEY (name),
	FOREIGN KEY (userid)
		REFERENCES oopcrud.users (id)
		ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS oopcrud.todos
(
	id INT unsigned NOT NULL AUTO_INCREMENT,
	title VARCHAR(100),
	description VARCHAR(200),
	category VARCHAR(50) NOT NULL,
	PRIMARY KEY (id),
	FOREIGN KEY (category)
		REFERENCES oopcrud.categories (name)
);
