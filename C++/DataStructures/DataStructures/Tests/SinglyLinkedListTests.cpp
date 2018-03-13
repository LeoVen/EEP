/*
* DataStructures.cpp
*
* Author: Leonardo Vencovsky
* Created on 13/03/2018
*
* Test Cases for Singly Linked Lists
*
*/

#include "..\stdafx.h"
#include "..\Headers\SinglyLinkedList.hpp"

using namespace std;

int SinglyLinkedListTest()
{
	cout << endl;
	cout << " +-------------------------------------+" << endl;
	cout << " |                                     |" << endl;
	cout << " |         Singly Linked List          |" << endl;
	cout << " |                                     |" << endl;
	cout << " +-------------------------------------+" << endl;
	cout << endl;

	SinglyLinkedList *sll = new SinglyLinkedList();

	// Test cases
	sll->displayMessage(sll->removeHead());
	sll->displayMessage(sll->removeMiddle(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertMiddle(1, 0));
	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeMiddle(1)); // 016
	sll->displayMessage(sll->removeMiddle(0)); // 014

	sll->displayMessage(sll->displayList());

	//sll->displayMessage(sll->insertHead(2));
	//sll->displayMessage(sll->insertHead(1));
	//sll->displayMessage(sll->insertHead(0));

	sll->displayMessage(sll->displayList());
	cout << "------------------------COPY----------------------------------" << endl;
	SinglyLinkedList *newSll = sll->copyList();
	cout << "------------------------COPY----------------------------------" << endl;
	sll->displayMessage(sll->removeMiddle(2)); // 013
	sll->displayMessage(sll->removeMiddle(2)); // 013

	sll->displayMessage(sll->displayList());

	sll->displayMessage(sll->eraseList());
	sll->displayMessage(sll->eraseList());
	cout << "-------------------------------------------------------" << endl;
	for (int i = 1; i < 10; i++) {
		sll->insertTail(i);
	}
	sll->displayMessage(sll->displayList());

	// New list
	cout << "------------------------NEW LIST------------------------" << endl;
	newSll->displayMessage(newSll->displayList());
	newSll->displayMessage(newSll->eraseList());

	sll->displayMessage(sll->removeHead());
	sll->displayMessage(sll->removeMiddle(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertHead(0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertTail(0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeHead());

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeTail());

	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeMiddle(0));

	sll->displayMessage(sll->insertMiddle(1, 0));
	sll->displayMessage(sll->insertMiddle(0, 0));
	sll->displayMessage(sll->removeMiddle(1)); // 016
	sll->displayMessage(sll->removeMiddle(0)); // 014

	sll->displayMessage(sll->displayList());

	sll->displayMessage(sll->insertHead(2));
	sll->displayMessage(sll->insertHead(1));
	sll->displayMessage(sll->insertHead(0));

	sll->displayMessage(sll->displayList());

	newSll->displayMessage(newSll->removeHead());
	newSll->displayMessage(newSll->removeMiddle(0));
	newSll->displayMessage(newSll->removeTail());

	newSll->displayMessage(newSll->insertHead(0));
	newSll->displayMessage(newSll->removeHead());

	newSll->displayMessage(newSll->insertHead(0));
	newSll->displayMessage(newSll->removeTail());

	newSll->displayMessage(newSll->insertHead(0));
	newSll->displayMessage(newSll->removeMiddle(0));

	newSll->displayMessage(newSll->insertTail(0));
	newSll->displayMessage(newSll->removeHead());

	newSll->displayMessage(newSll->insertTail(0));
	newSll->displayMessage(newSll->removeTail());

	newSll->displayMessage(newSll->insertTail(0));
	newSll->displayMessage(newSll->removeMiddle(0));

	newSll->displayMessage(newSll->insertMiddle(0, 0));
	newSll->displayMessage(newSll->removeHead());

	newSll->displayMessage(newSll->insertMiddle(0, 0));
	newSll->displayMessage(newSll->removeTail());

	newSll->displayMessage(newSll->insertMiddle(0, 0));
	newSll->displayMessage(newSll->removeMiddle(0));

	newSll->displayMessage(newSll->insertMiddle(1, 0));
	newSll->displayMessage(newSll->insertMiddle(0, 0));
	newSll->displayMessage(newSll->removeMiddle(1)); // 016
	newSll->displayMessage(newSll->removeMiddle(0)); // 014

	newSll->displayMessage(newSll->displayList());

	newSll->displayMessage(newSll->insertHead(2));
	newSll->displayMessage(newSll->insertHead(1));
	newSll->displayMessage(newSll->insertHead(0));

	newSll->displayMessage(newSll->displayList());

	printf("\n");
	sll->eraseList();
	newSll->eraseList();
	return 0;
}
