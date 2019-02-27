/**
 * @file swap.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/02/2019
 *
 * swap: a function that can swap two values.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define swap(A, B, T) \
    do                \
    {                 \
        T C = A;      \
        A = B;        \
        B = C;        \
    } while (0);

int main(void)
{
    int a = 123, b = 456;

    printf("A:%d B:%d\n", a, b);

    swap(a, b, int);

    printf("A:%d B:%d\n", a, b);

    printf("+------------+\n");

    double c = 6.3, d = 2.8;

    printf("%.2lf %.2lf\n", c, d);

    swap(c, d, double);

    printf("%.2lf %.2lf\n", c, d);

    printf("+------------+\n");

    const char *e = "Hello", *f = "World";

    printf("%s %s\n", e, f);

    swap(e, f, const char *);

    printf("%s %s\n", e, f);

    return 0;
}
