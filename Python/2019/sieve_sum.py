# https://github.com/ilanschnell/bitarray
from bitarray import bitarray


def sumPrimes(n):
    sum = 0
    sieve = bitarray([True] * (n+1))
    for p in range(2, n):
        if sieve[p]:
            sum += p
            for i in range(p*p, n, p):
                sieve[i] = False
    return sum


if __name__ == '__main__':

    print(sumPrimes(100000000))
