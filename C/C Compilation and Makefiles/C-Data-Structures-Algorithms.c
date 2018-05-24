/**
 * @file DataStructuresMenu.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 24/05/2018
 *
 * @brief Entrance point
 */

#include "Core.h"
#include "DataStructuresTests.h"

int main(int argc, char const *argv[])
{
	print_status_repr(DS_OK);
    SinglyLinkedListTests();
	DoublyLinkedListTests();
    StackTests();

	printf("\n");
	
	return 0;
}