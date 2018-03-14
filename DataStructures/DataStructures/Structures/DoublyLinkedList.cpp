/*
 * DoublyLinkedList.cpp
 *
 * Author: Leonardo Vencovsky
 * Created on 13/03/2018
 *
 * Doubly Linked List Implementations in C++
 *
 */

// Ignore "Cannot open file"
#include "stdafx.h"

// Used to log current time
#include <time.h>
#include <string>

using namespace std;

struct DoublyLinkedNode {
	int data;
	DoublyLinkedNode *prev;
	DoublyLinkedNode *next;
};

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

DoublyLinkedList::DoublyLinkedList(void)
{
	head = nullptr;
	tail = nullptr;
	size = 0;
	fix = 0;
}

int DoublyLinkedList::getSize()
{
	return size;
}

int DoublyLinkedList::toggleFix()
{
	if (fix == 0) fix = 1;
	else fix = 0;
	return 0;
}

int DoublyLinkedList::displayList()
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::insertHead(int value)
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::insertTail(int value)
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::insertMiddle(int value, int position)
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::removeHead()
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::removeMiddle(int position)
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

int DoublyLinkedList::removeTail()
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

DoublyLinkedList * DoublyLinkedList::copyList()
{
	cout << "Method not implemented yet" << endl;
	return nullptr;
}

int DoublyLinkedList::eraseList()
{
	cout << "Method not implemented yet" << endl;
	return 0;
}

DoublyLinkedNode * DoublyLinkedList::getHead()
{
	return head;
}

DoublyLinkedNode * DoublyLinkedList::getTail()
{
	return tail;
}


void DoublyLinkedList::displayMessage(int returnCode)
{
	time_t result = time(NULL);
	char str[26];
	ctime_s(str, sizeof(str), &result);
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