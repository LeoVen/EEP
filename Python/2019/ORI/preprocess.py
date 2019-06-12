# preprocess.py
#
# 24/05/2019
#
# Preprocessing Dataset
#

# Preprocessing
# STEP 0 - Set up custom variables for preprocessing
# STEP 1 - Read Dataset
# STEP 2 - Set best fitting Row Spacing and Column Spacing
# STEP 3 - Encode integers and labels
# STEP 4 - Write Dataset

import argparse
import numpy as np
import pandas as pd

def encode(filename, output_file):
    """
    Encode function used specifically for the dataset located in MainDataCSV.csv
    """

    if output_file == 'MainData':
        print("Don't replace current dataset")
        return

    # STEP 0 - Custom variables
    # B - Base for row spacing power
    # M - minimum column spacing
    B = 10
    M = 100

    # STEP 1 - Read dataset
    df = pd.read_csv(filename)
    # The values of this dataset
    values = df.values

    # STEP 2 - Set best fitting Row Spacing and Column Spacing
    # RS = row spacing variable
    # CS = column spacing variable
    RS = np.array([1 for i in range(df.shape[1])])
    for i in range(values.shape[1] - 1):
        RS[i] = int(B ** len(str(min(x for x in values[:, i + 1] if x != 0))))

    CT = max(RS) * M

    # STEP 3 - Encode integers and labels
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

    # INSIGHT
    print("+--------------------------------------------------+")
    print("|          Preprocessing Insight (Example)         |")
    print("+--------------------------------------------------+")
    print(f"Rate        : {len(set(values.flatten()))/len(values.flatten())}")
    print(f"Proportion  : {len(values.flatten())/len(set(values.flatten()))}")
    print(f"Row Spacing : {RS}")
    print(f"Col Spacing : {CT}")

    np.savetxt(f"{output_file}.csv", values, delimiter=',', fmt='%d')

    return values

if __name__ == '__main__':
    
    parser = argparse.ArgumentParser()

    parser.add_argument('-o', '--output', type=str, required=True, dest='file',
                        help='Choose file output name (without file extension)')

    args = parser.parse_args()

    encode('MainData.csv', args.file)
