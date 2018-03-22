/*
 * CDoublyLinkedList.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header for Doubly Linked List Implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	typedef struct CDoublyLinkedNode {
		int data;
		struct CSinglyLinkedNode *next;
		struct CSinglyLinkedNode *prev;
	} CDoublyLinkedNode;

	typedef struct CDoublyLinkedList {
		bool initialized;
		int size;
		CDoublyLinkedNode *head;
		CDoublyLinkedNode *tail;
	} CDoublyLinkedList;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes List. Obligatory! Or your application will crash.
	*
	* @see getCDoublyLinkedList() as an alternative
	*
	* @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	*
	* @Returns [ int ] Return Code (see code table)
	*/
	int initListDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |           Returns Struct            |
	// +-------------------------------------+
	/* Get a new Doubly Linked List
	*
	* @Returns [ CDoublyLinkedList * ] Pointer to new Singly Linked List
	*/
	CDoublyLinkedList * getCDoublyLinkedList();

	/* Get a DLL Node
	*
	* @Param [ int value ] Node value
	*
	* @Returns [ CDoublyLinkedNode * ] Pointer to new node with data
	*/
	CDoublyLinkedNode * getCDoublyLinkedNode(int value);

#ifdef __cplusplus
}
#endif

