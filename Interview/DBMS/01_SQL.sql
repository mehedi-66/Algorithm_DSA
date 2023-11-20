
/*



    -- single line comment

    SQL => Structured Query Language
    RDBMS => Relational Database Management Stystem
        - mysql, oracle,

        CRUD operation


            SQL------->|
                       |            |---|
                       |----------->|   |
                       |            =====
                       |             DB

                    API RDBMS

        => When sql query give to API of RDBMS it translate
            and understand send to DB and CRUD on DB then send back to user Query

*/

-- For Create Database

CREATE DATABASE shop;


-- For selecting dtatabse

USE shop


-- For creating Table

CREATE TABLE product (
    id INT PRIMARY KEY,
    name VARCHAR(255);
);


-- For inserting data into table

INSERT INTO product VALUES(1, 'Apple');   -- 1 row will added


-- For fetching data from table (ALL)

SELECT * FROM product;




/*
    **************** Data type inside the SQL ************
    Char        => string(0-255), string with size = (0, 255)
    VARCHAR     => string(0-255)

                                  ** Varchar and char only difference is  (char fix size) (varchar variable size) in memory
    TINYTEXT    => string(0-255)
    TEXT        => string(0-65535)
    BLOB        => string(0-65535)      any file => binary byte store like audio, video, image this type of
    MEDIUMTEXt  => string(0-1,67,77,215)
    MEDIUMBLOB  => string(0-16777215)
    LONGTEXT    => string(0-4,29,49,67,295)
    INT         => integer(-10^9 to 10^9)
    float
    double
    Decimal     => double stored as string
    DATE        => YYYY-MM-DD
    DATETIME    => YYYY-MM-DD HH:MM:SS
    TIMESTAMP   => YYYYMMDDHHMMSS
    TIME        => HH:MM:DD
    BOOLEAN     => 0/1
    BIT         => BIT(n) n up 64   store values in bits


    TINY < SMALL < MEDIUM < INT < BIGINT

    UNSIGNED we can use for only positive value and increase range of storing number

    Advanced DT
        1) JSON    => Javascript object notation


*/





/*
    ******************* SQL Type of Command ************

  1) DDL => Database definition Language: defining relation schema

    => CREATE         : create table, DB, view
    => ALTER TABLE    : modification in table structure e.g : change column data type or add/remove columns
    => DROP TABLE     : Delete table, DB, view
    => TRUNCATE       : remove all the tuples from the table
    => RENAME         : rename DB name, table name, column name


 2) DRL / DQL  (data retrieval language  / data query language): retrieve data from the tables

    => SELECT

 3) DML (data modification language ): use to perform modifications in the DB

    => INSERT       : insert data into a relation
    => UPDATE       : update relation data
    => DELETE       : delete row (s) from the relation

 4) DCL (Data Control language) : grant or revoke authorities from user

    => GRANT        : access privileges to the DB
    => REVOKE:      revoke user access privileges

 5) TCL (Transaction control language): to manage transactions done in the DB

    => START TRANSACTION    : begin a transaction
    => COMMIT               : apply all the changes and end transaction
    => ROLLABAC             : discard changes and end transaction
    => SAVEPOINT            : checkout within the group of transactions in which to rollback


    note: see the difference of DELETE, DROP, TRUNCATE

    note: transaction means => if you pay ... series of activities ... if fully happened or role back the money


*/





/*
    ************** MANAGING DB (DDL) *************

    1) CREATE of DB
        1)  CREATE DATABASE IF NOT EXISTS db-name
        2)  USE db-name;                        : need to execute to choose on which DB CREATE TABLE etc commands will be executed
                                                : make switching between DBs possible
        3) DROP DATABASE IF EXISTS db-name;     : dropping database
        4) SHOW DATABASES;                      : list all the DBs in the server
        5) SHOW TABLES;                         : list tables in the selected DB


*/


/*
    ************************* Example Database *********************

    1) Worker

        workerID  |   FirstName | LastName  |  Salary  |  JoinDate |   Department |



    2) Bonus

        worker, RefID | bonusAmount | BonusData |

    3) Title

        worker RefId |  workerTitle |  affectedFrom |



*/

CREATE TABLE Worker (

    WORKER_ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    FIRST_NAME VARCHER(255),
    LAST_NAME VARCHER(255),
    SALARY INT,
    JOINING_DATE DATETIME,
    DEPARTMENT VARCHER(255)
);


INSERT INTO Worker (WORKER_ID, ............. which field you need) VALUES(..... give value into selected fields  one or multipule rows we can add)


CREATE TABLE Bonus(

    WORKER_REF_ID INT,
    BONUS_AMOUNT INT,
    BONUS_DATE DATETIME,

    FOREIGN KEY(WORKER_REF_ID)
        REFERENCES Worker(WORKER_ID)
        ON DELETE CASECADE
);




-- DRL  (Data Retrieval Language)

/*
    1) SELECT <set of column name> FROM <table_name>

    2) Order of execution from Right to Left

*/

SELECT * FROM Worker;

SELECT FirstName, Salary FROM Worker;





-- Q => Can we use SELECT keyword without using FROM clause?
    /*
        1) YES, using DUAL Tables
        2) Dual tables are dummy tables create by MySQL, help users to do certain obvious actions without referring to user defined tables
        3) e.g  SELECT SS + 11;
            SELECT now();
            SELECT ucase(); etc

    */

SELECT 44 + 11;

-- ans 55   inside dummy table  give this ans

SELECT now();   -- it gives server time

SELECT  lcase('MEHEDi');   -- it give lower case ans







-- 4 WHERE Clause
    /*
        1) Reduce rows based on given conditions
        2) Eg SELECT * FROM customer WHERE age > 18
    */

SELECT * FROM Worker;

SELECT * FROM Worker WHERE Salary > 800000;

SELECT * FROM Worker WHERE Department = 'HR';






-- 5  BETWEEN Clause
    /*
        1) SELECT * FROM customer WHERE age between  0 AND 100;
        2) In the above e.g  0 and 100 are inclusive

        [0, 100]

    */
SELECT * FROM Worker WHERE Salary BETWEEN 80000 AND 3000000;





-- 6 IN Clause
    /*
        1) Reduce OR condition
        2) e.g SELECT * FROM officers WHERE Officer_name IN ('mehedi', 'suchana', 'Hasan');
    */

SELECT * FROM Worker WHERE  Department = 'HR' OR Department = 'ADMIN';

SELECT * FROM Worker WHERE Department IN ('HR', 'ADMIN');







-- 7 AND / OR / NOT
    /*
        1) AND => WHERE cond1 AND cond2
        2) OR => WHERE cond1 OR cond2
        3) NOT => WHERE col_name NOT IN (1, 2, 3);
    */
-- which employee not working in the HR and ADMIN only show them

SELECT * FROM Worker WHERE Department NOT IN ('HR', 'ADMIN');







-- 8 IS NULL
    /*
        e.g  SELECT * FROM customer WHERE prime_status is NULL

        sometimes some value in the database is null we have to identifying them ... that time it use
    */

SELECT * FROM Worker pincode is NULL;    -- show that worker who not given there pincode
