#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macro_list.h"
#include "common_lists.h"

// Can also be used in files
// MLIST_GENERATE(st, static_list, static, char *)

int main(int argc, char const *argv[])
{
	int_list *list = il_new(10);

	for (int i = 0; i < 100; i++)
	{
		il_push(list, i, list->length == 0 ? list->length : i % list->length);
	}

	printf("\n[ ");

	for (int i = 0; i < list->length - 1; i++)
		printf("%d, ", il_get(list, i));

	printf("%d ]\n", il_get(list, list->length - 1));

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
			for (int i = 0; i < list->length - 1; i++)
			{
				printf("%d, ", il_get(list, i));
			}
			printf("%d ]\n", il_get(list, list->length - 1));
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
			for (int i = 0; i < list->length - 1; i++)
			{
				printf("%d, ", il_get(list, i));
			}
			printf("%d ]\n", il_get(list, list->length - 1));
		}
	}

	il_free(list);

	list = il_new(1000);

	for (int i = 0; i < 1000; i++)
	{
		il_insert_if(list, i, list->length, i % 2 == 0);
	}

	// Print all even numbers
	if (!il_empty(list))
	{
		// Print
		printf("\n[ ");
		for (int i = 0; i < list->length - 1; i++)
		{
			printf("%d, ", il_get(list, i));
		}
		printf("%d ]\n", il_get(list, list->length - 1));
	}

	il_free(list);

	return 0;
}
