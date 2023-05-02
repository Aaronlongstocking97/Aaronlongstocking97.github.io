
# %%
import matplotlib
from sklearn import tree
import pandas as pd
import altair as alt
import numpy as np
import seaborn as sns

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

# %%
# Separate the features (X) and targets (Y)
x = dwellings_ml.filter(["livearea", "basement", "stories", "numbaths"])
y = dwellings_ml[["before1980"]]

# %% Split the data into train and test sets
x_train, x_test, y_train, y_test = train_test_split(x, y)

# %%
# Create a decision tree
classifier_DT = DecisionTreeClassifier(max_depth=124)

# Fit the decision tree
classifier_DT.fit(x_train, y_train)

# Test the decision tree (make predictions)
y_predicted_DT = classifier_DT.predict(x_test)

# Evaluate the decision tree
print("Accuracy:", metrics.accuracy_score(y_test, y_predicted_DT))


# %%
# method 1 - text
print(tree.export_text(classifier_DT))

# %%
# method 2 - graph
tree.plot_tree(classifier_DT, feature_names=x.columns, filled=True)

# %%
# Feature importance
classifier_DT.feature_importances_

# %%
feature_df = pd.DataFrame(
    {'features': x.columns, 'importance': classifier_DT.feature_importances_})
feature_df


# %%
# a confusion matrix
print(metrics.confusion_matrix(y_test, y_predicted_DT))

# %%
# this one might be easier to read
print(pd.crosstab(y_test.before1980, y_predicted_DT, rownames=[
      'True'], colnames=['Predicted'], margins=True))

# %%
# visualize a confusion matrix
# requires 'matplotlib' to be installed
metrics.plot_confusion_matrix(classifier_DT, x_test, y_test)

# h_subset = (ml_dat, .filter(['livearea', 'finbsmnt', 'basement', 'nocars']))

# %%
# sns.pairplot(h_subset, hue = "before1980")
