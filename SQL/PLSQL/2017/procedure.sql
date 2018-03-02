--Trabalhando com PROCEDURE

CREATE OR REPLACE PROCEDURE meu_procedimento
AS
BEGIN
  dbms_output.put_line('Hello World!');
END;

EXEC meu_procedimento;

DECLARE
  i INT;
  nome VARCHAR2 (20);
BEGIN
  i := 20;
  FOR i IN 1 .. 20 LOOP
    meu_procedimento;
  END LOOP;
END;

--Trabalhando com parâmetros


--IN e OUT
DECLARE
  a number;
  b number;
  c number;
PROCEDURE findMin(x IN number, y IN number, z OUT number)
AS
BEGIN
  IF x < y THEN
    z:= x;
  ELSE
    z:= y;
  END IF;
END;
BEGIN
  a:= 23;
  b:= 45;
  findMin(a, b, c);
  dbms_output.put_line(' Minimum of (23, 45) : ' || c);
END;


--IN OUT
DECLARE
  a number;
PROCEDURE squareNum(x IN OUT number) IS
BEGIN
  x := x * x;
END;
BEGIN
  a:= 23;
  squareNum(a);
  dbms_output.put_line(' Square of (23): ' || a);
END;


-- Trabalhando com FUNCTION

DECLARE
  i INT;
  random INT;
  numero_1 INT;
  numero_2 INT;
  
  FUNCTION aleatorio(numero1 IN INT, numero2 IN INT)
  RETURN INT IS 
    resultado INT;
  BEGIN
    resultado := ABS(MOD(dbms_random.random, numero1)) + ABS(MOD(dbms_random.random, numero2));
    RETURN resultado;
  END aleatorio;

BEGIN
  numero_1 := 10;
  numero_2 := 14;
  FOR i IN 1 .. 10 LOOP
    random := aleatorio(numero_1, numero_2);
    dbms_output.put_line (random);
  END LOOP;
END;

-- ////////////////////////////////////////////////////////////////////////////////////////////
DECLARE
  i INT;
  random INT;
  numero_1 INT;
  numero_2 INT;

  FUNCTION aleatorio(numero1 IN INT, numero2 IN INT)
  RETURN INT IS 
    resultado INT;
  BEGIN
    resultado := ABS(MOD(dbms_random.random, numero1)) + ABS(MOD(dbms_random.random, numero2));
    RETURN resultado;
  END aleatorio;


BEGIN
  numero_1 := 10;
  numero_2 := 14;
  FOR i IN 1 .. 10 LOOP
    random := aleatorio(numero_1, numero_2);
    dbms_output.put_line (random);
  END LOOP;
END;


DECLARE
  a NUMBER;
  b NUMBER;
  c NUMBER;
 
  FUNCTION max_entre_numeros(
      x IN NUMBER,
      y IN NUMBER)
    RETURN NUMBER
  IS
    z NUMBER;
  BEGIN
    IF x > y THEN
      z := x;
    ELSE
      Z:= y;
    END IF;
    RETURN z;
  END;
  BEGIN
    a := 23;
    b := 45;
    c := max_entre_numeros (a, b);
    dbms_output.put_line('Valor máximo obtido entre os valores ' || a ||
     ' e ' || b || ' foi ' || c);  
END;




-- Procedure de Fatorial ( Não funcionando )




-- Nova tentativa
DECLARE 
   i NUMBER; 
   n NUMBER;
   resultado NUMBER;

PROCEDURE fatorial(numero IN NUMBER) IS 
  resultado NUMBER;
BEGIN 
  IF numero = 0 THEN
    resultado := 1;
  ELSE
    resultado := numero * fatorial(numero - 1);
  END IF;
  dbms_output.put_line(numero || '! = ' || resultado);
END fatorial;
BEGIN 
   fatorial(5);
END;

