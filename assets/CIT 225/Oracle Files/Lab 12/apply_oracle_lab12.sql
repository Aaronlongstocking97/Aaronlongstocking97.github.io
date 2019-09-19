-- ------------------------------------------------------------------
--  Program Name:   apply_oracle_lab12.sql
--  Lab Assignment: Lab #12
--  Program Author: Aaron Jones
--  Creation Date:  05-Dec-2018
-- ------------------------------------------------------------------
-- Instructions:
-- ------------------------------------------------------------------
-- The two scripts contain spooling commands, which is why there
-- isn't a spooling command in this script. When you run this file
-- you first connect to the Oracle database with this syntax:
--
--   sqlplus student/student@xe
--
-- Then, you call this script with the following syntax:
--
--   sql> @apply_oracle_lab12.sql
--
-- ------------------------------------------------------------------
-- Call the prior lab.
-- ------------------------------------------------------------------

@@
/home/student/Data/cit225/oracle/lab11/apply_oracle_lab11.sql

-- Open log file.
SPOOL apply_oracle_lab12.txt
--SET PAGESIZE 9999
--SET LINESIZE 80
-- --------------------------------------------------------
--  Step #1
--  -------
--  Create the CALENDAR table as per the specifications.
-- --------------------------------------------------------

-- Insert step #1 statements here.


-- ------------------------------------------------------------------
--  Conditionally drop table.
-- ------------------------------------------------------------------
DECLARE
  /* Dynamic cursor. */
  CURSOR c
(cv_object_name VARCHAR2) IS
SELECT o.object_type
    , o.object_name
FROM user_objects o
WHERE  o.object_name LIKE UPPER(cv_object_name||'%');
BEGIN
  FOR i IN c
  ('CALENDAR') LOOP
  IF i.object_type = 'SEQUENCE' THEN
  EXECUTE IMMEDIATE 'DROP '
  ||i.object_type||' '||i.object_name;
ELSIF i.object_type = 'TABLE' THEN
EXECUTE IMMEDIATE 'DROP '
||i.object_type||' '||i.object_name||' CASCADE CONSTRAINTS';
END
IF;
  END LOOP;
END;
/

-- Create CALENDAR table.
CREATE TABLE calendar
(
  calendar_id NUMBER
,
  calendar_name VARCHAR2(10) CONSTRAINT nn_calendar_1 NOT NULL
,
  calendar_short_name VARCHAR2(3) CONSTRAINT nn_calendar_2 NOT NULL
,
  start_date DATE CONSTRAINT nn_calendar_3 NOT NULL
,
  end_date DATE CONSTRAINT nn_calendar_4 NOT NULL
,
  created_by NUMBER CONSTRAINT nn_calendar_5 NOT NULL
,
  creation_date DATE CONSTRAINT nn_calendar_6 NOT NULL
,
  last_updated_by NUMBER CONSTRAINT nn_calendar_7 NOT NULL
,
  last_update_date DATE CONSTRAINT nn_calendar_8 NOT NULL
,
  CONSTRAINT pk_calendar_1   PRIMARY KEY(calendar_id)
,
  CONSTRAINT fk_calendar_1   FOREIGN KEY(created_by) REFERENCES system_user(system_user_id)
,
  CONSTRAINT fk_calendar_2   FOREIGN KEY(last_updated_by) REFERENCES system_user(system_user_id)
);


-- Create a sequence.
CREATE SEQUENCE calendar_s1 START WITH 1001;


-- Step 1 Verification
SET NULL
''
COLUMN table_name   FORMAT A16
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22
COLUMN data_type    FORMAT A12
SELECT table_name
, column_id
, column_name
, CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
, CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM user_tab_columns
WHERE    table_name = 'CALENDAR'
ORDER BY 2;


-- Step 1 Verification
COLUMN constraint_name   FORMAT A22  HEADING "Constraint Name"
COLUMN search_condition  FORMAT A36  HEADING "Search Condition"
COLUMN constraint_type   FORMAT A1   HEADING "C|T"
SELECT uc.constraint_name
, uc.search_condition
, uc.constraint_type
FROM user_constraints uc INNER JOIN user_cons_columns ucc
  ON       uc.table_name = ucc.table_name
    AND uc.constraint_name = ucc.constraint_name
WHERE    uc.table_name = UPPER('calendar')
  AND uc.constraint_type IN (UPPER('c'),UPPER('p'))
ORDER BY uc.constraint_type DESC
,        uc.constraint_name;


-- Step 1 Verification
COL constraint_source FORMAT A38 HEADING "Constraint Name:| Table.Column"
COL references_column FORMAT A40 HEADING "References:| Table.Column"
SELECT uc.constraint_name||CHR(10)
||      '('||ucc1.table_name||'.'||ucc1.column_name||')' constraint_source
, 'REFERENCES'||CHR(10)
||      '('||ucc2.table_name||'.'||ucc2.column_name||')' references_column
FROM user_constraints uc
, user_cons_columns ucc1
, user_cons_columns ucc2
WHERE    uc.constraint_name = ucc1.constraint_name
  AND uc.r_constraint_name = ucc2.constraint_name
  AND ucc1.position = ucc2.position -- Correction for multiple column primary keys.
  AND uc.constraint_type = 'R'
  AND ucc1.table_name = 'CALENDAR'
ORDER BY ucc1.table_name
,        uc.constraint_name;


-- --------------------------------------------------------
--  Step #2
--  -------
--  Seed the CALENDAR table.
-- --------------------------------------------------------

-- Insert step #2 statements here.

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'January'
, 'JAN'
, TO_DATE('01-JAN-2009', 'DD/MM/YYYY')
, TO_DATE('31-JAN-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'February'
, 'FEB'
, TO_DATE('01-FEB-2009', 'DD/MM/YYYY')
, TO_DATE('28-FEB-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'March'
, 'MAR'
, TO_DATE('01-MAR-2009', 'DD/MM/YYYY')
, TO_DATE('31-MAR-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'April'
, 'APR'
, TO_DATE('01-APR-2009', 'DD/MM/YYYY')
, TO_DATE('30-APR-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'May'
, 'MAY'
, TO_DATE('01-MAY-2009', 'DD/MM/YYYY')
, TO_DATE('31-MAY-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'June'
, 'JUN'
, TO_DATE('01-JUN-2009', 'DD/MM/YYYY')
, TO_DATE('30-JUN-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'July'
, 'JUL'
, TO_DATE('01-JUL-2009', 'DD/MM/YYYY')
, TO_DATE('31-JUL-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'August'
, 'AUG'
, TO_DATE('01-AUG-2009', 'DD/MM/YYYY')
, TO_DATE('31-AUG-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'September'
, 'SEP'
, TO_DATE('01-SEP-2009', 'DD/MM/YYYY')
, TO_DATE('30-SEP-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'October'
, 'OCT'
, TO_DATE('01-OCT-2009', 'DD/MM/YYYY')
, TO_DATE('31-OCT-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'November'
, 'NOV'
, TO_DATE('01-NOV-2009', 'DD/MM/YYYY')
, TO_DATE('30-NOV-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);

-- Add new rows to the CALENDAR table
INSERT INTO calendar
  ( calendar_id
  , calendar_name
  , calendar_short_name
  , start_date
  , end_date
  , created_by
  , creation_date
  , last_updated_by
  , last_update_date )
VALUES
  ( calendar_s1.nextval
, 'December'
, 'DEC'
, TO_DATE('01-DEC-2009', 'DD/MM/YYYY')
, TO_DATE('31-DEC-2009', 'DD/MM/YYYY')
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Query the data insert.
COL calendar_name        FORMAT A10  HEADING "Calendar|Name"
COL calendar_short_name  FORMAT A8  HEADING "Calendar|Short|Name"
COL start_date           FORMAT A9   HEADING "Start|Date"
COL end_date             FORMAT A9   HEADING "End|Date"
SELECT calendar_name
, calendar_short_name
, start_date
, end_date
FROM calendar;


-- --------------------------------------------------------
--  Step #3
--  -------
--  Import the data from the transaction_reversal.csv
--  file into the TRANSACTION_REVERSAL table.
-- --------------------------------------------------------

-- Insert step #3 statements here.

-- ------------------------------------------------------------------
--  Conditionally drop table.
-- ------------------------------------------------------------------
DECLARE
  /* Dynamic cursor. */
  CURSOR c
(cv_object_name VARCHAR2) IS
SELECT o.object_type
    , o.object_name
FROM user_objects o
WHERE  o.object_name LIKE UPPER(cv_object_name||'%');
BEGIN
  FOR i IN c
  ('TRANSACTION_REVERSAL') LOOP
  IF i.object_type = 'SEQUENCE' THEN
  EXECUTE IMMEDIATE 'DROP '
  ||i.object_type||' '||i.object_name;
ELSIF i.object_type = 'TABLE' THEN
EXECUTE IMMEDIATE 'DROP '
||i.object_type||' '||i.object_name||' CASCADE CONSTRAINTS';
END
IF;
  END LOOP;
END;
/

-- Create TRANSACTION_REVERSAL table.
CREATE TABLE transaction_reversal
(
  transaction_id NUMBER
,
  transaction_account VARCHAR2(15)
,
  transaction_type NUMBER
,
  transaction_date DATE
,
  transaction_amount NUMBER
,
  rental_id NUMBER
,
  payment_method_type NUMBER
,
  payment_account_number VARCHAR2(19)
,
  created_by NUMBER
,
  creation_date DATE
,
  last_updated_by NUMBER
,
  last_update_date DATE
)
ORGANIZATION EXTERNAL
( TYPE ORACLE_LOADER
    DEFAULT DIRECTORY "UPLOAD"
    ACCESS PARAMETERS
( RECORDS DELIMITED BY NEWLINE CHARACTERSET US7ASCII
    BADFILE     'UPLOAD':'transaction_upload.bad'
    DISCARDFILE 'UPLOAD':'transaction_upload.dis'
    LOGFILE     'UPLOAD':'transaction_upload.log'
    FIELDS TERMINATED BY ','
    OPTIONALLY ENCLOSED BY "'"
    MISSING FIELD VALUES ARE NULL     )
    LOCATION
( 'transaction_upload2.csv'))
REJECT LIMIT UNLIMITED;

-- Create a sequence.
CREATE SEQUENCE transaction_reversal_s1 START WITH 1001;


-- Set environment variables.
--SET LONG 100000
--SET PAGESIZE 0

-- Set a local variable of a character large object (CLOB).
VARIABLE ddl_text CLOB

-- Get the internal DDL command for the TRANSACTION table from the data dictionary.
SELECT dbms_metadata.get_ddl('TABLE','TRANSACTION')
FROM dual;

-- Get the internal DDL command for the external TRANSACTION_UPLOAD table from the data dictionary.
SELECT dbms_metadata.get_ddl('TABLE','TRANSACTION_UPLOAD')
FROM dual;


-- Move the data from TRANSACTION_REVERSAL to TRANSACTION.
INSERT INTO transaction
(
SELECT transaction_s1.NEXTVAL
, transaction_account
, transaction_type
, transaction_date
, transaction_amount
, rental_id
, payment_method_type
, payment_account_number
, created_by
, creation_date
, last_updated_by
, last_update_date
FROM transaction_reversal
);

-- Step 3 Verification
COLUMN "Debit Transactions"  FORMAT A20 HEADING "Debit Transactions"
COLUMN "Credit Transactions" FORMAT A20 HEADING "Credit Transactions"
COLUMN "All Transactions"    FORMAT A20 HEADING "All Transactions"

-- Check current contents of the model.
SELECT 'SELECT record counts' AS "Statement"
FROM dual;
SELECT LPAD(TO_CHAR(c1.transaction_count,'99,999'),19,' ') AS "Debit Transactions"
, LPAD(TO_CHAR(c2.transaction_count,'99,999'),19,' ') AS "Credit Transactions"
, LPAD(TO_CHAR(c3.transaction_count,'99,999'),19,' ') AS "All Transactions"
FROM (SELECT COUNT(*) AS transaction_count
  FROM transaction
  WHERE transaction_account = '111-111-111-111') c1 CROSS JOIN
        (SELECT COUNT(*) AS transaction_count
  FROM transaction
  WHERE transaction_account = '222-222-222-222') c2 CROSS JOIN
        (SELECT COUNT(*) AS transaction_count
  FROM transaction) c3;


-- --------------------------------------------------------
--  Step #4
--  -------
--  Create a annual financial report using selective
--  aggregation.
-- --------------------------------------------------------

-- Insert step #4 statements here.

--
SET LINESIZE 350;

COL TRANSACTION_ACCOUNT FORMAT A10 HEADING "transaction"
COL JANUARY             FORMAT A10 HEADING "JAN"
COL FEBRUARY            FORMAT A10 HEADING "FEB"
COL MARCH               FORMAT A10 HEADING "MAR"
COL FQ1                 FORMAT A10 HEADING "FQ1
COL APRIL               FORMAT A10 HEADING "APR"
COL MAY                 FORMAT A10 HEADING "MAY"
COL JUNE                FORMAT A10 HEADING "JUN"
COL FQ1                 FORMAT A10 HEADING "FQ2"
COL JULY                FORMAT A10 HEADING "JUL"
COL AUGUST              FORMAT A10 HEADING "AUG"
COL SEPTEMBER           FORMAT A10 HEADING "SEP"
COL FQ1                 FORMAT A10 HEADING "FQ3"
COL OCTOBER             FORMAT A10 HEADING "OCT"
COL NOVEMBER            FORMAT A10 HEADING "NOV"
COL DECEMBER            FORMAT A10 HEADING "DEC"
COL FQ1                 FORMAT A10 HEADING "FQ4"


       SELECT   CASE
           WHEN t.transaction_account = '111-111-111-111' THEN 'Debit'
           WHEN t.transaction_account = '222-222-222-222' THEN 'Credit'
         END AS "TRANSACTION_ACCOUNT"
,        CASE
           WHEN t.transaction_account = '111-111-111-111' THEN 1
           WHEN t.transaction_account = '222-222-222-222' THEN 2
         END AS "SORTKEY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 1 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JANUARY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 2 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FEBRUARY"
,       LPAD(TO_CHAR
       (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 3 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "MARCH"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (1, 2, 3)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ1"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 4 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "APRIL"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 5 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "MAY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 6 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JUNE"
,      LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (4, 5, 6)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ2"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 7 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JULY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 8 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "AUGUST"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 9 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "SEPTEMBER"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (7, 8, 9)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ3"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 10 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "OCTOBER"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 11 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "NOVEMBER"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 12 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "DECEMBER"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (10, 11, 12)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ4"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(YEAR FROM transaction_date) IN (2009)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "YTD"
FROM     transaction t INNER JOIN common_lookup cl
ON       t.transaction_type = cl.common_lookup_id
WHERE    cl.common_lookup_table = 'TRANSACTION'
AND      cl.common_lookup_column = 'TRANSACTION_TYPE'
GROUP BY CASE
           WHEN t.transaction_account = '111-111-111-111' THEN 'Debit'
           WHEN t.transaction_account = '222-222-222-222' THEN 'Credit'
         END
,        CASE
           WHEN t.transaction_account = '111-111-111-111' THEN 1
           WHEN t.transaction_account = '222-222-222-222' THEN 2
         END
         UNION ALL
          SELECT  'TOTAL' AS "TRANSACTION_ACCOUNT"
,          3 AS "SORTKEY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 1 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JANUARY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 2 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FEBRUARY"
,       LPAD(TO_CHAR
       (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 3 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "MARCH"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (1, 2, 3)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ1"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 4 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "APRIL"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 5 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "MAY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 6 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JUNE"
,      LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (4, 5, 6)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ2"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 7 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "JULY"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 8 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "AUGUST"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 9 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "SEPTEMBER"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (7, 8, 9)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ3"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 10 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "OCTOBER"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 11 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "NOVEMBER"
,        LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) = 12 AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "DECEMBER"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(MONTH FROM transaction_date) IN (10, 11, 12)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "FQ4"
,       LPAD(TO_CHAR
        (SUM(CASE
               WHEN EXTRACT(YEAR FROM transaction_date) IN (2009)AND
                    EXTRACT(YEAR FROM transaction_date) = 2009 THEN
                 CASE
                   WHEN cl.common_lookup_type = 'DEBIT'
                   THEN t.transaction_amount
                   ELSE t.transaction_amount * -1
                 END
             END),'99,999.00'),10,' ') AS "YTD"
FROM     transaction t INNER JOIN common_lookup cl
ON       t.transaction_type = cl.common_lookup_id
WHERE    cl.common_lookup_table = 'TRANSACTION'
AND      cl.common_lookup_column = 'TRANSACTION_TYPE';


-- Close log file.
SPOOL OFF

-- Make all changes permanent.
COMMIT;
