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

#ifdef __cplusplus
}
#endif

