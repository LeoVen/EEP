/**
 * @file retif.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 21/02/2019
 *
 * ret_if: return if statement.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ret_if(C, R) \
    if (C)           \
        return R;

bool calc_chance(int sequence[], int length)
{
    for (int i = 0; i < length; i++)
    {
        ret_if(sequence[i] < 100, true);
    }

    return false;
}

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    int sequence[100];

    for (int i = 0; i < 100; i++)
    {
        sequence[i] = rand();
    }

    bool result = calc_chance(sequence, 100);

    printf("%s\n", result ? "Lucky" : "Unlucky");

    return 0;
}
