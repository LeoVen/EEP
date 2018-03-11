/*
	Leonardo Vencovsky
	07/03/2018
	Aula: Estrutura de Dados
	EEP

	Implementação de uma lista encadeada

    +-----------------------------------------+
    |            Singly Linked List           |
    +-----------------------------------------+
*/

/* NOTES
 *
 * I've chosen to make all functions independent. That is, no function calls another
 * function inside of itself. So I've made every logic again inside of every function.
 *
 * If you find any bugs or errors please create an issue.
 *
 * Any improvements are welcomed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <SinglyLinkedList.h>
#include <utility.h>

// Change to 1 if you want list's first position to be considered as 1. Default 0.
#define FIX 0

struct SinglyLinkedList {
    int data;
    struct SinglyLinkedList *next;
};

typedef struct SinglyLinkedList SLL;

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
/*[ 111]*/int initSLL(SLL **sll);                                           // Init with null
/*[ 112]*/int resetAndInitSLL(SLL **sll);                                   // free memory and init with null

/*[ 113]*/int insertHeadSLL(SLL **sll, int data);                          // Insert at first position of list
/*[ 115]*/int insertNodeSLL(SLL **sll, int data, int position);            // Insert at the middle of the list
/*[ 114]*/int insertTailSLL(SLL **sll, int data);                            // Insert at the end of the list

/*[ 116]*/int removeHeadSLL(SLL **sll);                                    // Remove first position
/*[ 117]*/int removeNodeSLL(SLL **sll, int position);                     // Remove nth position
/*[ 118]*/int removeTailSLL(SLL **sll);                                      // Remove last position

/*[ 119]*/int printSLL(SLL *sll);                                         // Prints entire list
/*[ 120]*/// TODO int listValueSLL(SLL *sll, int position);                 // Prints value of single position

/*[ 121]*/// TODO int invertListSLL(SLL **sll);                             // Inverts list
/*[ 122]*/// TODO int arrayToListSLL(SLL **sll, int v[]);                   // Transforms array to list
/*[ 123]*/int initRandomSLL(SLL **sll);                                 // Reset and Initialize list with random numbers
/*[ 124]*/int insertRandomSLL(SLL **sll, int quantity);                     // Insert n random nodes
/*[ 125]*/SLL ** cloneSLL(SLL **sll);                                  // Returns the clone of a list

/*[NONE]*/int getListSize(SLL *sll);                                     // Gets list's size
/*[NONE]*/// TODO int getArraySize(int v[]);                               // Gets array's size

/* -----------------------------------------------------------------------------
		[  1 ] INITIALIZE
------------------------------------------------------------------------------*/
int initSLL(SLL **sll)
{
    *sll = NULL;
    return 111;
}

/* -----------------------------------------------------------------------------
		[  2 ] RESET
------------------------------------------------------------------------------*/
int resetAndInitSLL(SLL **sll)
{
    SLL *run, *kill;

    if (*sll != NULL) {
        // List is not empty
        run = *sll;
        while (run != NULL)
        {
            kill = run;
            run = run -> next;
            free(kill);
        }
        *sll = NULL;
        return 112;
    } else {
        // List is empty
        *sll = NULL;
        return 102;
    }
}

/* -----------------------------------------------------------------------------
		[  3 ] INSERT START
------------------------------------------------------------------------------*/
int insertHeadSLL(SLL **sll, int data)
{
    SLL *new;
    new = (SLL *) malloc(sizeof( SLL ));
    new -> data = data;

    if (*sll == NULL) {
        new -> next = NULL;
        *sll = new;
    } else {
        new -> next = *sll;
        *sll = new;
    }
    return 113;
}

/* -----------------------------------------------------------------------------
		[  4 ] INSERT MIDDLE
------------------------------------------------------------------------------*/
int insertNodeSLL(SLL **sll, int data, int position)
{
    int i, size = getListSize(*sll);
    SLL *new, *run;

    new = (SLL *) malloc(sizeof( SLL ));
    new -> data = data;

    // Fixing every possible unexpected behavior
    if (position < (0 + FIX) || position > (size + FIX)) {
        // Invalid position
        return 105;
    } else {
        run = *sll;
        if (position == FIX) {
            // Insert at first position
            if (*sll == NULL) {
                // Could happen
                new -> next = NULL;
                *sll = new;
            } else {
                new -> next = *sll;
                *sll = new;
            }
            return 113;
        } else if (position == size + FIX) {
            // Insert at last position
            new -> next = NULL;
            if (*sll == NULL) {
                // Could happen
                *sll = new;
            } else {
                run = *sll;
                while(run -> next != NULL)
                {
                    run = run -> next;
                }
                run -> next = new;
            }
            return 115;
        } else {
            // Insertion at the middle
            for (i = 0 + FIX; i < position - 1 /*One position before*/; i++) {
                run = run -> next;
            }
            new -> next = run -> next;
            run -> next = new;
            return 114;
        }
    }
}

/* -----------------------------------------------------------------------------
		[  5 ] INSERT END
------------------------------------------------------------------------------*/
int insertTailSLL(SLL **sll, int data)
{
    SLL *new, *run;
    new = (SLL *) malloc(sizeof( SLL ));
    new -> data = data;
    new -> next = NULL;

    if (*sll == NULL) {
        // Empty List
        *sll = new;
    } else {
        // List not empty
        run = *sll;
        while(run -> next != NULL)
        {
            run = run -> next;
        }
        run -> next = new;
    }
    return 115;
}

/* -----------------------------------------------------------------------------
		[  6 ] REMOVE START
------------------------------------------------------------------------------*/
int removeHeadSLL(SLL **sll)
{
    SLL *kill;

    if (*sll == NULL) {
        // List is empty
        return 103;
    } else {
        // List not empty, remove first position
        kill = *sll;
        *sll = (*sll) -> next;
        free(kill);
        return 116;
    }
}

/* -----------------------------------------------------------------------------
		[  7 ] REMOVE MIDDLE
------------------------------------------------------------------------------*/
int removeNodeSLL(SLL **sll, int position)
{
    int i, size = getListSize(*sll);
    SLL *run, *kill;

    // Fixing every possible unexpected behavior
    if (position < (0 + FIX) || position >= (size + FIX)) {
        // Invalid position
        return 106;
    } else if (*sll == NULL) {
        // List is empty. Nothing to remove.
        return 103;
    } else {
        // Position is valid
        if (position == FIX) {
            // Remove first position
            kill = *sll;
            *sll = (*sll) -> next;
            free(kill);
            return 116;
        } else if (position == size - 1 + FIX) {
            // Remove last position
            run = *sll;
            if (run -> next == NULL) {
                // Only one position. Remove it.
                *sll = NULL;
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
            return 118;
        } else {
            // Remove chosen position
            run = *sll;
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
            return 117;
        }
    }
}

/* -----------------------------------------------------------------------------
		[  8 ] REMOVE END
------------------------------------------------------------------------------*/
int removeTailSLL(SLL **sll)
{
    SLL *run, *kill;

    if (*sll == NULL) {
        // List is empty
        return 103;
    } else {
        run = *sll;
        if (run -> next == NULL) {
            // Only one position. Remove it.
            *sll = NULL;
            free(run);
            return 118;
        } else {
            // More than one position. Go to one before the end.
            while (( run -> next ) -> next != NULL)
            {
                run = run -> next;
            }
            kill = run -> next;
            run -> next = NULL;
            free(kill);
            return 118;
        }
    }
}

/* -----------------------------------------------------------------------------
		[  9 ] LIST ALL
------------------------------------------------------------------------------*/
int printSLL(SLL *sll)
{
    if (sll == NULL) {
        // List is empty
        return 104;
    } else {
        println("\nSINGLY LINKED LIST\n");
        while (sll != NULL)
        {
            printf("%d ", sll -> data);
            sll = sll -> next;
        }
    }
    println(" ");
    return 100;
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
int initRandomSLL(SLL **sll)
{
    SLL *run, *kill;
    int random;

    if (*sll != NULL) {
        run = *sll;
        while (run != NULL)
        {
            kill = run;
            run = run -> next;
            free(kill);
        }
        *sll = NULL;
    } // Now list is empty

    int i;
    // Inserting new values to empty list
    for (i = 0; i < 10; i++) {
        random = getRandom();

        SLL *new;
        new = (SLL *) malloc(sizeof( SLL ));
        new -> data = random;
        new -> next = NULL;

        if (*sll == NULL) {
            // Making sure list is empty
            *sll = new;
            raise(0);
        } else {
            // OK
            run = *sll;
            while(run -> next != NULL)
            {
                run = run -> next;
            }
            run -> next = new;
        }
    }
    return 123;
}

/* -----------------------------------------------------------------------------
		[ 14 ] INSERT RANDOM
------------------------------------------------------------------------------*/
int insertRandomSLL(SLL **sll, int quantity)
{
    int i, random;

    for (i = 0; i < quantity; i++) {
        random = getRandom();

        SLL *new, *run;
        new = (SLL *) malloc(sizeof( SLL ));
        new -> data = random;
        new -> next = NULL;

        if (*sll == NULL) {
            // Empty List
            *sll = new;
        } else {
            // List not empty
            run = *sll;
            while(run -> next != NULL)
            {
                run = run -> next;
            }
            run -> next = new;
        }
    }
    return 124;
}

/* -----------------------------------------------------------------------------
		[ 15 ] CLONE LIST
------------------------------------------------------------------------------*/
/*
SLL ** cloneSLL(SLL **sll)
{
    SLL **newSll = NULL, *run, **newRun;

    if (*sll == NULL) {
        raise(108);
        return NULL;
    }
    else {
        run = *sll;
        if (run -> next == NULL) {
            // Only onde node
            SLL *new = (SLL *) malloc(sizeof( SLL ));
            new -> next = NULL;
            new -> data = run -> data;
            *newSll = new;
        } else {
            SLL *new = (SLL *) malloc(sizeof ( SLL ));
            new -> next = NULL;
            new -> data = run -> data;
            **newRun = **newSll;
            *newRun = new;
            while (run -> next != NULL)
            {
                SLL *new = (SLL *) malloc(sizeof ( SLL ));
                new -> data = run -> data;
                *newRun -> next = new;
                run = run -> next;
            }
        }
    }

    return *newSll;
}
 */

int getListSize(SLL *sll)
{
    SLL *run;
    int size = 0;

    run = sll;
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
