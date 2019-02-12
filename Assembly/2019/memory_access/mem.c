#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *i = malloc(sizeof(int));

    *i = 128;

    // Forces non-empty assembly output
    printf("%d", *i);

    free(i);

    return 0;
}
