/*
* SinglyLinkedList.c
*
* Author: Leonardo Vencovsky
* Created on 14/03/2018
*
* Singly Linked List Implementations in C
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct CSinglyLinkedNode {
	int data;
	struct CSinglyLinkedNode *next;
} CSinglyLinkedNode;

typedef struct CSinglyLinkedList {
	int size;
	CSinglyLinkedNode *head;
	CSinglyLinkedNode *tail;
} CSinglyLinkedList;

int initList(CSinglyLinkedList **sll)
{
	
	return 0;
}
