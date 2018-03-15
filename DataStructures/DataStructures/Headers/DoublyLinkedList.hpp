/*
 * DoublyLinkedList.hpp
 *
 * Author: Leonardo Vencovsky
 * Created on 13/03/2018
 *
 * Header for Doubly Linked List Implementations in C++
 *
 */

#pragma once

struct DoublyLinkedNode;

class DoublyLinkedList {
private:
	DoublyLinkedNode *head, *tail;
	long size;
	int fix; // Defines if list first position is 0 or 1 (default 0)
public:
	void displayMessage(int returnCode);
	DoublyLinkedList(void);
	int getSize();
	DoublyLinkedNode * getHead();
	DoublyLinkedNode * getTail();
	int toggleFix(); // Avoid using this
	int displayList();
	int insertHead(int value);
	int insertTail(int value);
	int insertMiddle(int value, int position);
	int removeHead();
	int removeMiddle(int position);
	int removeTail();
	int eraseList();
	DoublyLinkedList * copyList();
};