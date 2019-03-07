# #
# root.py
#
# Leonardo Vencovsky (https://github.com/LeoVen)
#
# 07/03/2019
#
# Bisection method to find the root of a continuous function
# #
def f(x):
    '''
    Function used in this example.
    '''
    return x ** 3 - 9 * x + 3


def find_root(F, low, high, iter=1000):
    '''
    Find root of continuous function where F(low) and F(high) have opposite signs:
        F(low) < 0 and F(high) > 0 or F(low) > 0 and F(high) < 0.
    '''

    if F(low) * F(high) > 0:
        return 0.0

    for _ in range(0, iter):
        mid = (low + high) / 2.0
        if F(low) * F(mid) > 0:
            low = mid
        else:
            high = mid

    return mid


def main():
    print(find_root(f, -4, -3))
    print(find_root(f, 0, 1))
    print(find_root(f, 2, 3))


if __name__ == '__main__':
    main()
