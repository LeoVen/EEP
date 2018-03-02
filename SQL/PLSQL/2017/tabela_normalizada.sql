--Criando tabelas
CREATE TABLE registro (
    r_id INT,
    nome VARCHAR (40),
    idade INT,
    salario DECIMAL (18, 2),
    PRIMARY KEY (r_id)
);

CREATE TABLE compras (
    id_compra INT,
    id_usuario INT,
    nome_produto VARCHAR (20),
    id_produto INT,
    total_pago DECIMAL (18, 2),
    PRIMARY KEY (id_compra)
);

SELECT * FROM registro

SELECT COUNT(*) FROM registro

-------------------------------------------------------------------------------------------------------------Script para registro
DECLARE
  --variáveis enviadas à tabela
  i INT; --r_id
  nome VARCHAR2 (50);
  idade INT;
  salario DECIMAL(18, 2);
  tamanho INT; --Tamanho da tabela
  --Vetores
  TYPE vetor IS VARRAY(20) OF VARCHAR2 (20);
  vetor_nomes vetor;
  vetor_sobrenomes vetor;
  --Variáveis controladoras
  input_total INT := 49;
  idade_maxima INT := 55;
  idade_minima INT := 20;
  salario_maximo INT := 8111;
BEGIN
  
  --Criando Vetores de Inserção
  vetor_nomes := vetor('Laila', 'Marcos', 'Paulo', 'Leonardo', 'Henrique', 'Yasmin', 'Flavia', 'Carol', 'Leticia', 'Guilherme', 'João', 'Gabriela', 'Marcia', 'Lucas', 'Rafael', 'Matheus', 'Raquel', 'Enzo', 'Melissa', 'Thiago');
  vetor_sobrenomes := vetor('Oliveira', 'Silva', 'Santos', 'Souza', 'Lima', 'Pereira', 'Ferreira', 'Costa', 'Costa', 'Rodrigues', 'Almeida', 'Alves', 'Carvalho', 'Araújo', 'Ribeiro', 'Smith', 'Schmidt', 'Takanashi', 'Wang', 'Martin');
  SELECT COUNT(*)
  INTO tamanho --Tamanho da tabela
  FROM registro;
  FOR i IN tamanho .. (tamanho + input_total) LOOP
    idade := idade_minima + ABS(MOD(dbms_random.random, idade_maxima - idade_minima));
    salario := TRUNC(dbms_random.value * ABS(MOD(dbms_random.random, salario_maximo)), 2);
    nome := CONCAT(CONCAT((vetor_nomes(1 + ABS(MOD(dbms_random.random, vetor_nomes.COUNT)))), ' '), (vetor_sobrenomes(1 + ABS(MOD(dbms_random.random, vetor_sobrenomes.COUNT)))));
    --Inserindo na tabela
    INSERT INTO registro
    VALUES (i, nome, idade, salario);
  END LOOP; --Loop de fora
  
END;
-------------------------------------------------------------------------------------------------------------Fim Script para registro

SELECT * FROM registro WHERE salario BETWEEN 2000 AND 3000

SELECT * FROM registro
ORDER BY nome

SELECT r_id FROM registro WHERE salario BETWEEN 200 AND 800

-------------------------------------------------------------------------------------------------------------Script para compras
DECLARE
  --variáveis enviadas à tabela
  i INT; --Id_compra
  usuario INT; --Id usuário
  nome_produto VARCHAR2 (20);
  valor_produto DECIMAL (18, 2);
  --Outros
  tamanho_registro INT; --Tamanho tabela registro
  tamanho INT;
  aleatorio INT;
  --Vetores
  TYPE vetor IS VARRAY(20) OF VARCHAR2 (20);
  TYPE vetor_int IS VARRAY(20) OF DECIMAL (18, 2);
  produtos vetor;
  pagamento vetor_int;
  --Variáveis de controle
  input_total INT := 99;
BEGIN
  
  SELECT COUNT(*) INTO tamanho_registro FROM registro; --tamanho máximo para ID de usuários
  SELECT COUNT(*) INTO tamanho FROM compras;
  --Criando vetor de nomes e preços de produtos
  produtos := vetor('Computador Dell', 'RAM 8GB', 'HDD 1GB', 'Monitor LED 25.0', 'RAM 4GB', 'SSD 122GB', 'Pen Drive 32GB', 'Pen Drive 64GB', 'Computador ASUS', 'MacBook Air 13'); 
  pagamento := vetor_int(3299.99, 299.99, 229.99, 674.99, 189.90, 359.99, 39.99, 73.99, 2249.99, 4249.99);
  FOR i IN tamanho .. (tamanho + input_total) LOOP
    aleatorio := 1 + ABS(MOD(dbms_random.random, pagamento.COUNT)); --Index para acessar os vetores
    usuario := ABS(1 + MOD(dbms_random.random, tamanho_registro));
    nome_produto := produtos(aleatorio);
    valor_produto := pagamento(aleatorio);
    --Inserindo no banco de dados
    INSERT INTO compras
    VALUES (i, usuario, nome_produto, aleatorio, valor_produto);
  END LOOP; --Loop externo 
END;
-------------------------------------------------------------------------------------------------------------Fim Script para compras

SELECT * FROM compras WHERE id_usuario = 20

SELECT * FROM compras
ORDER BY id_produto

SELECT id_usuario, COUNT(*)
FROM compras
WHERE total_pago = 674.99
GROUP BY id_usuario


-------------------------------------------------------------------------------------------------------------Testing INNER JOIN

SELECT registro.r_id, registro.nome, compras.id_compra, compras.nome_produto, compras.id_produto, compras.total_pago
FROM registro
INNER JOIN compras
ON registro.r_id = compras.id_usuario
WHERE registro.nome 
LIKE '%Yasmin%'
ORDER BY registro.r_id;
-- /
SELECT registro.r_id, registro.nome, compras.id_compra, compras.nome_produto, compras.id_produto, compras.total_pago
FROM registro
INNER JOIN compras
ON registro.r_id = compras.id_usuario
WHERE compras.nome_produto 
LIKE '%GB%'
ORDER BY registro.r_id;

-- Usando LIKE
SELECT COUNT(*) FROM compras WHERE nome_produto LIKE '%GB%'

SELECT * FROM registro ORDER BY nome DESC

SELECT SUM(total_pago) FROM compras WHERE id_usuario = 3

-- UNION só funciona com com colunas de mesmo tipo
SELECT id_compra FROM compras WHERE id_usuario = 3
UNION 
SELECT r_id FROM registro WHERE r_id = 3



-- Usando LIKE com 'Wildcard'
SELECT * FROM registro WHERE nome LIKE 'Thiago Cos__'
UNION
SELECT * FROM registro WHERE nome LIKE 'Leonardo%'
UNION
SELECT * FROM registro WHERE nome LIKE 'Ma%s%'

SELECT * FROM compras WHERE nome_produto LIKE '%Computador%'

SELECT * FROM registro WHERE nome LIKE '%el%'


