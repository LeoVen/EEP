create or replace function fatorial(numero in number) return number is
  resultado number;
begin

  if numero = 0 then
    resultado := 1;
  else
    resultado := numero * fatorial( numero - 1 );
  end if;

  return(resultado);
end fatorial;
/
