-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>


-- Algoritmos úteis
select coluna from tabela group by coluna having count(*) > 1 order by count(coluna);

select coluna, count(coluna) from tabela group by coluna having count(*) > 1 order by count(coluna) desc;


-- Deletar sequencias
drop sequence nome_sequencia;


-- Concatenar Data e Hora
select to_timestamp( 	to_char(	user_date + cast('0 '||user_time as interval day to second), 
									    'DD/MM/YYYY HH24:MI:SS'), 
						          'DD/MM/YYYY HH24:MI:SS')
from user_register;


-- Pegar os registros repetidos com o maior id
select coluna, max(coluna_id) from tabela group by coluna having count(coluna) > 1;



-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>



-- Criando tabela de usuários
-- Tirado de : http://www.mockaroo.com/

create table user_register
(
  user_name       varchar2 (50),
  user_country    varchar2 (50),
  user_city       varchar2 (100),
  user_street     varchar2 (100),
  user_zip        varchar2 (50),
  user_password   varchar2 (50),
  user_email      varchar2 (50),
  user_date       date,
  user_time       varchar2 (10)
);


-- Colocar esses parâmetros para user_time e user_date

to_char('#', 'HH24:MI:SS') -- Para o horário
to_date('#', 'DD/MM/YYYY') -- para a data



-- Adicionando a coluna user_id

-- 1º
alter table user_register add user_id number;

-- 2º
drop sequence user_register_seq;
create sequence user_register_seq start with 1 increment by 1 nomaxvalue;

-- 3º
update user_register set user_id = user_register_seq.nextval;

-- 4º
alter table user_register add constraint user_id primary key (user_id);


-- Testando Queries

select * from user_register order by user_date, user_time;


-- Verificando quais registros possuem mais de um user_name

select user_name from user_register group by user_name having count(*) > 1;


-- Identificando quais user_zip possuem mais de um

select count(user_zip), user_zip 
from user_register 
group by user_zip having count(*) > 1 
order by count(user_zip) desc;


-- Diferença de timestamp comparando o sysdate com registros
select sysdate -
       to_timestamp(  to_char(  user_date + cast('0 '||user_time as interval day to second), 
                                'DD/MM/YYYY HH24:MI:SS'), 
                      'DD/MM/YYYY HH24:MI:SS'),
       user_date,
       user_time
from user_register;


-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>


-- Criando tabela de nomes para outros programas

create table names
(
  first_name	varchar2 (50),
  last_name		varchar2 (50)
);


-- Adicionando a coluna id_name

-- 1º
alter table names add id_name number;

-- 2º
drop sequence name_seq;
create sequence name_seq start with 1 increment by 1 nomaxvalue;

-- 3º
update names set id_name = name_seq.nextval;

-- 4º
alter table names add constraint id_name primary key (id_name);


-- Verificando quais registros possuem mais de um first_name

select first_name, count(first_name) 
from names 
group by first_name having count(*) > 1 
order by count(first_name) desc;


-- O mesmo pode ser feito para last_name

select last_name, count(last_name) 
from names 
group by last_name having count(*) > 1 
order by count(last_name) desc;


-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>


-- Criando tabela de carros para outros programas
create table cars
(
  car_make		varchar2 (50),
  car_model		varchar2 (50),
  car_year		number
);


-- Adicionando a coluna id_car

-- 1º
alter table cars add car_id number;

-- 2º
drop sequence car_seq;
create sequence car_seq start with 1 increment by 1 nomaxvalue;

-- 3º
update cars set car_id = car_seq.nextval;

-- 4º
alter table cars add constraint car_id primary key (car_id);

-- 5º Criando tabela definitiva com unique
create table car_models
(
  car_make		varchar2 (50),
  car_model		varchar2 (50),
  car_year		number
);

insert into car_models (car_year, car_model, car_make) select unique car_year, car_model, car_make from cars;

-- Adicionando a coluna car_model_id

-- 5.1º
alter table car_models add car_model_id number;

-- 5.2º
drop sequence car_models_seq;
create sequence car_models_seq start with 1 increment by 1 nomaxvalue;

-- 5.3º
update car_models set car_model_id = car_models_seq.nextval;

-- 5.4º
alter table car_models add constraint car_model_id primary key (car_model_id);


-- Outros 
select car_model, max(car_id) from cars group by car_model having count(car_model) > 1;


-- Inner join de carros e pessoas por id
select * from user_register
inner join
car_models
on car_models.car_model_id = user_register.user_id
order by car_model



-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>



-- Criando tabela de produtos tirados de 
-- http://www.freedatagenerator.com/csv-data-generator

create table products
(
	product_name 	varchar2 (110),
	product_price 	number
);

-- Agora criando a tabela definitiva product_sales

create table product_sales
(
	product_id		number,
	product_name 	varchar2 (110),
	product_price 	number
);

-- 1º Criando sequencia de id
drop sequence product_sales_seq;
create sequence product_sales_seq start with 1 increment by 1 nomaxvalue;

-- 2º E então inserimos os valores
insert into product_sales (product_name, product_price)
select  	unique product_name, 
		    min(product_price) 
        from products group by product_name having count(product_name) > 1

-- 3º Agora inserimos os IDs
update product_sales set product_id = product_sales_seq.nextval;

alter table product_sales add constraint product_id primary key (product_id);




-- <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<< <<<<<  >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>> >>>>>



-- Criando tabela de compras


create table compras
(
	
)