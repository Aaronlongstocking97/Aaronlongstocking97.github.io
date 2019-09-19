-----------------------------------------------
-- Open log file.
SPOOL class_example_code.txt
SET PAGESIZE 999
SET LINESIZE 80
-----------------------------------------------

--SELECT * FROM TRANSACTION_UPLOAD
--WHERE first_name = 'Harry'
--ORDER BY check_out_date;

--SELECT DISTINCT check_out_date
--FROM transaction_upload 
--WHERE first_name = 'Harry'
--ORDER BY check_out_date;

--SELECT check_out_date 
--FROM transaction_upload
--WHERE first_name = 'Harry'
--ORDER BY check_out_date;

--SELECT contact_id
--FROM contact;

--SELECT * FROM rental;

--SELECT check_out_date 
--FROM rental 
--ORDER BY  check_out_date;

--SELECT check_out_date 
--FROM transaction_upload 
--ORDER BY  check_out_date;

--SELECT DISTINCT check_out_date 
--FROM transaction_upload 
--ORDER BY  check_out_date;




-- Close log file.
SPOOL OFF
