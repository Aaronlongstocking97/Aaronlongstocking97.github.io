
-- Open log file.
SPOOL test_case.txt

CREATE TABLE NUMERIC 
( x NUMBER );

INSERT INTO NUMERIC VALUES (1);
INSERT INTO NUMERIC VALUES (2);
INSERT INTO NUMERIC VALUES (3);
INSERT INTO NUMERIC VALUES (4);
INSERT INTO NUMERIC VALUES (NULL);
 
SELECT 
    CASE
        WHEN MOD(X,2) = 0 THEN 'EVEN'
        ELSE 'Odd'
    END AS STATE 
FROM NUMERIC




SELECT DISTINCT 
    first_name
    DECODE(middle_name,null,' ',' '||middle_name||' ')
    last_name
FROM contact;

--
SELECT member_id, first_name, last_name
FROM   contact c FULL JOIN member m
USING(member_id)
MINUS
SELECT member_id, first_name, last_name
FROM   contact c INNER JOIN member m
USING(member_id);

--
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
, 1003                                            -- member_type
,'Z293-71445'                                     -- account_number
,'1111-2222-3333-4444'                            -- credit_card_number
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


SPOOL OFF
