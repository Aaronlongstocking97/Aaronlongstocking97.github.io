
import pandas as pd
import altair as alt
import numpy as np
import sqlite3

# %%
# careful to list your path to the file.
sqlite_file = 'lahmansbaseballdb.sqlite'
con = sqlite3.connect(sqlite_file)

results = pd.read_sql_query(
    'SELECT * FROM allstarfull LIMIT 5',
    con)

print(results)

# SELECT - - < columns > and < column calculations >
# FROM - - < table name >
# JOIN - - < table name >
# ON - - < columns to join >
# WHERE - - < filter condition >
# GROUP BY - - < subsets for column calculations >
# HAVING - - < grouped filter condition >
# ORDER BY - - < how the output is returned in sequence >
# LIMIT - - < number of rows to return >


# Question One: Write an SQL query to create a new dataframe
#               about baseball players who attended BYU-Idaho.
#               The new table should contain five columns:
#               playerID, schoolID, salary, and the yearID/teamID
#               associated with each salary. Order the table by
#               salary (highest to lowest) and print out the
#               table in your report.
# Think about:
#               What tables (data) do you need?
#               What SQL commands do you need?


# %%


# %%
# Connect to the SQLite database file
conn = sqlite3.connect('lahmansbaseballdb.sqlite')

# Open the output SQL file
with open('baseball_data.sql', 'w') as f:

    # Set up the cursor
    cursor = conn.cursor()

    # Get a list of all tables in the database
    cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
    tables = cursor.fetchall()

    # Iterate over each table and write its contents to the SQL file
    for table_name in tables:
        table_name = table_name[0]
        cursor.execute(f"SELECT * FROM {table_name};")
        results = cursor.fetchall()

        # Write the table's contents to the SQL file
        f.write(f"DROP TABLE IF EXISTS {table_name};\n")
        schema_query = cursor.execute(
            f"SELECT sql FROM sqlite_master WHERE name='{table_name}' and type='table';")
        schema_query = cursor.fetchone()[0]
        f.write(f"{schema_query};\n")

        for row in results:
            f.write(f"INSERT INTO {table_name} VALUES {row};\n")

# Close the connection
conn.close()


# %%

# Open a connection to the SQLite database file
conn = sqlite3.connect('lahmansbaseballdb.sqlite')

# Create a cursor object
cur = conn.cursor()

# Execute the .dump command to export the database to an SQL file
with open('mydatabase.sql', 'w') as f:
    for line in conn.iterdump():
        f.write('%s\n' % line)

# Close the database connection
conn.close()
# %%
