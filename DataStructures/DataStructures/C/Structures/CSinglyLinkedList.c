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
#include <stdbool.h>

typedef struct CSinglyLinkedNode {
	int data;
	struct CSinglyLinkedNode *next;
} CSinglyLinkedNode;

typedef struct CSinglyLinkedList {
	bool initialized;
	int size;
	CSinglyLinkedNode *head;
	CSinglyLinkedNode *tail;
} CSinglyLinkedList;

// Functions
int initListSLL(CSinglyLinkedList **SinglyLinkedList);
int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value);

CSinglyLinkedNode * getSinglyLinkedNode(int value);

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
		CSinglyLinkedNode *sln = getSinglyLinkedNode(value);
		sll->size++;
		return 0;
	}
	return 1; // List not initialized
}

CSinglyLinkedNode * getSinglyLinkedNode(int value)
{
	CSinglyLinkedNode *sln = (CSinglyLinkedNode *) malloc (sizeof(CSinglyLinkedNode));
	sln->data = value;
	sln->next = NULL;
	return sln;
}