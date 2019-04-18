#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_prime(size_t n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    size_t i;
    for (i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main(int argc, char *argv[])
{
    for (size_t i = 7; i < 64; i++)
    {
        size_t mid = (pow(2, i) + pow(2, i + 1)) / 2;
        size_t dif = 300;
        size_t least;

        for (size_t j = mid - 100; j < mid + 100; j++)
        {
            if (is_prime(j))
            {
                if (abs(mid - j) < dif)
                {
                    dif = abs(mid - j);
                    least = j;
                }
            }
        }

        printf("%llu : %llu\n", i, least);
    }
}