/*
  Para usar o GROUP BY voc� deve usar no SELECT uma das seguintes fun��es:
       MIN()
       MAX()
       SUM()
       COUNT()
       AVG()
  /-- Fun��es de Agrupamento --/
*/
--Grouping Examples
SELECT COUNT(*), c_age
FROM c_user
GROUP BY c_age
ORDER BY COUNT(*) DESC

SELECT COUNT(*), SUM(c_salary)
FROM c_user
WHERE c_salary BETWEEN 200 AND 300
GROUP BY c_salary
ORDER BY COUNT(*) DESC
