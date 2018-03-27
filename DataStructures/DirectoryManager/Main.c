/*
* Main.c
*
* EEP
*
* Created on 27/03/2018
* by Leonardo Vencovsky
*
* Last modified on 27/03/2018
* by Leonardo Vencovsky
*
* Main entrance point to project
*
* Compiled in Visual Studio 2017
*
*/

#include <stdio.h>
#include "include\Directory.h"

int main()
{
	char *name = "Hello world";
	Directory *dir = getDirectoryByName(name);

	printf("\nDir Name: %s\n", dir->name);

	printf("\nHello World");
	printf("\n");
	return 0;
}

