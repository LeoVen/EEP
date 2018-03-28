                                                    DATA PUMP
1º Passo

Criar um diretorio  no banco de dados:
    - logar no SQLPLUS;
    - Execute os comandos:
        CREATE DIRECTORY dp AS '...\datapump'; (Windows)
        CREATE DIRECTORY dp AS '.../datapump'; (Linux)
        GRANT EXP_FULL_DATABASE  to system;
        GRANT READ, WRITE ON DIRECTORY dp to system;

Neste momento você acaba de criar um diretório no seu banco de dados.

2º Passo

Fazer um Export (expdp) Full de seu banco de dados:
    - Execute o comando abaixo para realizar um export full de seu banco
        expdp system/password@db10g full=Y directory=dp dumpfile=DB10G.dmp logfile=expdpDB10G.log
    
    - Execute o comando abaixo para fazer o import full para seu outro banco de dados
        impdp system/password@db10g full=Y directory=dp dumpfile=DB10G.dmp logfile=impdpDB10G.log
        
3º Passo

Fazer um export de um SCHEMA do banco de dados:
    - Para exportar apenas um SCHEMA de seu banco, execute o comando abaixo:
        expdp scott/tiger@db10g schemas=SCOTT directory=dp dumpfile=SCOTT.dmp logfile=expdpSCOTT.log

    - Para realizar o import do comando acima, execute o comando abaixo:
        impdp scott/tiger@db10g schemas=SCOTT directory=dp dumpfile=SCOTT.dmp logfile=impdpSCOTT.log
        
4º Passo

Fazer um export de um determinado SCHEMA e exportar apenas algumas tabelas:
            - Para exportar algumas tabelas do SCHEMA SCOTT, execute o comando abaixo:
                expdp scott/tiger@db10g tables=EMP,DEPT directory=dp dumpfile=EMP_DEPT.dmp logfile=expdpEMP_DEPT.log

            - Para fazer o import do comando acima, execute o comando abaixo:
                impdp scott/tiger@db10g tables=EMP,DEPT directory=dp dumpfile=EMP_DEPT.dmp logfile=impdpEMP_DEPT.log

5º Passo

Para remapear o importe de um SCHEMA para outro SCHEMA;
            - Importar tabela de um SCHEMA para dentro de outro SCHEMA, utilize o comando abaixo:
                impdp test/test@db10g tables=SCOTT.EMP network_link=REMOTE_SCOTT directory=dp logfile=impdpSCOTT.log remap_schema=SCOTT:TEST

                
6º Passo

Excluir e Incluir alguns recursos nos comandos EXPDP e IMPDP:
            - Comandos: INCLUDE e EXCLUDE
            Exemplos:
                expdp scott/tiger@db10g schemas=SCOTT include=TABLE:"IN ('EMP', 'DEPT')" directory=dp dumpfile=SCOTT.dmp logfile=expdpSCOTT.log

                expdp scott/tiger@db10g schemas=SCOTT exclude=TABLE:"= 'BONUS'" directory=dp dumpfile=SCOTT.dmp logfile=expdpSCOTT.log

            - Você também pode utilizar a opção para fazer o EXCLUDE DE SCHEMAS, utilize o recurso abaixo:
                EXCLUDE=SCHEMA:"IN ('OUTLN','SYSTEM','SYSMAN','FLOWS_FILES','APEX_030200','APEX_PUBLIC_USER','ANONYMOUS')"