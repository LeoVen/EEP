DECLARE

  i INT;
  chance FLOAT;
  minimum_chance FLOAT := 0.05; --Modifique para ter nomes maiores ou menores
  spacing INT;
  it INT;
  letter INT;
  word VARCHAR2 (30);
  
BEGIN
  it := 0;
  spacing := 0;
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
    
  END LOOP;
  dbms_output.put_line (word);
END;
