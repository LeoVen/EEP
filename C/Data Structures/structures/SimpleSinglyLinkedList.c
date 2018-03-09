/*
	Leonardo Vencovsky
	07/03/2018
	Aula: Estrutura de Dados
	EEP

	Implementação de uma lista encadeada

    +-----------------------------------------+
    |        Simple Singly Linked List        |
    +-----------------------------------------+
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
#include <SSLL.h>
#include <utility.h>

// Change to 1 if you want list's first position to be considered as 1. Default 0.
#define FIX 0

/*
+-----------------------------------------+
|        Simple Singly Linked List        |
+-----------------------------------------+
*/

struct SimpleSinglyLinkedList {
    int data;
    struct SimpleSinglyLinkedList *next;
};

typedef struct SimpleSinglyLinkedList SSLL;

/*
+-----------------------------------------+
|            Utility Functions            |
+-----------------------------------------+
*/
int getRandom();

/*
+-----------------------------------------+
|               Functions                 |
+-----------------------------------------+
*/
//[info_code]
/*[ 101]*/int initSSLL(SSLL **ssll);                                           // Init with null
/*[ 102]*/int resetAndInitSSLL(SSLL **ssll);                                   // free memory and initSSLL with null

/*[ 103]*/int insertHeadSSLL(SSLL **ssll, int data);                          // Insert at first position of list
/*[ 105]*/int insertNodeSSLL(SSLL **ssll, int data, int position);            // Insert at the middle of the list
/*[ 104]*/int insertTailSSLL(SSLL **ssll, int data);                            // Insert at the end of the list

/*[ 106]*/int removeHeadSSLL(SSLL **ssll);                                    // Remove first position
/*[ 107]*/int removeMiddleSSLL(SSLL **ssll, int position);                     // Remove nth position
/*[ 108]*/int removeTailSSLL(SSLL **ssll);                                      // Remove last position

/*[ 109]*/int printSSLL(SSLL *ssll);                                         // Prints entire list
/*[ 110]*/// TODO int listValue(SSLL *ssll, int position);                 // Prints value of single position

/*[ 111]*/// TODO int invertList(SSLL **ssll);                             // Inverts list
/*[ 112]*/// TODO int arrayToList(SSLL **ssll, int v[]);                   // Transforms array to list
/*[ 113]*/int initRandomSSLL(SSLL **ssll);                                 // Reset and Initialize list with random numbers
/*[ 114]*/int insertRandomSSLL(SSLL **ssll, int quantity);                     // Insert n random nodes
/*[ 115]*///SSLL* cloneList(SSLL **ssll);                                  // Returns the clone of a list

/*[NONE]*/int getListSize(SSLL *ssll);                                     // Gets list's size
/*[NONE]*/// TODO int getArraySize(int v[]);                               // Gets array's size

/* -----------------------------------------------------------------------------
		[  1 ] INITIALIZE
------------------------------------------------------------------------------*/
int initSSLL(SSLL **ssll)
{
    *ssll = NULL;
    return 101;
}

/* -----------------------------------------------------------------------------
		[  2 ] RESET
------------------------------------------------------------------------------*/
int resetAndInitSSLL(SSLL **ssll)
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
        initSSLL(ssll);
        return 2;
    }
}

/* -----------------------------------------------------------------------------
		[  3 ] INSERT START
------------------------------------------------------------------------------*/
int insertHeadSSLL(SSLL **ssll, int data)
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
int insertNodeSSLL(SSLL **ssll, int data, int position)
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
int insertTailSSLL(SSLL **ssll, int data)
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
int removeHeadSSLL(SSLL **ssll)
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
int removeMiddleSSLL(SSLL **ssll, int position)
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
int removeTailSSLL(SSLL **ssll)
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
int printSSLL(SSLL *ssll)
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
int initRandomSSLL(SSLL **ssll)
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
int insertRandomSSLL(SSLL **ssll, int quantity)
{
    int i, random;

    for (i = 0; i < quantity; i++) {
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


int getRandom()
{
    return rand() % 100;
}
