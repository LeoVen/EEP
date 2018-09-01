/**
 * @file StringDynamicArray.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 01/09/2018
 *
 * @brief Crazy experiment
 *
 * So I decided to join two data structures to make one. A dynamic-sized array
 * (struct DynamicArray) of strings (struct String). At last I've been able to
 * implement it and even sort the array. Phew!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum Status
{
	DS_OK =                    0, /**< Returned by a function when all operations were successful */
	DS_ERR_INVALID_POSITION =  1, /**< When an invalid position is passed as argument */
	DS_ERR_INVALID_OPERATION = 2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
	DS_ERR_INVALID_SIZE =      3, /**< When an invalid size is given */
	DS_ERR_NOT_FOUND =         4, /**< When a search fails to find a value */
	DS_ERR_ALLOC =             5, /**< When a function fails to allocate memory  */
	DS_ERR_UNEXPECTED_RESULT = 6, /**< When an unexpected result happens. Contact developers. */
	DS_ERR_ITER =              7, /**< When an iteration reaches an unexpected value */
	DS_ERR_NULL_POINTER =      8, /**< When a @c NULL parameter is passed to a function */
	DS_ERR_FULL =              9, /**< When a structure reaches its maximum capacity */
	DS_ERR_INVALID_ARGUMENT = 10  /**< When an argument passed is invalid for that operation */
} Status;

// Primary type of the Dynamic array
#ifndef STRING_SPEC
#define STRING_SPEC

#define STRING_INIT_SIZE 8             /*!< Buffer initial size macro. */
#define STRING_GROW_RATE 2             /*!< Buffer growth rate macro. */

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

int str_compare(String *str1, String *str2);
bool str_greater(String *str1, String *str2);
bool str_equals(String *str1, String *str2);
bool str_lesser(String *str1, String *str2);

bool str_equals_str(String *str, char *string);

bool str_buffer_full(String *str);
bool str_buffer_empty(String *str);
bool str_buffer_fits(String *str, size_t str_len);

Status str_realloc(String *str);

// Dynamic Array of String
#ifndef DYNAMIC_ARRAY_SPEC
#define DYNAMIC_ARRAY_SPEC

#define DYNAMIC_ARRAY_INIT_SIZE 8	   /*!< Buffer initial size macro. */
#define DYNAMIC_ARRAY_GROW_RATE 2	   /*!< Buffer growth rate macro. */
#define DS_DAR_T String *			   /*!< Array type. */
#define DS_DAR_INIT str_init		   /*!< Init function of array type. */
#define DS_DAR_DELETE str_delete	   /*!< Delete function of array type. */
#define DS_DAR_DISPLAY str_display_raw /*!< Display function of array type. */
#define DS_DAR_COMPARATOR str_compare  /*!< Comparator function of array type. */

#endif

typedef struct DynamicArray
{
	DS_DAR_T *buffer;   /*!< @c DynamicArray data buffer */
	size_t size;		/*!< @c DynamicArray size */
	size_t capacity;	/*!< @c DynamicArray total capacity */
	size_t growth_rate; /*!< @c DynamicArray buffer growth rate */
} DynamicArray;

Status str_dar_init(DynamicArray **dar);

Status str_dar_get(DynamicArray *dar, size_t index, DS_DAR_T *result);

Status str_dar_insert_front(DynamicArray *dar, DS_DAR_T value);
Status str_dar_insert_at(DynamicArray *dar, DS_DAR_T value, size_t index);
Status str_dar_insert_back(DynamicArray *dar, DS_DAR_T value);

Status str_dar_remove_front(DynamicArray *dar, DS_DAR_T *result);
Status str_dar_remove_at(DynamicArray *dar, size_t index, DS_DAR_T *result);
Status str_dar_remove_back(DynamicArray *dar, DS_DAR_T *result);

Status str_dar_remove_keys(DynamicArray *dar, DS_DAR_T value);

Status str_dar_display(DynamicArray *darr);
Status str_dar_display_raw(DynamicArray *darr);

Status str_dar_delete(DynamicArray **darr);
Status str_dar_erase(DynamicArray **dar);

size_t str_dar_cap(DynamicArray *dar);
size_t str_dar_size(DynamicArray *dar);

bool str_dar_is_empty(DynamicArray *dar);
bool str_dar_is_full(DynamicArray *dar);

Status str_dar_find_max(DynamicArray *dar, DS_DAR_T *result);
Status str_dar_find_min(DynamicArray *dar, DS_DAR_T *result);
Status str_dar_find_max_pos(DynamicArray *dar, size_t *result);
Status str_dar_find_min_pos(DynamicArray *dar, size_t *result);

bool str_dar_exists(DynamicArray *dar, DS_DAR_T value);

Status str_dar_find_occurrance_first(DynamicArray *dar, DS_DAR_T value, size_t *position);
Status str_dar_find_occurrance_last(DynamicArray *dar, DS_DAR_T value, size_t *position);

Status str_dar_grow(DynamicArray *dar, size_t size);
Status str_dar_realloc(DynamicArray *dar);


// Utility
Status random_array_char(char **string, size_t size);
Status sort_selection_array_str_dar(DS_DAR_T *array, size_t arr_size);


/* ------------------------------------------------------------------------------------------------------------------------ STR_     BEGIN */
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

	printf("\n");

	if (str_buffer_empty(str))
		return DS_OK;

	printf("String\n%s\n", str->buffer);

	return DS_OK;
}

Status str_display_raw(String *str)
{
	if (str == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_buffer_empty(str))
	{
		printf(" ");

		return DS_OK;
	}

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

int str_compare(String *str1, String *str2)
{
	if (str_greater(str1, str2))
		return 1;
	else if (str_lesser(str1, str2))
		return -1;
	else
		return 0;

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

bool str_buffer_full(String *str)
{
	return (str->len + 1) >= str->capacity; // +1 So we are able to write '\0' at the end
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
/* ------------------------------------------------------------------------------------------------------------------------ STR_     END */

/* ------------------------------------------------------------------------------------------------------------------------ STR_DAR_ BEGIN */
Status str_dar_init(DynamicArray **dar)
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

Status str_dar_insert_front(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_full(dar))
	{
		Status st = str_dar_realloc(dar);

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

Status str_dar_insert_at(DynamicArray *dar, DS_DAR_T value, size_t index)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (index > dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_dar_insert_front(dar, value);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size)
	{
		st = str_dar_insert_back(dar, value);

		if (st != DS_OK)
			return st;
	}
	else
	{
		if (str_dar_is_full(dar))
		{
			st = str_dar_realloc(dar);

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

Status str_dar_insert_back(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_full(dar))
	{
		Status st = str_dar_realloc(dar);

		if (st != DS_OK)
			return st;
	}

	dar->buffer[dar->size] = value;

	(dar->size)++;

	return DS_OK;
}

Status str_dar_remove_front(DynamicArray *dar, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
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

Status str_dar_remove_at(DynamicArray *dar, size_t index, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	Status st;

	if (index == 0)
	{
		st = str_dar_remove_front(dar, result);

		if (st != DS_OK)
			return st;
	}
	else if (index == dar->size - 1)
	{
		st = str_dar_remove_back(dar, result);

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

Status str_dar_remove_back(DynamicArray *dar, DS_DAR_T *result)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	*result = dar->buffer[dar->size - 1];

	(dar->size)--;

	return DS_OK;
}

Status str_dar_remove_keys(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	DS_DAR_T result;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
		{
			st = str_dar_remove_at(dar, i, &result);

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

Status str_dar_display(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar->size == 0)
	{

		printf("\n[ Empty ] \n");

		return DS_OK;
	}

	printf("\nStringDynamicArray\n[ ");

	size_t i;
	for (i = 0; i < dar->size - 1; i++)
	{
		DS_DAR_DISPLAY(dar->buffer[i]);
		printf(", ");
	}

	DS_DAR_DISPLAY(dar->buffer[dar->size - 1]);

	printf(" ]\n");

	return DS_OK;
}

Status str_dar_display_raw(DynamicArray *dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	if (str_dar_is_empty(dar))
		return DS_OK;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		DS_DAR_DISPLAY(dar->buffer[i]);
		printf(" ");
	}

	printf("\n");

	return DS_OK;
}

Status str_dar_delete(DynamicArray **dar)
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

Status str_dar_erase(DynamicArray **dar)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	Status st = str_dar_delete(dar);

	if (st != DS_OK)
		return st;

	st = str_dar_init(dar);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status str_dar_get(DynamicArray *dar, size_t index, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	if (index >= dar->size)
		return DS_ERR_INVALID_POSITION;

	*result = dar->buffer[index];

	return DS_OK;
}

size_t str_dar_cap(DynamicArray *dar)
{
	return dar->capacity;
}

size_t str_dar_size(DynamicArray *dar)
{
	return dar->size;
}

bool str_dar_is_empty(DynamicArray *dar)
{
	return dar->size == 0;
}

bool str_dar_is_full(DynamicArray *dar)
{
	return dar->size == dar->capacity;
}

Status str_dar_find_max(DynamicArray *dar, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
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

Status str_dar_find_min(DynamicArray *dar, DS_DAR_T *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
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

Status str_dar_find_max_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], dar->buffer[(*result)]) > 0)
			*result = i;
	}

	return DS_OK;
}

Status str_dar_find_min_pos(DynamicArray *dar, size_t *result)
{
	*result = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], dar->buffer[(*result)]) < 0)
			*result = i;
	}

	return DS_OK;
}

bool str_dar_exists(DynamicArray *dar, DS_DAR_T value)
{
	if (dar == NULL)
		return false;

	if (str_dar_is_empty(dar))
		return false;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
			return true;
	}

	return false;
}

Status str_dar_find_occurrance_first(DynamicArray *dar, DS_DAR_T value, size_t *position)
{
	*position = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
		{
			*position = i;

			return DS_OK;
		}
	}

	return DS_ERR_NOT_FOUND;
}

Status str_dar_find_occurrance_last(DynamicArray *dar, DS_DAR_T value, size_t *position)
{
	*position = 0;

	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (str_dar_is_empty(dar))
		return DS_ERR_INVALID_OPERATION;

	bool found = false;

	size_t i;
	for (i = 0; i < dar->size; i++)
	{
		if (DS_DAR_COMPARATOR(dar->buffer[i], value) == 0)
		{
			*position = i;

			found = true;
		}
	}

	if (found)
		return DS_OK;

	return DS_ERR_NOT_FOUND;
}

Status str_dar_grow(DynamicArray *dar, size_t size)
{
	if (dar == NULL)
		return DS_ERR_NULL_POINTER;

	if (dar->capacity >= size)
		return DS_OK;

	size_t temp_cap = dar->capacity;

	while (dar->capacity < size)
	{
		dar->capacity *= dar->growth_rate;
	}

	DS_DAR_T *new_buffer = realloc(dar->buffer, sizeof(DS_DAR_T) * dar->capacity);

	if (!new_buffer)
	{
		dar->capacity = temp_cap;

		return DS_OK;
	}

	dar->buffer = new_buffer;

	return DS_OK;
}

Status str_dar_realloc(DynamicArray *dar)
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

/* ------------------------------------------------------------------------------------------------------------------------ STR_DAR_ END */

/* ------------------------------------------------------------------------------------------------------------------------ UTILITY  BEGIN */

Status random_array_char(char **string, size_t size)
{
	(*string) = malloc(sizeof(char) * (size + 1));

	if (!(*string))
		return DS_ERR_ALLOC;

	char *alpha = " ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz 0123456789 ";

	size_t len = str_len(alpha);

	size_t i;
	for (i = 0; i < size; i++)
	{
		(*string)[i] = alpha[rand() % len];
	}

	(*string)[size] = '\0';

	return DS_OK;
}

Status sort_selection_array_str_dar(DS_DAR_T *array, size_t arr_size)
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
			if (DS_DAR_COMPARATOR(array[j], array[min]) > 0)
				min = j;

		tmp = array[min];
		array[min] = array[i];
		array[i] = tmp;
	}

	return DS_OK;
}

/* ------------------------------------------------------------------------------------------------------------------------ UTILITY  END */

int main(int argc, char *argv[])
{
	srand(time(NULL));

	DynamicArray *array;

	Status st = str_dar_init(&array);

	if (st != DS_OK)
		return st;

	String *string;
	char *content;
	size_t i, max = 10000, max_len = 10;

	for (i = 0; i < max; i++)
	{
		random_array_char(&content, max_len);

		st = str_make(&string, content);

		if (st != DS_OK)
			return st;

		st = str_dar_insert_back(array, string);

		if (st != DS_OK)
			return st;

		free(content);

		content = NULL;
	}

	str_dar_display(array);

	printf("\n\nSorting\n\n");

	sort_selection_array_str_dar(array->buffer, max);

	str_dar_display(array);

	str_dar_delete(&array);

	return 0;
}
