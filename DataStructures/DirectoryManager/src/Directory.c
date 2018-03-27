/*
* Directory.c
*
* EEP
*
* Created on 27/03/2018
* by Leonardo Vencovsky
*
* Last modified on 27/03/2018
* by Leonardo Vencovsky
*
* Directory Structure implementations for Directory Manager Project
*
* Compiled in Visual Studio 2017
*
*/

#include "..\include\Directory.h"

Directory * getDirectoryByName(char *name)
{
	Directory *dir = (Directory *)malloc(sizeof(Directory));
	dir->name = " ";
	dir->name = name;
	return dir;
}