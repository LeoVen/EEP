#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include "macro_list.h"
#include "common_lists.h"

double rrandom()
{
	return (double)rand() / ((double)RAND_MAX + 1.0);
}

int8_t random_int8_t(int8_t min, int8_t max)
{
	return (int8_t)floor(rrandom() *
							 ((double)max - (double)min + 1.0) +
						 (double)min);
}

char random_alpha()
{
	const char alpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
						  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
						  'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
						  'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D',
						  'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
						  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
						  'Y', 'Z'};
	return alpha[random_int8_t(0, 61)];
}

int main(int argc, char const *argv[])
{
	int_list *list = il_new(10);

	for (int i = 0; i < 100; i++)
	{
		il_push(list, i, list->count == 0 ? list->count : i % list->count);
	}

	printf("\n[ ");

	for (int i = 0; i < list->count - 1; i++)
		printf("%d, ", il_get(list, i));

	printf("%d ]\n", il_get(list, list->count - 1));

	il_free(list);

	list = il_new(10);

	for (int i = 0; i < 10; i++)
	{
		// Add elements
		il_push_back(list, i);

		// Print
		if (!il_empty(list))
		{
			// Print
			printf("\n[ ");
			for (int i = 0; i < list->count - 1; i++)
			{
				printf("%d, ", il_get(list, i));
			}
			printf("%d ]\n", il_get(list, list->count - 1));
		}
	}

	for (int i = 0; i < 10; i++)
	{
		// Remove elements
		il_pop_back(list);

		if (!il_empty(list))
		{
			// Print
			printf("\n[ ");
			for (int i = 0; i < list->count - 1; i++)
			{
				printf("%d, ", il_get(list, i));
			}
			printf("%d ]\n", il_get(list, list->count - 1));
		}
	}

	il_free(list);

	list = il_new(1000);

	for (int i = 0; i < 1000; i++)
	{
		il_insert_if(list, i, list->count, i % 2 == 0);
	}

	// Print all even numbers
	if (!il_empty(list))
	{
		// Print
		printf("\n[ ");
		for (int i = 0; i < list->count - 1; i++)
		{
			printf("%d, ", il_get(list, i));
		}
		printf("%d ]\n", il_get(list, list->count - 1));
	}

	il_free(list);

	char_stack *stack = cs_new(100);

	for (int i = 0; i < 2000; i++)
	{
		cs_push(stack, random_alpha());
	}

	size_t s = cs_count(stack);
	size_t c = cs_capacity(stack);
	printf("Stack size     : %" PRIu64 "\n", s);
	printf("Stack capacity : %" PRIu64 "\n", c);

	for (int i = 0; i < s; i++)
	{
		printf("%c ", cs_top(stack));
		cs_pop(stack);
	}

	printf("\nStack size: %" PRIu64 "", cs_count(stack));
	printf("\nStack capacity : %" PRIu64 "", cs_capacity(stack));

	cs_free(stack);

	return 0;
}
