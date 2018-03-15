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
	int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value);

	int displayListSLL(CSinglyLinkedList *SinglyLinkedList);

	void resetTail(CSinglyLinkedList *SinglyLinkedList);
	CSinglyLinkedNode * getCSinglyLinkedNode(int value);

#ifdef __cplusplus
}
#endif

