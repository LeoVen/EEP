/* 
 * File:   SinglyLinkedList.h
 * Author: Leonardo Vencovsky
 *
 * Created on 11/03/2018
 */

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

struct SinglyLinkedNode;

class SinglyLinkedList {
private:
    SinglyLinkedNode *head, *tail;
public:
    SinglyLinkedList(void);
    int displayList();
    int createNode(int value);
};

#endif /* SINGLYLINKEDLIST_H */

