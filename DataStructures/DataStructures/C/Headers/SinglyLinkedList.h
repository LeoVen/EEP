/*
* SinglyLinkedList.h
*
* Author: Leonardo Vencovsky
* Created on 14/03/2018
*
* Header for Singly Linked List Implementations in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	struct CSinglyLinkedNode
	{
		int data;
		CSinglyLinkedNode *next;
	};

	struct CSinglyLinkedList
	{
		int size;
		CSinglyLinkedNode *head;
		CSinglyLinkedNode *tail;
	};

	// Functions
	int initList(CSinglyLinkedList **sll);

#ifdef __cplusplus
}
#endif

