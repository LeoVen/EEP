#include <stdio.h>

void func()
{
    char array[10];
    gets(array);
}

int main(int argc, char **argv)
{
    func();
}