/**
 * @file parithm.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 18/02/2019
 *
 * Experimenting pointer arithmetic
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
	int a = 10;

	int *p = &a;

	if ((void *)(p - p) == NULL)
		printf("I have subtracted myself\n");

	int b = 11, c = 12, d = 13;

	int *ptr = &c;

	printf("%p, %p, %p\n", &b, &c, &d);
	printf("%d\n", *(ptr - 1));
	printf("%d\n", *(ptr + 1));

	return 0;
}