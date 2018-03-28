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
	printf("\n---------- ---------- C List New Ones ---------- ----------\n");
	deleteListSLL(&csll);
	int i;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		insertTailSLL(&csll, rand() % 10); // Numbers from 0 to 9
	}
	for (i = 0; i < 10; i++) {
		printf("\nThere are %3d number %d in the list", frequencyCountSLL(&csll, i), i);
	}

	CSinglyLinkedList *list = getCSinglyLinkedList();
	for (i = 0; i < 10; i++) {
		insertTailSLL(&list, i);
	}
	printf("\n---------- ---------- Reverse List ---------- ----------\n");
	// Reversing new List in hopes that the original one does not change
	CSinglyLinkedList *newList = copyCSinglyLinkedList(&list);
	printf("\nOld List:\n");
	displayListSLL(&list);
	printf("\nNew copied and reversed list:\n");
	// Reverse
	reverseListSLL(&newList);
	displayListSLL(&newList);

	int a = getListSizeSLL(&newList);
	for (i = 0; 0 < getListSizeSLL(&newList); i++) {
		removeHeadSLL(&newList);
	}

	printf("\nNew List erased\n");
	displayListSLL(&newList);

	insertTailSLL(&newList, 10);

	printf("\nOld %d, New %d\n", getListSizeSLL(&list), getListSizeSLL(&newList));

	for (i = 5; i < 15; i++) {
		if (containsValueSLL(&list, i)) printf("\nContains %2d : True", i);
		else printf("\nContains %2d : False", i);
	}
	printf("\n");
	displayListSLL(&list);

	printf("\n");
	//
	// 
	free(csll);
	return 0;
}