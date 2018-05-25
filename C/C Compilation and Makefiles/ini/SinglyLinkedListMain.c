/**
 * @file SinglyLinkedListMain.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 23/05/2018
 *
 * @brief Menu for Data Structures, containing Tests and Interactive Versions
 *
 */

#include "Core.h"

int SinglyLinkedListTests();

int main(int argc, char const *argv[])
{
	print_status_repr(DS_OK);
	SinglyLinkedListTests();

	printf("\n");
	
	return 0;
}