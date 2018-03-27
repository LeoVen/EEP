/*
* Directory.h
*
* EEP
*
* Created on 27/03/2018
* by Leonardo Vencovsky
*
* Last modified on 27/03/2018
* by Leonardo Vencovsky
*
* Header for Directory Structure implementations
*
* Compiled in Visual Studio 2017
*
*/

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stdio.h>
#include <string.h>

typedef struct Directory {
	char *name;
} Directory;

Directory * getDirectoryByName(char *name);

#endif