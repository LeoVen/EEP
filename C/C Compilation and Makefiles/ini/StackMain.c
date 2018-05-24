/**
 * @file DataStructuresMenu.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Menu for Data Structures containing all tests
 *
 */

#include "Core.h"

int StackTests();

int main(int argc, char const *argv[])
{
	print_status_repr(DS_OK);
	StackTests();

	printf("\n");

	return 0;
}
