"""
 Program:
    CS241 Checkpoint 12a, Finding A Median Of A Data Set
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
"""
import pandas

census_data = pandas.read_csv("census.csv")

print(census_data[0].median())

