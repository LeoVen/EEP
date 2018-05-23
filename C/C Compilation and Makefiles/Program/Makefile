# -*- MakeFile -*-

SinglyLinkedList: Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o
	gcc Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o -o SinglyLinkedList -l m

Main_SLL.o: Main_SLL.c Core.h
	gcc -c Main_SLL.c

Core.o: Core.c Core.h
	gcc -c Core.c

SinglyLinkedListTests.o: SinglyLinkedListTests.c SinglyLinkedList.o
	gcc -c SinglyLinkedListTests.c

SinglyLinkedList.o: SinglyLinkedList.c SinglyLinkedList.h
	gcc -c SinglyLinkedList.c

DoublyLinkedList: Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o
	gcc Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o -o DoublyLinkedList -l m

Main_DLL.o: Main_DLL.c Core.h
	gcc -c Main_DLL.c

Core.o: Core.c Core.h
	gcc -c Core.c

DoublyLinkedListTests.o: DoublyLinkedListTests.c DoublyLinkedList.o
	gcc -c DoublyLinkedListTests.c

DoublyLinkedList.o: DoublyLinkedList.c DoublyLinkedList.h
	gcc -c DoublyLinkedList.c

all: SinglyLinkedList DoublyLinkedList

clean:
	rm *.o *.exe