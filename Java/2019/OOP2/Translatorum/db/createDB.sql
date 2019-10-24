-- Author:  Leonardo Vencovsky (https://github.com/LeoVen/)
-- Created: 18/09/2019

CREATE DATABASE IF NOT EXISTS `translatorum`;
USE `translatorum`;

CREATE TABLE IF NOT EXISTS `language`
(
    `id` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    `name` VARCHAR(100) NOT NULL,
    PRIMARY KEY(`id`)
);

CREATE TABLE IF NOT EXISTS `word`
(
    `id` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    `language` INTEGER UNSIGNED NOT NULL,
    `word` VARCHAR(200) NOT NULL,
    PRIMARY KEY(`id`),
    FOREIGN KEY(`language`) REFERENCES `language`(`id`)
);

CREATE TABLE IF NOT EXISTS `translation`
(
    `id` INTEGER UNSIGNED NOT NULL AUTO_INCREMENT,
    `word1` INTEGER UNSIGNED NOT NULL,
    `word2` INTEGER UNSIGNED NOT NULL,
    PRIMARY KEY(`id`),
    FOREIGN KEY(`word1`) REFERENCES `word`(`id`),
    FOREIGN KEY(`word2`) REFERENCES `word`(`id`)
);
