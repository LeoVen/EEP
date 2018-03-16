/*
* CSinglyLinkedList.h
*
* Author: Leonardo Vencovsky
* Created on 14/03/2018
*
* Header for Singly Linked List Implementations in C
*
*/

#pragma once

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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
	// Insertion
	int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value);
	int insertMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int value, int position);
	int insertTailSLL(CSinglyLinkedList **SinglyLinkedList, int value);
	// Removal
	int removeHeadSLL(CSinglyLinkedList **SinglyLinkedList);
	int removeMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int position);
	int removeTailSLL(CSinglyLinkedList **SinglyLinkedList);
	// Display
	int displayListSLL(CSinglyLinkedList **SinglyLinkedList);
	int getListSizeSLL(CSinglyLinkedList **SinglyLinkedList);
	// Ohters
	void resetTail(CSinglyLinkedList *SinglyLinkedList);
	int deleteListSLL(CSinglyLinkedList **SinglyLinkedList);
	CSinglyLinkedNode * getCSinglyLinkedNode(int value);
	int searchValueSLL(CSinglyLinkedList **SinglyLinkedList, int value);

#ifdef __cplusplus
}
#endif

