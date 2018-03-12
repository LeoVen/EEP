/*
 * SinglyLinkedList.hpp
 *
 * Author: Leonardo Vencovsky
 * Created on 11/03/2018
 *
 * Singly Linked List Header
 */

#pragma once

struct SinglyLinkedNode;

class SinglyLinkedList {
private:
	SinglyLinkedNode *head, *tail;
public:
	void displayMessage(int returnCode);
	SinglyLinkedList(void);
	int displayList();
	int insertHead(int value);
	int insertTail(int value);
	int insertMiddle(int value, int position);
	int removeHead();
	int removeMiddle(int position);
	int removeTail();
};