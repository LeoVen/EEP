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
	
	removeHeadSLL(&csll);
	insertTailSLL(&csll, -1);
	// removeTailSLL(&csll);
	insertHeadSLL(&csll, 3);
	insertHeadSLL(&csll, 2);
	insertHeadSLL(&csll, 1);
	insertHeadSLL(&csll, 0);
	insertTailSLL(&csll, 4);
	insertTailSLL(&csll, 5);
	insertTailSLL(&csll, 7);
	insertTailSLL(&csll, 8);
	insertTailSLL(&csll, 9);

	displayListSLL(&csll);
	printf("\nSize: %d\n", getListSizeSLL(&csll));

	removeHeadSLL(&csll);
	removeTailSLL(&csll);
	removeTailSLL(&csll);
	removeMiddleSLL(&csll, 3);

	insertMiddleSLL(&csll, 6, 5);

	displayListSLL(&csll);
	printf("\nSize: %d\n", getListSizeSLL(&csll));

	removeTailSLL(&csll);
	removeTailSLL(&csll);
	removeTailSLL(&csll);

	printf("\nSize: %d\n", getListSizeSLL(&csll));
	displayListSLL(&csll);

	printf("\n---------- ---------- C List Deleted ---------- ----------\n");
	deleteListSLL(&csll);
	int i;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		insertTailSLL(&csll, rand() % 10); // Numbers from 0 to 9
	}
	for (i = 0; i < 10; i++) {
		printf("\nThere are %3d number %d in the list", searchValueSLL(&csll, i), i);
	}

	CSinglyLinkedList *list = getCSinglyLinkedList();
	for (i = 0; i < 10; i++) {
		insertTailSLL(&list, i);
	}
	printf("\n---------- ---------- Reverse List ---------- ----------\n");
	displayListSLL(&list);
	reverseListSLL(&list);

	printf("\n");
	//
	// 
	free(csll);
	return 0;
}