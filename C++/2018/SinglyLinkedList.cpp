/* 
 * File:   SinglyLinkedList.cpp
 * Author: Leonardo Vencovsky
 * 
 * Created on 11/03/2018
 */

#include <iostream>

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
    SinglyLinkedList(void);
    int displayList();
    int createNode(int value);
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
    run = this->head;
    while (run != nullptr)
    {
        cout <<  run->data << "\t";
        run = run -> next;
    }
}

int SinglyLinkedList::createNode(int value)
{
    SinglyLinkedNode *newNode = new SinglyLinkedNode;
    newNode -> data = value;
    newNode -> next = nullptr;
    if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
        newNode = nullptr;
    } else {
        this->tail -> next = newNode;
        this->tail = newNode;
    }
    size++;
    return 0;
}