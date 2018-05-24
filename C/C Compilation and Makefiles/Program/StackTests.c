/**
 * @file StackTests.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 31/03/2018
 *
 * @brief Test Cases for @c Stack implementations in C
 *
 */

#include "Stack.h"

int StackTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Stack               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Stack *stack;
	stk_init_stack(&stack);

	int i;
	for (i = 0; i < 10; i++) {
		stk_put(stack, i);
	}
	stk_display(stack);

	for (i = 0; i < 5; i++) {
		stk_slice(stack);
	}
	stk_display_raw(stack);

	stk_erase_stack(&stack);

	for (i = 0; i < 100; i++) {
		stk_put(stack, i);
	}

	stk_display_raw(stack);

	int data;
	size_t height;
	StackBox *aux;
	Stack *stk_even = NULL, *stk_odd = NULL;
	if (stk_init_stack(&stk_even) == DS_OK && stk_init_stack(&stk_odd) == DS_OK)
		if (stk_get_height(stack, &height) == DS_OK)
			for (i = 0; i < height; i++) {
				if (stk_look(stack, &data) == DS_OK) {
					if (data % 2 == 0) {
						stk_pop(stack, &aux);
						stk_push(stk_even, aux);
					}
					else {
						stk_pop(stack, &aux);
						stk_push(stk_odd, aux);
					}
				}
			}

	stk_display_raw(stk_even);
	stk_display_raw(stk_odd);

	stk_delete_stack(&stack);
	stk_delete_stack(&stk_even);
	stk_delete_stack(&stk_odd);

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

	printf("\n");
	return 0;
}