/* Tarefa 3: Parenteses Balanceados
 * Nome: Leonardo Vencovsky
 * RA: 201710276
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <math.h>
//#include <time.h>

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

/**
 * A @c StackBox is just like a @c SinglyLinkedNode but it is part of the
 * @c Stack implementation. The names are different for didactic purposes.
 * The structure has an integer as its data and a @c *below pointer that
 * points to the box underneath it, pointing to @c NULL if it is the very
 * first box above the ground.
 */
typedef struct StackBox {
	int data;                           /*!< Node's data */
	struct StackBox *below;             /*!< Pointer to the box underneath it */
} StackBox;

 /**
  * A @c Stack is much like a @c SinglyLinkedList but with LIFO operations,
  * that is, Last-in First-out, so the last item added is the first one to
  * be removed. This way, only one pointer to the top of the @c Stack is
  * needed since all operations are made relative to the top.
  *
  * @b Advantages over @c SinglyLinkedList
  * - Its functionality is restricted to attend only LIFO operations
  *
  * @b Drawbacks
  * - Restricted operations may cause some functions to be not available
  *
  * @b Functions
  *
  * @c Stack.c
  *
  */
typedef struct Stack {
	int height;                         /*!< Height of the Stack */
	StackBox *top;                      /*!< @c StackBox on top */
} Stack;

Status stk_get_height(Stack *stk, size_t *result);
Status stk_put(Stack *stk, int value);
Status stk_make_box(StackBox **box, int value);
Status stk_pop(Stack *stk, StackBox **box);
Status stk_init_stack(Stack **stk);
Status stk_init_stack(Stack **stk);
Status stk_check_balanced_brackets(const char *string, bool *result);

void print_status_repr(Status status);
char * status_repr(Status status);

Status stk_get_height(Stack *stk, size_t *result)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	StackBox *scan = stk->top;
	
	*result = 0;

	while (scan != NULL)
	{
		scan = scan->below;
		(*result)++;
	}

	if ((*result) != stk->height)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status stk_make_box(StackBox **box, int value)
{
	(*box) = malloc(sizeof(StackBox));

	if (!(*box))
		return DS_ERR_ALLOC;

	(*box)->below = NULL;
	(*box)->data = value;

	return DS_OK;
}

Status stk_put(Stack *stk, int value)
{
	if (stk == NULL)
		return DS_ERR_NULL_POINTER;

	StackBox *box;
	stk_make_box(&box, value);

	if (!box)
		return DS_ERR_ALLOC;

	box->below = stk->top;
	stk->top = box;

	(stk->height)++;

	return DS_OK;
}

Status stk_pop(Stack *stk, StackBox **box)
{
	if (stk == NULL || box == NULL)
		return DS_ERR_NULL_POINTER;

	(*box) = stk->top;
	stk->top = stk->top->below;
	(*box)->below = NULL;

	(stk->height)--;

	return DS_OK;
}

Status stk_init_stack(Stack **stk)
{
	(*stk) = malloc(sizeof(Stack));

	if (!(*stk))
		return DS_ERR_ALLOC;

	(*stk)->height = 0;
	(*stk)->top = NULL;

	return DS_OK;
}

Status stk_check_balanced_brackets(const char *string, bool *result)
{
	size_t i, height, str_len = strlen(string);

	*result = false;
	
	if (str_len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	Stack *stk;
	StackBox *box;

	st = stk_init_stack(&stk);

	if (st != DS_OK)
		return st;

	for (i = 0; i < str_len; i++)
	{

		if (string[i] == '{' || string[i] == '(' || string[i] == '[')
			stk_put(stk, string[i]);

		if (string[i] == '}' || string[i] == ')' || string[i] == ']')
		{

			stk_get_height(stk, &height);

			if (height == 0)
				return DS_OK; // False

			stk_pop(stk, &box);

			

			if ((box->data == '(' && string[i] == ')') ||
				(box->data == '{' && string[i] == '}') ||
				(box->data == '[' && string[i] == ']'))
				continue;
			else
				return DS_OK;

		}

	}

	stk_get_height(stk, &height);

	if (height == 0)
		*result = true;

	return DS_OK;
}

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

void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}

int main(int argc, char const *argv[])
{
	
	bool is_balanced;

	char *text;

	// Balanced
	print_status_repr(stk_check_balanced_brackets("[()]{}{[()()]()}", &is_balanced));
	text = (is_balanced) ? "String 1 is balanced" : "String 1 is not balanced";
	printf("\n%s", text);

	// Not balanced
	print_status_repr(stk_check_balanced_brackets("(()))()(", &is_balanced));
	text = (is_balanced) ? "String 2 is balanced" : "String 2 is not balanced";
	printf("\n%s", text);

	// Not balanced
	print_status_repr(stk_check_balanced_brackets("[(])", &is_balanced));
	text = (is_balanced) ? "String 3 is balanced" : "String 3 is not balanced";
	printf("\n%s", text);

	// Is balanced
	print_status_repr(stk_check_balanced_brackets("[]{{}([])}{()[[]{}]}", &is_balanced));
	text = (is_balanced) ? "String 4 is balanced" : "String 4 is not balanced";
	printf("\n%s", text);

	// Is balanced
	print_status_repr(stk_check_balanced_brackets("[]{{([])}{}()[[]{}]}", &is_balanced));
	text = (is_balanced) ? "String 5 is balanced" : "String 5 is not balanced";
	printf("\n%s", text);

	// Is balanced
	print_status_repr(stk_check_balanced_brackets("printf('Hello World!);", &is_balanced));
	text = (is_balanced) ? "String 6 is balanced" : "String 6 is not balanced";
	printf("\n%s", text);

	// Not balanced
	print_status_repr(stk_check_balanced_brackets("for ((i = 0; (i < 10); (i++)) {};", &is_balanced));
	text = (is_balanced) ? "String 7 is balanced" : "String 7 is not balanced";
	printf("\n%s", text);

	char buffer[201];

	printf("\n\n");
	printf("Entrada: ");
	fgets(buffer, 200, stdin);

	stk_check_balanced_brackets(buffer, &is_balanced);

	printf((is_balanced) ? "Caracteres balanceados" : "Caracteres nao balanceados");

	return 0;
}