begin
  --dbms_output.put_line(fatorial(10));
  dbms_output.put_line(math(1));
  dbms_output.put_line(math(2));
  dbms_output.put_line(math(3));
end;



--To import a dump copy and paste this on the cmd :
IMP LEO/darklight@orcl GRANTS=N IGNORE=Y FROMUSER=PI_ITV TOUSER=LEO FILE=C:\Users\leona\Downloads\Base_Corporativa\PIASA_CORP.dmp



CREATE USER LEO IDENTIFIED BY password;

GRANT CONNECT TO LEO;
ALTER USER LEO DEFAULT TABLESPACE PIMS_DATA;
ALTER USER LEO TEMPORARY TABLESPACE TEMP;
ALTER USER LEO QUOTA UNLIMITED ON PIMS_DATA;
GRANT IMP_FULL_DATABASE TO LEO;

begin
  dbms_output.put_line(user_register_seq);
end;
