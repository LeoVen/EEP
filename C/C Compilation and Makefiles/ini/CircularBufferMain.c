/**
 * @file CircularBufferMain.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/05/2018
 *
 * @brief Menu for Data Structures containing all tests
 *
 */

#include "Core.h"

int CircularBufferTests();

int main(int argc, char const *argv[])
{
	print_status_repr(DS_OK);
	CircularBufferTests();

	printf("\n");

	return 0;
}
