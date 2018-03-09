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

/* NOTES
 *
 * I've chosen to make all functions independent. That is, no function calls another
 * function inside of itself. So I've made every logic again inside of every function.
 *
 * If you find any bugs or erros please create an issue.
 *
 * Any improvements are welcomed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// change to "clear" if on Linux or "cls" on windows
#define CLEAR_SCREEN "cls"

// Change to 1 if you want list's first position to be considered as 1. Default 0.
#define FIX 0

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
//[info_code]
/*[ 101]*/int init(SSLL **ssll);                                           // Init with null
/*[ 102]*/int resetAndInit(SSLL **ssll);                                   // free memory and init with null

/*[ 103]*/int insertStart(SSLL **ssll, int data);                          // Insert at first position of list
/*[ 105]*/int insertMiddle(SSLL **ssll, int data, int position);            // Insert at the middle of the list
/*[ 104]*/int insertEnd(SSLL **ssll, int data);                            // Insert at the end of the list

/*[ 106]*/int removeStart(SSLL **ssll);                                    // Remove first position
/*[ 107]*/int removeMiddle(SSLL **ssll, int position);                     // Remove nth position
/*[ 108]*/int removeEnd(SSLL **ssll);                                      // Remove last position

/*[ 109]*/int listAll(SSLL *ssll);                                         // Prints entire list
/*[ 110]*/// TODO int listValue(SSLL *ssll, int position);                 // Prints value of single position

/*[ 111]*/// TODO int invertList(SSLL **ssll);                             // Inverts list
/*[ 112]*/// TODO int arrayToList(SSLL **ssll, int v[]);                   // Transforms array to list
/*[ 113]*/int initRandomList(SSLL **ssll);                                 // Reset and Initialize list with random numbers
/*[ 114]*/int insertRandom(SSLL **ssll, int quantity);                     // Insert n random nodes
/*[ 115]*///SSLL* cloneList(SSLL **ssll);                                  // Returns the clone of a list

/*[NONE]*/int getListSize(SSLL *ssll);                                     // Gets list's size
/*[NONE]*/// TODO int getArraySize(int v[]);                               // Gets array's size

// TODO implement all code numbers
// TODO implement menu

void raise(int error);
/*
+-----------------------------------------+
|            Support Functions            |
+-----------------------------------------+
*/
void pause();
void println(const char *str);
void goodbye();
int printMenu();
int getData();
int getRandom();
int getPosition();

/* -----------------------------------------------------------------------------
		MAIN
------------------------------------------------------------------------------*/
int main(int argc, char const *argv[])
{	
	SSLL *ssll;
	int option, data, position;
	bool stop = false, ini = false;

	while(!stop)
	{
		option = printMenu();
		srand(time(NULL));
		switch(option)
		{
			case 0:
				goodbye();
				stop = true;
				break;
			case 1:
				raise(init(&ssll));
				ini = true;
				break;
			case 2:
				if (ini) raise(resetAndInit(&ssll));
				else raise(500);
				break;
			case 3:
				if (ini) {
					data = getData();
					raise(insertStart(&ssll, data));
				} else raise(500);
				break;
			case 4:
				if (ini) {
					data = getData();
					position = getPosition();
					raise(insertMiddle(&ssll, data, position));
				} else raise(500);
				break;
			case 5:
				if (ini) {
					data = getData();
					raise(insertEnd(&ssll, data));
				} else raise(500);
				break;
			case 6:
				if (ini) raise(removeStart(&ssll));
				else raise(500);
				break;
			case 7:
				if (ini) {
					position = getPosition();
					raise(removeMiddle(&ssll, position));
				} else raise(500);
				break;
			case 8:
				if (ini) raise(removeEnd(&ssll));
				else raise(500);
				break;
			case 9:
				if (ini) raise(listAll(ssll));
				else raise(500);
				break;
			case 10:
				println("Method not implemented yet");
				pause();
				break;
			case 11:
				println("Method not implemented yet");
				pause();
				break;
			case 12:
				println("Method not implemented yet");
				pause();
				break;
			case 13:
				if (ini) raise(initRandomList(&ssll));
				else raise(500);
				break;
			case 14:
				if (ini) raise(insertRandom(&ssll, 10));
				else raise(500);
				break;
			case 15:
				println("Method not implemented yet");
				pause();
				break;
			case 16:
				if (ini) printf("\nSIZE %d\n", getListSize(ssll));
				pause();
				break;
			default:
				println("Invalid Option");
				pause();
				break;
		}
	}

	return 0;
}

/* -----------------------------------------------------------------------------
		[  1 ] INITIALIZE 
------------------------------------------------------------------------------*/
int init(SSLL **ssll)
{
	*ssll = NULL;
	return 101;
}

/* -----------------------------------------------------------------------------
		[  2 ] RESET 
------------------------------------------------------------------------------*/
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

/* -----------------------------------------------------------------------------
		[  3 ] INSERT START 
------------------------------------------------------------------------------*/
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

/* -----------------------------------------------------------------------------
		[  4 ] INSERT MIDDLE 
------------------------------------------------------------------------------*/
int insertMiddle(SSLL **ssll, int data, int position)
{
	int i, size = getListSize(*ssll);
	SSLL *new, *run;

	new = (SSLL *) malloc(sizeof( SSLL ));
	new -> data = data;

	// Fixing every possible unexpected behavior
	if (position < (0 + FIX) || position > (size + FIX)) {
		// Invalid position
		return 5;
	} else {
		run = *ssll;
		if (position == FIX) {
			// Insert at first position
			if (*ssll == NULL) {
				// Could happen
				new -> next = NULL;
				*ssll = new;
			} else {
				new -> next = *ssll;
				*ssll = new;
			}
			return 103;
		} else if (position == size + FIX) {
			// Insert at last position
			new -> next = NULL;
			if (*ssll == NULL) {
				// Could happen
				*ssll = new;
			} else {
				run = *ssll;
				while(run -> next != NULL)
				{
					run = run -> next;
				}
				run -> next = new;
			}
			return 105;
		} else {
			// Insertion at the middle
			for (i = 0 + FIX; i < position - 1 /*One position before*/; i++) {
				run = run -> next;
			}
			new -> next = run -> next;
			run -> next = new;
			return 104;
		}
	}
}

/* -----------------------------------------------------------------------------
		[  5 ] INSERT END 
------------------------------------------------------------------------------*/
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

/* -----------------------------------------------------------------------------
		[  6 ] REMOVE START 
------------------------------------------------------------------------------*/
int removeStart(SSLL **ssll)
{
	SSLL *kill;

	if (*ssll == NULL) {
		// List is empty
		return 3;
	} else {
		// List not empty, remove first position
		kill = *ssll;
		*ssll = (*ssll) -> next;
		free(kill);
		return 106;
	}
}

/* -----------------------------------------------------------------------------
		[  7 ] REMOVE MIDDLE 
------------------------------------------------------------------------------*/
int removeMiddle(SSLL **ssll, int position)
{
	int i, size = getListSize(*ssll);
	SSLL *run, *kill;

	// Fixing every possible unexpected behavior
	if (position < (0 + FIX) || position >= (size + FIX)) {
		// Invalid position
		return 6;
	} else if (*ssll == NULL) {
		// List is empty. Nothing to remove.
		return 3;
	} else {
		// Position is valid
		if (position == FIX) {
			// Remove first position
			kill = *ssll;
			*ssll = (*ssll) -> next;
			free(kill);
			return 106;
		} else if (position == size - 1 + FIX) {
			// Remove last position
			run = *ssll;
			if (run -> next == NULL) {
				// Only one position. Remove it.
				*ssll = NULL;
				free(run);
			} else {
				// More than one position. Go to one before the end.
				while (( run -> next ) -> next != NULL)
				{
					run = run -> next;
				}
				kill = run -> next;
				run -> next = NULL;
				free(kill);
			}
			return 108;
		} else {
			// Remove chosen position
			run = *ssll;
			for (i = 1 + FIX; i < position /*Two positions before*/; i++) {
				run = run -> next;
			}
			kill = run -> next;
			if (( run -> next ) -> next == NULL) {
				// Making sure we don't NULL -> next
				run -> next = NULL;
			} else {
				run -> next = ( run -> next ) -> next; // Skipping the removed one
			}
			free(kill);
			return 107;
		}
	}
}

/* -----------------------------------------------------------------------------
		[  8 ] REMOVE END 
------------------------------------------------------------------------------*/
int removeEnd(SSLL **ssll)
{
	SSLL *run, *kill;

	if (*ssll == NULL) {
		// List is empty
		return 3;
	} else {
		run = *ssll;
		if (run -> next == NULL) {
			// Only one position. Remove it.
			*ssll = NULL;
			free(run);
			return 108;
		} else {
			// More than one position. Go to one before the end.
			while (( run -> next ) -> next != NULL)
			{
				run = run -> next;
			}
			kill = run -> next;
			run -> next = NULL;
			free(kill);
			return 108;
		}
	}
}

/* -----------------------------------------------------------------------------
		[  9 ] LIST ALL 
------------------------------------------------------------------------------*/
int listAll(SSLL *ssll)
{
	int i;

	if (ssll == NULL) {
		// List is empty
		return 4;
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

/* -----------------------------------------------------------------------------
		[ 10 ] LIST SINGLE 
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
		[ 11 ] INVERT LIST 
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
		[ 12 ] CONVERT ARRAY TO LIST 
------------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
		[ 13 ] RESTART RANDOM 
------------------------------------------------------------------------------*/
int initRandomList(SSLL **ssll)
{
	SSLL *run, *kill;
	int random;

	if (*ssll != NULL) {
		run = *ssll;
		while (run != NULL)
		{
			kill = run;
			run = run -> next;
			free(kill);
		}
		*ssll = NULL;
	} // Now list is empty

	int i;
	// Inserting new values to empty list
	for (i = 0; i < 10; i++) {
		random = getRandom();

		SSLL *new;
		new = (SSLL *) malloc(sizeof( SSLL ));
		new -> data = random;
		new -> next = NULL;

		if (*ssll == NULL) {
			// Making sure list is empty
			*ssll = new;
			raise(0);
		} else {
			// OK
			run = *ssll;
			while(run -> next != NULL)
			{
				run = run -> next;
			}
			run -> next = new;
		}
	}
	return 113;
}

/* -----------------------------------------------------------------------------
		[ 14 ] INSERT RANDOM 
------------------------------------------------------------------------------*/
int insertRandom(SSLL **ssll, int quantity)
{
	int i, random;

	for (i = 0; i < 10; i++) {
		random = getRandom();

		SSLL *new, *run;
		new = (SSLL *) malloc(sizeof( SSLL ));
		new -> data = random;
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
	}
	return 114;
}

int getListSize(SSLL *ssll)
{
	SSLL *run;
	int size = 0;

	run = ssll;
	while (run != NULL)
	{
		size++;
		run = run -> next;
	}
	return size;
}


void raise(int error)
{
	switch(error)
	{
		case   0: println("OK      [  0  ] Success.");                                         break;
		case   1: println("WARNING [  1  ] List is empty.");                                   break;
		case   2: println("WARNING [  2  ] Attempt of reset. List already empty.");            break;
		case   3: println("WARNING [  3  ] Attempt of removal. List is empty.");               break;
		case   4: println("WARNING [  4  ] Attempt of listing. List is empty.");               break;
		case   5: println("WARNING [  5  ] Attempt of insertion. Invalid position.");          break;
		case   6: println("WARNING [  6  ] Attempt of removal. Invalid position.");            break;
		case 101: println("INFO    [ 101 ] List Initialized.");                                break;
		case 102: println("INFO    [ 102 ] List Reset and Initialized.");                      break;
		case 103: println("INFO    [ 103 ] Insert value at starting position.");               break;
		case 104: println("INFO    [ 104 ] Insert value at chosen position.");                 break;
		case 105: println("INFO    [ 105 ] Insert value at the last position.");               break;
		case 106: println("INFO    [ 106 ] First position removed.");                          break;
		case 107: println("INFO    [ 107 ] Chosen position removed.");                         break;
		case 108: println("INFO    [ 108 ] Last position removed.");                           break;
		case 109: println("INFO    [ 109 ] Entire List printed.");                             break;
		case 113: println("INFO    [ 113 ] List reset and initialized with random numbers.");  break;
		case 114: println("INFO    [ 114 ] Random numbers added.");                            break;
		case 500: println("ERROR   [ 500 ] List not Initialized.");                            break;
		case 501: println("ERROR   [ 501 ] Unexpected error.");                                break;
		default:  println("ERROR   [  UNKNOWN ERROR  ]");                                      break;
	}
	pause();
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

void goodbye()
{
	system(CLEAR_SCREEN);
	println(" ");
	println(" +--------------------------+");
	println(" |        Good Bye!         |");
	println(" +--------------------------+");
	println(" ");
	pause();
	system(CLEAR_SCREEN);
}

int printMenu()
{
	int option;
	system(CLEAR_SCREEN);
	println(" ");
	println(" +-----------------------------------------+");
	println(" |        Simple Singly Linked List        |");
	println(" +-----------------------------------------+\n");
	println(" ");
	println(" Choose an option");
	println(" ");
	println(" [  0 ] - Exit");
	println(" [  1 ] - Initialize list");
	println(" [  2 ] - Reset then initialize list");
	println(" [  3 ] - Insert node at the first position");
	println(" [  4 ] - Insert node at desired position");
	println(" [  5 ] - Insert node at the last position");
	println(" [  6 ] - Remove node at the first position");
	println(" [  7 ] - Remove node at desired position");
	println(" [  8 ] - Remove node at the last position");
	println(" [  9 ] - Print entire list data");
	println(" [ 10 ] - Print single position data");
	println(" [ 11 ] - Invert list");
	println(" [ 12 ] - Convert array to list");
	println(" [ 13 ] - Restart list with random numbers");
	println(" [ 14 ] - Insert 10 random nodes");
	println(" [ 15 ] - Clone list to another list");
	println(" ");
	printf(" > ");
	scanf("%d", &option);
	return option;
}

int getData()
{
	int data;

	println("\nInput data");
	printf("\n[&] < ");
	scanf("%d", &data);

	return data;
}

int getRandom()
{
	return rand() % 100;
}

int getPosition()
{
	int position;

	println("\nInput position");
	printf("\n[?] < ");
	scanf("%d", &position);

	return position;
}
