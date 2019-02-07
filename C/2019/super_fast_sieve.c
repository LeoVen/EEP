//https://stackoverflow.com/questions/18157322/find-the-sum-of-all-the-primes-below-two-million-project-euler-c
//https://ideone.com/2NRLTz
// Calculates the sum of prime numbers using bitarray
#include <stdio.h>
#include <string.h>

#define ISBITSET(x, i) ((x[i >> 3] & (1 << (i & 7))) != 0)
#define SETBIT(x, i) x[i >> 3] |= (1 << (i & 7));
#define CLEARBIT(x, i) x[i >> 3] &= (1 << (i & 7)) ^ 0xFF;

long long
sumPrimes(int n)
{
    int m = (n - 1) / 2;
    char b[m / 8 + 1];
    int i = 0;
    int p = 3;
    long long s = 2;
    int j;

    memset(b, 255, sizeof(b));

    while (p * p < n)
    {
        if (ISBITSET(b, i))
        {
            s += p;
            j = (p * p - 3) / 2;
            while (j < m)
            {
                CLEARBIT(b, j);
                j += p;
            }
        }
        i += 1;
        p += 2;
    }

    while (i < m)
    {
        if (ISBITSET(b, i))
        {
            s += p;
        }
        i += 1;
        p += 2;
    }

    return s;
}

int main(void)
{
    printf("%lld\n", sumPrimes(10000000));
    return 0;
}