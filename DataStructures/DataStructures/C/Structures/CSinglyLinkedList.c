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
    1 - List not Initialized or locked
    2 - Invalid Position
    3 - List is Empty
	4 - Only one node -> won't reverse/sort list

*/

#include "..\Headers\CSinglyLinkedList.h"

// +-------------------------------------------------------------------------------------------------+
// |                                           Initialize                                            |
// +-------------------------------------------------------------------------------------------------+

int initListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	(*SinglyLinkedList) = (CSinglyLinkedList *)malloc(sizeof(CSinglyLinkedList));
	(*SinglyLinkedList)->initialized = true;
	(*SinglyLinkedList)->length = 0;
	(*SinglyLinkedList)->head = NULL;
	(*SinglyLinkedList)->tail = NULL;
	return 0;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

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
		sll->length++;
		return 0;
	}
	return 1; // List not initialized or locked
}

int insertMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int value, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size]
		if (position < 0 || position > sll->length) return 2; // Invalid Position
		if (position == 0) {
			// OK
			return insertHeadSLL(SinglyLinkedList, value);
		}
		else if (position == sll->length) {
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
		(sll->length)++;
		resetTail(sll);
		return 0; // OK
	}
	return 1; // List not initialized or locked
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
		(sll->length)++;
		resetTail(sll);
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

int insertNodeSLL(CSinglyLinkedList **SinglyLinkedList, CSinglyLinkedNode *node, int position)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	if (sll->initialized) {
		// [0, size]
		if (position < 0 || position > sll->length) return 2; // Invalid Position
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
		else if (position == sll->length) {
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
	return 1; // List not initialized or locked
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

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
	if ((*SinglyLinkedList)->initialized) {
		if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
		CSinglyLinkedNode *kill = (*SinglyLinkedList)->head;
		(*SinglyLinkedList)->head = (*SinglyLinkedList)->head->next;
		free(kill);
		((*SinglyLinkedList)->length)--;
		// resetTail(sll);
		return 0;
	}
	return 1; // List not initialized or locked
}

int removeMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int position)
{
	if ((*SinglyLinkedList)->initialized) {
		// [0, size)
		if (position < 0 || position >(*SinglyLinkedList)->length - 1)
			return 2; // Invalid position
		if ((*SinglyLinkedList)->head == NULL)
			return 3; // List is empty
		if ((*SinglyLinkedList)->head->next == NULL || position == 0) {
			// OK
			removeHeadSLL(SinglyLinkedList);
		}
		else if (position == (*SinglyLinkedList)->length - 1) {
			// OK
			removeTailSLL(SinglyLinkedList);
		}
		else {
			CSinglyLinkedNode *previous = (*SinglyLinkedList)->head;
			CSinglyLinkedNode *after = (*SinglyLinkedList)->head->next;
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
		((*SinglyLinkedList)->length)--;
		resetTail((*SinglyLinkedList));
	}
	return 1; // List not initialized or locked
}

int removeTailSLL(CSinglyLinkedList **SinglyLinkedList)
{
	if ((*SinglyLinkedList)->initialized) {
		if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
		if ((*SinglyLinkedList)->head->next == NULL) {
			// Only one node to be removed. Use removeHeadSLL()
			// to better handle the situation
			removeHeadSLL(SinglyLinkedList);
			return 0; // OK
		}
		else {
			CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
			while (scanner->next->next != NULL)
			{
				scanner = scanner->next;
			}
			CSinglyLinkedNode *kill = scanner->next;
			scanner->next = NULL;
			free(kill);
		}
		((*SinglyLinkedList)->length)--;
		resetTail((*SinglyLinkedList));
		return 0; // OK
	}
	return 1; // List not initialized or locked
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

int displayListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	if ((*SinglyLinkedList)->initialized) {
		if ((*SinglyLinkedList)->head != NULL) {
			// Get reference of first node
			CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
			printf("\nC Singly Linked List\n");
			while (scanner != NULL)
			{
				printf("%d -> ", scanner->data);
				scanner = scanner->next;
			}
			printf("NULL\n");
			return 0; // OK
		}
		printf("\nC Singly Linked List\n[ EMPTY ]\n");
		return 2; // List is empty
	}
	return 1; // List not initialized or locked
}

int displayRawListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	if ((*SinglyLinkedList)->initialized) {
		if ((*SinglyLinkedList)->head != NULL) {
			// Get reference of first node
			CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
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

int deleteListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedNode *kill;
	(*SinglyLinkedList)->tail = (*SinglyLinkedList)->head;
	while ((*SinglyLinkedList)->tail != NULL)
	{
		// Free memory from heap
		kill = (*SinglyLinkedList)->tail;
		(*SinglyLinkedList)->tail = (*SinglyLinkedList)->tail->next;
		free(kill);
	}
	// If user wishes to use the list again
	initListSLL(SinglyLinkedList);
	return -1; // List erased
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

int frequencyCountSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	if ((*SinglyLinkedList)->head == NULL) return 0;
	int count = 0;
	while (scanner != NULL)
	{
		if (scanner->data == value) count++;
		scanner = scanner->next;
	}
	return count;
}

bool containsValueSLL(CSinglyLinkedList **SinglyLinkedList, int value)
{
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	if ((*SinglyLinkedList)->head == NULL) return false;
	while (scanner != NULL)
	{
		if (scanner->data == value) return true;
		scanner = scanner->next;
	}
	return false;
}

int findMin(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	if (scanner == NULL) return 3; // List is empty
	int min = scanner->data;
	while (scanner != NULL)
	{
		if (scanner->data < min) min = scanner->data;
		scanner = scanner->next;
	}
	return min;
}

int findMax(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	if (scanner == NULL) return 3; // List is empty
	int max = scanner->data;
	while (scanner != NULL)
	{
		if (scanner->data > max) max = scanner->data;
		scanner = scanner->next;
	}
	return max;
}

// TODO Get array with positions of matched values

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

CSinglyLinkedList * getCSinglyLinkedList()
{
	CSinglyLinkedList *sll = (CSinglyLinkedList *)malloc(sizeof(CSinglyLinkedList));
	sll->initialized = true;
	sll->length = 0;
	sll->head = NULL;
	sll->tail = NULL;
	return sll;
}

CSinglyLinkedNode * getCSinglyLinkedNode(int value)
{
	CSinglyLinkedNode *sln = (CSinglyLinkedNode *)malloc(sizeof(*sln));
	sln->next = NULL;
	sln->data = value;
	return sln;
}

int getListSizeSLL(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	int listSize = 0;
	if (scanner == NULL) return listSize;
	while (scanner != NULL)
	{
		scanner = scanner->next;
		listSize++;
	}
	return listSize;
}

int getNodeValueSLL(CSinglyLinkedList **SinglyLinkedList, int position)
{
	// Error!!
	if (position < 0 || position >= (*SinglyLinkedList)->length) return 1337.0;
	int i, value = (*SinglyLinkedList)->head->data;
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	for (i = 0; i < position; i++) {
		scanner = scanner->next;
	}
	value = scanner->data;
	return value;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Copy                                                |
// +-------------------------------------------------------------------------------------------------+

CSinglyLinkedList * copyCSinglyLinkedList(CSinglyLinkedList **SinglyLinkedList)
{
	CSinglyLinkedList *sll = *SinglyLinkedList;
	CSinglyLinkedList *newList = getCSinglyLinkedList();
	int i;
	for (i = 0; i < (*SinglyLinkedList)->length; i++) {
		insertTailSLL(&newList, getNodeValueSLL(&(*SinglyLinkedList), i));
	}
	return newList;
}

CSinglyLinkedNode * copyCSinglyLinkedNode(CSinglyLinkedNode *node)
{
	return getCSinglyLinkedNode(node->data);
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Sorting                                               |
// +-------------------------------------------------------------------------------------------------+

int reverseListSLL(CSinglyLinkedList **SinglyLinkedList)
{
	if ((*SinglyLinkedList)->length == 0) return 3; // List is empty
	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
	CSinglyLinkedNode *prev = NULL;
	CSinglyLinkedNode *curr = (*SinglyLinkedList)->head;
	CSinglyLinkedNode * next = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	(*SinglyLinkedList)->head = prev;
	return 0;
}

int switchNodesSLL(CSinglyLinkedList **SinglyLinkedList, int position1, int position2)
{
	if (position1 < 0 || position2 < 0 || 
		position1 >= (*SinglyLinkedList)->length ||
		position2 >= (*SinglyLinkedList)->length)
		return 2; // Invalid Position
	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
	if (position1 == position2) return 2; // Invalid Position
	int i;
	CSinglyLinkedNode *beforeNode1 = (*SinglyLinkedList)->head;
	CSinglyLinkedNode *beforeNode2 = (*SinglyLinkedList)->head;
	// Since nodes are already pointing to position 0 :
	// TODO Special case for position == 0
	// TODO Special case for position == size - 1 (last position)
	//
	//
	if (position1 != 0) {
		for (i = 0; i < position1 - 1; i++) {
			beforeNode1 = beforeNode1->next;
		}
	}
	if (position2 != 0) {
		for (i = 0; i < position2 - 1; i++) {
			beforeNode2 = beforeNode2->next;
		}
	}
	return 0;
}

int switchNodeWithHead(CSinglyLinkedList **SinglyLinkedList, int position)
{
	// TODO Switch node at position with first node
	//
	//
}

int switchNodeWithTail(CSinglyLinkedList **SinglyLinkedList, int position)
{
	// TODO Switch node at position with first node
	//
	//
}

int switchNodeHeadTail(CSinglyLinkedList **SinglyLinkedList)
{
	// TODO Switch head node with tail node
}

int bubbleSortSLL(CSinglyLinkedList **SinglyLinkedList)
{
	if ((*SinglyLinkedList)->head == NULL) return 3; // List is empty
	if ((*SinglyLinkedList)->length == 1) return 4; // Only one node
	CSinglyLinkedNode *scanner = (*SinglyLinkedList)->head;
	int i = 0;
	while (scanner != NULL)
	{
		// TODO Switch function
		//
		//
		scanner = scanner->next;
	}
}

// SelectionSort
// InsertionSort