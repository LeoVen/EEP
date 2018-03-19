/*
 * SinglyLinkedList.cpp
 *
 * Author: Leonardo Vencovsky
 * Created on 11/03/2018
 *
 * Singly Linked List Implementations in C++
 *
 */

// Ignore "Cannot open file"
#include "stdafx.h"

// Used to log current time
#include <time.h>
#include <string>

using namespace std;

struct SinglyLinkedNode {
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
	int getSize();
	SinglyLinkedNode * getHead();
	SinglyLinkedNode * getTail();
	int displayList();
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
	int reverseList(); // Needs to be implemented
	// TODO void resetTail() - set tail to last node automatically
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
	cout << "\nC++ Singly Linked List\n";

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
	else if (position == 0) {
		// Insert at head
		newNode->next = head;
		head = newNode;
		size++;
		return 11;
	}
	else if (position == size) {
		// Insert at tail
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
	else {
		SinglyLinkedNode *kill = head;
		head = head->next;
		kill = nullptr;
		size--;
		return 14;
	}
}

int SinglyLinkedList::removeMiddle(int position)
{
	SinglyLinkedNode *scanner = head;
	if (head == nullptr) return 2;
	else if (position < 0 || position >= size) return 1;
	else if (position == 0) {
		// Remove first position
		head = head->next;
		size--;
		return 14;
	}
	else {
		// Stops two positions before
		for (int i = 1; i < position; i++) {
			scanner = scanner->next;
		}
		if ((scanner->next)->next == nullptr) {
			// Remove last position
			scanner->next = nullptr;
			tail = scanner;
			size--;
			return 16;
		}
		else {
			// Remove chosen position
			SinglyLinkedNode *temp = (scanner->next)->next;
			scanner->next = nullptr;
			scanner->next = temp;
			size--;
			return 15;
		}
	}
	return 0;
}

int SinglyLinkedList::removeTail()
{
	if (head == nullptr) return 2;
	else {
		SinglyLinkedNode *scanner = head;
		if (scanner->next == nullptr) {
			head = nullptr;
			tail = nullptr;
			scanner = nullptr;
		}
		else {
			while ( (scanner->next )->next != nullptr)
			{
				scanner = scanner->next;
			}
			scanner->next = nullptr;
			tail = scanner;
		}
		size--;
		return 16;
	}
}

SinglyLinkedList * SinglyLinkedList::copyList()
{
	if (head == nullptr) {
		this->displayMessage(2);
		SinglyLinkedList *newSll = new SinglyLinkedList();
		return newSll;
	}
	else {
		// Scanners
		SinglyLinkedNode *scanner = this->head;
		// New list
		SinglyLinkedList *newList = new SinglyLinkedList();
		// First node
		SinglyLinkedNode *firstNode = new SinglyLinkedNode;
		newList->head = firstNode;
		// Scanner for new list
		SinglyLinkedNode *newScanner = newList->head;
		// Adapting first node
		newScanner->data = scanner->data;
		newScanner->next = nullptr;
		newList->size = 1;
		while (scanner->next != nullptr)
		{
			scanner = scanner->next;
			SinglyLinkedNode *newNode = new SinglyLinkedNode;
			newScanner->next = newNode;
			newNode->data = scanner->data;
			newNode->next = nullptr;
			newScanner = newNode;
			newList->size++;
		}
		// Pointing tail
		newList->tail = newScanner;
		displayMessage(17);
		return newList;
	}
}

int SinglyLinkedList::eraseList()
{
	if (head == nullptr) return 2;
	while (head != nullptr)
	{
		tail = head;
		head = head->next;
		tail = nullptr;
	}
	size = 0;
	return 9;
}

SinglyLinkedNode * SinglyLinkedList::getNode(int position)
{
	SinglyLinkedNode *newNode = new SinglyLinkedNode;
	newNode->next = nullptr;
	newNode->data = 0;
	if (head == nullptr) {
		displayMessage(2);
		return newNode;
	}
	else if (position < 0 || position >= size) {
		displayMessage(1);
		return newNode;
	}
	else {
		if (head->next == nullptr) {
			// Get first node
			newNode->data = head->data;
		}
		else if (position == size - 1) {
			// Get last node
			newNode->data = tail->data;
		}
		else {
			SinglyLinkedNode *scanner = new SinglyLinkedNode;
			scanner = head;
			for (int i = 0; i < position; i++) {
				scanner = scanner->next;
			}
			newNode->data = scanner->data;
		}
		return newNode;
	}
}

int SinglyLinkedList::insertNode(SinglyLinkedNode *newNode, int position)
{
	newNode->next = nullptr; // Making sure it points to something
	if (head == nullptr && position != 0) return 2;
	else if (position < 0 || position > size) return 1;
	else {
		if (position == 0 && head == nullptr) {
			newNode->next = head;
			head = newNode;
			tail = newNode;
			size++;
			return 11;
		}
		else if (position == 0) {
			// Insert at head
			newNode->next = head;
			head = newNode;
			size++;
			return 11;
		}
		else if (position == size) {
			// Insert at tail
			tail->next = newNode;
			size++;
			return 13;
		}
		else {
			// Insert at middle
			SinglyLinkedNode *scanner = head;
			// Stops one before
			for (int i = 1; i < position; i++) {
				scanner = scanner->next;
			}
			newNode->next = (scanner->next)->next;
			scanner->next = newNode;
			size++;
			return 12;
		}
	}
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
	case 9:
		cout << str << " [009]-[ INFO ] List Erased" << endl;
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
	case 14:
		cout << str << " [014]-[ INFO ] Head Node Removed" << endl;
		break;
	case 15:
		cout << str << " [015]-[ INFO ] Middle Node Removed" << endl;
		break;
	case 16:
		cout << str << " [016]-[ INFO ] Tail Node Removed" << endl;
		break;
	case 17:
		cout << str << " [017]-[ INFO ] List copied" << endl;
		break;
	case 999:
		cout << str << " [999]-[ ERROR ] Fatal Error" << endl;
		break;
	default:
		cout << str << " [???]-[ ????? ] Unknown Code" << endl;
		break;
	}
}

int SinglyLinkedList::getSize()
{
	return size;
}

SinglyLinkedNode * SinglyLinkedList::getHead()
{
	return head;
}

SinglyLinkedNode * SinglyLinkedList::getTail()
{
	return tail;
}

