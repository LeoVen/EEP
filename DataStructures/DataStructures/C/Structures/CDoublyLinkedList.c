/*
 * CDoublyLinkedList.c
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Doubly Linked List Implementations in C
 *
 */

 /*
 Return Codes

	-1 - List Erased
	0 - Success
	1 - List not Initialized or locked
	2 - Invalid Position
	3 - List is Empty
	4 - Only one node -> won't reverse list

 */

#include "..\Headers\CDoublyLinkedList.h"

 // +-------------------------------------------------------------------------------------------------+
 // |                                           Initialize                                            |
 // +-------------------------------------------------------------------------------------------------+

int initListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	dll->initialized = true;
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

CDoublyLinkedList * getCDoublyLinkedList()
{
	CDoublyLinkedList *dll = (CDoublyLinkedList *)malloc(sizeof(CDoublyLinkedList));
	dll->initialized = true;
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return dll;
}

CDoublyLinkedNode * getCDoublyLinkedNode(int value)
{
	CDoublyLinkedNode *dln = (CDoublyLinkedNode *)malloc(sizeof(CDoublyLinkedNode));
	dln->data = value;
	dln->prev = NULL;
	dln->next = NULL;
	return dln;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

int insertHeadDLL(CDoublyLinkedList **DoublyLinkedList, int value)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {
		CDoublyLinkedNode *dln = getCDoublyLinkedNode(value);
		if (dll->head == NULL) {
			dll->head = dln;
			dll->tail = dln; // OK
		}
		else {
			dln->next = dll->head;
			dll->head->prev = dln;
			dll->head = dln;
		}
		resetHeadTail(dll);
		dll->size++;
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

int insertMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int value, int position)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {

	}
	return 1; // List not initialized or locked
}

int insertTailDLL(CDoublyLinkedList **DoublyLinkedList, int value)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {
		CDoublyLinkedNode *dln = getCDoublyLinkedNode(value);
		// Careful with head == NULL
		if (dll->head == NULL) {
			dll->head = dln;
			dll->tail = dln; // OK
		}
		else {
			(dll->tail)->next = dln; // OK
			dln->prev = dll->tail;
			dll->tail = dln;
		}
		(dll->size)++;
		resetHeadTail(dll);
		return 0;
	}
	return 1; // List not initialized or locked
}

int insertNodeDLL(CDoublyLinkedList **DoublyLinkedList, CDoublyLinkedNode *node, int position)
{
	return 1;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

int removeHeadDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {
		if (dll->head == NULL) return 3; // List is empty
		CDoublyLinkedNode *kill = dll->head;
		dll->head = dll->head->next;
		if (dll->head == NULL) dll->tail = NULL;
		else dll->head->prev = NULL;
		free(kill);
		(dll->size)--;
		resetHeadTail(dll);
		return 0;
	}
	return 1; // List not initialized or locked
}

int removeMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int position)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {

	}
	return 1; // List not initialized or locked
}

int removeTailDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {
		if (dll->head == NULL) return 3; // List is empty
		if (dll->head->next == NULL) {
			// Only one node to be removed. Use removeHeadSLL()
			// to better handle the situation
			removeHeadSLL(DoublyLinkedList);
			return 0; // OK
		}
		else {
			CDoublyLinkedNode *kill = dll->tail;
			dll->tail = dll->tail->prev;
			if (dll->tail != NULL) dll->tail->next = NULL;
			free(kill);
		}
		(dll->size)--;
		// resetHeadTail(dll);
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	if (dll->initialized) {
		if (dll->head != NULL) {
			// Get reference of first node
			CDoublyLinkedNode *scanner = dll->head;
			printf("\nC Doubly Linked List\nNULL <->");
			while (scanner != NULL)
			{
				printf(" %d <->", scanner->data);
				scanner = scanner->next;
			}
			printf(" NULL\n");
			return 0; // OK
		}
		printf("\nC Doubly Linked List\n[ EMPTY ]\n");
		return 2; // List is empty
	}
	return 1; // List not initialized or locked
}

int getListSizeDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	CDoublyLinkedNode *scanner = dll->head;
	int listSize = 0;
	if (scanner == NULL) return listSize;
	while (scanner != NULL)
	{
		scanner = scanner->next;
		listSize++;
	}
	return listSize;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

void resetHeadTail(CDoublyLinkedList *DoublyLinkedList)
{
	// BOTH must be pointing at either NULL or a Doubly Linked Node
	if (DoublyLinkedList->head != NULL && DoublyLinkedList->tail != NULL) {
		while (DoublyLinkedList->head->prev != NULL)
		{
			DoublyLinkedList->head = DoublyLinkedList->head->prev;
		}
		while (DoublyLinkedList->tail->next != NULL)
		{
			DoublyLinkedList->tail = DoublyLinkedList->tail->next;
		}
	}
	else printf("\nRESET FAILED\n");
}