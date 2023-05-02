# %%
# Load packages and data
import pandas as pd
import numpy as np
import json

url_flights = "https://raw.githubusercontent.com/byuidatascience/data4missing/master/data-raw/flights_missing/flights_missing.json"
flights = pd.read_json(url_flights)

# %%
# Find all the missing values
# method 1: find "official" null values
# hp, wt, and vs
flights.isnull().sum()

# %%
# method 2: just look at the data
# car, hp, wt, vs, gear
flights.head(10)

# %%
# method 3: look at summaries
# the values in 'gear' look funny
flights.describe()

# %%
# method 4: count up categories
# looks like 4 rows are blank
flights.flight.value_counts()


# %%
# There are a lot of functions
# we could use to give the missing values
# a consistent format.

# flights.columns()

# Clean the data:

# flights_1_2 = (flights
#                .replace(-999, np.nan)
#                .replace("1500+", 1500)
#                .assign(new_variable="num_delays_carrier"))


# clean = (flights
#                .replace(-999, np.nan)
#                .replace("1500+", 1500)
#                .query("month != 'n/a'"))

# print(clean.num_delays_carrier.describe())

#  lamda functions will be helpful on question number three.
#  Make new columns as you go and refer to thos columns.
clean2 = (flights
          .replace(-999, np.nan)
          .replace("1500+", 1500)
          .query("month != 'n/a'")
          .assign(num_delays_carrier=lambda x: x.num_delays_carrier.astype(int)))

# clean2.describe()
clean2.num_delays_carrier.mean()


# %%
flights.groupby("airport_code").sum().reset_index()


clean2_b = clean2.groupby("airport_code").sum().reset_index().filter(
    ["airport_code", "number_of_flights_total", "num_of_delays_total"])
# clean2

# `replace()` is one of the easiest
# let's change everything to np.nan
flights_new = flights.replace(999, np.nan).replace("", np.nan)

# or equivalently:
flights_new = flights.replace([999, ""], np.nan)


# did we get them all?
flights_new.isnull().sum()


# %%
agg_dat = (flights
           .groupby("airport_code")
           .agg(
               sum_flights_total=("num_of_flights_total", np.sum),
               sum_flights_delay=("num_of_delays_total", np.sum)
           )
           .assign(
               prop_delay=lambda x: x["sum_flights_delay"] / x.
               sum_flights_total
           )
           )

# agg_dat


# %%
# Saving JSON files from a pandas dataframe
# save the new data as a json
flights_new.to_json("my_flights_data.json")

# [
#     {
#         "car": "Mazda RX4",
#         "mpg": 21,
#         "cyl": 6,
#         "disp": 160,
#         "hp": 110,
#         "drat": 3.9,
#         "wt": 2.62,
#         "qsec": 16.46,
#         "vs": 0,
#         "am": 1,
#         "gear": 4,
#         "carb": 4
#     }
# ]


# %%
# Question 5 wants us to "include one record example"
# in our md report that "has a missing value"

# you can print out a json file like this:
json_data = flights_new.to_json()
print(json_data)

# but that won't look good in our report.
# instead....

# %%
# you can do this.
# in this format, the json file is
# organized/printed by column
json_data = flights_new.to_json()
json_object = json.loads(json_data)
json_formatted_str = json.dumps(json_object, indent=4)
print(json_formatted_str)

# %%
# we can change the format of the
# json file using 'orient'
json_data = flights.to_json(orient="split")
json_object = json.loads(json_data)
json_formatted_str = json.dumps(json_object, indent=4)
print(json_formatted_str)

# %%
# by table
json_data = flights.to_json(orient="table")
json_object = json.loads(json_data)
json_formatted_str = json.dumps(json_object, indent=4)
print(json_formatted_str)

# %%
# by "record" or "row"
json_data = flights.to_json(orient="records")
json_object = json.loads(json_data)
json_formatted_str = json.dumps(json_object, indent=4)
print(json_formatted_str)
