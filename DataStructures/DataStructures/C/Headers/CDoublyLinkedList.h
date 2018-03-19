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

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

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

#ifdef __cplusplus
}
#endif

