-- ------------------------------------------------------------------
--  Program Name:   apply_oracle_lab1.sql
--  Lab Assignment: lab 1
--  Program Author: Aaron Jones
--  Creation Date:  21-Sep-2018
-- ------------------------------------------------------------------
-- Instructions:
-- ------------------------------------------------------------------
-- When you run this file you first connect to the Oracle database
-- with this syntax:
--
--   sqlplus student/student@xe
--
-- Then, you call this script with the following syntax:
--
--   sql> @apply_oracle_lab4.sql
--
-- ------------------------------------------------------------------
-- Run instructor provided setup scripts.
@@
/home/student/Data/cit225/oracle/lib1/utility/cleanup_oracle.sql
@@/home/student/Data/cit225/oracle/lib1/
create/create_oracle_store2.sql
--
-- Open log file.
SPOOL apply_oracle_lab1.log
--
-- Run file to display step 4
-- @@/home/student/Data/cit225/oracle/lib1/seed/seeding.sql
--
--
-- Create TABLE_NAME data to display step 5
-- SELECT   table_name
-- FROM     user_tables
-- WHERE    table_name NOT IN ('EMP','DEPT')
-- AND NOT  table_name LIKE 'DEMO%'
-- AND NOT  table_name LIKE 'APEX%'
-- ORDER BY table_name;
--
-- Close log file.
SPOOL OFF
