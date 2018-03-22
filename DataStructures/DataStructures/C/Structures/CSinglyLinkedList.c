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
 * For good practice always use eraseListSLL() at the end of
 * your code. This will free the dynamic memory used by malloc()
 *
 */

/*
	Return Codes

   -1 - List Erased
    0 - Success
    1 - List not Initialized
    2 - Invalid Position
    3 - List is Empty

*/

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

CSinglyLinkedList * getCSinglyLinkedList()
{
	CSinglyLinkedList *sll = (CSinglyLinkedList *)malloc(sizeof(CSinglyLinkedList));
	sll->initialized = true;
	sll->size = 0;
	sll->head = NULL;
	sll->tail = NULL;
	return sll;
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
			for (i = 1; i < position; i++) {
				scanner = scanner->next;
			}
			// Allocate memory for new Node
			CSinglyLinkedNode *sln = getCSinglyLinkedNode(value);
			sln->next = scanner->next;
			scanner->next = sln;
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
		if (sll->head == NULL) return 3; // List is empty
		CSinglyLinkedNode *kill = sll->head;
		sll->head = sll->head->next;
		free(kill);
		(sll->size)--;
		// resetTail(sll);
		return 0;
	}
	return 1; // List not initialized
}

int removeMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size)
		if (position < 0 || position > sll->size - 1) return 2; // Invalid position
		if (sll->head == NULL) return 3; // List is empty
		if (sll->head->next == NULL || position == 0) {
			// OK
			removeHeadSLL(SinglyLinkedList);
		}
		else if (position == sll->size - 1) {
			// OK
			removeTailSLL(SinglyLinkedList);
		}
		else {
			CSinglyLinkedNode *previous = sll->head;
			CSinglyLinkedNode *after = sll->head->next;
			int i;
			// i = 1 to stop one before the node to be deleted
			for (i = 1; i < position ; i++) {
				previous = after;
				after = after->next;
			}
			// Skip node to be removed
			previous->next = after->next;
			free(after);
		}
		(sll->size)--;
		resetTail(sll);
	}
	return 1; // List not initialized
}

int removeTailSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		if (sll->head == NULL) return 3; // List is empty
		if (sll->head->next == NULL) {
			// Only one node to be removed. Use removeHeadSLL()
			// to better handle the situation
			removeHeadSLL(SinglyLinkedList);
		}
		else {
			CSinglyLinkedNode *scanner = sll->head;
			while (scanner->next->next != NULL)
			{
				scanner = scanner->next;
			}
			CSinglyLinkedNode *kill = scanner->next;
			scanner->next = NULL;
			free(kill);
		}
		(sll->size)--;
		resetTail(sll);
		return 0; // OK
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

int displayListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		if (sll->head != NULL) {
			// Get reference of first node
			CSinglyLinkedNode *scanner = sll->head;
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

int deleteListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	CSinglyLinkedNode *kill;
	sll->tail = sll->head;
	while (sll->tail != NULL)
	{
		// Free memory from heap
		kill = sll->tail;
		sll->tail = sll->tail->next;
		free(kill);
	}
	// If user wishes to use the list again
	initListSLL(SinglyLinkedList);
	return -1; // List erased
}

int getListSizeSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	CSinglyLinkedNode *scanner = sll->head;
	int listSize = 0;
	if (scanner == NULL) return listSize;
	while (scanner != NULL)
	{
		scanner = scanner->next;
		listSize++;
	}
	return listSize;
}

int searchValueSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	CSinglyLinkedNode *scanner = sll->head;
	if (sll->head == NULL) return 0;
	int count = 0;
	while (scanner != NULL)
	{
		if (scanner->data == value) count++;
		scanner = scanner->next;
	}
	return count;
}

int insertNodeSLL(CSinglyLinkedList **SinglyLinkedList, CSinglyLinkedNode *node, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size]
		if (position < 0 || position > sll->size) return 2; // Invalid Position
		if (sll->head == NULL) {
			// Insert at head
			// TODO
			//
		}
		else if (position == 0) {
			// Insert at head
			// TODO
			//
		}
		else if (position == sll->size) {
			// Insert at tail
			// TODO
			//
		}
		else {
			// Insert at middle
			// TODO
			//
		}
	}
	return 1; // List not initialized
}

int reverseListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
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