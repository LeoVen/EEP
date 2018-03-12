/*
 * SinglyLinkedList.cpp
 *
 * Author: Leonardo Vencovsky
 * Created on 11/03/2018
 *
 * Singly Linked List Implementations
 */

#include "stdafx.h"
#include <time.h>
#include <string>

using namespace std;

struct SinglyLinkedNode
{
	int data;
	SinglyLinkedNode *next;
};

class SinglyLinkedList {
private:
	SinglyLinkedNode *head, *tail;
	long size;
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

SinglyLinkedList::SinglyLinkedList(void)
{
	head = nullptr;
	tail = nullptr;
	size = 0;
}

int SinglyLinkedList::displayList()
{
	SinglyLinkedNode *run = new SinglyLinkedNode;
	run = head;
	if (run == nullptr) return 2;
	cout << "\nSingly Linked List\n";

	while (run != nullptr)
	{
		cout << run->data << " -> ";
		run = run->next;
	}

	cout << "nullptr\n\n";
	return 10;
}

int SinglyLinkedList::insertHead(int value)
{
	SinglyLinkedNode *newNode = new SinglyLinkedNode;
	newNode->data = value;
	if (head == nullptr) {
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
		size++;
	}
	else {
		newNode->next = head;
		head = newNode;
		size++;
	}
	return 11;
}

int SinglyLinkedList::insertMiddle(int value, int position)
{
	SinglyLinkedNode *newNode = new SinglyLinkedNode;
	newNode->data = value;
	if (position < 0 || position > size) return 1;
	if (head == nullptr) {
		newNode->next = nullptr;
		head = newNode;
		tail = newNode;
		size++;
		return 11;
	}
	else if (position == 0) {
		newNode->next = head;
		head = newNode;
		size++;
		return 11;
	}
	else if (position == size) {
		newNode->next = nullptr;
		tail->next = newNode;
		tail = newNode;
		size++;
		return 13;
	}
	else {
		SinglyLinkedNode *previous = new SinglyLinkedNode;
		SinglyLinkedNode *current = new SinglyLinkedNode;
		current = head;
		for (int i = 0; i < position; i++)
		{
			previous = current;
			current = current->next;
		}
		previous->next = newNode;
		newNode->next = current;
		size++;
		return 12;
	}
}

int SinglyLinkedList::insertTail(int value)
{
	SinglyLinkedNode *newNode = new SinglyLinkedNode;
	newNode->data = value;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	size++;
	return 13;
}

int SinglyLinkedList::removeHead()
{
	if (head == nullptr) return 2;
}

int SinglyLinkedList::removeMiddle(int position)
{
	if (head == nullptr) return 2;
	if (position < 0 || position > size) return 1;
}

int SinglyLinkedList::removeTail()
{

}

void SinglyLinkedList::displayMessage(int returnCode)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof (str), &result);
	for (int i = 0; i < 26; i++)
	{
		if (str[i] == '\n') str[i] = '\0';
	}
	switch (returnCode)
	{
	case 0:
		cout << str << " [000]-[ INFO ] Success" << endl;
		break;
	case 1:
		cout << str << " [001]-[ ERROR ] Invalid Position" << endl;
		break;
	case 2:
		cout << str << " [002]-[ ERROR ] List is Empty" << endl;
		break;
	case 10:
		cout << str << " [010]-[ INFO ] List Displayed" << endl;
		break;
	case 11:
		cout << str << " [011]-[ INFO ] Insert Node at Head" << endl;
		break;
	case 12:
		cout << str << " [012]-[ INFO ] Insert Node at Middle" << endl;
		break;
	case 13:
		cout << str << " [013]-[ INFO ] Insert Node at Tail" << endl;
		break;
	default:
		cout << str << " [???]-[ ????? ] Unknown Code" << endl;
		break;
	}
}