# apriori.py
#
# 24/05/2019
#
# Apriori Algorithm
#

import numpy as np
import pandas as pd
import argparse
from itertools import chain, combinations
from collections import defaultdict

# Preprocessing
# STEP 0 - Set up custom variables for preprocessing
# STEP 1 - Read Dataset
# STEP 2 - Set best fitting Row Spacing and Column Spacing
# STEP 3 - Encode integers and labels
# STEP 4 - Write Dataset

# Apriori Algorithm
# STEP 5 - Create the superset of itemsets and a transaction_list
# STEP 6 - Filter the superset of itemsets based on minimum support
# STEP 7 - Generate n-itemsets until the resulting set is empty
# STEP 8 - Prepare the resulting itemsets
# STEP 9 - Calculate the confidence of rules


def encode(filename, encoded_file_name):
    """
    Encode function used specifically for the dataset located in MainDataCSV.csv
    """
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

    if encoded_file_name != '':
        np.savetxt(f"{encoded_file_name}.csv", values, delimiter=',', fmt='%d')

    return values


def apriori(values, min_support, min_confidence):
    """
    Apriori algorithm given a matrix of values, the minimum support and the
    minimum confidence.
    """

    # Internal Functions
    # - filter_item_sets - Filter the itemsets with less than the minimum support
    # - subsets - Generates a powerset of an itemset
    # - support - Calculates the support of a given itemset
    def filter_item_sets(item_set, transaction_list, freq_map, min_support):
        """
        Calculates the support for each item in the item_set and returns a
        subset of the item_set where each element satisfies the minimum support
        """
        result_set = set()
        local_map = defaultdict(int)

        # For each itemset in the superset of itemsets, check if they are a
        # subset of a transaction, counting the frequency of that itemset
        for item in item_set:
            for transaction in transaction_list:
                if item.issubset(transaction):
                    freq_map[item] += 1
                    local_map[item] += 1

        # Only add to the result_set the itemsets that have achieved the
        # minimum support required
        for item, count in local_map.items():
            item_support = float(count) / len(transaction_list)

            if item_support >= min_support:
                result_set.add(item)

        return result_set

    def subsets(arr):
        """
        Returns the non-empty subsets of an itemset (the powerset)
        """
        return chain(*[combinations(arr, i + 1) for i, _ in enumerate(arr)])

    def support(item):
        """
        Calculates the support of a given item using the variables freq_set and
        transaction_list
        """
        return float(freq_map[item]) / len(transaction_list)

    # STEP 5 - Create the superset of itemsets and a transaction_list
    transaction_list = list()  # each row in the csv
    item_set = set()           # superset of item_sets

    for row in values:
        transaction = frozenset(row)
        transaction_list.append(transaction)
        for item in transaction:
            # Here 1-itemSet is generated
            item_set.add(frozenset([item]))

    # STEP 6 - Filter the superset of itemsets based on minimum support
    # Frequency mapping an itemset to its frequency (with default value of 0)
    freq_map = defaultdict(int)
    # Map that keeps track of (n-item_sets : support)
    large_map = dict()

    # Create 1-item_set first
    # This will also update freq_map
    one_item_set = filter_item_sets(item_set,
                                    transaction_list,
                                    freq_map,
                                    min_support)

    # STEP 7 - Generate n-itemsets until the resulting set is empty
    current_set = one_item_set
    n = 2
    while current_set != set([]):
        # Save current superset
        large_map[n - 1] = current_set
        # Combination of sets n by n
        current_set = set(i.union(j)
                          for i in current_set
                          for j in current_set
                          if len(i.union(j)) == n)
        # Filter the current set given the minimum support
        current_new_set = filter_item_sets(current_set,
                                           transaction_list,
                                           freq_map,
                                           min_support)
        # Next n by n itemsets
        current_set = current_new_set
        n += 1

    # STEP 8 - Prepare the resulting itemsets
    # These itemsets have achieved the minimum required support
    result_items = []
    for key, value in large_map.items():
        result_items.extend([(tuple(item), support(item)) for item in value])

    # STEP 9 - Calculate the confidence of rules
    # Also add to the resulting_rules, those that have achieved the minimum
    # suport
    result_rules = []
    for key, value in large_map.items():
        for itemset in value:
            # Generate all possible subsets from the given itemset that
            # achieved the minimum support
            powerset = map(frozenset, [x for x in subsets(itemset)])
            for subset in powerset:
                # For each generated subset, calculate the difference between
                # the original and its subsets
                # This is done so we can calculate:
                #     subset -> remain
                remain = itemset.difference(subset)
                if len(remain) > 0:
                    confidence = support(itemset) / support(subset)
                    if confidence >= min_confidence:
                        # If that rule achieved a minimum support, save it as:
                        #    subset -> remain    (confidence)
                        result_rules.append(
                            ((tuple(subset), tuple(remain)), confidence))

    return result_items, result_rules


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='''
        Apriori is an algorithm for frequent item set mining and association
        rule learning over transactional databases. It proceeds by identifying
        the frequent individual items in the database and extending them to
        larger and larger item sets as long as those item sets appear
        sufficiently often in the database. The frequent item sets determined
        by Apriori can be used to determine association rules which highlight
        general trends in the database.
    ''')
    parser.add_argument('-s', '--support', type=float, default=0.15, dest='s',
                        help='The minimum support for an itemset to be considered')
    parser.add_argument('-c', '--confidence', type=float, default=0.6, dest='c',
                        help='The minimum confidence for a rule to be considered')
    parser.add_argument('-f', '--file', type=str, default='example0.csv',
                        dest='file', help='Filename containing a CSV')
    parser.add_argument('-o', '--output', type=str, default='', required=False,
                        dest='out', help='''When running with the example0.csv,
                                            specify the file name if you wish
                                            to save the encoded data to a file''')
    parser.add_argument('-hdr', '--header', dest='h', action='store_true',
                        help='''Wheather or not the specified csv contains a
                                header row''')
    args = parser.parse_args()

    if (args.file == 'example0.csv'):
        items, rules = apriori(encode(args.file, args.out), args.s, args.c)
    else:
        values = list()
        if args.h:
            df = pd.read_csv(args.file).values
        else:
            df = pd.read_csv(args.file, header=None).values
        for row in df:
            # x == x doesn't work for NaN
            values.append(list(filter(lambda x: x == x, list(row))))
        items, rules = apriori(values, args.s, args.c)

    # Printing results
    print("\n+--------------------------------------------------+")
    print("|                     ItemSets                     |")
    print("+--------------------------------------------------+")
    for item, support in sorted(items, key=lambda x: -x[1]):
        print("Item [{0:.4f}] : {1}".format(support, str(list(item))))

    print("\n+--------------------------------------------------+")
    print("|                      Rules                       |")
    print("+--------------------------------------------------+")
    for rule, confidence in sorted(rules, key=lambda x: -x[1]):
        print("Rule [{0:.4f}] : {1} ----------> {2}"
              .format(confidence, str(list(rule[0])), str(list(rule[1]))))
