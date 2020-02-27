# -*- coding: utf-8 -*-

def word_frequency(filepath, title=None, N=10, R1=0, R2=10):

    with open(filepath, encoding="utf8") as file:
        data = file.read().lower()

    from nltk.tokenize import RegexpTokenizer

    tokenizer = RegexpTokenizer(r'\w+')
    tokens = tokenizer.tokenize(data)

    from collections import Counter

    counter = Counter(tokens)

    result_list = counter.most_common(N)
    result_list = result_list[R1:R2]

    x = [nth[0] for nth in result_list]
    y = [nth[1] for nth in result_list]

    import matplotlib.pyplot as plt

    plt.bar(x, height=y)
    plt.ylabel('Word Frequency')
    plt.title(title)
    plt.show()


if __name__ == '__main__':
    word_frequency('ex.txt', title='Example')
