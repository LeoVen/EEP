/*
 * SinglyLinkedListTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 14/03/2018
 *
 * Test Cases for Singly Linked Lists in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\CSinglyLinkedList.h"

int CSinglyLinkedListTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Singly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CSinglyLinkedList *csll = (CSinglyLinkedList *) malloc (sizeof(CSinglyLinkedList));
	initListSLL(&csll);
	if (csll->size == 0) {
		printf("\n YAY! It's Working!\n");
	}
	insertTailSLL(&csll, -1);
	insertHeadSLL(&csll, 3);
	insertHeadSLL(&csll, 2);
	insertHeadSLL(&csll, 1);
	insertHeadSLL(&csll, 0);
	insertTailSLL(&csll, 4);
	insertTailSLL(&csll, 5);
	insertTailSLL(&csll, 6);
	displayListSLL(csll);

	return 0;
}