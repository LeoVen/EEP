/* Tarefa 2: Problema de Josefo
 * Nome: Leonardo Vencovsky
 * RA: 201710276
 */

/*
 * People are standing in a circle waiting to be executed. Counting begins at a
 * specified point in the circle and proceeds around the circle in a specified
 * direction. After a specified number of people are skipped, the next person
 * is executed. The procedure is repeated with the remaining people, starting
 * with the next person, going in the same direction and skipping the same
 * number of people, until only one person remains, and is freed.
 *
 * The problem — given the number of people, starting point, direction, and
 * number to be skipped — is to choose the position in the initial circle to
 * avoid execution.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

typedef enum Status {
	DS_OK                        =  0, /**< Returned by a function when all operations were successful */
	DS_ERR_INVALID_POSITION      =  1, /**< When an invalid position is passed as argument */
	DS_ERR_INVALID_OPERATION     =  2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
	DS_ERR_INVALID_SIZE          =  3, /**< When an invalid size is given */
	DS_ERR_NOT_FOUND             =  4, /**< When a search fails to find a value ) */
	DS_ERR_ALLOC                 =  5, /**< When a function fails to allocate memory  */
	DS_ERR_OPERATION_FAILED      =  6, /**< When a function does not receive <code>DS_OK</code> from an internal function */
	DS_ERR_UNEXPECTED_RESULT     =  7, /**< When an unexpected result happens. Contact developers. */
	DS_ERR_ITER                  =  8, /**< When an iteration reaches an unexpected value */
	DS_ERR_NULL_POINTER          =  9, /**< When a @c NULL parameter is passed to a function */
	DS_ERR_UNEXPECTED_OPERATION  = 10  /**< When an operation is called for a wrong purpose */
} Status;

/**
 * A @c CircularLinkedNode is what a @c CircularLinkedList is composed of.
 * They are exactly the same as @c SinglyLinkedNode. The differentiation of
 * both was made so that no structure depends on another.
 */
typedef struct CircularLinkedNode {
	int data;                           /*!< Pointer to node's content */
	struct CircularLinkedNode *next;    /*!< Pointer to the next node on the list */
} CircularLinkedNode;


/**
 * A @c CircularLinkedList is a structure much like a @c SinglyLinkedList
 * except that the nodes wrap around making it a circular structure. This
 * way only one pointer is necessarry as you won't have any problems like
 * pointing the @c *head pointer to the next node making the node before it
 * inaccessible. But in a circular list you must be careful to not fall
 * into an infinite loop as the list won't have a node pointing to @c NULL
 * as if it was the end of it.
 */
typedef struct CircularLinkedList {
	int length;                         /*!< List length */
	struct CircularLinkedNode *curr;    /*!< Pointer to current node. Functions operate relative to this node */
} CircularLinkedList;

Status cll_init_list(CircularLinkedList **cll);
Status cll_init_node(CircularLinkedNode **cln);
Status cll_insert_after(CircularLinkedList *cll, int value);
Status cll_remove_after(CircularLinkedList *cll);
Status cll_insert_first(CircularLinkedList *cll, int value);
Status cll_remove_last(CircularLinkedList *cll);
Status cll_josephus(CircularLinkedList **cll, size_t n, size_t k, size_t *result);

Status cll_init_list(CircularLinkedList **cll)
{
	(*cll) = malloc(sizeof(CircularLinkedList));

	if (!cll)
		return DS_ERR_ALLOC;

	(*cll)->curr = NULL;
	(*cll)->length = 0;

	return DS_OK;
}

Status cll_init_node(CircularLinkedNode **cln)
{
	(*cln) = malloc(sizeof(CircularLinkedNode));

	if (!cln)
		return DS_ERR_ALLOC;

	(*cln)->data = NULL;
	(*cln)->next = NULL;

	return DS_OK;
}

Status cll_insert_after(CircularLinkedList *cll, int value)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0) {

		Status st = cll_insert_first(cll, value);

		if (st != DS_OK)
			return st;

	}
	else {

		CircularLinkedNode *cln;
		cll_init_node(&cln);

		if (!cln)
			return DS_ERR_ALLOC;

		cln->data = value;

		cln->next = cll->curr->next;
		cll->curr->next = cln;

		cll->curr = cll->curr->next;

		(cll->length)++;

	}

	return DS_OK;
}

Status cll_remove_after(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	if (cll->length == 1) {
		
		Status st = cll_remove_last(cll);
		
		if (st != DS_OK)
			return st;

	}
	else {

		CircularLinkedNode *kill = cll->curr->next;

		cll->curr->next = kill->next;

		free(kill);

		(cll->length)--;

	}

	return DS_OK;
}

Status cll_insert_first(CircularLinkedList *cll, int value)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length != 0 || cll->curr != NULL)
		return DS_ERR_UNEXPECTED_OPERATION;

	CircularLinkedNode *cln;
	cll_init_node(&cln);

	if (!cln)
		return DS_ERR_ALLOC;

	cln->data = value;

	cll->curr = cln;
	cln->next = cln;

	(cll->length)++;

	return DS_OK;
}

Status cll_remove_last(CircularLinkedList *cll)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->length > 1)
		return DS_ERR_UNEXPECTED_OPERATION;

	free(cll->curr);

	cll->curr = NULL;

	(cll->length)--;
	
	return DS_OK;
}

Status cll_iter(CircularLinkedList *cll, size_t positions)
{
	if (cll == NULL)
		return DS_ERR_NULL_POINTER;

	if (cll->length == 0 || cll->curr == NULL)
		return DS_ERR_INVALID_OPERATION;

	int i;
	for (i = 0; i < positions; i++) {
		cll->curr = cll->curr->next;
	}

	return DS_OK;
}

Status cll_josephus(CircularLinkedList **cll, size_t n, size_t k, size_t *result)
{

	if (n)

	cll_init_list(cll);

	if (!(*cll))
		return DS_ERR_ALLOC;

	int i;
	for (i = 1; i <= n; i++) {

		cll_insert_after(*cll, i);

	}

	while ((*cll)->length > 1)
	{
		cll_iter(*cll, k - 1);
		cll_remove_after(*cll);
	}

	if ((*cll)->length == 1) {
		*result = (size_t)(*cll)->curr->data;
	}
	else
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}



int main(int argc, char const *argv[])
{
	
	printf("Josephus of N elements and K iterations\n");

	size_t k, n, result;
	
	printf("N < ");
	scanf("%u", &n);

	printf("K < ");
	scanf("%u", &k);

	CircularLinkedList *jos;
	if (cll_josephus(&jos, n, k, &result) == DS_OK)
		printf("\n Josephus of (%u, %u) = %u", n, k, result);
	
	return 0;
}