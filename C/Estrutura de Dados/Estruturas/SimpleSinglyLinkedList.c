/*
	Leonardo Vencovsky
	07/03/2018
	Aula: Estrutura de Dados
	EEP

	Implementação de uma lista encadeada

    +-----------------------------------------+
    |        Simple Singly Linked List        |
    +-----------------------------------------+
	
	Compiled with MinGW
*/

#include <stdio.h>
#include <stdlib.h>

/*
+-----------------------------------------+
|        Simple Singly Linked List        |
+-----------------------------------------+
*/
typedef struct SimpleSinglyLinkedList {
	int data;
	struct SimpleSinglyLinkedList *next;
}SSLL;

/*
+-----------------------------------------+
|               Functions                 |
+-----------------------------------------+
*/
//[code]
/*[ 101]*/int init(SSLL **ssll);                                           // Init with null
/*[ 102]*/int resetAndInit(SSLL **ssll);                                   // free memory and init with null

/*[ 103]*/int insertStart(SSLL **ssll, int data);                          // Insert at first position of list
/*[ 104]*/int insertEnd(SSLL **ssll, int data);                            // Insert at the end of the list
/*[ 105]*/// TODO int insertMiddle(SSLL *ssll, int data, int position);    // Insert at the middle of the list

/*[ 106]*/// TODO int removeStart(SSLL **ssll);                            // Remove first position
/*[ 107]*/// TODO int removeMiddle(SSLL **ssll, int position);             // Remove nth position
/*[ 108]*/// TODO int removeEnd(SSLL **ssll);                              // Remove last position

/*[ 109]*/// TODO int listAll(SSLL *ssll);                                 // Prints entire list
/*[ 110]*/// TODO int listValue(SSLL *ssll, int position);                 // Prints value of single position

/*[ 111]*/// TODO int invertList(SSLL **ssll);                             // Inverts list
/*[ 112]*/// TODO int arrayToList(SSLL **ssll, int v[]);                   // Transforms array to list
/*[ 113]*/// TODO int initRandomList(SSLL **ssll);                         // Reset and Initialize list with random numbers

/*[NONE]*/// TODO int getListSize(SSLL *ssll);                             // Gets list's size
/*[NONE]*/// TODO int getArraySize(int v[]);                               // Gets array's size

// TODO implement all code numbers
// TODO implement menu

void printCode(int error);
/*
+-----------------------------------------+
|            Support Functions            |
+-----------------------------------------+
*/
void pause();
void println(const char *str);

/* -----------------------------------------------------------------------------
		MAIN
------------------------------------------------------------------------------*/
int main(int argc, char const *argv[])
{
	println(" ");
	
	SSLL *ssll;
	printCode(init(&ssll));
	printCode(resetAndInit(&ssll));
	printCode(listAll(ssll));
	
	printCode(insertEnd(&ssll, 11));
	printCode(listAll(ssll));
	printCode(insertStart(&ssll, 10));
	printCode(insertStart(&ssll, 9));
	printCode(insertEnd(&ssll, 12));
	printCode(insertStart(&ssll, 8));

	printCode(listAll(ssll));
	printCode(resetAndInit(&ssll));
	printCode(insertStart(&ssll, 1));
	printCode(insertStart(&ssll, 0));
	printCode(listAll(ssll));

	return 0;
}

/* -----------------------------------------------------------------------------
		Initialize 
------------------------------------------------------------------------------*/
int init(SSLL **ssll)
{
	*ssll = NULL;
	return 101;
}

int resetAndInit(SSLL **ssll)
{
	SSLL *run, *kill;
	if (*ssll != NULL) {
		// List is not empty
		run = *ssll;
		while (run != NULL)
		{
			kill = run;
			run = run -> next;
			free(kill);
		}
		*ssll = NULL;
		return 102;
	} else {
		// List is empty
		init(ssll);
		return 2;
	}
}

int insertStart(SSLL **ssll, int data)
{
	SSLL *new;
	new = (SSLL *) malloc(sizeof( SSLL ));
	new -> data = data;

	if (*ssll == NULL) {
		new -> next = NULL;
		*ssll = new;
	} else {
		new -> next = *ssll;
		*ssll = new;
	}
	return 103;
}

int insertEnd(SSLL **ssll, int data)
{
	SSLL *new, *run;
	new = (SSLL *) malloc(sizeof( SSLL ));
	new -> data = data;
	new -> next = NULL;

	if (*ssll == NULL) {
		// Empty List
		*ssll = new;
	} else {
		// List not empty
		run = *ssll;
		while(run -> next != NULL)
		{
			run = run -> next;
		}
		run -> next = new;
	}
	return 105;
}

int listAll(SSLL *ssll)
{
	int i;

	if (ssll == NULL) {
		// List is empty
		return 1;
	} else {
		println("\nLIST\n");
		while (ssll != NULL)
		{
			printf("%d ", ssll->data);
			ssll = ssll -> next;
		}
	}
	println("\n");
	return 0;
}

void printCode(int error)
{
	switch(error)
	{
		case   0: println("OK      [  0  ] Success");                               break;
		case   1: println("WARNING [  1  ] List is empty");                         break;
		case   2: println("WARNING [  2  ] List is empty and now Re-initialized");  break;
		case 101: println("INFO    [ 101 ] List Initialized");                      break;
		case 102: println("INFO    [ 102 ] List Reset and Initialized");            break;
		case 103: println("INFO    [ 103 ] Insert value at starting position");     break;
		case 104: println("INFO    [ 104 ] Insert value at chosen position");       break;
		case 105: println("INFO    [ 105 ] Insert value at the last position");     break;
		default:  println("ERROR   [  UNKNOWN ERROR  ]");                           break;
	}
}





/*
+-----------------------------------------+
|            Utility Functions            |
+-----------------------------------------+
*/
void pause()
{
	printf("Press enter to continue...");
	fflush(stdin);
	getchar();
}

void println(const char *str)
{
	printf("%s\n", str);
}