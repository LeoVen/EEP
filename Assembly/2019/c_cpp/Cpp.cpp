#include <stdio.h>

void no_res(int &x, int &y, int &z)
{
    x += z;
    y += z;
}

int main(int argc, char const *argv[])
{
    int a = 1, b = 2, c = 3;

    no_res(a, b, c);

    return 0;
}