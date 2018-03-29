/*
	Ponteiro de Ponteiro de Ponteiro de Ponteiro
*/

#include <stdio.h>

void func_1(int *a);
void func_2(int **b);
void func_3(int ***c);
void func_4(int ****d);

int main(int argc, char **argv) {
	
	int x = 10;

	printf("\n [ x ] value   : %d\n", x);
	printf(" [ x ] address : %p\n", &x);
	func_1(&x);
	printf("\n [ x ] address : %p", &x);
	printf("\n [ x ] value   : %d\n", x);

	return 0;
}

void func_1(int *a)
{
	(*a)++;
	printf("\n [ a ] points to : %p\n", a);
	printf(" [ a ] address   : %p\n", &a);
	func_2(&a);
}

void func_2(int **b)
{
	(**b)++;
	printf("\n [ b ] points to : %p\n", b);
	printf(" [ b ] address   : %p\n", &b);
	func_3(&b);
}

void func_3(int ***c)
{
	(***c)++;
	printf("\n [ c ] points to : %p\n", c);
	printf(" [ c ] address   : %p\n", &c);
	func_4(&c);
}

void func_4(int ****d )
{
	(****d)++;
	printf("\n [ d ] points to : %p\n", d);
	printf(" [ d ] address   : %p\n", &d);
}