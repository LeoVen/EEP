/* Tarefa 4: Impressora
 * Nome: Leonardo Vencovsky
 * RA: 201710276
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>

int PriorityQueueTests();

/**
 * @brief Status code returned by functions
 *
 * These status codes are returned by almost all functions in the project.
 * They are used to prevent unwanted results when a function fails and can
 * also be used by the user to control his/her own program flow.
 *
 */
typedef enum Status {
	DS_OK                        =  0, /**< Returned by a function when all operations were successful */
	DS_ERR_INVALID_POSITION      =  1, /**< When an invalid position is passed as argument */
	DS_ERR_INVALID_OPERATION     =  2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
	DS_ERR_INVALID_SIZE          =  3, /**< When an invalid size is given */
	DS_ERR_NOT_FOUND             =  4, /**< When a search fails to find a value */
	DS_ERR_ALLOC                 =  5, /**< When a function fails to allocate memory  */
	DS_ERR_UNEXPECTED_RESULT     =  6, /**< When an unexpected result happens. Contact developers. */
	DS_ERR_ITER                  =  7, /**< When an iteration reaches an unexpected value */
	DS_ERR_NULL_POINTER          =  8, /**< When a @c NULL parameter is passed to a function */
	DS_ERR_FULL                  =  9, /**< When a structure reaches its maximum capacity */
	DS_ERR_INVALID_ARGUMENT      = 10  /**< When an argument passed is invalid for that operation */
} Status;

char * status_repr(Status status);

void print_status_repr(Status status);

int dev_short_cut();


/**
 * A @c PriorityQueueNode is what a @c PriorityQueue is composed of. It has an
 * integer as its data, a priority integer that decides where that node will be
 * placed and one pointer to the @c PriorityQueueNode before it or simply NULL
 * when it is the last inserted  element in the @c PriorityQueue.
 *
 */
typedef struct PriorityQueueNode {
	int data;                           /*!< Node's data */
	int priority;                       /*!< Node's priority */
	struct PriorityQueueNode *before;   /*!< Pointer to the previous node in the @c PriorityQueue */
} PriorityQueueNode;

/**
 * A @c PriorityQueue is much like a @c Queue but with a priority indicator
 * at each node. This priority decides if a node will be inserted after
 * certain elements that have a lower priority allowing this newly inserted
 * Node to be removed earlier.
 *
 * @b Advantages over @c Queue
 * - Each Node has a priority value. This priority can be very useful when
 * that node must be removed of the Queue sooner.
 *
 * @b Drawbacks
 * - None
 *
 * @b Functions
 *
 * @c PriorityQueue.c
 *
 */
typedef struct PriorityQueue {
	size_t length;                      /*!< Total @c Queue length */
	struct PriorityQueueNode *front;    /*!< Where @c PriorityQueueNode are removed */
	struct PriorityQueueNode *rear;     /*!< Where @c PriorityQueueNode are inserted */
} PriorityQueue;

Status prq_init_queue(PriorityQueue **prq);
Status prq_init_node(PriorityQueueNode **node);

PriorityQueue * prq_get_queue();
PriorityQueueNode * prq_get_node(int value, int priority);

Status prq_make_node(PriorityQueueNode **node, int value, int priority);

Status prq_get_length(PriorityQueue *prq, size_t *result);

Status prq_enqueue(PriorityQueue *prq, int value, int priority);
Status prq_enqueue_node(PriorityQueue *prq, PriorityQueueNode *node);

Status prq_dequeue(PriorityQueue *prq);
Status prq_dequeue_node(PriorityQueue *prq, PriorityQueueNode **result);

Status prq_display(PriorityQueue *prq);
Status prq_display_raw(PriorityQueue *prq);

Status prq_delete_node(PriorityQueueNode **node);
Status prq_delete_queue(PriorityQueue **prq); // Erases and sets to NULL
Status prq_erase_queue(PriorityQueue **prq);  // Erases and inits

Status prq_peek_front(PriorityQueue *prq, int *result);
Status prq_peek_rear(PriorityQueue *prq, int *result);

bool prq_is_empty(PriorityQueue *prq);

Status prq_priority_highest(PriorityQueue *prq, int *result);
Status prq_priority_lowest(PriorityQueue *prq, int *result);

/**
 * @brief Visualize status codes
 *
 * This function returns a string that represents the status error for
 * better visualization.
 *
 * @param[in] status The status returned by a function
 *
 * @return A string equivalent of the status name
 */
char * status_repr(Status status)
{
	switch (status)
	{
		case DS_OK: return "DS_OK";
		case DS_ERR_INVALID_POSITION: return "DS_ERR_INVALID_POSITION";
		case DS_ERR_INVALID_OPERATION: return "DS_ERR_INVALID_OPERATION";
		case DS_ERR_INVALID_SIZE: return "DS_ERR_INVALID_SIZE";
		case DS_ERR_NOT_FOUND: return "DS_ERR_NOT_FOUND";
		case DS_ERR_ALLOC: return "DS_ERR_ALLOC";
		case DS_ERR_UNEXPECTED_RESULT: return "DS_ERR_UNEXPECTED_RESULT";
		case DS_ERR_ITER: return "DS_ERR_ITER";
		case DS_ERR_NULL_POINTER: return "DS_ERR_NULL_POINTER";
		case DS_ERR_FULL: return "DS_ERR_FULL";
		case DS_ERR_INVALID_ARGUMENT: return "DS_ERR_INVALID_ARGUMENT";
		default: return "DS_UNKNOWN_ERROR";
	}
}

/**
 * @brief Visualize status codes in the console
 *
 * This function automatically prints a status code in your console. Can be
 * used for debugging.
 *
 * @param[in] status The status returned by a function
 */
void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}


// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status prq_init_queue(PriorityQueue **prq)
{
	(*prq) = malloc(sizeof(PriorityQueue));

	if (!(*prq))
		return DS_ERR_ALLOC;

	(*prq)->front = NULL;
	(*prq)->rear = NULL;

	(*prq)->length = 0;

	return DS_OK;
}

Status prq_init_node(PriorityQueueNode **node)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->data = NULL;
	(*node)->priority = NULL;
	
	(*node)->before = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

PriorityQueue * prq_get_queue()
{
	PriorityQueue *prq = malloc(sizeof(PriorityQueue));

	prq->front = NULL;
	prq->rear = NULL;

	prq->length = 0;

	return prq;
}

PriorityQueueNode * prq_get_node(int value, int priority)
{
	PriorityQueueNode *node = malloc(sizeof(PriorityQueueNode));

	node->before = NULL;

	node->data = value;
	node->priority = priority;

	return node;
}

Status prq_make_node(PriorityQueueNode **node, int value, int priority)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->before = NULL;

	(*node)->data = value;
	(*node)->priority = priority;

	return DS_OK;
}

Status prq_get_length(PriorityQueue *prq, size_t *result)
{
	*result = 0;

	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	while (scan != NULL)
	{
		(*result)++;

		scan = scan->before;
	}

	if ((*result) != prq->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status prq_enqueue(PriorityQueue *prq, int value, int priority)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *node;

	prq_make_node(&node, value, priority);

	if (!node)
		return DS_ERR_ALLOC;

	if (prq_is_empty(prq)) {

		prq->rear = node;
		prq->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = prq->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = prq->front;

			prq->front = node;

		}
		else {

			node->before = curr;

			prev->before = node;

		}

	}

	(prq->length)++;

	return DS_OK;
}

Status prq_enqueue_node(PriorityQueue *prq, PriorityQueueNode *node)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	node->before = NULL;

	if (prq_is_empty(prq)) {

		prq->rear = node;
		prq->front = node;

	}
	else {

		PriorityQueueNode *prev = NULL;
		PriorityQueueNode *curr = prq->front;

		while (curr != NULL && curr->priority >= node->priority)
		{
			prev = curr;
			curr = curr->before;
		}

		if (prev == NULL) {

			node->before = prq->front;
			prq->front = node;

		}
		else {

			node->before = curr;
			prev->before = node;

		}

	}

	(prq->length)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status prq_dequeue(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *node = prq->front;

	prq->front = prq->front->before;

	free(node);

	(prq->length)--;

	if (prq->length == 0)
		prq->rear = NULL;

	return DS_OK;
}

Status prq_dequeue_node(PriorityQueue *prq, PriorityQueueNode **result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	(*result) = prq->front;

	prq->front = prq->front->before;

	(*result)->before = NULL;

	(prq->length)--;

	if (prq->length == 0)
		prq->rear = NULL;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status prq_display(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq)) {

		printf("\nPriority Queue\n[ empty ]\n");
		
		return DS_OK;
	}

	PriorityQueueNode *scan = prq->front;

	printf("\nPriority Queue\nfront <-");

	while (scan != NULL)
	{
		printf(" %d <-", scan->data);
		scan = scan->before;
	}

	printf(" rear\n");

	return DS_OK;
}

Status prq_display_raw(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	printf("\n");

	while (scan != NULL)
	{
		printf("%d ", scan->data);
		scan = scan->before;
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status prq_delete_node(PriorityQueueNode **node)
{
	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status prq_delete_queue(PriorityQueue **prq)
{
	if ((*prq) == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *prev = (*prq)->front;

	while ((*prq)->front != NULL)
	{
		(*prq)->front = (*prq)->front->before;
		
		free(prev);

		prev = (*prq)->front;
	}

	free((*prq));

	(*prq) = NULL;

	return DS_OK;
}

Status prq_erase_queue(PriorityQueue **prq)
{
	if ((*prq) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = prq_delete_queue(prq);

	if (st != DS_OK)
		return st;

	st = prq_init_queue(prq);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

Status prq_peek_front(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	*result = prq->front->data;

	return DS_OK;
}

Status prq_peek_rear(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	*result = prq->rear->data;

	return DS_OK;
}

bool prq_is_empty(PriorityQueue *prq)
{
	return (prq->length == 0 || prq->rear == NULL);
}

Status prq_priority_highest(PriorityQueue *prq, int *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority > *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}

Status prq_priority_lowest(PriorityQueue *prq, int *result)
{
	*result = 0;

	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *scan = prq->front;

	*result = scan->priority;

	while (scan != NULL)
	{
		if (scan->priority < *result)
			*result = scan->priority;

		scan = scan->before;
	}

	return DS_OK;
}


int PriorityQueueTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |           C Priority Queue          |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	PriorityQueue *prq;

	Status st = DS_OK;

	size_t i, len = 0;

	prq_init_queue(&prq);

	if (prq_is_empty(prq))
		printf("Priority Queue is Empty");

	prq_enqueue(prq, 0, 20);
	prq_enqueue(prq, 1, 10);
	prq_enqueue(prq, 2, 12);
	prq_enqueue(prq, 3, 11);
	prq_enqueue(prq, 4, 11);
	prq_enqueue(prq, 5, 11);
	prq_enqueue(prq, 6, 13);
	prq_enqueue(prq, 7, 21);
	prq_enqueue(prq, 8, 20);

	prq_display(prq);
	// front <- 7 <- 0 <- 8 <- 6 <- 2 <- 3 <- 4 <- 5 <- 1 <- rear

	prq_erase_queue(&prq);

	prq_enqueue_node(prq, prq_get_node(0, 20));
	prq_enqueue_node(prq, prq_get_node(1, 10));
	prq_enqueue_node(prq, prq_get_node(2, 12));
	prq_enqueue_node(prq, prq_get_node(3, 11));
	prq_enqueue_node(prq, prq_get_node(4, 11));
	prq_enqueue_node(prq, prq_get_node(5, 11));
	prq_enqueue_node(prq, prq_get_node(6, 13));
	prq_enqueue_node(prq, prq_get_node(7, 21));
	prq_enqueue_node(prq, prq_get_node(8, 20));

	prq_display(prq);
	// front <- 7 <- 0 <- 8 <- 6 <- 2 <- 3 <- 4 <- 5 <- 1 <- rear

	int highest, lowest;

	prq_priority_highest(prq, &highest);
	prq_priority_lowest(prq, &lowest);

	printf("\nHighest priority : %d\nLowest Priority : %d\n", highest, lowest);

	prq_get_length(prq, &len);

	for (i = 0; i < len; i++) {
		prq_dequeue(prq);
	}

	prq_display(prq);

	prq_erase_queue(&prq);

	for (i = 0; i < 100; i++)
		prq_enqueue(prq, i, i % 5);

	prq_display(prq);

	PriorityQueue *prq_even = NULL, *prq_odd = NULL;
	PriorityQueueNode *node;
	int data;
	size_t j;
	if (prq_init_queue(&prq_odd) == DS_OK && prq_init_queue(&prq_even) == DS_OK) {
		prq_get_length(prq, &len);
		for (j = 0; j < len; j++) {
			prq_peek_front(prq, &data);
			if (data % 2 == 0) {
				prq_dequeue_node(prq, &node);
				prq_enqueue_node(prq_even, node);
			}
			else {
				prq_dequeue_node(prq, &node);
				prq_enqueue_node(prq_odd, node);
			}
		}
	}

	prq_display(prq);
	prq_display(prq_odd);
	prq_display(prq_even);

	prq_delete_queue(&prq);
	prq_delete_queue(&prq_odd);
	prq_delete_queue(&prq_even);

	printf("\n");
	return 0;
}


int main(int argc, char const *argv[])
{
	
	PriorityQueueTests();

	return 0;
}