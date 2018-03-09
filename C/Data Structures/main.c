/*
	Leonardo Vencovsky
	09/03/2018

    Entry function
    Here you can test all structures

*/

#include <stdio.h>
#include <stdlib.h>
#include <SSLL.h>
#include <utility.h>

int main()
{


    return 0;
}

int * getArray(int size)
{
    int *p = malloc ( ( size + 0 ) * sizeof(int));

    int *arr = p;

    for (int i = 0; i < size; i++)
    {
        *p = 0;
        p++;
    }
    return arr;
}