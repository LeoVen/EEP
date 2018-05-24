# -*- MakeFile -*-

all: SinglyLinkedList DoublyLinkedList Stack

# SinglyLinkedList

SinglyLinkedList: Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o
	gcc Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o -o SinglyLinkedList -l m

Main_SLL.o: Main_SLL.c Core.h
	gcc -c Main_SLL.c

SinglyLinkedListTests.o: SinglyLinkedListTests.c SinglyLinkedList.o
	gcc -c SinglyLinkedListTests.c

SinglyLinkedList.o: SinglyLinkedList.c SinglyLinkedList.h
	gcc -c SinglyLinkedList.c

# DoublyLinkedList 

DoublyLinkedList: Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o
	gcc Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o -o DoublyLinkedList -l m

Main_DLL.o: Main_DLL.c Core.h
	gcc -c Main_DLL.c

DoublyLinkedListTests.o: DoublyLinkedListTests.c DoublyLinkedList.o
	gcc -c DoublyLinkedListTests.c

DoublyLinkedList.o: DoublyLinkedList.c DoublyLinkedList.h
	gcc -c DoublyLinkedList.c

# Stack

Stack: Main_STK.o Core.o StackTests.o Stack.o
	gcc Main_STK.o Core.o StackTests.o Stack.o -o Stack -l m

Main_STK.o: Main_STK.c Core.h
	gcc -c Main_STK.c

StackTests.o: StackTests.c Stack.o
	gcc -c StackTests.c

Stack.o: Stack.c Stack.h
	gcc -c Stack.c

# Core

Core.o: Core.c Core.h
	gcc -c Core.c

clean:
	rm *.o *.exe