/*
 * SinglyLinkedList.hpp
 *
 * Author: Leonardo Vencovsky
 * Created on 11/03/2018
 *
 * Header for Singly Linked List implementations in C++
 *
 */

#pragma once

struct SinglyLinkedNode;

class SinglyLinkedList {
private:
	SinglyLinkedNode *head, *tail;
	long size;
public:
	void displayMessage(int returnCode);
	SinglyLinkedList(void);
	int displayList();
	int getSize();
	SinglyLinkedNode * getHead();
	SinglyLinkedNode * getTail();
	int insertHead(int value);
	int insertTail(int value);
	int insertMiddle(int value, int position);
	int removeHead();
	int removeMiddle(int position);
	int removeTail();
	int eraseList();
	SinglyLinkedList * copyList();
	SinglyLinkedNode * getNode(int position);
	int insertNode(SinglyLinkedNode *newNode, int position);
	int reverseList();
};