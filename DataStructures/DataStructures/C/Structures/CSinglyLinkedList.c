/*
 * CSinglyLinkedList.c
 *
 * Author: Leonardo Vencovsky
 * Created on 14/03/2018
 *
 * Singly Linked List Implementations in C
 *
 * Observation:
 * To use the list you must ALWAYS initListSLL(&yourList)
 * before using other functions or you'll compare a variable
 * not initialized and it might crash your program.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "..\Headers\CSinglyLinkedList.h"

int initListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	sll->initialized = true;
	sll->size = 0;
	sll->head = NULL;
	sll->tail = NULL;
	return 0;
}

/* INSERT
 *
 * Interval [0, size]
 * Assuming lists starts at the zeroth (0) position.
 *
 * There are three cases:
 *
 * Always:
 *     Check if structure was initialized. Initialization is obligatory!
 *
 * Insert head:
 *     Node->next = head
 *     Reposition head to new Node
 *
 * Insert tail:
 *     Insert new Node to tail->next
 *     Reposition tail to new Node
 *
 * Insert middle:
 *     Position can be the same as the size
 *     This allows you to insert at the last non-existing (yet) position
 *     if (position == 0) - Insert at head
 *     if (position == size - 1) - Insert at tail
 *     else  Insert middle with (possibly) double pointer
 *         - interval [0 , size]
 *         - Position tmp pointer one before chosen node
 *         - new Node->next = tmp->next
 *         - tmp->next = new Node
 *     reposition tail
 *
 */

int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	// TODO, Check if this de-reference is needed to access struct variables
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

int insertMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int value, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size]
		if (position < 0 || position > sll->size) return 2; // Invalid Position
		if (position == 0) {
			// OK
			return insertHeadSLL(SinglyLinkedList, value);
		}
		else if (position == sll->size) {
			// OK
			return insertTailSLL(SinglyLinkedList, value);
		}
		else {
			int i;
			CSinglyLinkedNode *scanner = sll->head;
			// i starts at 1 so scanner stops one before
			// TODO what if position is 1 ?
			for (i = 1; i < position; i++) {
				scanner = scanner->next;
			}
			// Allocate memory for new Node
			CSinglyLinkedNode *sln = getCSinglyLinkedNode(value);
			// TODO
			// 
			// 
			// 
		}
		(sll->size)++;
		resetTail(sll);
		return 0; // OK
	}
	return 1; // List not initialized
}

int insertTailSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		CSinglyLinkedNode *sln = getCSinglyLinkedNode(value);
		// Careful with head == NULL
		if (sll->head == NULL) {
			sll->head = sln; // OK
		}
		else {
			(sll->tail)->next = sln;
		}
		(sll->size)++;
		resetTail(sll);
		return 0; // OK
	}
	return 1; // List not initialized
}

/* REMOVE
 *
 * Interval [0, size)
 * Assuming lists starts at the zeroth (0) position.
 *
 * There are three cases:
 *
 * Always:
 *     Check if structure was initialized. Initialization is obligatory!
 *     Check if head == null or if size == 0. If yes, list is empty.
 *
 * Remove head:
 *     Get reference to head
 *     Reposition head = head->next
 *     Remove reference to head
 *
 * Remove tail:
 *     Go to one before tail
 *     Remove next node
 *     Reposition tail ()
 *
 * Remove middle:
 *     Position has to be smaller then size
 *         Because lists also start with 0!
 *     if (position == 0) - Insert at head
 *     if (position == size - 1) - Insert at tail
 *     else - Remove middle with (possibly?) double pointer
 *         - interval [0 , size)
 *         - Position tmp pointer one before chosen node
 *         - tmp->next = (tmp->next)->next // Skipps node to be removed
 *     Reposition tail
 *
 */

int removeHeadSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// TODO
		//
		//
		//
	}
	return 1; // List not initialized
}

int removeMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size)
		if (position < 0 || position > sll->size - 1) return 2; // Invalid position
		// TODO
		//
		//
		//
	}
	return 1; // List not initialized
}

int removeTailSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// TODO
		//
		//
		//
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
			while (scanner != NULL)
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