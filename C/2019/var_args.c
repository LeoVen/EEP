/**
 * @file var_args.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 05/02/2019
 *
 * Experimenting with <stdarg.h>
 *
 */

#include <stdio.h>
#include <stdarg.h>

double inner_sum(int arg_count, va_list args)
{
    double sum = 0.0;

    for (int i = 0; i < arg_count; i++)
    {
        sum += va_arg(args, double);
    }

    return sum;
}

double average(int arg_count, ...)
{
    va_list valist;

    va_start(valist, arg_count);

    double sum = inner_sum(arg_count, valist);

    va_end(valist);

    return sum / (double)arg_count;
}

int main(void)
{
    printf("Average: %lf\n", average(4, 8.5, 4.8, 9.1, 3.4));
    printf("Average: %lf\n", average(2, 5.0, 5.0));
    printf("Average: %lf\n", average(3, 10.0, 5.0, 7.5));

    return 0;
}