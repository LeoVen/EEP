import numpy as np
from math import log, e


def integrate(F, n0, nf):
    return sum([F(x)*(abs(nf-n0)/(abs(nf-n0)*300))for x in np.linspace(n0, nf, abs(nf-n0)*300)])


def integral(function, n=1000, start=0, stop=100):
    return (float(stop-start)/n) * sum([eval(function) for x in [start+(i*float(stop-start)/n) for i in range(n)]])


def main():

    # Examples:
    r0 = integrate(lambda x: log(x), 1, 1000)
    r1 = integral('log(x)', start=1, stop=1000)

    r2 = integrate(lambda x: x**2 - 2*x + 10, -100, 100)
    r3 = integral('x**2 - 2*x + 10', start=-100, stop=100)

    print(r0)
    print(r1)

    print("----------------------------------------")

    print(r2)
    print(r3)


if __name__ == '__main__':
    main()
