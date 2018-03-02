CREATE TABLE c_user (
       c_id INT               NOT NULL,
       c_name VARCHAR (30)    NOT NULL,
       c_age int              NOT NULL,
       c_address VARCHAR (80)         ,
       c_salary float                 ,
       PRIMARY KEY (c_id)
);

CREATE TABLE orders (
       o_id INT               NOT NULL,
       o_customer VARCHAR (20)NOT NULL,
       o_order VARCHAR (20)   NOT NULL,
       PRIMARY KEY (o_id)
);

DROP TABLE c_user;

SELECT * FROM c_user ORDER BY c_salary

SELECT COUNT(*) FROM c_user

SELECT COUNT(*) FROM c_user WHERE (c_salary > 2000) AND (c_salary < 3000)
SELECT COUNT(*) FROM c_user WHERE c_salary = 0

SELECT * FROM c_user WHERE c_salary BETWEEN 16 AND 21 ORDER BY c_salary DESC

DECLARE
  --Variáveis
  l INT;
  age INT;
  address VARCHAR2 (80);
  salary  FLOAT;
  --Variáveis para a geração de palavras aleatórias
  i INT;
  chance FLOAT;
  minimum_chance FLOAT := 0.05; --Modifique para ter nomes maiores ou menores
  spacing INT;
  it INT;
  letter INT;
  word VARCHAR2 (30);
  --Outras
  total_registers INT;
  --Média
  table_size INT;
  total float;
  
BEGIN
  SELECT COUNT(*)
  INTO total_registers
  FROM c_user;
  
  FOR l IN (total_registers) .. (total_registers + 9999) LOOP
    it := 0;
    spacing := 0;
    word := '';
    FOR i IN 1..30 LOOP
      
      chance := trunc(dbms_random.value(), 4);
      IF (chance < minimum_chance) AND (it > 4) THEN
        EXIT;
      ELSIF (chance >= 0.30) AND (chance <= 0.8) THEN
        letter := 97 + ABS(MOD(dbms_random.random, 24));
        word := CONCAT(word, CHR(letter));
        it := it + 1;
        spacing := spacing + 1;
      ELSIF (chance < 0.30) AND (chance >= minimum_chance) THEN
        letter := 65 + ABS(MOD(dbms_random.random, 24));
        word := CONCAT(word, CHR(letter));
        it := it + 1;
        spacing := spacing + 1;
      ELSIF (chance > 0.8) AND (it > 2) AND (spacing > 4) THEN
        spacing := 0;
        letter := 32;
        word := CONCAT(word, CHR(letter));
        it := it + 1;
      END IF;
      
    END LOOP; --Word generated
    --Gerando outros dados
    age := 18 + ABS(MOD(dbms_random.random, 40));
    salary := trunc(dbms_random.value * ABS(MOD(dbms_random.random, 11149)), 2);
    
    --Getting address
    it := 0;
    spacing := 0;
    address := '';
    FOR i IN 1..80 LOOP
      
      chance := trunc(dbms_random.value(), 4);
      IF (chance < minimum_chance) AND (it > 4) THEN
        EXIT;
      ELSIF (chance >= 0.30) AND (chance <= 0.8) THEN
        letter := 97 + ABS(MOD(dbms_random.random, 24));
        address := CONCAT(address, CHR(letter));
        it := it + 1;
        spacing := spacing + 1;
      ELSIF (chance < 0.30) AND (chance >= minimum_chance) THEN
        letter := 65 + ABS(MOD(dbms_random.random, 24));
        address := CONCAT(address, CHR(letter));
        it := it + 1;
        spacing := spacing + 1;
      ELSIF (chance > 0.8) AND (it > 2) AND (spacing > 4) THEN
        spacing := 0;
        letter := 32;
        address := CONCAT(address, CHR(letter));
        it := it + 1;
      END IF;
      
    END LOOP; --Address generated
    --Sending words to database
    INSERT INTO c_user
    VALUES (l, word, age, address, salary);
    --dbms_output.put_line
    --('Index : ' || l || ' Nome : ' || word || ' Idade : ' || age || ' Salário : ' || salary || ' Endereço : ' || address);
  END LOOP;
  SELECT COUNT(*) INTO table_size FROM c_user;
  SELECT SUM(c_salary) INTO total FROM c_user;
  dbms_output.put_line ('Média : ' || (total / table_size));
END;
