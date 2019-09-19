"""
 Program:
    CS241 Team Activity 12, Pandas
Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary: 
    
"""

import pandas
import matplotlib.pyplot as plt


data = pandas.read_csv("weather_year.csv")
print(data) # display data frame
#print(len(data)) # Get number of rows
#print(data.columns) # Get columns
#print(data["EDT"]) # Get columns
#print(data[["EDT", "Mean TemperatureF"]]) # print multiple columns
#print(data.EDT) # Access columns using dot syntax, but only works
#if it is a single key word from the column string name
#print(data.EDT.head()) # Gives the first five items in a column
#print(data.EDT.head(10)) # Number in the head() function gives
# the first items in a column
#print(data.EDT.tail(10)) # Number in the tail() function gives
# the last items in a column
#print(data["Mean TemperatureF"].head()) # Use when using a dictionary

data.columns = ["date", "max_temp", "mean_temp", "min_temp", "max_dew",
                "mean_dew", "min_dew", "max_humidity", "mean_humidity",
                "min_humidity", "max_pressure", "mean_pressure",
                "min_pressure", "max_visibilty", "mean_visibility",
                "min_visibility", "max_wind", "mean_wind", "min_wind",
                "precipitation", "cloud_cover", "events", "wind_dir"]
#print(data) # Displays the renamed columns
#print(data.mean_temp.head())
#print(data.mean_temp.std()) # Displays the standard deviation
#data.mean_temp.hist() # used with matplotlib hist() or plot() produce plots
# if nothing pops up, you can then do:
#plt.show() # shows the graph

#print(data.std()) # When you want the standard deviation for each column
# you need to plot the graph first 
print(data.date.head()) # Displays the 
