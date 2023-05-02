

import pandas as pd
import altair as alt
import numpy as np
import datadotworld as dw
import sqlite3

from IPython.display import Markdown
from IPython.display import display
from tabulate import tabulate

dw_results = dw.query('byuidss/cse-250-baseball-database',
                      'SELECT * FROM batting LIMIT 100')

batting5 = dw_results.dataframe

print(batting5)

# connect to the SQLite database
sqlite_file = 'lahmansbaseballdb.sqlite'
conn = sqlite3.connect(sqlite_file)

lite_results = pd.read_sql_query(
    'SELECT * FROM allstarfull LIMIT 5',
    conn)

print(lite_results)

# Question # 1
# Write an SQL query to create a new dataframe
# about baseball players who attended BYU-Idaho.
# The new table should contain five columns:
# playerID, schoolID, salary, and the yearID/teamID
# associated with each salary.
# Order the table by salary (highest to lowest)
# and print out the table in your report.

result = dw.query('byuidss/cse-250-baseball-database',
                  """
    SELECT p.playerID, cp.schoolID, s.salary, s.yearID, s.teamID
    FROM people AS p
    JOIN collegeplaying AS cp ON p.playerID = cp.playerID
    JOIN salaries AS s ON p.playerID = s.playerID
    WHERE cp.schoolID = 'idbyuid'
    ORDER BY s.salary DESC;
    """)

gq1 = result.dataframe
print(gq1.head(3).to_markdown())
# gq1

# execute the SQL query and store the result in a pandas dataframe
df = pd.read_sql_query("""
    SELECT p.playerID, cp.schoolID, s.salary, s.yearID, s.teamID
    FROM people AS p
    JOIN collegeplaying AS cp ON p.playerID = cp.playerID
    JOIN salaries AS s ON p.playerID = s.playerID
    WHERE cp.schoolID = 'idbyuid'
    ORDER BY s.salary DESC
""", conn)

# print the resulting dataframe
print(df)
