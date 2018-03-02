/*

OBJETIVO
Tentar reproduzir um vetor com objetos por meio de fun��es que geram palavras aleat�rias

DIFICULDADE:
Dificil pra um caralho!

*/

DECLARE
  --Vari�veis de preenchimento
  i INT;
  nome VARCHAR (20);
  idade INT;
  endereco VARCHAR (50);
  salario DECIMAL (18, 2);

  -- Objeto
  CREATE OR REPLACE TYPE objeto AS OBJECT
  (
   u_id INT,
   u_name VARCHAR (20),
   u_age INT,
   u_addr VARCHAR (50),
   u_payment DECIMAL (18, 2)
   );
  
  -- Vetor de objetos
  TYPE vetor IS VARRAY(20) OF objeto;
  
BEGIN
  -- Testando
  vetor(1) := objeto(1, 'Leonardo', 20, 'Rua Dr Paulo Pinto, 268', 1140.00);
END;
  
