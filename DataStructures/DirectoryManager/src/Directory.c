/*
 * Directory.c
 *
 * EEP
 *
 * Created on 27/03/2018
 * by Leonardo Vencovsky 201710276
 * by Guilherme Pinazza  201710351
 * by Vitor Facioli      201710292
 *
 * Last modified by Leonardo Vencovsky
 *
 * Directory Structure implementations for Directory Manager Project
 *
 * Compiled in Visual Studio 2017
 *
 */

// For Visual Studio (strcpy)
#pragma warning(disable : 4996)

#include "..\include\Directory.h"
#include "..\include\StringHandler.h"

Directory * getDirectoryByName(char *name)
{
	Directory *dir = (Directory *)malloc(sizeof(Directory));
	dir->parent = NULL;
	dir->list = NULL;
	dir->next = NULL;
	changeDirName(dir, name);
	return dir;
}

void changeDirName(Directory *dir, char *name)
{
	dir->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
	strcpy(dir->name, name);
}

int makeDirectory(Directory **current, char *name)
{
	Directory *curr = *current;
	Directory *newDir = (Directory *)malloc(sizeof(Directory));
	changeDirName(newDir, name);
	newDir->list = NULL;
	newDir->parent = curr;
	newDir->next = curr->list;
	curr->list = newDir;
}

int listDirectory(Directory **current)
{
	Directory *curr = *current;
	Directory *head = curr->list;
	while (head != NULL)
	{
		printf(" %s\t", head->name);
		head = head->next;
	}
	return 0;
}
bool dirExists(Directory *curr, char *param)
{
	Directory *scanner = curr->list;
	while (scanner != NULL)
	{
		if (hashCode(param) == hashCode(scanner->name))
			return true;
		scanner = scanner->next;
	}
	return false;
}

int changeDirectory(Directory **curr, char *param)
{
	if (dirExists((*curr), param)) {
		Directory *scanner = (*curr)->list;
		while (scanner != NULL)
		{
			if (hashCode(scanner->name) == hashCode(param)) {
				(*curr) = scanner;
				break;
			}
		}
	}
	else
		printf("No such directory\n");
	return 0;
}

int changeToParent(Directory **curr)
{
	if ((*curr)->parent != NULL)
		(*curr) = (*curr)->parent;
}

int printWorkingDirectory(Directory *curr)
{
	Directory *scanner = curr;
	// TODO strcat at beggining of string
	char *buffer = NULL;
	char *str = NULL;
	while (scanner != NULL)
	{
		if (!str) {
			buffer = malloc(sizeof(char) * strlen(scanner->name) + 1);
			strcpy(buffer, scanner->name);
			str = buffer;
		}
		else {
			str = strcat_head(str, scanner->name);
			str = strcat_head(str, "/");
		}
		scanner = scanner->parent;
	}
	if (str != NULL)
		printf("%s\n", str);
	return 0;
}