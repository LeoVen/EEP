# apriori.py
#
# 11/06/2019
#
# Apriori Algorithm
#

import argparse
from itertools import chain, combinations
from collections import defaultdict

# Apriori Algorithm
# STEP 1 - Create the superset of itemsets and a transaction_list
# STEP 2 - Filter the superset of itemsets based on minimum support
# STEP 3 - Generate n-itemsets until the resulting set is empty
# STEP 4 - Prepare the resulting itemsets
# STEP 5 - Calculate the confidence of rules


def apriori(values, min_support, min_metrics, sort):
    """
    Apriori algorithm given a matrix of values, the minimum support and the
    minimum confidence.

    Parameters
    ----------
        values : A matrix of values where an association rule is expected to be
                 found.
        min_support : A float value between (0, 1] for the minimum support of
                      an itemset.
        min_metrics : A tuple of type (min_conf, min_lift, min_lev, min_conv),
                      where :
                      - min_conf : The minimum confidence of a rule (X -> Y)
                      - min_lift : The minimum lift of a rule (X -> Y)
                      - min_lev  : The minimum leverage of a rule (X -> Y)
                      - min_conv : The minimum conviction of a rule (X -> Y)
        sort : An integer with the possible values :
               - 0 : Sort values by confidence
               - 1 : Sort values by lift
               - 2 : Sort values by leverage
               - 3 : Sort values by conviction

    Returns
    -------
    result_items : An array of structure [ [ itemset, support ], ...]
    result_rules : An array of structure [ [ X, Y, [ metrics ] ] , ... ]
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

    # STEP 1 - Create the superset of itemsets and a transaction_list
    transaction_list = list()  # each row in the csv
    item_set = set()           # superset of item_sets

    for row in values:
        transaction = frozenset(row)
        transaction_list.append(transaction)
        for item in transaction:
            # Here 1-itemSet is generated
            item_set.add(frozenset([item]))

    # STEP 2 - Filter the superset of itemsets based on minimum support
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

    # STEP 3 - Generate n-itemsets until the resulting set is empty
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

    # STEP 4 - Prepare the resulting itemsets
    # These itemsets have achieved the minimum required support
    result_items = []
    for key, value in large_map.items():
        result_items.extend([(tuple(item), support(item)) for item in value])

    # STEP 5 - Calculate the confidence of rules
    # Also add to the resulting_rules, those that have achieved the minimum
    # suport
    result_rules = []
    # For each n-itemset of itemsets
    for key, value in large_map.items():

        # For each itemset in the superset
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

                    # Calculate metrics
                    supp_x = support(subset)
                    supp_y = support(remain)
                    supp_union = support(itemset)
                    # conf(X -> Y) = supp(X union Y) / supp(X)
                    confidence = supp_union / supp_x
                    # lift(X -> Y) = supp(X union Y) / ( supp(X) * supp(Y) )
                    lift = supp_union / (supp_x * supp_y)
                    # leverage(X -> Y) = supp(X union Y) - supp(X) * supp(Y)
                    leverage = supp_union - (supp_x * supp_y)
                    # conv(X -> Y) = ( 1 - supp(Y) ) / ( 1 - conf(X -> Y) )
                    if confidence == 1.0:
                        conviction = 100.0
                    else:
                        conviction = (1.0 - supp_y) / (1.0 - confidence)

                    metrics = [confidence, lift, leverage, conviction]

                    # Compare if all the metrics attend the minimum
                    if len([0 for i in range(len(metrics)) if metrics[i] >= min_metrics[i]]) == len(metrics):
                        # If that rule achieved a minimum confidence or lift,
                        # save it as:
                        #    subset -> remain    [conf, lift, lev, conv]
                        metrics = [confidence, lift, leverage, conviction]

                        result_rules.append(
                            [tuple(subset), tuple(remain), tuple(metrics)])

    # result_items = [ [ itemset, support ], [ itemset, support ], ...]
    # result_rules = [ [ X, Y, [ metrics ] ] , [ X, Y, [ metrics ] ], ... ]
    return sorted(result_items, key=lambda x: -x[1]), sorted(result_rules, key=lambda x: -x[2][sort])


if __name__ == '__main__':

    metrics = ['confidence', 'lift', 'leverage', 'conviction']
    metric_map = {x: y for x, y in zip(metrics, range(len(metrics)))}

    parser = argparse.ArgumentParser(description='''
        Apriori is an algorithm for frequent item set mining and association
        rule learning over transactional databases. It proceeds by identifying
        the frequent individual items in the database and extending them to
        larger and larger item sets as long as those item sets appear
        sufficiently often in the database. The frequent item sets determined
        by Apriori can be used to determine association rules which highlight
        general trends in the database.

        Metrics

        Support
            Range : (0, 1]
            Support is the proportion of how many times an itemset appears in
            the transactions divided by the total amount of transactions.

            supp(X) : frequency(X) / total_transactions

        Confidence
            Range : (0, 1]
            Confidence of a rule (X -> Y) is the probability of finding the
            itemset Y in transactions where the itemset X is also present.

            conf(X -> Y) = supp(X union Y) / supp(X)

        Lift
            Range : (0, ∞)
            Lift of a rule (X -> Y) will also take into account the popularity
            of Y. The smaller the lift is, the more likely it is that the rule
            (X -> Y) is a coincidence due to Y appearing so many times.
                - A lift = 1 suggests there is no association
                - A lift > 1 suggests there is a positive correlation
                - A lift < 1 suggests there is a negative correlation

            lift(X -> Y) = supp(X union Y) / ( supp(X) * supp(Y) )

        Leverage
            Range : [-1, 1]
            Leverage computes the difference between the observed frequency of
            A and C appearing together and the frequency that would be expected
            if A and C were independent.
                - A leverage = 0 indicates independence.
                - A leverage > 0 indicates positive association
                - A leverage < 0 indicates negative association

            leverage(X -> Y) = supp(X union Y) - supp(X) * supp(Y)

        Conviction
            Range : (0, ∞)
            Conviction of a rule (X -> Y) shows the frequency that that it
            makes an incorrect prediction. A conviction of 1.2 shows that the
            rule (X -> Y) would be incorrect 20% more often if the association
            between X and Y was purely random chance.

            conv(X -> Y) = ( 1 - supp(Y) ) / ( 1 - conf(X -> Y) )

    ''', formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument('-s', '--support', type=float, default=0.15, dest='s',
                        help='The minimum support for an itemset to be considered (default 0.2)')
    parser.add_argument('-c', '--confidence', type=float, default=0.6, dest='c',
                        help='The minimum confidence for a rule to be considered (default 0.6)')
    parser.add_argument('-l', '--lift', type=float, default=1.0, dest='l',
                        help='The minimum lift for a rule to be considered (default 1.0)')
    parser.add_argument('-lv', '--leverage', type=float, default=0.05, dest='lv',
                        help='The minimum lift for a rule to be considered (default 0.05)')
    parser.add_argument('-cv', '--conviction', type=float, default=1.0, dest='cv',
                        help='The minimum conviction for a rule to be considered (default 1.0)')
    parser.add_argument('-sort', '--sort_by_metric', type=str,
                        default='confidence', dest='filter', choices=metrics,
                        help='Sort the values by a given metric')
    parser.add_argument('-f', '--file', type=str, required=True, dest='file',
                        help='Full file (e.g. data.csv) name containing a CSV')
    parser.add_argument('-d', '--decoder', type=str, required=False, dest='dec',
                        default='', help="""Specify the decoder file. It follows
                        two columns, the first as the key and the second as the
                        value, separated by ':'""")
    parser.add_argument('-hdr', '--header', dest='hdr', action='store_true',
                        help='''Wheather or not the specified csv contains a
                                header row''')
    parser.add_argument('-delim', '--delimeter', type=str, dest='d', default=',',
                        help='''Value delimeter''')
    args = parser.parse_args()

    # Retrieve minimum number for metrics
    # (confidence, lift, leverage, conviction)
    min_metrics = (args.c, args.l, args.lv, args.cv)

    # Load CSV data
    csv_data = []
    with open(args.file, 'r') as f:
        for line in f:
            csv_data.append(frozenset(x.strip()
                                      for x in line.rstrip().split(args.d)))

    # If header is present, skip it
    if args.hdr:
        csv_data = csv_data[1:]

    items, rules = apriori(csv_data, args.s, min_metrics,
                           metric_map[args.filter])

    print("\n+--------------------------------------------------+")
    print("| Apriori Algorithm Results                        |")
    print("+--------------------------------------------------+")
    print("| S  - Support     {:6.3f}                         |".format(args.s))
    print("| C  - Confidence  {:6.3f}                         |".format(args.c))
    print("| L  - Lift        {:6.3f}                         |".format(args.l))
    print("| LV - Leverage    {:6.3f}                         |".format(args.lv))
    print("| CV - Conviction  {:6.3f}                         |".format(args.cv))
    print("+--------------------------------------------------+")

    # Printing results
    if args.dec == '':
        # Prints result without decoder
        print("\n+--------------------------------------------------+")
        print("|                     ItemSets                     |")
        print("+--------------------------------------------------+")
        for item, support in items:
            print("Item S[{0:.4f}] : {1}".format(support, str(list(item))))

        print("\n+--------------------------------------------------+")
        print("|                      Rules                       |")
        print("+--------------------------------------------------+")
        for X, Y, metrics in rules:
            print("Rule [ C[{:8.4f}] L[{:8.4f}] LV[{:8.4f}] CV[{:8.4f}] ] : {} ----------> {}"
                  .format(metrics[0], metrics[1], metrics[2], metrics[3],
                          str(list(X)), str(list(Y))))
    else:
        # Print result with decoder
        dec = {}
        # First load it
        with open(args.dec, 'r') as f:
            for row in f:
                l = row.strip().split(':')
                dec[str(l[0]).strip()] = str(l[1]).strip()
        # Now print decoded results
        print("\n+--------------------------------------------------+")
        print("|                     ItemSets                     |")
        print("+--------------------------------------------------+")
        for item, support in items:
            print("Item S[{0:.4f}] : {1}".format(
                support, str(list(dec[x] for x in item))))

        print("\n+--------------------------------------------------+")
        print("|                      Rules                       |")
        print("+--------------------------------------------------+")
        for X, Y, metrics in rules:
            print("Rule [ C[{:8.4f}] L[{:8.4f}] LV[{:8.4f}] CV[{:8.4f}] ] : {} ----------> {}"
                  .format(metrics[0], metrics[1], metrics[2], metrics[3],
                          str(list(dec[a] for a in X)), str(list(dec[b] for b in Y))))
