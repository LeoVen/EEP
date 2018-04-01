/*
 * CStackTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 31/03/2018
 *
 * Test Cases for Stack in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\CStack.h"

int CStackTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Stack               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CStack *stack;
	initCStack(&stack);

	int i;
	for (i = 0; i < 100; i++) {
		pushCStack(&stack, i);
	}

	displayCStack(&stack);

	printf("\n");
	return 0;
}