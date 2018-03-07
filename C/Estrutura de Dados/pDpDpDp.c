/*
	Ponteiro de Ponteiro de Ponteiro de Ponteiro
*/

#include <stdio.h>
#include <stdlib.h>

void func_1(int *a);
void func_2(int **b);
void func_3(int ***c);
void func_4(int ****d);

int main(int argc, char **argv) {
	
	int x = 10;
	printf("\nAddress of initial value: %p", &x);
	printf("\nAnd its value: %d\n", x);
	func_1(&x);
	printf("\nAddress of final value: %p", &x);
	printf("\nAnd its value: %d\n", x);

	return 0;
}

void func_1(int *a)
{
	(*a)++;
	func_2(&a);
	printf("\nAddress of a: %p\n", &a);
	printf("And it points to : %p\n", a);
}

void func_2(int **b)
{
	(**b)++;
	func_3(&b);
	printf("\nAddress of b: %p\n", &b);
	printf("And it points to : %p\n", b);
}

void func_3(int ***c)
{
	(***c)++;
	func_4(&c);
	printf("\nAddress of c: %p\n", &c);
	printf("And it points to : %p\n", c);
}

void func_4(int ****d )
{
	(****d)++;
	printf("\nAddress of d: %p\n", &d);
	printf("And it points to : %p\n", d);
}