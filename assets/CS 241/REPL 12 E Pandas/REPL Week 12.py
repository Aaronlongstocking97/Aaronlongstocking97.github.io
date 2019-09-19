"""
 Program:
    CS241 REPL Week 12, Movie Database
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary:
    

                     
"""

import pandas
import matplotlib.pyplot as plt

# Read movies data into a dataframe
data = pandas.read_csv("movies.csv")

# Print out columns
print(data.columns)
print("Movie Length mean: {}" .format(data.length.mean()))
print("Voter Rating median: {}" .format(data.rating.median()))
print()

# Get the Year of the First PG Movie
#print(data.groupby("mpaa").year.min())
data.mpaa = data.mpaa.apply(lambda x : x.strip())
print(data[data.mpaa == "PG"].year.min())
print()

# Plot graph of all movies by MPAA ratings
data_mpaa_count = data[data.mpaa != ""].mpaa.value_counts().sort_index()
print(data_mpaa_count)
data_mpaa_count.plot(kind="bar", title="Movies by MPAA Rating", rot=0)
#plt.show()
#plt.savefig("graph1.png")
print()

# Find the average budget Action Movies
action_budget = data[(data.budget > 0) & (data["Action"] == 1)].budget.mean()
print(action_budget)
print()

# Find the non-short movie with the highest cost per minute
data["CostPerMinute"] = data.budget / data.length
print(data[data.Short == 0].sort_values(by="CostPerMinute", ascending=False).iloc[0])
print()

# Find the average budget per year
avg_budget_per_year = data.groupby("year").budget.mean()
print(avg_budget_per_year)
print()

# Find trends in movie ratings
rating_per_year = {} # dictionary
for rating in ["PG","PG-13","R","NC-17"]:
    rating_per_year[rating] = data[data.mpaa == rating].groupby("year").size()
    print(rating_per_year[rating])
rating_per_year_df = pandas.DataFrame(rating_per_year)
print(rating_per_year_df)
x_val = [x for x in range(1980,2005,5)]
rating_per_year_df[rating_per_year_df.index > 1980].plot(kind="line", style='.-', title="Ratings Per Year", xticks=x_val)
plt.show()
plt.savefig("graph2.png")


