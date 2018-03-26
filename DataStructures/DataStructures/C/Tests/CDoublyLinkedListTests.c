/*
 * DoublyLinkedListTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Test Cases for Doubly Linked Lists in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\CDoublyLinkedList.h"

int CDoublyLinkedListTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Doubly Linked List        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CDoublyLinkedList *dll = getCDoublyLinkedList();

	CDoublyLinkedNode *node = getCDoublyLinkedNode(2);
	int i;
	for (i = 0; i < 10; i++) {
		insertTailDLL(&dll, i);
	}
	for (i = 0; i < 10; i++) {
		insertHeadDLL(&dll, i);
	}

	displayListDLL(&dll);

	for (i = 0; 0 < getListSizeDLL(&dll); i++) {
		removeTailDLL(&dll);
	}

	for (i = 0; 0 < getListSizeDLL(&dll); i++) {
		removeHeadDLL(&dll);
	}

	displayListDLL(&dll);

	free(dll);
	printf("\n");
	return 0;
}