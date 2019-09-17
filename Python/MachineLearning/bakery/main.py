# python       = 3.7.3
# numpy        = 1.16.3
# pandas       = 0.24.2
# matplotlib   = 3.0.3
# scikit-learn = 0.20.3
# tensorflow   = 1.13.1
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LinearRegression
from statsmodels.regression.linear_model import OLS


def plot_with(dataset, xname, yname):
    c = (dataset.loc[dataset['Type'] == 'Cupcake'])[[xname, yname]]
    m = (dataset.loc[dataset['Type'] == 'Muffin'])[[xname, yname]]
    s = (dataset.loc[dataset['Type'] == 'Scone'])[[xname, yname]]

    plt.scatter(c.iloc[:, 0], c.iloc[:, 1], c='r')
    plt.scatter(m.iloc[:, 0], m.iloc[:, 1], c='b')
    plt.scatter(s.iloc[:, 0], s.iloc[:, 1], c='g')
    plt.xlabel(xname)
    plt.ylabel(yname)


# Read data
dataset = pd.read_csv('bakery.csv')

# Shuffle and reset index
dataset = dataset.sample(frac=1).reset_index(drop=True)

# Treating Y
# Encoding categorical data by adding dummy variables
Y = pd.get_dummies(dataset['Type']).values

# Treating X
X = dataset.iloc[:, 1:].values

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2)

# Fitting Multiple Linear Regression to the Training set
regressor = LinearRegression()
regressor.fit(X_train, Y_train)

# Plotting examples
plt.subplot(2, 2, 1)
plot_with(dataset, 'Flour', 'Milk')
plt.subplot(2, 2, 2)
plot_with(dataset, 'Butter', 'Milk')
plt.subplot(2, 2, 3)
plot_with(dataset, 'Milk', 'Sugar')
plt.subplot(2, 2, 4)
plot_with(dataset, 'Flour', 'Sugar')

plt.tight_layout()
plt.show()
