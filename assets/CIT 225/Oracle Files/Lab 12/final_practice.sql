
-- Open log file.
SPOOL test_case.txt

SELECT ADD_MONTHS ('28-APR-97', 120) FROM DUAL;

SPOOL OFF
