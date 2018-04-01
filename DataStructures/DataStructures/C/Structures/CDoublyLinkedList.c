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
	dll->length = 0;
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
	dll->length = 0;
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

int getListSizeDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedNode *scanner = (*DoublyLinkedList)->head;
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
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

int insertHeadDLL(CDoublyLinkedList **DoublyLinkedList, int value)
{
	if ((*DoublyLinkedList)->initialized) {
		CDoublyLinkedNode *dln = getCDoublyLinkedNode(value);
		if ((*DoublyLinkedList)->head == NULL) {
			(*DoublyLinkedList)->head = dln;
			(*DoublyLinkedList)->tail = dln; // OK
		}
		else {
			dln->next = (*DoublyLinkedList)->head;
			(*DoublyLinkedList)->head->prev = dln;
			(*DoublyLinkedList)->head = dln;
		}
		resetHeadTail((*DoublyLinkedList));
		(*DoublyLinkedList)->length++;
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

int insertMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int value, int position)
{
	if ((*DoublyLinkedList)->initialized) {
		// TODO
		//
		//
	}
	return 1; // List not initialized or locked
}

int insertTailDLL(CDoublyLinkedList **DoublyLinkedList, int value)
{
	if ((*DoublyLinkedList)->initialized) {
		CDoublyLinkedNode *dln = getCDoublyLinkedNode(value);
		// Careful with head == NULL
		if ((*DoublyLinkedList)->head == NULL) {
			(*DoublyLinkedList)->head = dln;
			(*DoublyLinkedList)->tail = dln; // OK
		}
		else {
			((*DoublyLinkedList)->tail)->next = dln; // OK
			dln->prev = (*DoublyLinkedList)->tail;
			(*DoublyLinkedList)->tail = dln;
		}
		((*DoublyLinkedList)->length)++;
		resetHeadTail((*DoublyLinkedList));
		return 0;
	}
	return 1; // List not initialized or locked
}

int insertNodeDLL(CDoublyLinkedList **DoublyLinkedList, CDoublyLinkedNode *node, int position)
{
	// TODO
	//
	//
	return 1;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

int removeHeadDLL(CDoublyLinkedList **DoublyLinkedList)
{
	if ((*DoublyLinkedList)->initialized) {
		if ((*DoublyLinkedList)->head == NULL) return 3; // List is empty
		CDoublyLinkedNode *kill = (*DoublyLinkedList)->head;
		(*DoublyLinkedList)->head = (*DoublyLinkedList)->head->next;
		if ((*DoublyLinkedList)->head == NULL) (*DoublyLinkedList)->tail = NULL;
		else (*DoublyLinkedList)->head->prev = NULL;
		free(kill);
		((*DoublyLinkedList)->length)--;
		resetHeadTail((*DoublyLinkedList));
		return 0;
	}
	return 1; // List not initialized or locked
}

int removeMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int position)
{
	if ((*DoublyLinkedList)->initialized) {
		// TODO
		//
		//
	}
	return 1; // List not initialized or locked
}

int removeTailDLL(CDoublyLinkedList **DoublyLinkedList)
{
	if ((*DoublyLinkedList)->initialized) {
		if ((*DoublyLinkedList)->head == NULL) return 3; // List is empty
		if ((*DoublyLinkedList)->head->next == NULL) {
			// Only one node to be removed. Use removeHeadSLL()
			// to better handle the situation
			removeHeadSLL(DoublyLinkedList);
			return 0; // OK
		}
		else {
			CDoublyLinkedNode *kill = (*DoublyLinkedList)->tail;
			(*DoublyLinkedList)->tail = (*DoublyLinkedList)->tail->prev;
			if ((*DoublyLinkedList)->tail != NULL)
				(*DoublyLinkedList)->tail->next = NULL;
			free(kill);
		}
		((*DoublyLinkedList)->length)--;
		// resetHeadTail((*DoublyLinkedList));
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	if ((*DoublyLinkedList)->initialized) {
		if ((*DoublyLinkedList)->head != NULL) {
			// Get reference of first node
			CDoublyLinkedNode *scanner = (*DoublyLinkedList)->head;
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

int displayRawListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	if ((*DoublyLinkedList)->initialized) {
		if ((*DoublyLinkedList)->head != NULL) {
			// Get reference of first node
			CDoublyLinkedNode *scanner = (*DoublyLinkedList)->head;
			printf("\n");
			while (scanner != NULL)
			{
				printf("%d ", scanner->data);
				scanner = scanner->next;
			}
			return 0; // OK
		}
		printf("\n[ EMPTY ]\n");
		return 2; // List is empty
	}
	return 1; // List not initialized or locked
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
	else if (DoublyLinkedList->head == NULL && DoublyLinkedList->tail == NULL) {}
	else printf("\nRESET FAILED\n");
}

int deleteListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedNode *kill;
	if ((*DoublyLinkedList)->head == NULL) return 3;
	while ((*DoublyLinkedList)->head != NULL) {
		// TODO
		//
		//
	}
	return -1; // List erased
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

// TODO Search value
// TODO Get array with positions of matched values

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

// TODO copy List
// TODO copy Node

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

// Reverse
// BubbleSort
// SelectionSort
// InsertionSort