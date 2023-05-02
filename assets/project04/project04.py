
# %%
import matplotlib
from sklearn import tree
import pandas as pd
import altair as alt

from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn import metrics

# %%
# Pull the data and assign each data set to a variable
dwellings_denver = pd.read_csv(
    "https://raw.githubusercontent.com/byuidatascience/data4dwellings/master/data-raw/dwellings_denver/dwellings_denver.csv")
dwellings_ml = pd.read_csv(
    "https://raw.githubusercontent.com/byuidatascience/data4dwellings/master/data-raw/dwellings_ml/dwellings_ml.csv")
dwellings_neighborhoods_ml = pd.read_csv(
    "https://raw.githubusercontent.com/byuidatascience/data4dwellings/master/data-raw/dwellings_neighborhoods_ml/dwellings_neighborhoods_ml.csv")
