/*
 * SinglyLinkedListTests.cpp
 *
 * Author: Leonardo Vencovsky
 * Created on 13/03/2018
 *
 * Test Cases for Singly Linked Lists
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

// Ignore "Cannot open file"
#include "stdafx.h"
#include "..\Headers\Structures.hpp"

using namespace std;

int SinglyLinkedListTest()
{
	cout << endl;
	cout << " +-------------------------------------+" << endl;
	cout << " |                                     |" << endl;
	cout << " |       C++ Singly Linked List        |" << endl;
	cout << " |                                     |" << endl;
	cout << " +-------------------------------------+" << endl;
	cout << endl;

	SinglyLinkedList *sll1 = new SinglyLinkedList();
	SinglyLinkedList *sll2 = new SinglyLinkedList();
	SinglyLinkedList *sll3 = new SinglyLinkedList();

	// Test cases
	for (int i = 0; i < 10; i++) {
		sll1->insertTail(i);
	}
	sll1->displayList();
	sll1->removeHead();
	sll2 = sll1->copyList();
	sll2->insertTail(10);
	sll1->eraseList();
	sll2->displayList();
	sll1->displayList();

	sll3->insertNode(sll2->getNode(sll2->getSize() - 1), 0);
	sll3->insertTail(10);

	sll3->displayList();

	sll3->removeTail();
	sll3->removeTail();
	sll3->removeTail();

	sll3->displayMessage(sll3->insertNode(sll2->getNode(0), 0));
	cout << "\nSIZE: " << sll3->getSize() << endl;

	sll3->displayList();



	printf("\n");
	sll1->eraseList();
	sll2->eraseList();
	sll3->eraseList();
	return 0;
}
