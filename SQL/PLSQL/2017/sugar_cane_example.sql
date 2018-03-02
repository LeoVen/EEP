CREATE TABLE sugar_cane_productivity (
    ranking int                      NOT NULL,
    country varchar (20)             NOT NULL,
    production float                 NOT NULL,
    PRIMARY KEY (ranking)
);

-- Observe que é preciso usar o primeiro exemplo ao contrário do segundo
-- INSERT ALL pois o segundo exemplo não é valido
-- (1)
INSERT ALL
    INTO sugar_cane_productivity VALUES (1, 'Brazil', 736.11)
    INTO sugar_cane_productivity VALUES (2, 'India', 352.15)
    INTO sugar_cane_productivity VALUES (3, 'China', 126.15)
    INTO sugar_cane_productivity VALUES (4, 'Thailand', 103.7)
    INTO sugar_cane_productivity VALUES (5, 'Pakistan', 62.83)
    INTO sugar_cane_productivity VALUES (6, 'Mexico', 56.673)
    INTO sugar_cane_productivity VALUES (7, 'Colombia', 36.51)
    INTO sugar_cane_productivity VALUES (8, 'Australia', 30.52)
    INTO sugar_cane_productivity VALUES (9, 'Indonesia', 28.6)
    INTO sugar_cane_productivity VALUES (10, 'USA', 27.6)
SELECT * FROM DUAL;

--(2)
/*
INSERT INTO sugar_cane_productivity
VALUES
(1, 'Brazil', 736.11), 
(2, 'India', 352.15), 
(3, 'China', 126.15), 
(4, 'Thailand', 103.7), 
(5, 'Pakistan', 62.83), 
(6, 'Mexico', 56.673), 
(7, 'Colombia', 36.51),
(8, 'Australia', 30.52), 
(9, 'Indonesia', 28.6), 
(10, 'USA', 27.6);
*/

SELECT * FROM sugar_cane_productivity

/*

Programa que compara a produção de um país com outro

*/
DECLARE
  --Declaração de variáveis
  c_id1 sugar_cane_productivity.ranking%type := 5; --Modifique para comparar outro país
  c_id2 sugar_cane_productivity.ranking%type := 12; --Modifique para comparar outro país
  --Declarando variáveis
  percent_difference decimal(20, 2);
  c_name1 varchar2 (20);
  c_name2 varchar2 (20);
  c_prod1 float;
  c_prod2 float;
  number_rows int;
BEGIN
  --Função que conta o número de registros especificados, neste caso todos (*)
  SELECT COUNT(*)
  INTO number_rows
  FROM sugar_cane_productivity;
  --Verificando se as variáveis estão entre 1 e a quantidade de registros
  IF (c_id1 BETWEEN 1 AND number_rows) AND (c_id1 BETWEEN 1 AND number_rows) THEN
    --Seleção do primeiro país
    SELECT country, production INTO c_name1, c_prod1
    FROM sugar_cane_productivity
    WHERE ranking = c_id1;
    --Seleção do segundo país
    SELECT country, production INTO c_name2, c_prod2
    FROM sugar_cane_productivity
    WHERE ranking = c_id2;
    --Calculando porcentagem
    percent_difference := (c_prod1 / c_prod2) * 100;
    --Output
    dbms_output.put_line
    ('Country ' || c_name1 || ' has ' || percent_difference || ' % the production of ' || c_name2);
    dbms_output.put_line
    ('Number of rows : ' || number_rows);
  ELSE 
    dbms_output.put_line
    ('Error');
  END IF;
END;
/*
PERGUNTA

PORQUE IF NÃO EVITA O ERRO?

*/
/*

Programa que pega os países que possuem uma produção maior que X
         (usando loop)

*/
DECLARE
  --Variáveis
  number_rows int;
  specified_value float := 100.0; --Especificar valor
  i int := 1;
  country_out varchar2 (20);
  production_out float;
  --Variável para guardar as colunas (Somente em PL/SQL)
  dsc varchar2 (16384);
BEGIN
  --Achando o número de registros
  SELECT COUNT(*)
  INTO number_rows
  FROM sugar_cane_productivity;
  LOOP
    --Fazendo a seleção
    SELECT country, production
    INTO country_out, production_out
    FROM sugar_cane_productivity
    WHERE ranking = i;
    --Checando os valores
    IF (production_out >= specified_value) AND (i < number_rows) THEN
      dbms_output.put_line
      (country_out || ' has a production of ' || production_out);
      i := i + 1;
    ELSIF (production_out < specified_value) AND (i < number_rows) THEN
      i := i + 1;
    ELSE 
      EXIT;
    END IF;
  END LOOP;
END;

-- Usando ROWNUM

SELECT * FROM (
SELECT * FROM compras
WHERE id_compra > 20 AND id_compra < 40
ORDER BY id_compra)
WHERE ROWNUM <= 20;

-- Alter Table
ALTER TABLE sugar_cane_productivity ADD pop_pais FLOAT;

-- Não é possível deletar uma coluna criada por SYS mesmo você sendo SYS... DUMB
ALTER TABLE sugar_cane_productivity DROP COLUMN pop_pais;

// ------------------------------ Tabela relacional ------------------------------ //

CREATE TABLE country_info (
    ranking int           NOT NULL,
    country varchar (20)  NOT NULL,
    population float
);

INSERT ALL
    INTO country_info VALUES (1, 'China', 1409517397)
    INTO country_info VALUES (2, 'India', 1339180127 )
    INTO country_info VALUES (3, 'USA', 324459463)
    INTO country_info VALUES (4, 'Indonesia', 263991379)
    INTO country_info VALUES (5, 'Brazil', 209288278)
    INTO country_info VALUES (6, 'Pakistan', 197015955)
    INTO country_info VALUES (7, 'Mexico', 129163276)
    INTO country_info VALUES (8, 'Thailand', 69037513)
    INTO country_info VALUES (9, 'Colombia', 49065615)
    INTO country_info VALUES (10, 'Australia', 24450561)
SELECT * FROM DUAL;

SELECT
t.ranking AS t_ranking, t.country AS t_country, t.production AS t_production,
s.country AS s_country, s.ranking AS s_ranking, s.population AS s_population
FROM sugar_cane_productivity t
INNER JOIN country_info s
ON t.country = s.country ORDER BY s.ranking;