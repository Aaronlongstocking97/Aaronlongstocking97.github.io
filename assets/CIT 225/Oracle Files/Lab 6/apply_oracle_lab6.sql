-- ------------------------------------------------------------------
--  Program Name:   apply_oracle_lab5.sql
--  Lab Assignment: lab 6
--  Program Author: Aaron Jones
--  Creation Date:  20-Oct-2018
-- ------------------------------------------------------------------
-- Call library files.
-- ------------------------------------------------------------------

@/home/student/Data/cit225/oracle/lab5/apply_oracle_lab5.sql
SET PAGESIZE 100
SET LINESIZE 100

-- ------------------------------------------------------------------
-- Open log file.
-- ------------------------------------------------------------------

SPOOL apply_oracle_lab6.txt

-- ------------------------------------------------------------------
--
-- ----------------------------------------------------------
--  Step #1
--  -------
--  Add the rental_item_price and rental_item_type to the
--  rental_item table. both columns will use the NUMBER 
--  data type.
-- ----------------------------------------------------------

--Add table data to the rental_item table.
ALTER TABLE rental_item
  ADD  (rental_item_type    NUMBER   
,       rental_item_price   NUMBER);   

  
-- Step 1 Verification for the insertion of the new data type
SET NULL ''
COLUMN table_name   FORMAT A14    HEADING "TABLE_NAME"
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22    HEADING "COLUMN_NAME"
COLUMN data_type    FORMAT A12
SELECT   table_name
,        column_id
,        column_name
,        CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
,        CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM     user_tab_columns
WHERE    table_name = 'RENTAL_ITEM'
ORDER BY 2;


-- ----------------------------------------------------------
--  Step #2
--  -------
--  Create the PRICE table while adding a check constrain
--  to the ACTIVE_FLAG column.
-- ----------------------------------------------------------

-- Conditionally drop the table.
DECLARE
  /* Dynamic cursor. */
  CURSOR c (cv_object_name VARCHAR2) IS
    SELECT o.object_type
    ,      o.object_name
    FROM   user_objects o
    WHERE  o.object_name LIKE UPPER(cv_object_name||'%');
BEGIN
  FOR i IN c('PRICE') LOOP
    IF i.object_type = 'SEQUENCE' THEN
      EXECUTE IMMEDIATE 'DROP '||i.object_type||' '||i.object_name;
    ELSIF i.object_type = 'TABLE' THEN
      EXECUTE IMMEDIATE 'DROP '||i.object_type||' '||i.object_name||' CASCADE CONSTRAINTS';
    END IF;
  END LOOP;
END;
/
 
 
-- Create the PRICE table.
CREATE TABLE price
( price_id                    NUMBER
, item_id                     NUMBER       CONSTRAINT nn_price_1 NOT NULL
, price_type                  NUMBER       
, active_flag                 VARCHAR2(1)  CONSTRAINT nn_price_3 NOT NULL
, start_date                  DATE         CONSTRAINT nn_price_4 NOT NULL
, end_date                    DATE         
, amount                      NUMBER       CONSTRAINT nn_price_6 NOT NULL
, created_by                  NUMBER       CONSTRAINT nn_price_7 NOT NULL
, creation_date               DATE         CONSTRAINT nn_price_8 NOT NULL
, last_updated_by             NUMBER       CONSTRAINT nn_price_9 NOT NULL
, last_update_date            DATE         CONSTRAINT nn_price_10 NOT NULL
, CONSTRAINT pk_price_1       PRIMARY KEY(price_id)
, CONSTRAINT fk_price_1       FOREIGN KEY(item_id) REFERENCES item(item_id)
, CONSTRAINT fk_price_2       FOREIGN KEY(price_type) REFERENCES common_lookup(common_lookup_id)
, CONSTRAINT fk_price_3       FOREIGN KEY(created_by) REFERENCES system_user(system_user_id)
, CONSTRAINT fk_price_4       FOREIGN KEY(last_updated_by) REFERENCES system_user(system_user_id)
, CONSTRAINT yn_price         CHECK(active_flag IN ('Y','N')));


-- Step 2 Verification for the PRICE table.
SET NULL ''
COLUMN table_name   FORMAT A14    HEADING "TABLE_NAME"
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22    HEADING "COLUMN_NAME"
COLUMN data_type    FORMAT A12
SELECT   table_name
,        column_id
,        column_name
,        CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
,        CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM     user_tab_columns
WHERE    table_name = 'PRICE'
ORDER BY 2;


-- Step 2 Verification for the constraint check.
COLUMN constraint_name      FORMAT A16 HEADING "CONSTRAINT_NAME"
COLUMN search_condition     FORMAT A30 HEADING "SEARCH_CONDITION_VC"
SELECT   uc.constraint_name
,        uc.search_condition
FROM     user_constraints uc INNER JOIN user_cons_columns ucc
ON       uc.table_name = ucc.table_name
AND      uc.constraint_name = ucc.constraint_name
WHERE    uc.table_name = UPPER('price')
AND      ucc.column_name = UPPER('active_flag')
AND      uc.constraint_name = UPPER('yn_price')
AND      uc.constraint_type = 'C';


-- ----------------------------------------------------------
--  Step #3
--  -------
--  Renaming and inserting new data into the ITEM table and 
--  the RENTAL table.
-- ----------------------------------------------------------

-- Part A Change the column name to RELEASE_DATE
ALTER TABLE item 
    RENAME COLUMN item_release_date TO release_date;

    
-- Step 3 Verification for column rename 
SET NULL ''
COLUMN table_name   FORMAT A14
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22
COLUMN data_type    FORMAT A12
SELECT   table_name
,        column_id
,        column_name
,        CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
,        CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM     user_tab_columns
WHERE    table_name = 'ITEM'
ORDER BY 2;


-- Part B Inserting new DVD releases
INSERT INTO item
( item_id
, item_barcode
, item_type
, item_title
, item_subtitle
, item_rating
, release_date
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( item_s1.nextval
,'43396-70603'
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'ITEM'
  AND      common_lookup_type = 'BLU-RAY')
,'Tron'
,''
,'PG'
,(TRUNC(SYSDATE) - 1)
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO item
( item_id
, item_barcode
, item_type
, item_title
, item_subtitle
, item_rating
, release_date
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( item_s1.nextval
,'85391-13213'
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'ITEM'
  AND      common_lookup_type = 'BLU-RAY')
,'Ender''s Game'
,''
,'G'
,(TRUNC(SYSDATE) - 1)
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO item
( item_id
, item_barcode
, item_type
, item_title
, item_subtitle
, item_rating
, release_date
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( item_s1.nextval
,'85391-10843'
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'ITEM'
  AND      common_lookup_type = 'BLU-RAY')
,'Elysium'
,''
,'G'
,(TRUNC(SYSDATE) - 1)
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Step 3 Verification for three compliant rentals and rental items.
SELECT   i.item_title
,        SYSDATE AS today
,        i.release_date
FROM     item i
WHERE   (SYSDATE - i.release_date) < 31;


-- Part C Insert a new member account with three contacts 
INSERT INTO member
( member_id
, member_type
, account_number
, credit_card_number
, credit_card_type
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( member_s1.nextval                               -- member_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_type = 'GROUP')                                  
,'US00011'                                        -- account_number
,'6011 0000 0000 0078'                            -- credit_card_number
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'MEMBER'
  AND      common_lookup_type = 'DISCOVER_CARD')  -- credit_card_type
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert the first contact into the CONTACT table.
INSERT INTO contact
( contact_id
, member_id
, contact_type
, first_name
, last_name
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( contact_s1.nextval                              -- contact_id
, member_s1.currval                               -- member_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'CONTACT'
  AND      common_lookup_type = 'CUSTOMER')       -- contact_type
,'Harry'                                          -- first_name
,'Potter'                                         -- last_name
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert an address into the ADDRESS table.
INSERT INTO address
( address_id
, contact_id
, address_type
, city
, state_province
, postal_code
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( address_s1.nextval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_type = 'HOME')           -- address_type
,'Provo'                                          -- city
,'Utah'                                           -- state_province
,'84604'                                          -- postal_code
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a street address into the STREET_ADDRESS table.
INSERT INTO street_address
( street_address_id
, address_id
, street_address
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( street_address_s1.nextval                       -- street_address_id
, address_s1.currval                              -- address_id
,'900 E, 300 N'                                    -- street_address
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a # into the TELEPHONE table.
INSERT INTO telephone
( telephone_id
, contact_id
, address_id
, telephone_type
, country_code
, area_code
, telephone_number
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( telephone_s1.nextval                            -- telephone_id
, address_s1.currval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'MULTIPLE'
  AND      common_lookup_type = 'HOME')           -- telephone_type
,'USA'                                            -- country_code
,'801'                                            -- area_code
,'333-3333'                                       -- telephone_number
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert the second contact into the CONTACT table.
INSERT INTO contact
( contact_id
, member_id
, contact_type
, first_name
, last_name
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( contact_s1.nextval                              -- contact_id
, member_s1.currval                               -- member_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'CONTACT'
  AND      common_lookup_type = 'CUSTOMER')       -- contact_type
,'Ginny'                                          -- first_name
,'Potter'                                         -- last_name
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert an address into the ADDRESS table.
INSERT INTO address
( address_id
, contact_id
, address_type
, city
, state_province
, postal_code
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( address_s1.nextval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_type = 'HOME')           -- address_type
,'Provo'                                          -- city
,'Utah'                                           -- state_province
,'84604'                                          -- postal_code
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a street address into the STREET_ADDRESS table.
INSERT INTO street_address
( street_address_id
, address_id
, street_address
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( street_address_s1.nextval                       -- street_address_id
, address_s1.currval                              -- address_id
,'900 E, 300 N'                                    -- street_address
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a # into the TELEPHONE table.
INSERT INTO telephone
( telephone_id
, contact_id
, address_id
, telephone_type
, country_code
, area_code
, telephone_number
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( telephone_s1.nextval                            -- telephone_id
, address_s1.currval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'MULTIPLE'
  AND      common_lookup_type = 'HOME')           -- telephone_type
,'USA'                                            -- country_code
,'801'                                            -- area_code
,'333-3333'                                       -- telephone_number
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert the third contact into the CONTACT table.
INSERT INTO contact
( contact_id
, member_id
, contact_type
, first_name
, middle_name
, last_name
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( contact_s1.nextval                              -- contact_id
, member_s1.currval                               -- member_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'CONTACT'
  AND      common_lookup_type = 'CUSTOMER')       -- contact_type
,'Lily'                                           -- first_name
,'Luna'                                           -- middle_name
,'Potter'                                         -- last_name
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert an address into the ADDRESS table.
INSERT INTO address
( address_id
, contact_id
, address_type
, city
, state_province
, postal_code
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( address_s1.nextval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_type = 'HOME')           -- address_type
,'Provo'                                          -- city
,'Utah'                                           -- state_province
,'84604'                                          -- postal_code
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a street address into the STREET_ADDRESS table.
INSERT INTO street_address
( street_address_id
, address_id
, street_address
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( street_address_s1.nextval                       -- street_address_id
, address_s1.currval                              -- address_id
,'900 E, 300 N'                                    -- street_address
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


--  Insert a # into the TELEPHONE table.
INSERT INTO telephone
( telephone_id
, contact_id
, address_id
, telephone_type
, country_code
, area_code
, telephone_number
, created_by
, creation_date
, last_updated_by
, last_update_date )
 VALUES
( telephone_s1.nextval                            -- telephone_id
, address_s1.currval                              -- address_id
, contact_s1.currval                              -- contact_id
,(SELECT   common_lookup_id
  FROM     common_lookup
  WHERE    common_lookup_context = 'MULTIPLE'
  AND      common_lookup_type = 'HOME')           -- telephone_type
,'USA'                                            -- country_code
,'801'                                            -- area_code
,'333-3333'                                       -- telephone_number
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- created_by
, SYSDATE                                         -- creation_date
,(SELECT   system_user_id
  FROM     system_user
  WHERE    system_user_name = 'SYSADMIN')         -- last_updated_by
, SYSDATE                                         -- last_update_date
);


-- Step 3 Verification for member account data
COLUMN account_number  FORMAT A10  HEADING "Account|Number"
COLUMN full_name       FORMAT A20  HEADING "Name|(Last, First MI)"
COLUMN street_address  FORMAT A14  HEADING "Street Address"
COLUMN city            FORMAT A10  HEADING "City"
COLUMN state           FORMAT A10  HEADING "State"
COLUMN postal_code     FORMAT A6   HEADING "Postal|Code"
SELECT   m.account_number
,        c.last_name || ', ' || c.first_name
||       CASE
           WHEN c.middle_name IS NOT NULL THEN
             ' ' || c.middle_name || ' '
         END AS full_name
,        sa.street_address
,        a.city
,        a.state_province AS state
,        a.postal_code
FROM     member m INNER JOIN contact c
ON       m.member_id = c.member_id INNER JOIN address a
ON       c.contact_id = a.contact_id INNER JOIN street_address sa
ON       a.address_id = sa.address_id INNER JOIN telephone t
ON       c.contact_id = t.contact_id
WHERE    c.last_name = 'Potter';


-- Insert 3 records into the RENTAL table.
INSERT INTO rental
( rental_id
, customer_id
, check_out_date
, return_date                  
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( rental_s1.nextval
,(SELECT   contact_id
  FROM     contact
  WHERE    last_name = 'Potter'
  AND      first_name = 'Harry')
, TRUNC(SYSDATE)
, TRUNC(SYSDATE) + 1 
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO rental
( rental_id
, customer_id
, check_out_date
, return_date                  
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( rental_s1.nextval
,(SELECT   contact_id
  FROM     contact
  WHERE    last_name = 'Potter'
  AND      first_name = 'Ginny')
, TRUNC(SYSDATE)
, TRUNC(SYSDATE) + 3
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO rental
( rental_id
, customer_id
, check_out_date
, return_date                  
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( rental_s1.nextval
,(SELECT   contact_id
  FROM     contact
  WHERE    last_name = 'Potter'
  AND      middle_name = 'Luna'
  AND      first_name = 'Lily')
, TRUNC(SYSDATE)
, TRUNC(SYSDATE) + 5
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Insert 4 records into the RENTAL_ITEM table.
INSERT INTO rental_item
( rental_item_id
, rental_id
, item_id
, created_by
, creation_date
, last_updated_by
, last_update_date)
VALUES
( rental_item_s1.nextval
,(SELECT   r.rental_id
  FROM     rental r
  ,        contact c
  WHERE    r.customer_id = c.contact_id
  AND      c.last_name = 'Potter'
  AND      c.first_name = 'Harry')
,(SELECT   i.item_id
  FROM     item i
  ,        common_lookup cl
  WHERE    i.item_title = 'Star Wars I'
  AND      i.item_subtitle = 'Phantom Menace'
  AND      i.item_type = cl.common_lookup_id
  AND      cl.common_lookup_type = 'DVD_WIDE_SCREEN')
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO rental_item
( rental_item_id
, rental_id
, item_id
, created_by
, creation_date
, last_updated_by
, last_update_date)
VALUES
( rental_item_s1.nextval
,(SELECT   r.rental_id
  FROM     rental r inner join contact c
  ON       r.customer_id = c.contact_id
  WHERE    c.last_name = 'Potter'
  AND      c.first_name = 'Harry')
,(SELECT   d.item_id
  FROM     item d join common_lookup cl
  ON       d.item_title = 'Star Wars II'
  WHERE    d.item_subtitle = 'Attack of the Clones'
  AND      d.item_type = cl.common_lookup_id
  AND      cl.common_lookup_type = 'DVD_WIDE_SCREEN')
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO rental_item
( rental_item_id
, rental_id
, item_id
, created_by
, creation_date
, last_updated_by
, last_update_date)
VALUES
( rental_item_s1.nextval
,(SELECT   r.rental_id
  FROM     rental r
  ,        contact c
  WHERE    r.customer_id = c.contact_id
  AND      c.last_name = 'Potter'
  AND      c.first_name = 'Ginny')
,(SELECT   d.item_id
  FROM     item d
  ,        common_lookup cl
  WHERE    d.item_title = 'Star Wars III'
  AND      d.item_subtitle = 'Revenge of the Sith'
  AND      d.item_type = cl.common_lookup_id
  AND      cl.common_lookup_type = 'DVD_WIDE_SCREEN')
, 1001
, SYSDATE
, 1001
, SYSDATE);


INSERT INTO rental_item
( rental_item_id
, rental_id
, item_id
, created_by
, creation_date
, last_updated_by
, last_update_date)
VALUES
( rental_item_s1.nextval
,(SELECT   r.rental_id
  FROM     rental r
  ,        contact c
  WHERE    r.customer_id = c.contact_id
  AND      c.last_name = 'Potter'
  AND      middle_name = 'Luna'
  AND      c.first_name = 'Lily')
,(SELECT   d.item_id
  FROM     item d
  ,        common_lookup cl
  WHERE    d.item_title = 'I Remember Mama'
  AND      d.item_subtitle IS NULL
  AND      d.item_type = cl.common_lookup_id
  AND      cl.common_lookup_type = 'BLU-RAY')
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Step 3 Verification for the rental items
COLUMN full_name   FORMAT A18
COLUMN rental_id   FORMAT 9999   HEADING "RENTAL_ID"
COLUMN rental_days FORMAT A14
COLUMN rentals     FORMAT 9999
COLUMN items       FORMAT 9999
SELECT   c.last_name||', '||c.first_name||' '||c.middle_name AS full_name
,        r.rental_id
,       (r.return_date - r.check_out_date) || '-DAY RENTAL' AS rental_days
,        COUNT(DISTINCT r.rental_id) AS rentals
,        COUNT(ri.rental_item_id) AS items
FROM     rental r INNER JOIN rental_item ri
ON       r.rental_id = ri.rental_id INNER JOIN contact c
ON       r.customer_id = c.contact_id
WHERE   (SYSDATE - r.check_out_date) < 15
AND      c.last_name = 'Potter'
GROUP BY c.last_name||', '||c.first_name||' '||c.middle_name
,        r.rental_id
,       (r.return_date - r.check_out_date) || '-DAY RENTAL'
ORDER BY 2;

-- ----------------------------------------------------------
--  Step #4
--  -------
--  Modify the common_lookup table to support additional 
--  data and transfer data between tables using an update 
--  statement. Also insert data to create certain index's 
--  against the common_lookup table. 
-- ----------------------------------------------------------

--Part A drop common_lookup indexs

-- Drop a non-unique index.
DROP INDEX common_lookup_n1;


-- Drop a unique index.
DROP INDEX common_lookup_u2;


--Step 4 Verification for the drop index statements
COLUMN table_name FORMAT A14
COLUMN index_name FORMAT A20
SELECT   table_name
,        index_name
FROM     user_indexes
WHERE    table_name = 'COMMON_LOOKUP';


-- Part B Add new colomns to the common_lookup table
ALTER TABLE common_lookup
  ADD  (common_lookup_table   VARCHAR2(30)   
,       common_lookup_column  VARCHAR2(30)   
,       common_lookup_code    VARCHAR2(30)); 


-- Step 4 Verification for the added columns 
SET NULL ''
COLUMN table_name   FORMAT A14
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22
COLUMN data_type    FORMAT A12
SELECT   table_name
,        column_id
,        column_name
,        CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
,        CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM     user_tab_columns
WHERE    table_name = 'COMMON_LOOKUP'
ORDER BY 2;


-- Step 4 Verification for the lookup_context and lookup_type 
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
ORDER BY 1, 2, 3; 


-- Part C1 Move data between two columns without copying 'MULTIPLE'
UPDATE common_lookup
SET    common_lookup_table = common_lookup_context
WHERE  common_lookup_context != 'MULTIPLE';


-- Step 4 Verification for the merge of data between two columns
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
ORDER BY 1, 2, 3;


-- Part C2 Add 'ADDRESS' in the blank row in the COMMON_LOOKUP_TABLE
UPDATE common_lookup
SET    common_lookup_table = 'ADDRESS'
WHERE  common_lookup_context = 'MULTIPLE';


-- Step 4 Verification for the insertion of 'ADDRESS' in the COMMON_LOOKUP_TABLE
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
ORDER BY 1, 2, 3;


-- Part C3 merge data between the COMMON_LOOKUP_COLUMN and CONTEXT tables
UPDATE common_lookup
SET    common_lookup_column = common_lookup_context || '_TYPE'
WHERE  common_lookup_context != 'MULTIPLE';


-- Step 4 Verification to show the data is merge and that there is no data in 
-- the 'WORK' or 'HOME' columns for the the COMMON_LOOKUP_COLUMN        
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
WHERE    common_lookup_table IN
          (SELECT table_name
           FROM   user_tables)
ORDER BY 1, 2, 3;



-- Part C4 Add 'ADDRESS_TYPE' to the COMMON_LOOKUP_COLUMN where the 'MULTIPLE' row is located
UPDATE common_lookup
SET    common_lookup_column = 'ADDRESS_TYPE' 
WHERE  common_lookup_context = 'MULTIPLE';


-- Step 4 Verification for the insertion of the 'ADDRESS_TYPE'
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
WHERE    common_lookup_table IN
          (SELECT table_name
           FROM   user_tables)
ORDER BY 1, 2, 3;


-- Part D Drop the NOT NULL constraint and add new data
ALTER TABLE common_lookup
DROP CONSTRAINT nn_clookup_1;


-- Add new rows to the common_lookup table
INSERT INTO common_lookup 
( common_lookup_id
, common_lookup_table
, common_lookup_column
, common_lookup_type
, common_lookup_meaning
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( common_lookup_s1.nextval 
, 'TELEPHONE'
, 'TELEPHONE_TYPE'
, 'HOME'
, 'Home'
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Add new rows to the common_lookup table
INSERT INTO common_lookup 
( common_lookup_id
, common_lookup_table
, common_lookup_column
, common_lookup_type
, common_lookup_meaning
, created_by
, creation_date
, last_updated_by
, last_update_date )
VALUES
( common_lookup_s1.nextval 
, 'TELEPHONE'
, 'TELEPHONE_TYPE'
, 'WORK'
, 'Work'
, 1001
, SYSDATE
, 1001
, SYSDATE);


-- Step 4 Verification for the insertion of the new rows added 
COLUMN common_lookup_context  FORMAT A14  HEADING "Common|Lookup Context"
COLUMN common_lookup_table    FORMAT A12  HEADING "Common|Lookup Table"
COLUMN common_lookup_column   FORMAT A18  HEADING "Common|Lookup Column"
COLUMN common_lookup_type     FORMAT A18  HEADING "Common|Lookup Type"
SELECT   common_lookup_context
,        common_lookup_table
,        common_lookup_column
,        common_lookup_type
FROM     common_lookup
WHERE    common_lookup_table IN
          (SELECT table_name
           FROM   user_tables)
ORDER BY 1, 2, 3;


-- Part E1 DROP the COMMON_LOOKUP_CONTEXT
ALTER TABLE common_lookup
DROP COLUMN common_lookup_context;


-- Part E2 Add a NOT NULL constraint to the COMMON_LOOKUP_TABLE
ALTER TABLE common_lookup
MODIFY (common_lookup_table VARCHAR2(30) CONSTRAINT nn_clookup_8 NOT NULL);


-- Part E2 Add a NOT NULL constraint to the COMMON_LOOKUP_COLUMN
ALTER TABLE common_lookup
MODIFY (common_lookup_column VARCHAR2(30) CONSTRAINT nn_clookup_9 NOT NULL);


-- Step 4 Verification for the new structure for the COMMON_LOOKUP table
SET NULL ''
COLUMN table_name   FORMAT A14     HEADING "Table Name"
COLUMN column_id    FORMAT 9999
COLUMN column_name  FORMAT A22     HEADING "Column|Name"
COLUMN data_type    FORMAT A12
SELECT   table_name
,        column_id
,        column_name
,        CASE
           WHEN nullable = 'N' THEN 'NOT NULL'
           ELSE ''
         END AS nullable
,        CASE
           WHEN data_type IN ('CHAR','VARCHAR2','NUMBER') THEN
             data_type||'('||data_length||')'
           ELSE
             data_type
         END AS data_type
FROM     user_tab_columns
WHERE    table_name = 'COMMON_LOOKUP'
ORDER BY 2;


-- Step 4 Verification of the new constraints added to each column
COLUMN constraint_name   FORMAT A22  HEADING "Constraint Name"
COLUMN search_condition  FORMAT A36  HEADING "Search Condition" 
COLUMN constraint_type   FORMAT A10  HEADING "Constraint|Type"
SELECT   uc.constraint_name
,        uc.search_condition
,        uc.constraint_type
FROM     user_constraints uc INNER JOIN user_cons_columns ucc
ON       uc.table_name = ucc.table_name
AND      uc.constraint_name = ucc.constraint_name
WHERE    uc.table_name = UPPER('common_lookup')
AND      uc.constraint_type IN (UPPER('c'),UPPER('p'))
ORDER BY uc.constraint_type DESC
,        uc.constraint_name;


-- Part E3 Create a unique index on multiple columns 
CREATE UNIQUE INDEX clookup_u1
  ON common_lookup(common_lookup_table, common_lookup_column, common_lookup_type);
  
  
-- Step 4 Verification for the COMMON_LOOKUP unique natural key inedex
COLUMN sequence_name   FORMAT A22 HEADING "Sequence Name"
COLUMN column_position FORMAT 999 HEADING "Column|Position"
COLUMN column_name     FORMAT A22 HEADING "Column|Name"
SELECT   ui.index_name
,        uic.column_position
,        uic.column_name
FROM     user_indexes ui INNER JOIN user_ind_columns uic
ON       ui.index_name = uic.index_name
AND      ui.table_name = uic.table_name
WHERE    ui.table_name = UPPER('common_lookup')
ORDER BY ui.index_name
,        uic.column_position;
  
-- Part F Fix foreign key values and add accurate data to the 
-- COMMON_LOOKUP_ID on the TELEPHONE_TYPE column of the TELEPHONE table
UPDATE telephone
SET    telephone_type = 
(SELECT common_lookup_id
FROM   common_lookup
WHERE  common_lookup_table = 'TELEPHONE'
AND    common_lookup_type = 'HOME')
WHERE telephone_type = 
(SELECT common_lookup_id
FROM   common_lookup
WHERE  common_lookup_table = 'ADDRESS'
AND    common_lookup_type = 'HOME'); 
  
  
-- Step 4 Verification of the structured UPDATE to the TELEPHONE_TYPE columns 
COLUMN common_lookup_table  FORMAT A14 HEADING "Common|Lookup Table"
COLUMN common_lookup_column FORMAT A14 HEADING "Common|Lookup Column"
COLUMN common_lookup_type   FORMAT A8  HEADING "Common|Lookup|Type"
COLUMN count_dependent      FORMAT 999 HEADING "Count of|Foreign|Keys"
COLUMN count_lookup         FORMAT 999 HEADING "Count of|Primary|Keys"
SELECT   cl.common_lookup_table
,        cl.common_lookup_column
,        cl.common_lookup_type
,        COUNT(a.address_id) AS count_dependent
,        COUNT(DISTINCT cl.common_lookup_table) AS count_lookup
FROM     address a RIGHT JOIN common_lookup cl
ON       a.address_type = cl.common_lookup_id
WHERE    cl.common_lookup_table = 'ADDRESS'
AND      cl.common_lookup_column = 'ADDRESS_TYPE'
AND      cl.common_lookup_type IN ('HOME','WORK')
GROUP BY cl.common_lookup_table
,        cl.common_lookup_column
,        cl.common_lookup_type
UNION
SELECT   cl.common_lookup_table
,        cl.common_lookup_column
,        cl.common_lookup_type
,        COUNT(t.telephone_id) AS count_dependent
,        COUNT(DISTINCT cl.common_lookup_table) AS count_lookup
FROM     telephone t RIGHT JOIN common_lookup cl
ON       t.telephone_type = cl.common_lookup_id
WHERE    cl.common_lookup_table = 'TELEPHONE'
AND      cl.common_lookup_column = 'TELEPHONE_TYPE'
AND      cl.common_lookup_type IN ('HOME','WORK')
GROUP BY cl.common_lookup_table
,        cl.common_lookup_column
,        cl.common_lookup_type;



SPOOL OFF
