#include <stdio.h>

int main(int argc, char const *argv[])
{
    int sum = 0;
    for (int i = 0; i < 1000; i++)
        sum += i * i;

    // Forces non-empty assembly output
    printf("%d", sum); // 332833500

    return 0;
}