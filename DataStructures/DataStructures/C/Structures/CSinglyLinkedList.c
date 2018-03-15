/*
* CSinglyLinkedList.c
*
* Author: Leonardo Vencovsky
* Created on 14/03/2018
*
* Singly Linked List Implementations in C
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\Headers\CSinglyLinkedList.h"


// Functions
int initListSLL(CSinglyLinkedList **SinglyLinkedList);
int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value);

int displayListSLL(CSinglyLinkedList *SinglyLinkedList);

void resetTail(CSinglyLinkedList *SinglyLinkedList);
CSinglyLinkedNode * getCSinglyLinkedNode(int value);

int initListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	sll->initialized = true;
	sll->size = 0;
	sll->head = NULL;
	sll->tail = NULL;
	return 0;
}

// To be implemented
int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		CSinglyLinkedNode *sln = getCSinglyLinkedNode(value);

		if (sll->head == NULL) {
			sll->head = sln;
		}
		else {
			sln->next = sll->head;
			sll->head = sln;
		}

		resetTail(sll);
		sll->size++;
		return 0;
	}
	return 1; // List not initialized
}

CSinglyLinkedNode * getCSinglyLinkedNode(int value)
{
	CSinglyLinkedNode *sln = (CSinglyLinkedNode *) malloc(sizeof(*sln));
	sln->next = NULL;
	sln->data = value;
	return sln;
}

int displayListSLL(CSinglyLinkedList *SinglyLinkedList)
{
	if (SinglyLinkedList->initialized) {
		if (SinglyLinkedList->head != NULL) {
			// Get reference of first node
			CSinglyLinkedNode *scanner = SinglyLinkedList->head;
			printf("\nC Singly Linked List\n");
			while (scanner != NULL) // Can NULL just not be 0....... error in this line, loop is infinite
			{
				printf("%d -> ", scanner->data);
				scanner = scanner->next;
			}
			printf("NULL\n");
			return 0; // OK
		}
		return 2; // List is empty
	}
	return 1; // List not initialized
	
}

void resetTail(CSinglyLinkedList *SinglyLinkedList)
{
	SinglyLinkedList->tail = SinglyLinkedList->head;
	if (SinglyLinkedList->tail != NULL) {
		while (SinglyLinkedList->tail->next != NULL)
		{
			SinglyLinkedList->tail = SinglyLinkedList->tail->next;
		}
	}
}