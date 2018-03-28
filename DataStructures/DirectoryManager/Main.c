/*
* Main.c
*
* EEP
*
* Created on 27/03/2018
* by Leonardo Vencovsky 201710276
* by Guilherme Pinazza  201710351
* by Vitor Facioli      201710292
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
#include <stdlib.h>
#include "include\Directory.h"

// #define CLEAR_SCREEN "clear"
#define CLEAR_SCREEN "cls"

void printMenu();
void getUserInput();

int main()
{
	printMenu();
	getUserInput();
	Directory *root = getDirectoryByName("/");
	Directory *curr = root;
	printf("\nName: %s", root->name);

	makeDirectory(&curr, "vitao");
	makeDirectory(&curr, "igor");
	makeDirectory(&curr, "yan");
	makeDirectory(&curr, "leonardo");

	listDirectory(&curr);

	curr = curr->list; // change dir

	makeDirectory(&curr, "vitao_02");
	makeDirectory(&curr, "yan_0");

	listDirectory(&curr);

	curr = curr->list; // change dir

	makeDirectory(&curr, "igor_03");
	makeDirectory(&curr, "images_02");
	makeDirectory(&curr, "videos_3");

	listDirectory(&curr);

	curr = curr->parent->parent;

	listDirectory(&curr);

	printf("\n");
	return 0;
}

void printMenu()
{
	printf("\n");
	printf(" +-------------------------------------------------------------------+\n");
	printf(" |                                                                   |\n");
	printf(" |                         Directory Manager                         |\n");
	printf(" |                                                                   |\n");
	printf(" |  Created By:                                                      |\n");
	printf(" |                                                                   |\n");
	printf(" |  Guilherme Pinazza                                                |\n");
	printf(" |  Leonardo Vencovsky                                               |\n");
	printf(" |  Vitor Facioli                                                    |\n");
	printf(" |                                                                   |\n");
	printf(" +-------------------------------------------------------------------+\n");
	printf("\n");

	printf("Enter 'help' to see command list\n");
}

void getUserInput()
{
	printf("\n$ ");
	char *userInput = (char *)malloc(sizeof(char) * MAX_DIRNAME_SIZE);
	fgets(userInput, MAX_DIRNAME_SIZE, stdin);
	char *next;
	char *command = strtok_s(userInput, " ", &next);
	printf("\nComando: %s", command);
	char *param = strtok_s(NULL, "\0", &next);
	printf("\nParam: %s", param);
}