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

#include "include\Directory.h"

// Change if on linux / windows
// #define CLEAR_SCREEN "clear"
#define CLEAR_SCREEN "cls"

/* Functions that prints first menu
 *
 * @Returns [ void ]
 */
void printMenu();

/* Functions that prints help menu
 *
 * @Returns [ void ]
 */
void printHelpMenu();

/* Function that gets user input and separates it to commands and arguments
 *
 * @Param [ Directory *current ] Current working directory
 *
 * @Returns [ bool ] breaks loop if command is exit
 */
bool getUserInput(Directory *current);

/* Function that gets user input and returns how many spaces are in the string
*
* @Param [ char *userInput ] User input string
*
* @Returns [ int ] How many spaces
*/
int checkUserInput(char *userInput);

/* Command switch
 *
 * @Param [ Directory **current ] Current working directory
 * @Param [ char *command ] Command string
 * @Param [ char *parameter ] Parameter string
 *
 * @Returns [ bool ] breaks loop if command is exit
 */
bool switchCommand(Directory **current, char *command, char *parameter);

/* Returns an integer that represents its hashcode for string comparison
 *
 * @Param [ char *command ] String to get hashcode
 *
 * @Returns [ int ] a number equivalent for a string
 */
int hashCode(char *command);

/* Prints a line
 *
 * @Param [ const char *str ] String to be printed
 *
 * @Returns [ int ] a number equivalent for a string
 */
void println(const char *str);

int main()
{
	printMenu();
	Directory *root = getDirectoryByName("/");
	Directory *curr = root;
	
	while (getUserInput(curr))
	{

	}

	/*
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
	*/

	printf("\n");
	return 0;
}

void printMenu()
{
	println(" ");
	println(" +-------------------------------------------------------------------+");
	println(" |                                                                   |");
	println(" |                         Directory Manager                         |");
	println(" |                                                                   |");
	println(" |  Created By:                                                      |");
	println(" |                                                                   |");
	println(" |  Guilherme Pinazza                                                |");
	println(" |  Leonardo Vencovsky                                               |");
	println(" |  Vitor Facioli                                                    |");
	println(" |                                                                   |");
	println(" +-------------------------------------------------------------------+");
	println(" ");

	println("Enter 'help' to see command list\n");
}

bool getUserInput(Directory *current)
{
	println("$ ");
	char *userInput = (char *)malloc(sizeof(char) * MAX_DIRNAME_SIZE);
	fgets(userInput, MAX_DIRNAME_SIZE, stdin);
	int sp = checkUserInput(userInput);
	char *next, *command, *param;
	if (sp == 0) {
		println("one commad");
		// Only one command
		command = strtok_s(userInput, "\0", &next);
		printf("\nSize: %d", strlen(command));
		param = NULL;
		return switchCommand(&current, command, param);
	}
	else if (sp == 1) {
		println("more than one commad");
		command = strtok_s(userInput, " ", &next);
		printf("\nSize: %d", strlen(command));
		param = strtok_s(NULL, "\0", &next);
		return switchCommand(&current, command, param);
	}
	else {
		println("more than two commands");
	}
}

bool switchCommand(Directory **current, char *command, char *parameter)
{
	int hash = hashCode(command);
	if (hash == hashCode("mkdir") && parameter != NULL) {
		makeDirectory(current, parameter);
	}
	else if (hash == hashCode("ls")) {
		listDirectory(current);
	}
	else if (hash == hashCode(CLEAR_SCREEN)) {
		system(CLEAR_SCREEN);
	}
	else if (hash == hashCode("help")) {
		printHelpMenu();
	}
	else if (hash == hashCode("exit")) {
		return false;
	}
	else {
		println("No such command. Enter 'help' to see command list");
	}
	return true;
}

int hashCode(char *command)
{
	int i, hash = 0;
	for (i = 0; i < strlen(command); i++) {
		hash += command[i] * i;
	}
	return hash;
}

void printHelpMenu()
{
	println("HelpMenu");
}

void println(const char *str)
{
	printf("\n%s", str);
}

int checkUserInput(char *userInput)
{
	int i, sp = 0;
	for (i = 0; i < strlen(userInput); i++) {
		// Space
		if (userInput[i] == 32)
			sp++;
	}
	return sp;
}