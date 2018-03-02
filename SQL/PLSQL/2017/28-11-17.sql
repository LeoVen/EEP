select count(user_zip), user_zip 
from user_register 
group by user_zip having count(*) > 1 
order by count(user_zip) desc

select * from cars

select car_model, max(car_id) from cars group by car_model having count(car_model) > 1

select car_model, count(car_model) from cars group by car_model having count(*) > 1 order by count(car_model) desc

select * from cars where car_model = 'Grand Prix'

select unique car_model from cars order by car_model --1003
select unique car_make from cars --77

select unique car_model, car_make from cars order by car_model --1037



begin
  delete_car;
end;

declare
    i int;
begin
  

select * from user_register

select ( to_date(sysdate, 'DD/MM/YYYY HH24:MI:SS') - to_date(user_time, '01/11/2017 HH24:MI:SS') ), 
       to_date(user_time, 'HH24:MI:SS'),
       to_date(sysdate, 'DD/MM/YYYY HH24:MI:SS')
from user_register

select to_date(user_time, 'HH24:MI:SS') - to_date(sysdate, 'DD/MM/YYYY HH24:MI:SS'), 
       to_date(user_time, 'HH24:MI:SS'),
       to_date(sysdate, 'DD/MM/YYYY HH24:MI:SS')
from user_register


select to_date(user_time, 'HH24:MI:SS') from user_register


select (to_date('2010-07-07 19:30', 'YYYY-MM-DD hh24:mi') 
             - to_date('2009-07-07 19:30', 'YYYY-MM-DD hh24:mi')) diff_hours 
       from dual;



select sysdate -
       to_timestamp(  to_char(  user_date + cast('0 '||user_time as interval day to second), 
                                'DD/MM/YYYY HH24:MI:SS'), 
                      'DD/MM/YYYY HH24:MI:SS'),
       user_date,
       user_time
from user_register

select user_time, count(user_time) from user_register group by user_time having count(*) > 1 order by count(user_time) desc

select user_date, count(user_time) from user_register group by user_date having count(*) > 1 order by count(user_time)

select user_date, count(user_time) from user_register group by user_date having count(*) = 1

select user_name, count(user_name) from user_register group by user_name having count(*) > 1 order by count(user_name) desc

select count(unique user_name) from user_register

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

select to_date('2015/09/21 12:22:13', ' : : HH24:MI:SS') from dual

drop table user_register

select extract(second from systimestamp) from dual

select systimestamp from dual

select to_date(to_char(systimestamp, 'HH24:MI:SS'), 'HH24:MI:SS')  from dual

select to_char(systimestamp, 'HH24:MI:SS') from dual

create table car_models
(
  car_make		varchar2 (50),
  car_model		varchar2 (50),
  car_year		number
);

drop table car_models

insert into car_models (car_year, car_model, car_make) select unique car_year, car_model, car_make from cars

select * from car_models

select * from user_register

-- 1º
alter table car_models add car_model_id number;

-- 2º
drop sequence car_models_seq
create sequence car_models_seq start with 1 increment by 1 nomaxvalue;

-- 3º
update car_models set car_model_id = car_models_seq.nextval;

-- 4º
alter table car_models add constraint car_model_id primary key (car_model_id);

-- 1º
alter table user_register add user_id number;

-- 2º
drop sequence user_register_seq
create sequence user_register_seq start with 1 increment by 1 nomaxvalue;

-- 3º
update user_register set user_id = user_register_seq.nextval;

-- 4º
alter table user_register add constraint user_id primary key (user_id);

drop table user_register


create table products
(
  product_name   varchar2 (110),
  product_price   number
)

select unique product_name from products

select unique product_price from products
select product_price, count(product_price) from products group by product_price having count(*) > 1 order by count(product_price) desc

select unique product_name, min(product_price) from products group by product_name having count(product_name) > 1

create table product_sales
(
  product_id    number,
  product_name  varchar2 (110),
  product_price   number
);

drop table product_sales

drop sequence product_sales_seq;
create sequence product_sales_seq start with 1 increment by 1 nomaxvalue;

update product_sales set product_id = product_sales_seq.nextval;

insert into product_sales (product_id, product_name, product_price)
select  product_sales_seq.nextval,
        unique product_name, 
        min(product_price) 
        from products group by product_name having count(product_name) > 1)
        

insert into product_sales (product_id, product_name, product_price)
select * from
--( select  product_sales_seq.nextval from dual ) A
( select rownum from dual) A
inner join 
(select
        unique product_name, 
        min(product_price) 
        from products group by product_name having count(product_name) > 1) B
on A.rownum = B.rownum

insert into product_sales (product_name, product_price)
select    unique product_name, 
        min(product_price) 
        from products group by product_name having count(product_name) > 1

       
update product_sales set product_id = product_sales_seq.nextval;
alter table product_sales add constraint product_id primary key (product_id);


select * from product_sales




select * from
( select unique product_price
         from products group by product_price having count(product_price) > 1 ) A
full join
( select
         unique product_name, 
         min(product_price) 
         from products group by product_name having count(product_name) > 1 ) B
on A.rownum = B.rownum
