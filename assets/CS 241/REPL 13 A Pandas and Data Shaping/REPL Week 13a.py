"""
 Program:
    CS241 REPL Week 13, Intro to Pandas and Data Shaping
 Instructor:
    Borther Macbeth
 Author:
    Aaron Jones
 Summary:
    

                     
"""

import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load Data
players = pd.read_csv("basketball_players.csv")
master = pd.read_csv("basketball_master.csv")
nba = pd.merge(players, master, how="left", left_on="playerID", right_on="bioID")

# Rank the top 200 players by all time points and rebounds
subset = nba[["playerID","points","rebounds","assists","fgAttempted"]].groupby("playerID").sum()
subset = subset.sort_values(by="points", ascending=False).head(200)
subset["PointsRank"] = subset["points"].rank(ascending=True, pct=True)
subset["ReboundsRank"] = subset["rebounds"].rank(ascending=True, pct=True)

# Rank those same players by points per attempted shot
subset["PointsPerAttempt"] = subset.points / subset.fgAttempted
subset["PointsPerAttemptRank"] = subset["PointsPerAttempt"].rank(ascending=True, pct=True)

pd.set_option("display.max_columns",10)
print(subset)

# Find the top players in points, rebounds, and points per attempt
best = subset[(subset.PointsRank > 0.90) & (subset.ReboundsRank > 0.90) & (subset.PointsPerAttemptRank > 0.90)]
print(best)

# Create a table of average stats per year (also plot it)
subset = nba[["year","points","rebounds","assists","fgAttempted"]].groupby("year").mean()
print(subset)
subset.plot()
plt.show()

# Create a table with year, stat, and value (also plot using sns.lineplot)
subset_melt = subset.reset_index().melt("year", var_name="stat", value_name="value")
print(subset_melt)
sns.lineplot(data=subset_melt, x="year", y="value", hue="stat")
plt.show()

# Create the table of average stats per year again by using a pivot table
subset_pivot = subset_melt.pivot(index="year", columns="stat", values="value")
print(subset_pivot)


