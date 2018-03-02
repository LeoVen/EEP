declare
  i number;
create or replace function math(choice in number) return float is
  const float;
begin
  const := 0;

  if ( choice = 1 ) then
    --Here goes pi
    for i in 0 .. 10000000 loop
      const := const + ( power(-1, i) * 4 ) / ( 2 * i + 1 );
    end loop;
    
  elsif ( choice = 2 ) then
    --Here goes e
    for i in 0 .. 70 loop
      const := const + 1 / fatorial(i);
    end loop;
    
  elsif ( choice = 3 ) then
    --Here goes phi
    const := ( 1 + power(5, 1/2) ) / 2;
    
  else
    dbms_output.put_line('Error, something went wrong');
    const := 1;
  end if;

  return(const);
end math;
/
