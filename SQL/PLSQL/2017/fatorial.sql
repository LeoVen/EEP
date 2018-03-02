-- Função recursiva fatorial

DECLARE
  fat INT;
  numer INT;
  
  FUNCTION fatorial(numero IN INT)
  RETURN INT IS
    resultado INT;
  BEGIN
    IF numero = 0 THEN
      resultado := 1;
    ELSE
      resultado := numero * fatorial(numero - 1);
    END IF;
    RETURN resultado;
  END fatorial;
  
BEGIN
  numer := 10; -- Pode haver input do usuário se possível
  fat := fatorial(numer);
  dbms_output.put_line (numer || '! = ' || fat);
END;
