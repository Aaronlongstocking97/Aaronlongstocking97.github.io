
-- Open log file.
SPOOL class_example_code.txt

UPDATE telephone
SET    t.telephone_type =
       -- Logic to look up the new and correct value. 
        (SELECT cl.common_lookup_id
         FROM common_lookup cl
         WHERE cl.common_lookup_table = 'TELEPHONE'
         AND cl.common_lookup_column = 'TELEPHONE_TYPE'
         AND cl.common_lookup_type = 'HOME')
WHERE   t.telephone_type =
         -- Logic to look up the old and now incorrect values.
        (SELECT cl.common_lookup_id
         FROM common_lookup cl
         WHERE cl.common_lookup_table = 'TELEPHONE'
         AND cl.common_lookup_column = 'TELEPHONE_TYPE'
         AND cl.common_lookup_type = 'HOME');
 

SPOOL OFF
