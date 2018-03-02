DECLARE
  planeta varchar2(20):= 'mundo';
  SUBTYPE name IS varchar2(20);
  SUBTYPE message IS varchar2(100);
  salutation name;
  greetings message;
  -- Definindo uma constante
  pi CONSTANT double precision := 3.14159265359;
  -- Usando casas decimais
  -- 10: casas decimais antes; 2: casas decimais depois
  sales number(10, 2);
BEGIN
  salutation := 'Arnaldo ';
  -- comentário de uma linha
  greetings := 'Olá bem vindo ao ';
  sales := 255.555; -- Inline coment
  /*
  Comentário de
  várias linhas
  */
  dbms_output.put_line(salutation || greetings || planeta);
  dbms_output.put_line('Sales ' || sales);
  -- || é um operador de concatenção
END;
