# main.py
#
# 24/05/2019
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# Apriori Algorithm
#
import numpy as np
import pandas as pd

# Encoding ##########
# Custom parameters
S = 100
T = 1e7 // S

df = pd.read_csv('MainDataCSV.csv')

values = df.values

# Encode, step 1
for i in range(len(values.T) - 1):
    values[:, i + 1] = values[:, i + 1] // S

offset = values.shape[0]

# Encode, step 2
for i in range(len(values.T) - 1):
    values[:, i + 1] += (i + 1) * int(T) + offset

# Create a mapping between labels and numbers
# fit
labels = {}
for i, label in enumerate(values.T[0]):
    labels[label] = i
# transform
for i in range(values.shape[0]):
    values[i, 0] = labels[values[i, 0]]

# Dataset is ready
# Encoding ##########

print(f"Rate : {len(set(values.flatten())) / len(values.flatten())}")
