/*
	Leonardo Vencovsky
	09/03/2018

    Utility functions

*/

#include <stdio.h>
#include <utility.h>

void println(const char *str)
{
    printf("\n%s", str);
}

void pause()
{
    printf("Press enter to continue...");
    fflush(stdin);
    getchar();
}