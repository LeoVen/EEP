import numpy as np
from math import e

def simpson(f, lower, upper, n=100):
    x = np.linspace(lower, upper, n+1)
    return (x[1] - x[0]) / 3 * (f(x[0]) + 4 * sum(f(x[1:-1:2])) + 2 * sum(f(x[2:-1:2])) + f(x[-1]))

def newton_cotes(f, lower, upper, n):
    x = np.linspace(lower, upper, n+1)
    return (x[1] - x[0]) / 2 * ( f(x[0]) + 2 * sum(f(x[1:-1])) + f(x[-1]) )

def f(x):
    return e ** x

print(simpson(f, 0, 1, 10))
print(newton_cotes(f, 0, 1, 10))
