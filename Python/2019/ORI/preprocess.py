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
# STEP 4 - Write encoded dataset
# STEP 5 - Save decoder dataset

import argparse
import numpy as np
import pandas as pd
from collections import defaultdict


def encode(filename, output_file, decoder_file, b, min_col, max_row, min_row, cols):
    """
    Encode function used specifically for the dataset located in MainDataCSV.csv
    """

    if output_file == 'MainData':
        print("Don't replace current dataset")
        return

    # Decode dictionary
    # The decoder will not be able to reverse back to the original value since
    # it was first encoded using a range, but it should give a good approximation
    # on what the value was like (using the mean of all values that fell into
    # the encoded category)
    decoder = defaultdict(int)

    # STEP 0 - Custom variables
    # B - Base for row spacing power
    B = b
    # MINC - minimum column spacing
    MINC = min_col
    # MAXR - maximum row spacing
    MAXR = B * max_row
    # MINR - minimum row spacing
    MINR = B * min_row

    # STEP 1 - Read dataset
    df = pd.read_csv(filename)
    # The values of this dataset
    values = df.values[:, cols]

    # STEP 2 - Set best fitting Row Spacing and Column Spacing
    # RS = row spacing variable
    # CS = column spacing variable
    RS = [1 for i in range(df.shape[1])]
    # Skip first column
    for i in range(1, values.shape[1]):
        RS[i] = int(B ** len(str(min(x for x in values[:, i] if x != 0))))
        if RS[i] > MAXR:
            RS[i] = MAXR
        if RS[i] < MINR:
            RS[i] = MINR

    CS = max(RS) * MINC

    # STEP 3 - Encode integers and labels
    # Encoding integers
    for i, column in enumerate(values.T):

        if i == 0:
            # Skip first column containing labels
            continue

        for j in range(len(column)):
            encoded_value = (values[j, i] // RS[i]) + i * int(CS)
            # Save current value to decoder based on the average of current
            # values
            if decoder[encoded_value] == 0:
                # If the value was not calculated yet, simply update it with
                # the first value
                decoder[encoded_value] = [df.columns[i].strip(), values[j, i]]
            else:
                # Shouldn't happen
                if (decoder[encoded_value][0] != df.columns[i].strip()):
                    raise Exception(f"Overlapping columns")

                # If a value is already present, take their mean
                decoder[encoded_value] = [df.columns[i].strip(
                ), (decoder[encoded_value][1] + values[j, i]) // 2]

            # Apply encoded value
            values[j, i] = encoded_value

    # Encoding labels
    # Create a mapping between labels and numbers
    # fit
    labels = {}
    for i, label in enumerate(values.T[0]):
        labels[label] = i
        decoder[i] = label
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
    print(f"Col Spacing : {CS}")

    # STEP 4 - Write encoded dataset
    np.savetxt(output_file, values, delimiter=',', fmt='%d')

    # STEP 5 - Save decoder dataset
    with open(decoder_file, "w") as f:
        for key, value in decoder.items():
            print(f"{key} : {value[0]}-{value[1]}", file=f)

    return values


if __name__ == '__main__':

    parser = argparse.ArgumentParser()

    parser.add_argument('-o', '--output', type=str, required=True, dest='file',
                        help='Choose file output name')
    parser.add_argument('-d', '--decoder', type=str, required=True, dest='dec',
                        help='''Specify the decoder file. It follows two columns,
                        the first as the key and the second as the value,
                        separated by \':\'''')
    parser.add_argument('-b', '--base', type=int, default=10, dest='b',
                        help='''Base of row spacing power''')
    parser.add_argument('-col', '--min_col_sep', type=int, default=100000,
                        dest='col', help='''Minimum column separator''')
    parser.add_argument('-rmax', '--max_row_sep', type=int, default=10, dest='rmax',
                        help='''Maximum row separator. Resulting row separator is
                        given by rmax * b''')
    parser.add_argument('-rmin', '--min_row_sep', type=int, default=1, dest='rmin',
                        help='''Minimum row separator. Resulting row separator is
                        given by rmin * b''')
    parser.add_argument('-cols', nargs='+', type=int, dest='cols',
                        default=[x for x in range(14)], help='''Columns to be
                                                                accepted (from
                                                                range [0-13])''')

    args = parser.parse_args()

    encode('MainData.csv', args.file, args.dec, args.b, args.col, args.rmax, args.rmin, args.cols)
