-- Random Words Function

DECLARE
  --Variáveis externas
  word VARCHAR(100);
  -- Variáveis da função
  i INT;
  vowel NUMBER := 0;     -- Check vowel count
  consonant NUMBER := 0; -- Check consonant count
  space NUMBER;
  letra VARCHAR2(20);
  chance FLOAT;
  v NUMBER := 4;
  c NUMBER := 21;
  -- Vetores contendo ASCII
  TYPE vetor_vow IS VARRAY(5) OF NUMBER;
  TYPE vetor_con IS VARRAY(21) OF NUMBER;
  vogais vetor_vow := vetor_vow(65, 69, 73, 79, 85);
  consoantes vetor_con := vetor_con(66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90);
  -- Variáveis controladoras
  max_vow NUMBER := 1;
  max_con NUMBER := 1;
  min_space NUMBER := 4; -- Tamanho mínimo da palavra
  max_space NUMBER := 10;
  max_palavras NUMBER;
  max_word_size NUMBER := 18;
  palavra VARCHAR(20); --não é controladora porém depende de max_word_size
  vowel_activate NUMBER := 0.4;
  
  FUNCTION random_word
    RETURN VARCHAR2 IS
      palavras VARCHAR(100);
  BEGIN
    max_palavras := 1 + ABS(MOD(dbms_random.random, 3));
    FOR i IN 1 .. max_palavras LOOP
      space := 0;
      FOR j IN 1 .. max_word_size LOOP
        IF space >= min_space THEN
          space := 0;
        END IF;
        -- Começa a forma letras e jogá-las em 'palavra'
        chance := dbms_random.value(0, 1);
        IF (chance < 0.1 AND space >= min_space) OR (space >= max_space) THEN
          letra := CHR(32);
          space := 0;
        END IF;
        IF space = 0 THEN
          -- Generates uppercase letter
          IF (chance > vowel_activate) AND (vowel <= max_vow) THEN
            -- Gets a vowel
            letra := CHR(vogais(1 + ABS(MOD(dbms_random.random, v))));
            space := space + 1;
            vowel := vowel + 1;
            consonant := 0;
          ELSIF (chance <= vowel_activate) THEN
            -- Gets a consonant
            letra := CHR(consoantes(1 + ABS(MOD(dbms_random.random, c))));
            space := space + 1;
            consonant := consonant + 1;
            vowel := 0;
          END IF;
        ELSIF space != 0 THEN
          -- No upper case letters
          IF (chance > vowel_activate) AND (vowel <= max_vow) THEN
            -- Gets a vowel
            letra := CHR(32 + vogais(1 + ABS(MOD(dbms_random.random, v))));
            space := space + 1;
            vowel := vowel + 1;
            consonant := 0;
          ELSIF (chance <= vowel_activate) AND (consonant <= max_con) THEN
            -- Gets a consonant
            letra := CHR(32 + consoantes(1 + ABS(MOD(dbms_random.random, c))));
            space := space + 1;
            consonant := consonant + 1;
            vowel := 0;
          END IF;
        END IF;
        palavra := CONCAT(palavra, letra);
      END LOOP;
      palavras := CONCAT(palavras, CONCAT(palavra, ' '));
      -- Resetando 'palavra'
      palavra := '';
    END LOOP;
    RETURN palavras;
  END random_word;
  -- End Declare
BEGIN
  word := random_word();
  dbms_output.put_line(word);
END;
