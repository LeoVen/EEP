CREATE TABLE random (
    num_float float,
    num_int int,
    num_result float
);

DROP TABLE random;

SELECT * FROM random;

SELECT COUNT(*) FROM random;

/*

    dbms_random.random() -> Produz inteiros entre [-2**31 e 2**31)
    dbms_random.value() -> Produz numeros entre [0 , 1) com 38 casas de precisão
    
*/

DECLARE

  val_i int;
  val_f float;
  result_f float;
  
BEGIN
  
  FOR i IN 1..1000 LOOP
    
    val_i := 1+ABS(MOD(dbms_random.random,10000));
    val_f := trunc(dbms_random.value(), 4);
    result_f := val_i * val_f;
    dbms_output.put_line (result_f);
    INSERT INTO random
    VALUES (val_f, val_i, result_f);
    
  END LOOP;
  
END;

--Selecting
SELECT num_result FROM random WHERE num_int BETWEEN 0 AND 10 ORDER BY num_float

--Ordering
SELECT * FROM random
ORDER BY num_int;

SELECT * FROM random
ORDER BY num_float;

SELECT * FROM random
ORDER BY num_result;

--Desc
SELECT * FROM random
ORDER BY num_int DESC;

SELECT * FROM random
ORDER BY num_float DESC;

SELECT * FROM random
ORDER BY num_result DESC;
