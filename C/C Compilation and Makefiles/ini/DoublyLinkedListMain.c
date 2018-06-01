/**
 * @file DoublyLinkedListMain.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Menu for Data Structures, containing Tests and Interactive Versions
 *
 */

#include "Core.h"

int DoublyLinkedListTests();

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	print_status_repr(DS_OK);
	DoublyLinkedListTests();

	printf("\n");

	return 0;
}