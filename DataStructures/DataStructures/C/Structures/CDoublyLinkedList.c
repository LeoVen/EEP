/*
 * CSinglyLinkedList.c
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
 1 - List not Initialized
 2 - Invalid Position
 3 - List is Empty

 */

#include "..\Headers\CDoublyLinkedList.h"

int initListDLL(CDoublyLinkedList **DoublyLinkedList)
{
	CDoublyLinkedList *dll = *DoublyLinkedList;
	dll->initialized = true;
	dll->size = 0;
	dll->head = NULL;
	dll->tail = NULL;
	return 0;
}