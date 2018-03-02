import itertools

def erat2( ):
    D = {  }
    yield 2
    for q in itertools.islice(itertools.count(3), 0, None, 2):
        p = D.pop(q, None)
        if p is None:
            D[q*q] = q
            yield q
        else:
            x = p + q
            while x in D or not (x&1):
                x += p
            D[x] = p


def get_primes_erat(n):
  return list(itertools.takewhile(lambda p: p<n, erat2()))

def nthPrimeUpTo(n):
    return len(get_primes_erat(n))

def main():
    print('Fast way to get prime numbers up to N')
    n = int(input())
    print('Length of vector return by function (all prime numbers) :')
    print(len(get_primes_erat(n)))

if __name__ == '__main__':
    main()
