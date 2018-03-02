create or replace procedure factorial(numero in number, resultado out number) is
begin
  
       if numero = 0 then
          resultado := 1;
       else
          resultado := numero * factorial( numero - 1);
       end if;
       
       dbms_output.put_line(resultado);

end factorial;
/
