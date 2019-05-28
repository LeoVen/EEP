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
import itertools

# STEP 0 - Custom variables
# B - Base for row spacing power
# M - minimum column spacing
B = 10
M = 100
# MS - Minimum Support
# MC - Minimum Confidence
MS = 40
MC = 0.5

# STEP 1 - Read dataset
df = pd.read_csv('MainDataCSV.csv')
# The values of this dataset
values = df.values

# STEP 2 - Best fitting encoding variables
# RS = row spacing variable
# CS = column spacing variable
RS = np.array([1 for i in range(df.shape[1])])
for i in range(values.shape[1] - 1):
    RS[i] = int(B ** len(str(min(x for x in values[:, i + 1] if x != 0))))

CT = max(RS) * M

# STEP 3 - Encoding
# Encoding integers
for i in range(len(values.T) - 1):
    values[:, i + 1] = (values[:, i + 1] // RS[i]) + (i + 1) * int(CT)
# Encoding labels
# Create a mapping between labels and numbers
# fit
labels = {}
for i, label in enumerate(values.T[0]):
    labels[label] = i
# transform
for i in range(values.shape[0]):
    values[i, 0] = labels[values[i, 0]]
# Dataset is ready

# STEP 4 - Apriori

# INSIGHT
print(f"Rate           : {len(set(values.flatten())) / len(values.flatten())}")
print(f"Proportion     : {len(values.flatten()) / len(set(values.flatten()))}")
print(f"Row Spacing    : {RS}")
print(f"Column Spacing : {CT}")

# np.savetxt('out.csv', values, delimiter=',', fmt='%d')
