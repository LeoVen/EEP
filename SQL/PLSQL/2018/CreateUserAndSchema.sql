-- https://www.techonthenet.com/oracle/users/create_user.php
-- Create User

CREATE USER user_name 
  IDENTIFIED { BY password
             | EXTERNALLY [ AS 'certificate_DN' ]
             | GLOBALLY [ AS '[ directory_DN ]' ]
             }
  [ DEFAULT TABLESPACE tablespace
  | TEMPORARY TABLESPACE
       { tablespace | tablespace_group }
  | QUOTA integer [ K | M | G | T | P | E ]
        | UNLIMITED }
        ON tablespace
    [ QUOTA integer [ K | M | G | T | P | E ]
        | UNLIMITED }
            ON tablespace
    ]
  | PROFILE profile_name
  | PASSWORD EXPIRE
  | ACCOUNT { LOCK | UNLOCK }
     [ DEFAULT TABLESPACE tablespace
     | TEMPORARY TABLESPACE
         { tablespace | tablespace_group }
     | QUOTA integer [ K | M | G | T | P | E ]
           | UNLIMITED }
           ON tablespace
       [ QUOTA integer [ K | M | G | T | P | E ]
           | UNLIMITED }
           ON tablespace
        ]
     | PROFILE profile
     | PASSWORD EXPIRE
     | ACCOUNT { LOCK | UNLOCK } ]
     ] ;

-- Parameters:
/*

	-- user_name
The name of the database account that you wish to create.

	-- PROFILE profile_name
Optional. It is the name of the profile that you wish to assign to the user account to limit the amount of database resources assigned to the user account. If you omit this option, the DEFAULT profile is assigned to the user.

	-- PASSWORD EXPIRE
Optional. If this option is set, then the password must be reset before the user can log into the Oracle database.

	-- ACCOUNT LOCK
Optional. It disables access to the user account.

	-  ACCOUNT UNLOCK
Optional. It enables access to the user account.

*/

-- https://www.techonthenet.com/oracle/schemas/create_schema.php
-- Create Schema
/*

In essence, a schema is created in Oracle when a user is created.

*/

--  Assign SYSTEM privileges
GRANT create session TO User_Name;
GRANT create table TO User_Name;
GRANT create view TO User_Name;
GRANT create any trigger TO User_Name;
GRANT create any procedure TO User_Name;
GRANT create sequence TO User_Name;
GRANT create synonym TO User_Name;

-- https://www.techonthenet.com/oracle/grant_revoke.php
-- Grant / Revoke
/*

+------------------------------------------------------------------------------------------------+
|  Privilege   |   Description                                                                   |
+--------------+---------------------------------------------------------------------------------+
|  SELECT      |   Ability to perform SELECT statements on the table.                            |
|  INSERT      |   Ability to perform INSERT statements on the table.                            |
|  UPDATE      |   Ability to perform UPDATE statements on the table.                            |
|  DELETE      |   Ability to perform DELETE statements on the table.                            |
|  REFERENCES  |   Ability to create a constraint that refers to the table.                      |
|  ALTER       |   Ability to perform ALTER TABLE statements to change the table definition.     |
|  INDEX       |   Ability to create an index on the table with the create index statement.      |
|  ALL         |   All privileges on table.                                                      |
+------------------------------------------------------------------------------------------------+

*/

-- Grant
GRANT [Privilege(s)] ON [Object_Name] TO [User_Name];

-- Grant to all users (using the keyword public)
GRANT [Privilege(s)] ON [Object_Name] TO public;

-- Revoke
REVOKE [Privilege(s)] ON [Object_Name] TO [User_Name];

-- Grant/Revoke on Functions/Procedures

[GRANT | REVOKE] EXECUTE ON [Object_Name] TO [User_name]