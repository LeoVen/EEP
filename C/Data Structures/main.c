/*
	Leonardo Vencovsky
	09/03/2018

    Entry function
    Here you can test all structures

*/

#include <stdio.h>
#include <stdlib.h>
#include <SinglyLinkedList.h>
#include <utility.h>
#include <StaticArray.h>

int main()
{
    int *p = getArray(10);
    initArray(p, 10);
    pushValueArray(p, 10, 1);
    pushValueArray(p, 10, 2);
    insertValueArray(p, 10, 3, 4);
    insertValueArray(p, 10, 4, 5);
    pushValueArray(p, 10, 3);
    printArray(p, 10);

    return 0;
}