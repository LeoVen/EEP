/**
 * @file ProcessScheduling.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 06/09/2018
 *
 * Process Queue
 *
 */

 /* ----------------------------------------------------------------------------------------------------
  *
  *                                                                                         Header Files
  *
  * ---------------------------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define FILE_NAME "process.txt"

  /* ---------------------------------------------------------------------------------------------------- Core.h */

#define CLEAR_SCREEN system("cls")
//#define CLEAR_SCREEN system("clear")

#define SLEEP_F Sleep(200)
//#define SLEEP_F sleep(1)

#define PROCESS_MAX_PRI 5

/**
 * @brief Status code returned by functions
 *
 * These status codes are returned by almost all functions in the project.
 * They are used to prevent unwanted results when a function fails and can
 * also be used by the user to control his/her own program flow.
 *
 */
typedef enum Status {
	DS_OK = 0, /**< Returned by a function when all operations were successful */
	DS_ERR_INVALID_POSITION = 1, /**< When an invalid position is passed as argument */
	DS_ERR_INVALID_OPERATION = 2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
	DS_ERR_INVALID_SIZE = 3, /**< When an invalid size is given */
	DS_ERR_NOT_FOUND = 4, /**< When a search fails to find a value */
	DS_ERR_ALLOC = 5, /**< When a function fails to allocate memory  */
	DS_ERR_UNEXPECTED_RESULT = 6, /**< When an unexpected result happens. Contact developers. */
	DS_ERR_ITER = 7, /**< When an iteration reaches an unexpected value */
	DS_ERR_NULL_POINTER = 8, /**< When a @c NULL parameter is passed to a function */
	DS_ERR_FULL = 9, /**< When a structure reaches its maximum capacity */
	DS_ERR_INVALID_ARGUMENT = 10  /**< When an argument passed is invalid for that operation */
} Status;

char * status_repr(Status status);

void print_status_repr(Status status);

/* ---------------------------------------------------------------------------------------------------- Core.h */

/* ---------------------------------------------------------------------------------------------------- String.h */

#ifndef STRING_SPEC
#define STRING_SPEC

#define STRING_INIT_SIZE 8
#define STRING_GROW_RATE 2

#endif

typedef struct String
{
	char *buffer;		/*!< Character buffer */
	size_t len;			/*!< Word length */
	size_t capacity;	/*!< Buffer capacity */
	size_t growth_rate; /*!< Buffer capacity growth rate */
} String;

Status str_init(String **str);
Status str_make(String **str, char *content);

Status str_get_string(String *str, char **result);

Status str_push_char_front(String *str, char ch);
Status str_push_char_at(String *str, char ch, size_t index);
Status str_push_char_back(String *str, char ch);

Status str_push_front(String *str, char *ch);
Status str_push_at(String *str, char *ch, size_t index);
Status str_push_back(String *str, char *ch);

Status str_prepend(String *str1, String *str2);
Status str_add(String *str1, String *str2, size_t index);
Status str_append(String *str1, String *str2);

Status str_pop_char_front(String *str);
Status str_pop_char_at(String *str, size_t index);
Status str_pop_char_back(String *str);

Status str_display(String *str);
Status str_display_raw(String *str);

Status str_delete(String **str);
Status str_erase(String **str);

Status str_back(String *str, char *result);
Status str_front(String *str, char *result);

size_t str_length(String *str);
size_t str_len(char *ch);

Status str_compare(String *str1, String *str2, int *result);
bool str_greater(String *str1, String *str2);
bool str_equals(String *str1, String *str2);
bool str_lesser(String *str1, String *str2);

bool str_equals_str(String *str, char *string);

Status str_copy(String *str, String **result);
Status str_swap(String **str1, String **str2);

bool str_buffer_full(String *str);
bool str_buffer_empty(String *str);
bool str_buffer_fits(String *str, size_t str_len);

Status str_realloc(String *str);


/* ---------------------------------------------------------------------------------------------------- String.h */

/* ---------------------------------------------------------------------------------------------------- Process.h */

typedef struct Process
{
	struct String *name;
	size_t pid;
	size_t cpu;
	size_t io;
	size_t pri;
	struct String *type; // SO UI UNI -> 0, 1, 2
} Process;

Status prc_init(Process **prc, String *name, size_t pid, size_t cpu, size_t io, size_t pri, String *type);

Status prc_delete(Process **prc);

Status prc_display(Process *prc);

int prc_compare(Process *prc1, Process *prc2);

Status prc_copy(Process *prc, Process **result);

size_t prc_translate_type(String *str);

/* ---------------------------------------------------------------------------------------------------- Process.h */

/* ---------------------------------------------------------------------------------------------------- QueueArray.h */

#ifndef QUEUE_ARRAY_SPEC
#define QUEUE_ARRAY_SPEC

#define QUEUE_ARRAY_INIT_SIZE 8
#define QUEUE_ARRAY_GROW_RATE 2
#define QUEUE_T Process*
#define QUEUE_DELETE prc_delete
#define QUEUE_DISPLAY prc_display
#define QUEUE_COMPARATOR prc_compare

#endif

typedef struct QueueArray
{
	QUEUE_T *buffer;	/*!< @c QueueArray data buffer */
	size_t length;		/*!< @c QueueArray length */
	size_t capacity;	/*!< @c QueueArray total capacity */
	size_t growth_rate; /*!< @c QueueArray buffer growth rate */
} QueueArray;

Status qua_init(QueueArray **qua);

Status qua_get_length(QueueArray *qua, size_t *result);
size_t qua_length(QueueArray *qua);

Status qua_enqueue(QueueArray *qua, QUEUE_T value);

Status qua_dequeue(QueueArray *qua, QUEUE_T *value);

Status qua_display(QueueArray *qua);

Status qua_delete(QueueArray **qua);
Status qua_delete_shallow(QueueArray **qua);
Status qua_erase(QueueArray **qua);

bool qua_is_empty(QueueArray *qua);
bool qua_is_full(QueueArray *qua);

//Status qua_copy(QueueArray *qua, QueueArray **result);

Status qua_realloc(QueueArray *qua);


/* ---------------------------------------------------------------------------------------------------- QueueArray.h */

/* ---------------------------------------------------------------------------------------------------- DynamicArray.h */

#ifndef DYNAMIC_ARRAY_SPEC
#define DYNAMIC_ARRAY_SPEC

#define DYNAMIC_ARRAY_INIT_SIZE 8	   /*!< Buffer initial size macro. */
#define DYNAMIC_ARRAY_GROW_RATE 2	   /*!< Buffer growth rate macro. */
#define DS_DAR_T Process *			   /*!< Array type. */
#define DS_DAR_INIT prc_init		   /*!< Init function of array type. */
#define DS_DAR_DELETE prc_delete	   /*!< Delete function of array type. */
#define DS_DAR_DISPLAY prc_display     /*!< Display function of array type. */
#define DS_DAR_COMPARATOR prc_compare  /*!< Comparator function of array type. */
#define DS_DAR_COPY prc_copy           /*!< Copy function of array type. */

#endif

typedef struct DynamicArray
{
	DS_DAR_T *buffer;   /*!< @c DynamicArray data buffer */
	size_t size;		/*!< @c DynamicArray size */
	size_t capacity;	/*!< @c DynamicArray total capacity */
	size_t growth_rate; /*!< @c DynamicArray buffer growth rate */
} DynamicArray;

Status dar_init(DynamicArray **dar);

Status dar_get(DynamicArray *dar, size_t index, DS_DAR_T *result);

Status dar_insert_front(DynamicArray *dar, DS_DAR_T value);
Status dar_insert_at(DynamicArray *dar, DS_DAR_T value, size_t index);
Status dar_insert_back(DynamicArray *dar, DS_DAR_T value);

Status dar_remove_front(DynamicArray *dar, DS_DAR_T *result);
Status dar_remove_at(DynamicArray *dar, size_t index, DS_DAR_T *result);
Status dar_remove_back(DynamicArray *dar, DS_DAR_T *result);

Status dar_remove_keys(DynamicArray *dar, DS_DAR_T value);

Status dar_display(DynamicArray *dar);

Status dar_delete(DynamicArray **dar);
Status dar_delete_shallow(DynamicArray **dar);
Status dar_erase(DynamicArray **dar);

size_t dar_cap(DynamicArray *dar);
size_t dar_size(DynamicArray *dar);

bool dar_is_empty(DynamicArray *dar);
bool dar_is_full(DynamicArray *dar);

Status dar_find_max(DynamicArray *dar, DS_DAR_T *result);
Status dar_find_min(DynamicArray *dar, DS_DAR_T *result);
Status dar_find_max_pos(DynamicArray *dar, size_t *result);
Status dar_find_min_pos(DynamicArray *dar, size_t *result);

bool dar_exists(DynamicArray *dar, DS_DAR_T value);

Status dar_copy(DynamicArray *dar, QueueArray **result);

Status dar_realloc(DynamicArray *dar);

/* ---------------------------------------------------------------------------------------------------- DynamicArray.h */

/* ---------------------------------------------------------------------------------------------------- PriorityQueue.h */

#ifndef PQUEUE_ARRAY_SPEC
#define PQUEUE_ARRAY_SPEC

#define PQUEUE_T Process*
#define PQUEUE_DELETE prc_delete
#define PQUEUE_DISPLAY prc_display

#endif

typedef struct PriorityQueueNode
{
	PQUEUE_T data;					/*!< Node's data */
	size_t priority;				/*!< Node's priority */
	struct PriorityQueueNode *prev; /*!< Pointer to the previous node in the @c PriorityQueue */
} PriorityQueueNode;

typedef struct PriorityQueue
{
	size_t length;					 /*!< Total @c Queue length */
	struct PriorityQueueNode *front; /*!< Where @c PriorityQueueNode are removed */
	struct PriorityQueueNode *rear;  /*!< Where @c PriorityQueueNode are inserted */
} PriorityQueue;

Status prq_init_queue(PriorityQueue **prq);

Status prq_make_node(PriorityQueueNode **node, PQUEUE_T value, size_t priority);

Status prq_get_length(PriorityQueue *prq, size_t *result);

Status prq_enqueue(PriorityQueue *prq, PQUEUE_T value, size_t priority);

Status prq_dequeue(PriorityQueue *prq, PQUEUE_T *result);

Status prq_display(PriorityQueue *prq);

Status prq_delete_node(PriorityQueueNode **node);
Status prq_delete_queue(PriorityQueue **prq); // Erases and sets to NULL
Status prq_erase_queue(PriorityQueue **prq);  // Erases and inits

bool prq_is_empty(PriorityQueue *prq);

//Status prq_copy_node(PriorityQueueNode *node, PriorityQueueNode **result);
//Status prq_copy_queue(PriorityQueue *prq, PriorityQueue **result);


/* ---------------------------------------------------------------------------------------------------- PriorityQueue.h */

/* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         Header Files
 *
 * ---------------------------------------------------------------------------------------------------- */

 /* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         Source Files
 *
 * ---------------------------------------------------------------------------------------------------- */

 /* ---------------------------------------------------------------------------------------------------- Core.c */

char *status_repr(Status status)
{
	switch (status)
	{
	case DS_OK:
		return "DS_OK";
	case DS_ERR_INVALID_POSITION:
		return "DS_ERR_INVALID_POSITION";
	case DS_ERR_INVALID_OPERATION:
		return "DS_ERR_INVALID_OPERATION";
	case DS_ERR_INVALID_SIZE:
		return "DS_ERR_INVALID_SIZE";
	case DS_ERR_NOT_FOUND:
		return "DS_ERR_NOT_FOUND";
	case DS_ERR_ALLOC:
		return "DS_ERR_ALLOC";
	case DS_ERR_UNEXPECTED_RESULT:
		return "DS_ERR_UNEXPECTED_RESULT";
	case DS_ERR_ITER:
		return "DS_ERR_ITER";
	case DS_ERR_NULL_POINTER:
		return "DS_ERR_NULL_POINTER";
	case DS_ERR_FULL:
		return "DS_ERR_FULL";
	case DS_ERR_INVALID_ARGUMENT:
		return "DS_ERR_INVALID_ARGUMENT";
	default:
		return "DS_UNKNOWN_ERROR";
	}
}

void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}

/* ---------------------------------------------------------------------------------------------------- Core.c */

/* ---------------------------------------------------------------------------------------------------- String.c */

Status str_init(String **str)
{
	(*str) = malloc(sizeof(String));

	if (!(*str))
		return DS_ERR_ALLOC;

	(*str)->buffer = malloc(sizeof(char) * STRING_INIT_SIZE);

	if (!((*str)->buffer))
		return DS_ERR_ALLOC;

	(*str)->buffer[0] = '\0';

	(*str)->capacity = STRING_INIT_SIZE;
	(*str)->growth_rate = STRING_GROW_RATE;

	(*str)->len = 0;

	return DS_OK;
}

Status str_make(String **str, char *string)
{
	size_t length = str_len(string);

	if (length == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st = str_init(str);

	if (st != DS_OK)
		return st;

	if ((*str)->capacity <= length)
	{
		size_t new_capacity = STRING_INIT_SIZE;

		while (new_capacity <= length)
		{
			new_capacity *= STRING_GROW_RATE;
		}

		char *new_buffer = realloc((*str)->buffer, sizeof(char) * new_capacity);

		if (!new_buffer)
		{
			(*str)->capacity = STRING_INIT_SIZE;

			return DS_ERR_ALLOC;
		}

		(*str)->buffer = new_buffer;

		(*str)->capacity = new_capacity;
	}

	(*str)->len = length;

	size_t i;
	for (i = 0; i < length; i++)
	{
		(*str)->buffer[i] = string[i];
	}

	(*str)->buffer[length] = '\0';

	return DS_OK;
}

Status str_get_string(String *str, char **result)
{
	(*result) = NULL;

	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	char *string = malloc(sizeof(char) * (str->len + 1));

	if (!string)
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < str->len; i++)
		string[i] = str->buffer[i];

	string[str->len] = '\0';

	(*result) = string;

	return DS_OK;
}

Status str_push_char_front(String *str, char ch)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (str_buffer_full(str))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = str->len; i > 0; i--)
	{
		str->buffer[i] = str->buffer[i - 1];
	}

	str->buffer[0] = ch;

	(str->len)++;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_push_char_at(String *str, char ch, size_t index)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (index > str->len)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_push_char_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len)
	{
		st = str_push_char_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else
	{
		if (str_buffer_full(str))
		{
			st = str_realloc(str);

			if (st != DS_OK)
				return st;
		}

		size_t i;
		for (i = str->len; i > index; i--)
		{
			str->buffer[i] = str->buffer[i - 1];
		}

		str->buffer[index] = ch;

		(str->len)++;

		str->buffer[str->len] = '\0';
	}

	return DS_OK;
}

Status str_push_char_back(String *str, char ch)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (str_buffer_full(str))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	str->buffer[str->len] = ch;

	(str->len)++;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_push_front(String *str, char *ch)
{
	if (str == NULL || ch == NULL)
		return DS_ERR_NULL_POINTER;

	size_t len = str_len(ch);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	while (!str_buffer_fits(str, len))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = str->len; i > 0; i--)
	{
		str->buffer[i + len - 1] = str->buffer[i - 1];
	}

	for (i = 0; i < len; i++)
	{
		str->buffer[i] = ch[i];
	}

	str->len += len;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_push_at(String *str, char *ch, size_t index)
{
	if (str == NULL || ch == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (index == 0)
	{
		st = str_push_front(str, ch);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len)
	{
		st = str_push_back(str, ch);

		if (st != DS_OK)
			return st;
	}
	else
	{
		size_t len = str_len(ch);

		if (len == 0)
			return DS_ERR_INVALID_ARGUMENT;

		while (!str_buffer_fits(str, len))
		{
			st = str_realloc(str);

			if (st != DS_OK)
				return st;
		}

		size_t i, j;
		for (i = str->len; i >= index; i--)
		{
			str->buffer[i + len] = str->buffer[i];
		}

		for (i = index, j = 0; i < index + len; i++, j++)
		{
			str->buffer[i] = ch[j];
		}

		str->len += len;

		str->buffer[str->len] = '\0';
	}

	return DS_OK;
}

Status str_push_back(String *str, char *ch)
{
	if (str == NULL || ch == NULL)
		return DS_ERR_NULL_POINTER;

	size_t len = str_len(ch);

	if (len == 0)
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	while (!str_buffer_fits(str, len))
	{
		st = str_realloc(str);

		if (st != DS_OK)
			return st;
	}

	size_t i, j;
	for (i = str->len, j = 0; i < len + str->len; i++, j++)
	{
		str->buffer[i] = ch[j];
	}

	str->len += len;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_prepend(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str2))
		return DS_OK;

	Status st;

	while (!str_buffer_fits(str1, str2->len))
	{
		st = str_realloc(str1);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = str1->len; i > 0; i--)
	{
		str1->buffer[i + str2->len - 1] = str1->buffer[i - 1];
	}

	for (i = 0; i < str2->len; i++)
	{
		str1->buffer[i] = str2->buffer[i];
	}

	str1->len += str2->len;

	str1->buffer[str1->len] = '\0';

	return DS_OK;
}

Status str_add(String *str1, String *str2, size_t index)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	if (index == 0)
	{
		st = str_prepend(str1, str2);

		if (st != DS_OK)
			return st;
	}
	else if (index == str1->len)
	{
		st = str_append(str1, str2);

		if (st != DS_OK)
			return st;
	}
	else
	{
		while (!str_buffer_fits(str1, str2->len))
		{
			st = str_realloc(str1);

			if (st != DS_OK)
				return st;
		}

		size_t i, j;
		for (i = str1->len; i >= index; i--)
		{
			str1->buffer[i + str2->len] = str1->buffer[i];
		}

		for (i = index, j = 0; i < index + str2->len; i++, j++)
		{
			str1->buffer[i] = str2->buffer[j];
		}

		str1->len += str2->len;

		str1->buffer[str1->len] = '\0';
	}

	return DS_OK;
}

Status str_append(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str2))
		return DS_OK;

	Status st;

	while (!str_buffer_fits(str1, str2->len))
	{
		st = str_realloc(str1);

		if (st != DS_OK)
			return st;
	}

	size_t i, j;
	for (i = str1->len, j = 0; i < str1->len + str2->len; i++, j++)
	{
		str1->buffer[i] = str2->buffer[j];
	}

	str1->len += str2->len;

	str1->buffer[str1->len] = '\0';

	return DS_OK;
}

Status str_pop_char_front(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < str->len; i++)
	{
		str->buffer[i] = str->buffer[i + 1];
	}

	(str->len)--;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_pop_char_at(String *str, size_t index)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	if (index >= str->len)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_pop_char_front(str);

		if (st != DS_OK)
			return st;
	}
	else if (index == str->len - 1)
	{
		st = str_pop_char_back(str);

		if (st != DS_OK)
			return st;
	}
	else
	{
		size_t i;
		for (i = index; i < str->len; i++)
		{
			str->buffer[i] = str->buffer[i + 1];
		}

		(str->len)--;

		str->buffer[str->len] = '\0';
	}

	return DS_OK;
}

Status str_pop_char_back(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	(str->len)--;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

Status str_display(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
	{
		printf("\nString\n[ empty ]\n");
		return DS_OK;
	}

	printf("\nString\n%s\n", str->buffer);

	return DS_OK;
}

Status str_display_raw(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (str_buffer_empty(str))
		return DS_OK;

	printf("%s", str->buffer);

	return DS_OK;
}

Status str_delete(String **str)
{
	if ((*str) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*str)->buffer);

	free(*str);

	*str = NULL;

	return DS_OK;
}

Status str_erase(String **str)
{
	if ((*str) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = str_delete(str);

	if (st != DS_OK)
		return st;

	st = str_init(str);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status str_clear(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	str->len = 0;

	str->buffer[0] = '\0';

	return DS_OK;
}

Status str_front(String *str, char *result)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	*result = str->buffer[0];

	return DS_OK;
}

Status str_back(String *str, char *result)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
		return DS_ERR_INVALID_OPERATION;

	*result = str->buffer[str->len - 1];

	return DS_OK;
}

size_t str_length(String *str)
{
	if (str == NULL)
		return 0;

	return str->len;
}

size_t str_len(char *ch)
{
	char *h = ch;

	while (*ch)
		++ch;

	return ch - h;
}

Status str_compare(String *str1, String *str2, int *result)
{
	if (str1 == NULL || str2 == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_greater(str1, str2))
		*result = 1;
	else if (str_lesser(str1, str2))
		*result = -1;
	else
		*result = 0;

	return DS_OK;
}

bool str_greater(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	size_t i, len = (str1->len > str2->len) ? str2->len : str1->len;

	for (i = 0; i < len; i++)
	{
		if (str1->buffer[i] - str2->buffer[i] < 0)
			return true;
		else if (str1->buffer[i] - str2->buffer[i] > 0)
			return false;
	}

	if (str1->len > str2->len)
		return true;

	return false;
}

bool str_equals(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	if (str1->len != str2->len)
		return false;

	size_t i;
	for (i = 0; i < str1->len; i++)
		if (str1->buffer[i] != str2->buffer[i])
			return false;

	return true;
}

bool str_lesser(String *str1, String *str2)
{
	if (str1 == NULL || str2 == NULL)
		return false;

	size_t i, len = (str1->len > str2->len) ? str2->len : str1->len;

	for (i = 0; i < len; i++)
	{
		if (str1->buffer[i] - str2->buffer[i] > 0)
			return true;
		else if (str1->buffer[i] - str2->buffer[i] < 0)
			return false;
	}

	if (str1->len < str2->len)
		return false;

	return true;
}

bool str_equals_str(String *str, char *string)
{
	if (str == NULL || string == NULL)
		return false;

	size_t len = str_len(string);

	if (str->len != len)
		return false;

	size_t i;
	for (i = 0; i < len; i++)
		if (str->buffer[i] != string[i])
			return false;

	return true;
}

Status str_copy(String *str, String **result)
{
	*result = NULL;

	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = str_init(result);

	if (st != DS_OK)
		return st;

	while (!str_buffer_fits(*result, str->len))
	{
		st = str_realloc(*result);

		if (st != DS_OK)
			return st;
	}

	char *s1 = str->buffer, *s2 = (*result)->buffer;

	while (*s2++ = *s1++);

	(*result)->len = str->len;

	return DS_OK;
}

Status str_swap(String **str1, String **str2)
{
	String *temp = (*str1);

	(*str1) = (*str2);
	(*str2) = temp;

	return DS_OK;
}

bool str_buffer_full(String *str)
{
	return (str->len + 1) >= str->capacity;
}

bool str_buffer_empty(String *str)
{
	return str->len == 0;
}

bool str_buffer_fits(String *str, size_t str_len)
{
	return (str->len + str_len) < str->capacity;
}

Status str_realloc(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	str->capacity *= str->growth_rate;

	char *new_buffer = realloc(str->buffer, sizeof(char) * str->capacity);

	if (!new_buffer)
	{
		str->capacity /= str->growth_rate;

		return DS_ERR_ALLOC;
	}

	str->buffer = new_buffer;

	str->buffer[str->len] = '\0';

	return DS_OK;
}

/* ---------------------------------------------------------------------------------------------------- String.c */

/* ---------------------------------------------------------------------------------------------------- Process.c */

Status prc_init(Process **prc, String *name, size_t pid, size_t cpu, size_t io, size_t pri, String *type)
{
	(*prc) = malloc(sizeof(Process));

	if (!(*prc))
		return DS_ERR_ALLOC;

	(*prc)->name = name;

	(*prc)->pid = pid;
	(*prc)->cpu = cpu;
	(*prc)->io = io;
	(*prc)->pri = pri;
	(*prc)->type = type;

	return DS_OK;
}

Status prc_delete(Process **prc)
{
	if (*prc == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = str_delete(&((*prc)->name));

	if (st != DS_OK)
		return st;

	st = str_delete(&((*prc)->type));

	if (st != DS_OK)
		return st;

	free(*prc);

	*prc = NULL;

	return DS_OK;
}

Status prc_display(Process *prc)
{
	if (prc == NULL)
		return DS_ERR_NULL_POINTER;

	printf("%10s\t%zu\t%zu\t%zu\t%zu\t%s\n", prc->name->buffer, prc->pid, prc->cpu, prc->io, prc->pri, prc->type->buffer);

	return DS_OK;
}

int prc_compare(Process *prc1, Process *prc2)
{
	if (prc1 == NULL || prc2 == NULL)
		return 0;

	if (prc1->pid > prc2->pid)
		return 1;
	else if (prc1->pid < prc2->pid)
		return -1;

	return 0;
}

Status prc_copy(Process *prc, Process **result)
{
	if (prc == NULL)
		return DS_ERR_NULL_POINTER;

	String *name, *type;

	Status st = str_copy(prc->name, &name);

	if (st != DS_OK)
		return st;

	st = str_copy(prc->type, &type);

	if (st != DS_OK)
		return st;

	st = prc_init(result, name, prc->pid, prc->cpu, prc->io, prc->pri, type);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// Specific use to prc
size_t prc_translate_type(String *str)
{
	if (str == NULL)
		return 3;

	if (str_equals_str(str, "SO"))
		return 0;
	else if (str_equals_str(str, "UI"))
		return 1;
	else if (str_equals_str(str, "UNI"))
		return 2;
	else
		return 3;
}

/* ---------------------------------------------------------------------------------------------------- Process.c */

/* ---------------------------------------------------------------------------------------------------- QueueArray.c */

Status qua_init(QueueArray **qua)
{
	(*qua) = malloc(sizeof(QueueArray));

	if (!(*qua))
		return DS_ERR_ALLOC;

	(*qua)->buffer = malloc(sizeof(QUEUE_T) * QUEUE_ARRAY_INIT_SIZE);

	if (!((*qua)->buffer))
		return DS_ERR_ALLOC;

	(*qua)->capacity = QUEUE_ARRAY_INIT_SIZE;
	(*qua)->growth_rate = QUEUE_ARRAY_GROW_RATE;

	(*qua)->length = 0;

	return DS_OK;
}

Status qua_get_length(QueueArray *qua, size_t *result)
{
	if (qua == NULL)
		return DS_ERR_NULL_POINTER;

	*result = qua->length;

	return DS_OK;
}

size_t qua_length(QueueArray *qua)
{
	return qua->length;
}

Status qua_enqueue(QueueArray *qua, QUEUE_T value)
{
	if (qua == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_full(qua))
	{
		Status st = qua_realloc(qua);

		if (st != DS_OK)
			return st;
	}

	qua->buffer[qua->length] = value;

	(qua->length)++;

	return DS_OK;
}

Status qua_dequeue(QueueArray *qua, QUEUE_T *value)
{
	*value = 0;

	if (qua == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_empty(qua))
		return DS_ERR_INVALID_OPERATION;

	*value = qua->buffer[0];

	size_t i;

	for (i = 0; i < qua->length - 1; i++)
	{
		qua->buffer[i] = qua->buffer[i + 1];
	}

	(qua->length)--;

	return DS_OK;
}

Status qua_display(QueueArray *qua)
{
	if (qua == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Process Name", "PID", "CPU", "I/O", "PRI", "TYPE");
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "------------", "---", "---", "---", "---", "----");

	if (qua_is_empty(qua))
	{
		printf("\n");

		return DS_OK;
	}

	Status st;

	size_t i;
	for (i = 0; i < qua->length; i++)
	{
		st = QUEUE_DISPLAY(qua->buffer[i]);

		if (st != DS_OK)
			return st;
	}

	printf("\n");

	return DS_OK;
}

Status qua_delete(QueueArray **qua)
{
	if ((*qua) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	size_t i;
	for (i = 0; i < (*qua)->length; i++)
	{
		st = QUEUE_DELETE(&((*qua)->buffer[i]));

		if (st != DS_OK)
			return st;
	}

	free((*qua)->buffer);

	free(*qua);

	*qua = NULL;

	return DS_OK;
}

Status qua_delete_shallow(QueueArray **qua)
{
	if ((*qua) == NULL)
		return DS_ERR_NULL_POINTER;

	free((*qua)->buffer);

	free(*qua);

	*qua = NULL;

	return DS_OK;
}

Status qua_erase(QueueArray **qua)
{
	if ((*qua) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = qua_delete(qua);

	if (st != DS_OK)
		return st;

	st = qua_init(qua);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

bool qua_is_empty(QueueArray *qua)
{
	return qua->length == 0;
}

bool qua_is_full(QueueArray *qua)
{
	return qua->length == qua->capacity;
}

//Status qua_copy(QueueArray *qua, QueueArray **result)

Status qua_realloc(QueueArray *qua)
{
	if (qua == NULL)
		return DS_ERR_NULL_POINTER;

	qua->capacity *= qua->growth_rate;

	QUEUE_T *new_buffer = realloc(qua->buffer, sizeof(QUEUE_T) * qua->capacity);

	if (!new_buffer)
	{
		qua->capacity /= qua->growth_rate;

		return DS_ERR_ALLOC;
	}

	qua->buffer = new_buffer;

	return DS_OK;
}

/* ---------------------------------------------------------------------------------------------------- QueueArray.c */

/* ---------------------------------------------------------------------------------------------------- DynamicArray.c */

Status dar_init(DynamicArray **dar)
{
	(*dar) = malloc(sizeof(DynamicArray));

	if (!(*dar))
		return DS_ERR_ALLOC;

	(*dar)->buffer = calloc(DYNAMIC_ARRAY_INIT_SIZE, sizeof(DS_DAR_T));

	if (!((*dar)->buffer))
		return DS_ERR_ALLOC;

	(*dar)->capacity = DYNAMIC_ARRAY_INIT_SIZE;
	(*dar)->growth_rate = DYNAMIC_ARRAY_GROW_RATE;

	(*dar)->size = 0;

	return DS_OK;
}

Status dar_insert_front(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_full(dar))
	{
		Status st = dar_realloc(dar);

		if (st != DS_OK)
			return st;
	}

	size_t i;
	for (i = dar->size; i > 0; i--)
	{
		dar->buffer[i] = dar->buffer[i - 1];
	}

	dar->buffer[0] = value;

	(dar->size)++;

	return DS_OK;
}

Status dar_insert_at(DynamicArray *dar, DS_DAR_T value, size_t index)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (index > dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = dar_insert_front(dar, value);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size)
	{
		st = dar_insert_back(dar, value);

		if (st != DS_OK)
			return st;
	}
	else
	{
		if (dar_is_full(dar))
		{
			st = dar_realloc(dar);

			if (st != DS_OK)
				return st;
		}

		size_t i;
		for (i = dar->size; i > index; i--)
		{
			dar->buffer[i] = dar->buffer[i - 1];
		}

		dar->buffer[index] = value;

		(dar->size)++;
	}

	return DS_OK;
}

Status dar_insert_back(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_full(dar))
	{
		Status st = dar_realloc(dar);

		if (st != DS_OK)
			return st;
	}

	dar->buffer[dar->size] = value;

	(dar->size)++;

	return DS_OK;
}

Status dar_remove_front(DynamicArray *dar, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[0];

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		dar->buffer[i] = dar->buffer[i + 1];
	}

	(dar->size)--;

	return DS_OK;
}

Status dar_remove_at(DynamicArray *dar, size_t index, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = dar_remove_front(dar, result);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size - 1)
	{
		st = dar_remove_back(dar, result);

		if (st != DS_OK)
			return st;
	}
	else
	{
		*result = dar->buffer[index];

		size_t i;
		for (i = index; i < dar->size; i++)
		{
			dar->buffer[i] = dar->buffer[i + 1];
		}

		(dar->size)--;
	}

	return DS_OK;
}

Status dar_remove_back(DynamicArray *dar, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[dar->size - 1];

	(dar->size)--;

	return DS_OK;
}

Status dar_remove_keys(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	DS_DAR_T result;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
		{
			st = dar_remove_at(dar, i, &result);

			if (st != DS_OK)
				return st;

			st = DS_DAR_DELETE(&result);

			if (st != DS_OK)
				return st;

			i--;
		}
	}

	return DS_OK;
}

Status dar_display(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Process Name", "PID", "CPU", "I/O", "PRI", "TYPE");
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "------------", "---", "---", "---", "---", "----");

	if (dar_is_empty(dar))
	{
		printf("\n");

		return DS_OK;
	}

	Status st;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		st = DS_DAR_DISPLAY(dar->buffer[i]);

		if (st != DS_OK)
			return st;
	}

	printf("\n");

	return DS_OK;
}

Status dar_delete(DynamicArray **dar)
{
	if (*dar == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	size_t i;
	for (i = 0; i < (*dar)->size; i++)
	{
		st = DS_DAR_DELETE(&((*dar)->buffer[i]));

		if (st != DS_OK)
			return st;
	}

	free((*dar)->buffer);
	free((*dar));

	(*dar) = NULL;

	return DS_OK;
}

Status dar_delete_shallow(DynamicArray **dar)
{
	if (*dar == NULL)
		return DS_ERR_NULL_POINTER;

	free((*dar)->buffer);
	free((*dar));

	(*dar) = NULL;

	return DS_OK;
}

Status dar_erase(DynamicArray **dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = dar_delete(dar);

	if (st != DS_OK)
		return st;

	st = dar_init(dar);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status dar_get(DynamicArray *dar, size_t index, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	*result = dar->buffer[index];

	return DS_OK;
}

size_t dar_cap(DynamicArray *dar)
{
	return dar->capacity;
}

size_t dar_size(DynamicArray *dar)
{
	return dar->size;
}

bool dar_is_empty(DynamicArray *dar)
{
	return dar->size == 0;
}

bool dar_is_full(DynamicArray *dar)
{
	return dar->size == dar->capacity;
}

Status dar_find_max(DynamicArray *dar, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[0];

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], *result) > 0)
			*result = dar->buffer[i];
	}

	return DS_OK;
}

Status dar_find_min(DynamicArray *dar, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[0];

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], *result) < 0)
			*result = dar->buffer[i];
	}

	return DS_OK;
}

Status dar_find_max_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], dar->buffer[(*result)]) > 0)
			*result = i;
	}

	return DS_OK;
}

Status dar_find_min_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], dar->buffer[(*result)]) < 0)
			*result = i;
	}

	return DS_OK;
}

bool dar_exists(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return false;

	if (dar_is_empty(dar))
		return false;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
			return true;
	}

	return false;
}

Status dar_copy(DynamicArray *dar, QueueArray **result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = qua_init(result);

	if (st != DS_OK)
		return st;

	DS_DAR_T copy;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		st = DS_DAR_COPY(dar->buffer[i], &copy);

		if (st != DS_OK)
			return st;

		st = qua_enqueue(*result, copy);

		if (st != DS_OK)
			return st;

		copy = NULL;
	}

	return DS_OK;
}

Status dar_realloc(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	dar->capacity *= dar->growth_rate;

	DS_DAR_T *new_buffer = realloc(dar->buffer, sizeof(DS_DAR_T) * dar->capacity);

	if (!new_buffer)
	{
		dar->capacity /= dar->growth_rate;

		return DS_ERR_ALLOC;
	}

	dar->buffer = new_buffer;

	return DS_OK;
}

Status sort_selection_array_dar(DS_DAR_T *array, size_t arr_size)
{
	if (array == NULL)
		return DS_ERR_NULL_POINTER;

	if (arr_size < 2)
		return DS_ERR_INVALID_SIZE;

	size_t i, j, min;
	DS_DAR_T tmp;

	for (i = 0; i < arr_size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < arr_size; j++)
			if (DS_DAR_COMPARATOR(array[j], array[min]) < 0)
				min = j;

		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
	}

	return DS_OK;
}

/* ---------------------------------------------------------------------------------------------------- DynamicArray.c */

/* ---------------------------------------------------------------------------------------------------- PriorityQueue.c */

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

Status prq_make_node(PriorityQueueNode **node, PQUEUE_T value, size_t priority)
{
	(*node) = malloc(sizeof(PriorityQueueNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->prev = NULL;

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

		scan = scan->prev;
	}

	if ((*result) != prq->length)
		return DS_ERR_UNEXPECTED_RESULT;

	return DS_OK;
}

Status prq_enqueue(PriorityQueue *prq, PQUEUE_T value, size_t priority)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	PriorityQueueNode *node;

	prq_make_node(&node, value, priority);

	if (!node)
		return DS_ERR_ALLOC;

	if (prq_is_empty(prq))
	{
		prq->rear = node;
		prq->front = node;
	}
	else
	{

		PriorityQueueNode *before = NULL;
		PriorityQueueNode *curr = prq->front;

		while (curr != NULL && curr->priority <= node->priority)
		{
			before = curr;

			curr = curr->prev;
		}

		if (before == NULL)
		{

			node->prev = prq->front;

			prq->front = node;
		}
		else
		{

			node->prev = curr;

			before->prev = node;
		}
	}

	(prq->length)++;

	return DS_OK;
}

Status prq_dequeue(PriorityQueue *prq, PQUEUE_T *result)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	if (prq_is_empty(prq))
		return DS_ERR_INVALID_OPERATION;

	PriorityQueueNode *node = prq->front;

	prq->front = prq->front->prev;

	*result = node->data;

	free(node);

	(prq->length)--;

	if (prq->length == 0)
		prq->rear = NULL;

	return DS_OK;
}

Status prq_display(PriorityQueue *prq)
{
	if (prq == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Process Name", "PID", "CPU", "I/O", "PRI", "TYPE");
	printf("%s\t%s\t%s\t%s\t%s\t%s\n", "------------", "---", "---", "---", "---", "----");

	if (prq_is_empty(prq))
	{
		printf("\n");

		return DS_OK;
	}

	PriorityQueueNode *scan = prq->front;

	while (scan != NULL)
	{
		PQUEUE_DISPLAY(scan->data);

		scan = scan->prev;
	}

	printf("\n");

	return DS_OK;
}

Status prq_delete_node(PriorityQueueNode **node)
{
	Status st = PQUEUE_DELETE(&((*node)->data));

	if (st != DS_OK)
		return st;

	free(*node);

	(*node) = NULL;

	return DS_OK;
}

Status prq_delete_queue(PriorityQueue **prq)
{
	if ((*prq) == NULL)
		return DS_ERR_NULL_POINTER;

	Status st;

	PriorityQueueNode *prev = (*prq)->front;

	while ((*prq)->front != NULL)
	{
		(*prq)->front = (*prq)->front->prev;

		st = prq_delete_node(&prev);

		if (st != DS_OK)
			return st;

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

bool prq_is_empty(PriorityQueue *prq)
{
	return (prq->length == 0 || prq->rear == NULL);
}

/* ---------------------------------------------------------------------------------------------------- PriorityQueue.c */

/* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         Source Files
 *
 * ---------------------------------------------------------------------------------------------------- */

 /* ----------------------------------------------------------------------------------------------------
  *
  *                                                                                         File IO Functions
  *
  * ---------------------------------------------------------------------------------------------------- */

Status file_load(DynamicArray *process_table)
{
	String *text;

	Status st = str_init(&text);

	if (st != DS_OK)
		return st;

	FILE *file = fopen(FILE_NAME, "r");

	if (file == NULL)
		return DS_ERR_UNEXPECTED_RESULT;

	char c;

	while (1)
	{
		c = fgetc(file);

		if (c == EOF)
			break;

		st = str_push_char_back(text, c);

		if (st != DS_OK)
			return st;
	}

	fclose(file);

	if (text->len == 0)
	{
		str_delete(&text);
		return DS_OK;
	}

	String *name, *pid_s, *cpu_s, *io_s, *pri_s, *type;
	size_t pid, cpu, io, pri;

	while (text->len > 1)
	{
		st += str_init(&name);
		st += str_init(&pid_s);
		st += str_init(&cpu_s);
		st += str_init(&io_s);
		st += str_init(&pri_s);
		st += str_init(&type);

		if (st != DS_OK)
			return st;

		// Find name
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == ',')
				break;

			st = str_push_char_back(name, c);

			if (st != DS_OK)
				return st;
		}

		// Find pid_s
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == ',')
				break;

			st = str_push_char_back(pid_s, c);

			if (st != DS_OK)
				return st;
		}

		// Find cpu_s
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == ',')
				break;

			st = str_push_char_back(cpu_s, c);

			if (st != DS_OK)
				return st;
		}

		// Find io_s
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == ',')
				break;

			st = str_push_char_back(io_s, c);

			if (st != DS_OK)
				return st;
		}

		// Find pri_s
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == ',')
				break;

			st = str_push_char_back(pri_s, c);

			if (st != DS_OK)
				return st;
		}

		// Find type
		while (1)
		{
			c = text->buffer[0];

			st = str_pop_char_front(text);

			if (st != DS_OK)
				return st;

			if (c == '\n')
				break;

			st = str_push_char_back(type, c);

			if (st != DS_OK)
				return st;
		}

		Process *process;

		// Convert pid
		sscanf(pid_s->buffer, "%zu", &pid);

		// Convert cpu
		sscanf(cpu_s->buffer, "%zu", &cpu);

		// Convert io
		sscanf(io_s->buffer, "%zu", &io);

		// Convert priority
		sscanf(pri_s->buffer, "%zu", &pri);

		// Create process
		st = prc_init(&process, name, pid, cpu, io, pri, type);

		if (st != DS_OK)
			return st;

		// Add to array
		st = dar_insert_back(process_table, process);

		if (st != DS_OK)
			return st;

		process = NULL;

		type = NULL;
		name = NULL;

		str_delete(&pid_s);
		str_delete(&cpu_s);
		str_delete(&io_s);
		str_delete(&pri_s);
	}

	str_delete(&text);

	return DS_OK;
}

Status file_save(DynamicArray *content)
{
	FILE *f = fopen(FILE_NAME, "w");

	if (f == NULL)
		return DS_ERR_UNEXPECTED_RESULT;

	size_t i;
	for (i = 0; i < content->size; i++)
	{
		fprintf(f, "%s,%zu,%zu,%zu,%zu,%s\n", content->buffer[i]->name->buffer,
			content->buffer[i]->pid, content->buffer[i]->cpu, content->buffer[i]->io,
			content->buffer[i]->pri, content->buffer[i]->type->buffer);
	}

	fclose(f);

	return DS_OK;
}

/* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         File IO Functions
 *
 * ---------------------------------------------------------------------------------------------------- */

 /* ----------------------------------------------------------------------------------------------------
  *
  *                                                                                         Algorithms
  *
  * ---------------------------------------------------------------------------------------------------- */

Status alg_round_robin(QueueArray *pqueue)
{
	if (pqueue == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_empty(pqueue))
		return DS_ERR_INVALID_ARGUMENT;

	Status st;

	QueueArray *finished;

	st = qua_init(&finished);

	if (st != DS_OK)
		return st;

	// IO
	Process *blocked = NULL;

	Process *current = NULL;

	size_t iterations = 0;

	while (1)
	{
		CLEAR_SCREEN;

		if (pqueue->length == 0 && blocked != NULL)
		{
			st = qua_enqueue(pqueue, blocked);

			if (st != DS_OK)
				return st;

			blocked = NULL;
		}

		st = qua_dequeue(pqueue, &current);

		if (st != DS_OK)
			return st;

		if (current->cpu > 0)
			(current->cpu)--;

		if (current->io > 0)
		{
			if (blocked == NULL)
			{
				(current->io)--;

				blocked = current;
			}
			else
			{
				st = qua_enqueue(pqueue, blocked);

				if (st != DS_OK)
					return st;

				(current->io)--;

				blocked = current;
			}

		}
		else
		{
			if (current->cpu > 0)
			{
				st = qua_enqueue(pqueue, current);

				if (st != DS_OK)
					return st;
			}
			else
			{
				st = qua_enqueue(finished, current);

				if (st != DS_OK)
					return st;
			}

		}

		current = NULL;

		qua_display(pqueue);

		printf("\nCurrently blocked:\n");

		if (blocked != NULL)
			prc_display(blocked);
		else
			printf("None\n");

		SLEEP_F;
		//getch();

		iterations++;

		if (pqueue->length == 0 && blocked == NULL)
			break;
	}

	printf("\nResults\n");

	qua_display(finished);

	printf("\nFinished in %zu iterations", iterations);

	getch();

	st = qua_delete(&finished);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status alg_pri_static(QueueArray *pqueue)
{
	if (pqueue == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_empty(pqueue))
		return DS_ERR_INVALID_ARGUMENT;

	PriorityQueue *pri_queue;
	QueueArray *finished;

	Status st = prq_init_queue(&pri_queue);

	if (st != DS_OK)
		return st;

	st = qua_init(&finished);

	if (st != DS_OK)
		return st;

	Process *current = NULL;
	Process *blocked = NULL;

	size_t i, len = pqueue->length;
	for (i = 0; i < len; i++)
	{
		st = qua_dequeue(pqueue, &current);

		if (st != DS_OK)
			return st;

		st = prq_enqueue(pri_queue, current, current->pri);

		if (st != DS_OK)
			return st;
	}

	size_t iterations = 0;

	while (1)
	{
		CLEAR_SCREEN;

		if (pri_queue->length == 0 && blocked != NULL)
		{
			st = prq_enqueue(pri_queue, blocked, blocked->pri);

			if (st != DS_OK)
				return st;

			blocked = NULL;
		}

		st = prq_dequeue(pri_queue, &current);

		if (st != DS_OK)
			return st;

		if (current->cpu > 0)
			(current->cpu)--;

		if (current->io > 0)
		{
			if (blocked == NULL)
			{
				(current->io)--;

				blocked = current;
			}
			else
			{
				st = prq_enqueue(pri_queue, blocked, blocked->pri);

				if (st != DS_OK)
					return st;

				(current->io)--;

				blocked = current;
			}
		}
		else
		{
			if (current->cpu > 0)
			{
				st = prq_enqueue(pri_queue, current, current->pri);

				if (st != DS_OK)
					return st;
			}
			else
			{
				st = qua_enqueue(finished, current);

				if (st != DS_OK)
					return st;
			}
		}

		current = NULL;

		prq_display(pri_queue);

		printf("\nCurrently blocked:\n");

		if (blocked != NULL)
			prc_display(blocked);
		else
			printf("None\n");

		SLEEP_F;
		//getch();

		iterations++;

		if (pri_queue->length == 0 && blocked == NULL)
			break;
	}

	printf("\nResults\n");

	qua_display(finished);

	printf("\nFinished in %zu iterations", iterations);

	st = prq_delete_queue(&pri_queue);

	getch();

	if (st != DS_OK)
		return st;

	st = qua_delete(&finished);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status alg_pri_dynamic(QueueArray *pqueue)
{
	if (pqueue == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_empty(pqueue))
		return DS_ERR_INVALID_ARGUMENT;

	PriorityQueue *pri_queue;
	QueueArray *finished;

	Status st = prq_init_queue(&pri_queue);

	if (st != DS_OK)
		return st;

	st = qua_init(&finished);

	if (st != DS_OK)
		return st;

	Process *current = NULL;
	Process *blocked = NULL;

	size_t i, len = pqueue->length;
	for (i = 0; i < len; i++)
	{
		st = qua_dequeue(pqueue, &current);

		if (st != DS_OK)
			return st;

		st = prq_enqueue(pri_queue, current, current->pri);

		if (st != DS_OK)
			return st;
	}

	size_t iterations = 0;

	while (1)
	{
		CLEAR_SCREEN;

		if (pri_queue->length == 0 && blocked != NULL)
		{
			if (blocked->pri > 0)
				(blocked->pri)--;

			st = prq_enqueue(pri_queue, blocked, blocked->pri);

			if (st != DS_OK)
				return st;

			blocked = NULL;
		}

		st = prq_dequeue(pri_queue, &current);

		if (st != DS_OK)
			return st;

		if (current->cpu > 0)
			(current->cpu)--;

		if (current->io > 0)
		{
			if (blocked == NULL)
			{
				(current->io)--;

				blocked = current;
			}
			else
			{
				if (blocked->pri > 0)
					(blocked->pri)--;

				st = prq_enqueue(pri_queue, blocked, blocked->pri);

				if (st != DS_OK)
					return st;

				(current->io)--;

				blocked = current;
			}
		}
		else
		{
			if (current->cpu > 0)
			{
				if (current->pri > 0)
					(current->pri)++;

				st = prq_enqueue(pri_queue, current, current->pri);

				if (st != DS_OK)
					return st;
			}
			else
			{
				st = qua_enqueue(finished, current);

				if (st != DS_OK)
					return st;
			}
		}

		current = NULL;

		prq_display(pri_queue);

		printf("\nCurrently blocked:\n");

		if (blocked != NULL)
			prc_display(blocked);
		else
			printf("None\n");

		SLEEP_F;
		//getch();

		iterations++;

		if (pri_queue->length == 0 && blocked == NULL)
			break;
	}

	printf("\nResults\n");

	qua_display(finished);

	printf("\nFinished in %zu iterations", iterations);

	st = prq_delete_queue(&pri_queue);

	getch();

	if (st != DS_OK)
		return st;

	st = qua_delete(&finished);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status alg_pri_type(QueueArray *pqueue)
{
	if (pqueue == NULL)
		return DS_ERR_NULL_POINTER;

	if (qua_is_empty(pqueue))
		return DS_ERR_INVALID_ARGUMENT;

	PriorityQueue *pri_queue;
	QueueArray *finished;

	Status st = prq_init_queue(&pri_queue);

	if (st != DS_OK)
		return st;

	st = qua_init(&finished);

	if (st != DS_OK)
		return st;

	Process *current = NULL;
	Process *blocked = NULL;

	size_t i, len = pqueue->length;
	for (i = 0; i < len; i++)
	{
		st = qua_dequeue(pqueue, &current);

		if (st != DS_OK)
			return st;

		st = prq_enqueue(pri_queue, current, prc_translate_type(current->type));

		if (st != DS_OK)
			return st;
	}

	size_t iterations = 0;

	while (1)
	{
		CLEAR_SCREEN;

		if (pri_queue->length == 0 && blocked != NULL)
		{
			st = prq_enqueue(pri_queue, blocked, prc_translate_type(blocked->type));

			if (st != DS_OK)
				return st;

			blocked = NULL;
		}

		st = prq_dequeue(pri_queue, &current);

		if (st != DS_OK)
			return st;

		if (current->cpu > 0)
			(current->cpu)--;

		if (current->io > 0)
		{
			if (blocked == NULL)
			{
				(current->io)--;

				blocked = current;
			}
			else
			{
				st = prq_enqueue(pri_queue, blocked, prc_translate_type(blocked->type));

				if (st != DS_OK)
					return st;

				(current->io)--;

				blocked = current;
			}
		}
		else
		{
			if (current->cpu > 0)
			{
				st = prq_enqueue(pri_queue, current, prc_translate_type(current->type));

				if (st != DS_OK)
					return st;
			}
			else
			{
				st = qua_enqueue(finished, current);

				if (st != DS_OK)
					return st;
			}
		}

		current = NULL;

		prq_display(pri_queue);

		printf("\nCurrently blocked:\n");

		if (blocked != NULL)
			prc_display(blocked);
		else
			printf("None\n");

		SLEEP_F;
		//getch();

		iterations++;

		if (pri_queue->length == 0 && blocked == NULL)
			break;
	}

	printf("\nResults\n");

	qua_display(finished);

	printf("\nFinished in %zu iterations", iterations);

	st = prq_delete_queue(&pri_queue);

	getch();

	if (st != DS_OK)
		return st;

	st = qua_delete(&finished);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

/* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         Algorithms
 *
 * ---------------------------------------------------------------------------------------------------- */

 /* ----------------------------------------------------------------------------------------------------
  *
  *                                                                                         Menu Functions
  *
  * ---------------------------------------------------------------------------------------------------- */

Status process_table(DynamicArray **ptable)
{
	Status st;

	int choice;

	size_t i;

	while (1)
	{
		CLEAR_SCREEN;
		printf(" +--------------------------------------------------+\n");
		printf(" |                  Process Table                   |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" | 0 - Return                                       |\n");
		printf(" | 1 - Add process                                  |\n");
		printf(" | 2 - Alter process                                |\n");
		printf(" | 3 - Remove process                               |\n");
		printf(" | 4 - List process table                           |\n");
		printf(" | 5 - Clear process table                          |\n");
		printf(" | 6 - Reload from file                             |\n");
		printf(" | 7 - Save to file                                 |\n");
		printf(" | 8 - Sort table by PID                            |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" > ");

		scanf("%d", &choice);

		if (choice == 0)
		{
			return DS_OK;
		}
		else if (choice == 1)
		{
			String *name, *type;
			size_t pid = 0, pri, cpu, io;

			st += str_init(&name);
			st += str_init(&type);

			if (st != DS_OK)
				return st;

			char c = ' ';

			getchar(); // get newline from scanf

			printf("Name > ");
			while (c != '\n')
			{
				c = getchar();

				if (c != '\n')
				{
					st = str_push_char_back(name, c);

					if (st != DS_OK)
						return st;
				}
			}

			c = ' ';

			printf("Type > ");
			while (c != '\n')
			{
				c = getchar();

				if (c != '\n')
				{
					st = str_push_char_back(type, c);

					if (st != DS_OK)
						return st;
				}
			}

			printf("PRI > ");
			scanf("%zu", &pri);

			printf("CPU > ");
			scanf("%zu", &cpu);

			printf("I/O > ");
			scanf("%zu", &io);

			if ((*ptable)->size == 0)
				pid = 1001;
			else
			{
				for (i = 0; i < (*ptable)->size; i++)
				{
					if ((*ptable)->buffer[i]->pid > pid)
						pid = (*ptable)->buffer[i]->pid;
				}

				pid++;
			}

			Process *process;

			st = prc_init(&process, name, pid, cpu, io, pri, type);

			if (st != DS_OK)
				return st;

			st = dar_insert_back(*ptable, process);

			if (st != DS_OK)
				return st;

		}
		else if (choice == 2)
		{
			if ((*ptable)->size == 0)
			{
				printf("Process table is empty...");

				getch();

				continue;
			}

			Process *alter = NULL;

			size_t pid;

			printf("PID > ");
			scanf("%zu", &pid);

			bool found = false;

			for (i = 0; i < (*ptable)->size; i++)
			{
				if ((*ptable)->buffer[i]->pid == pid)
				{
					found = true;

					alter = (*ptable)->buffer[i];
				}
			}

			if (!found)
			{
				printf("Process not found...");

				getch();
			}
			else
			{
				while (1)
				{
					CLEAR_SCREEN;
					printf(" +--------------------------------------------------+\n");
					printf(" |                  Alter Process                   |\n");
					printf(" +--------------------------------------------------+\n");
					printf(" | 0 - Return                                       |\n");
					printf(" | 1 - Alter Name                                   |\n");
					printf(" | 2 - Alter Process ID                             |\n");
					printf(" | 3 - Alter CPU                                    |\n");
					printf(" | 4 - Alter I/O                                    |\n");
					printf(" | 5 - Alter Priority                               |\n");
					printf(" | 6 - Alter Type                                   |\n");
					printf(" +--------------------------------------------------+\n");
					printf("\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\n", "Process Name", "PID", "CPU", "I/O", "PRI", "TYPE");
					printf("%s\t%s\t%s\t%s\t%s\t%s\n", "------------", "---", "---", "---", "---", "----");
					prc_display(alter);
					printf("\n\n");
					printf(" > ");

					scanf("%zu", &choice);

					if (choice == 0)
					{
						break;
					}
					else if (choice == 1)
					{
						String *new_name;

						st = str_init(&new_name);

						if (st != DS_OK)
							return st;

						char ch = ' ';

						getchar(); // get newline from scanf

						printf("Name > ");
						while (ch != '\n')
						{
							ch = getchar();

							if (ch != '\n')
							{
								st = str_push_char_back(new_name, ch);

								if (st != DS_OK)
									return st;
							}
						}

						st = str_delete(&(alter->name));

						if (st != DS_OK)
							return st;

						alter->name = new_name;
					}
					else if (choice == 2)
					{
						size_t new_pid;

						bool exists = false;

						printf("PID > ");
						scanf("%zu", &new_pid);

						for (i = 0; i < (*ptable)->size; i++)
						{
							if ((*ptable)->buffer[i]->pid == new_pid)
							{
								exists = true;

								break;
							}
						}

						if (exists)
						{
							printf("PID already exists...");

							getch();
						}
						else
						{
							alter->pid = new_pid;
						}
					}
					else if (choice == 3)
					{
						size_t new_cpu;

						printf("CPU > ");
						scanf("%zu", &new_cpu);

						alter->cpu = new_cpu;
					}
					else if (choice == 4)
					{
						size_t new_io;

						printf("I/O > ");
						scanf("%zu", &new_io);

						alter->io = new_io;
					}
					else if (choice == 5)
					{
						size_t new_pri;

						printf("PRI > ");
						scanf("%zu", &new_pri);

						alter->pri = new_pri;
					}
					else if (choice == 6)
					{
						String *new_type;

						st = str_init(&new_type);

						if (st != DS_OK)
							return st;

						char n = ' ';

						getchar(); // get newline from scanf

						printf("Type > ");
						while (n != '\n')
						{
							n = getchar();

							if (n != '\n')
							{
								st = str_push_char_back(new_type, n);

								if (st != DS_OK)
									return st;
							}
						}

						st = str_delete(&(alter->type));

						if (st != DS_OK)
							return st;

						alter->type = new_type;
					}
					else
					{
						printf("Invalid command...");

						getch();
					}
				}
			}


		}
		else if (choice == 3)
		{
			Process *remove;

			size_t pid;

			printf("PID > ");
			scanf("%zu", &pid);

			bool found = false;
			for (i = 0; i < (*ptable)->size; i++)
			{
				if ((*ptable)->buffer[i]->pid == pid)
				{
					found = true;

					st = dar_remove_at(*ptable, i, &remove);

					if (st != DS_OK)
						return st;

					st = prc_delete(&remove);

					if (st != DS_OK)
						return st;
				}
			}

			if (!found)
			{
				printf("Process not found...");

				getch();
			}

		}
		else if (choice == 4)
		{
			st = dar_display(*ptable);

			if (st != DS_OK)
				return st;

			printf("\nPress enter to continue...");
			getch();
		}
		else if (choice == 5)
		{
			st = dar_erase(ptable);

			if (st != DS_OK)
				return st;
		}
		else if (choice == 6)
		{
			st = dar_erase(ptable);

			if (st != DS_OK)
				return st;

			st = file_load(*ptable);

			if (st != DS_OK)
				return st;
		}
		else if (choice == 7)
		{
			st = file_save(*ptable);

			if (st != DS_OK)
			{
				print_status_repr(st);

				return st;
			}
		}
		else if (choice == 8)
		{
			st = sort_selection_array_dar((*ptable)->buffer, (*ptable)->size);

			if (st != DS_OK)
				return st;
		}
		else
		{
			printf("Invalid command...");

			getch();
		}
	}

	return DS_OK;
}

Status process_scheduling(DynamicArray *ptable)
{
	Status st;

	while (1)
	{
		CLEAR_SCREEN;
		printf(" +--------------------------------------------------+\n");
		printf(" |           Process Scheduling Algorithms          |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" | 0 - Return                                       |\n");
		printf(" | 1 - Round Robin                                  |\n");
		printf(" | 2 - Static Priority                              |\n");
		printf(" | 3 - Dynamic Priority                             |\n");
		printf(" | 4 - By Process Type                              |\n");
		printf(" | 5 - All Algorithms                               |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" > ");

		int choice;

		scanf("%d", &choice);

		if (choice == 0)
		{
			return DS_OK;
		}
		else if (choice >= 1 && choice <= 5)
		{
			QueueArray *queue;

			st = dar_copy(ptable, &queue);

			if (st != DS_OK)
				return st;

			st = sort_selection_array_dar(queue->buffer, queue->length);

			if (st != DS_OK)
				return st;

			if (choice == 1)
			{
				st = alg_round_robin(queue);

				if (st != DS_OK)
				{
					print_status_repr(st);

					getch();
				}
			}
			else if (choice == 2)
			{
				st = alg_pri_static(queue);

				if (st != DS_OK)
				{
					print_status_repr(st);

					getch();
				}
			}
			else if (choice == 3)
			{
				st = alg_pri_dynamic(queue);

				if (st != DS_OK)
				{
					print_status_repr(st);

					getch();
				}
			}
			else if (choice == 4)
			{
				st = alg_pri_type(queue);

				if (st != DS_OK)
				{
					print_status_repr(st);

					getch();
				}
			}
			else if (choice == 5)
			{
				// TODO
				// All algorithms
			}

			st = qua_delete(&queue);

			if (st != DS_OK)
				return st;
		}
		else
		{
			printf("Invalid command...");

			getch();
		}
	}

	return DS_OK;
}

void copyright(void)
{
	CLEAR_SCREEN;
	printf(" +--------------------------------------------------+\n");
	printf(" |                     Copyright                    |\n");
	printf(" +--------------------------------------------------+\n");
	printf(" | Leonardo Vencovsky 201710276                     |\n");
	printf(" +--------------------------------------------------+\n");

	printf("\nPress enter to continue...");

	getch();
}

/* ----------------------------------------------------------------------------------------------------
 *
 *                                                                                         Menu Functions
 *
 * ---------------------------------------------------------------------------------------------------- */

int main()
{
	DynamicArray *ptable;

	Status st = dar_init(&ptable);

	if (st != DS_OK)
		return st;

	st = file_load(ptable);

	if (st != DS_OK)
	{
		print_status_repr(st);

		return st;
	}

	bool exit = false;

	int choice;

	while (!exit)
	{
		CLEAR_SCREEN;
		printf(" +--------------------------------------------------+\n");
		printf(" |              Process Scheduling Menu             |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" | 0 - Exit                                         |\n");
		printf(" | 1 - Process Table                                |\n");
		printf(" | 2 - Process Scheduling                           |\n");
		printf(" | 3 - Copyright                                    |\n");
		printf(" +--------------------------------------------------+\n");
		printf(" > ");

		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			exit = true;
			break;
		case 1:
			st = process_table(&ptable);
			if (st != DS_OK)
			{
				print_status_repr(st);
				getchar();
				return st;
			}
			break;
		case 2:
			st = process_scheduling(ptable);
			if (st != DS_OK)
			{
				print_status_repr(st);
				getchar();
				return st;
			}
			break;
		case 3:
			copyright();
			break;
		default:
			printf("Invalid command...");
			getch();
			break;
		}
	}

	dar_delete(&ptable);

	return 0;
}
