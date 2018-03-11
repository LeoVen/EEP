/* 
 * File:   main.cpp
 * Author: Leonardo Vencovsky
 *
 * Created on 11/03/2018
 */

#include <cstdlib>
#include <iostream>
#include "SinglyLinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    SinglyLinkedList sll;
    sll.createNode(10);
    sll.createNode(20);
    sll.createNode(30);
    sll.displayList();
    
    return 0;
}

