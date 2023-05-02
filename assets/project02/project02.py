# %%
# Needed Libraries
import json
from urllib.request import urlopen
import matplotlib
from sklearn import tree
import pandas as pd
import altair as alt
import numpy as np
import seaborn as sns

from IPython.display import Markdown
from IPython.display import display
from tabulate import tabulate
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn import metrics
# Load flights data from URL
flights = pd.read_json(
    "https://raw.githubusercontent.com/byuidatascience/data4missing/master/data-raw/flights_missing/flights_missing.json")

# Group flights data by airport code and calculate metrics
prop_total_delays = (flights.groupby('airport_code')
                     .agg(total_flights=('num_of_flights_total', 'sum'),
                          total_delays=('num_of_delays_total', 'sum'),
                          total_delay_mins=('minutes_delayed_total', 'sum'))
                     .assign(prop_delays=lambda x: x.total_delays / x.total_flights,
                             avg_delay_hours=lambda x: x.total_delay_mins / (x.total_delays * 60))
                     .sort_values(by=["prop_delays", "avg_delay_hours"], ascending=False))

# Remove rows with missing values in the "month" column
flight_data = (flights.drop(flights.index[flights["month"] == "n/a"]))

# Group the data by month and calculate the total number of delays for each month.
total_delays = flight_data.groupby(
    'month')['num_of_delays_total'].sum().reset_index()

# Group the data by month and calculate the total number of minutes delayed for each month.
total_delay_minutes = flight_data.groupby(
    'month')['minutes_delayed_total'].sum().reset_index()

# Create a new data frame that shows the average time per delay for each month.
avg_delay_time = pd.DataFrame({'month': total_delay_minutes['month'],
                               'avg_time_per_delay': total_delay_minutes['minutes_delayed_total'] / total_delays['num_of_delays_total']})

# Group the data by month and calculate the total number of flights for each month.
total_flights = flight_data.groupby(
    "month")["num_of_flights_total"].sum().reset_index()

# Merge the data frames for total delays and total flights by month and
# calculate the percentage of delays for each month.
percentage_delays_month = total_delays.merge(total_flights, on="month")
percentage_delays_month["percentage_delays"] = percentage_delays_month["num_of_delays_total"] / \
    percentage_delays_month["num_of_flights_total"] * 100

# # A bar chart that shows the percentage of delays for each month.
# chart3 = alt.Chart(percentage_delays_month).mark_bar().encode(
#     x=alt.X('month:N', sort=['January', 'February', 'March', 'April', 'May', 'June',
#             'July', 'August', 'September', 'October', 'November', 'December'], title='Month'),
#     y=alt.Y('percentage_delays:Q', title='Percentage of Delays'),
#     tooltip=[alt.Tooltip('month:N', title='Month'), alt.Tooltip(
#         'percentage_delays:Q', title='Percentage of Delays')]
# ).properties(title='Percentage of Delays by Month').configure_axis(grid=True)

# chart3

# # Sort the chart by percentage of delays in ascending order
# best_month_chart = chart.transform_window(
#     rank='rank(percentage_delays)',
#     sort=[alt.SortField('percentage_delays', order='ascending')]
# ).transform_filter(
#     (alt.datum.rank == 1)
# ).properties(title='Best Month to Fly to Avoid Delays')

# best_month_chart

# Calculate the average of the column num_of_delays_late_aircraft
late_aircraft_avg = flights.num_of_delays_late_aircraft.replace(
    -999, np.nan).mean()

# Replace all the invalid values -999 with the average value only in the column "num_of_delays_late_aircraft"
flights["num_of_delays_late_aircraft"].replace(
    -999, late_aircraft_avg, inplace=True)

# Calculate the total number of flights delayed by weather using the given rules
severe_weather = flights["num_of_delays_weather"]
mild_weather_late_aircraft = 0.3 * flights["num_of_delays_late_aircraft"]
nas_weather_multiplier = np.where(flights["month"].isin(
    ["April", "May", "June", "July", "August"]), 0.4, 0.65)
mild_weather_nas = nas_weather_multiplier * flights["num_of_delays_nas"]
num_delays_weather = severe_weather + \
    mild_weather_late_aircraft + mild_weather_nas

# Add the new columns to the flights dataframe
flights["severe_weather"] = severe_weather
flights["mild_weather_late_aircraft"] = mild_weather_late_aircraft
flights["mild_weather_nas"] = mild_weather_nas
flights["num_delays_weather"] = num_delays_weather


# Group flights by airport code and calculate total number of flights and total number of weather delays for each airport
delays_by_weather_by_airport = (flights.groupby('airport_code')
                                .agg(total_flights=('num_of_flights_total', 'sum'),
                                     total_delays_weather=('num_delays_weather', 'sum'))
                                # Add a new column with the proportion of delays caused by weather for each airport
                                .assign(prop_delays_weather=lambda x: x.total_delays_weather / x.total_flights * 100)
                                # Reset the index so that airport code becomes a column instead of an index
                                .reset_index()
                                )

# Replace missing values with NaN
flights = flights.fillna(value="NaN")
