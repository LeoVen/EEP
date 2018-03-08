/*
	Exemplo básico de malloc
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int *p, i, pos = 100;
	p = malloc(pos * sizeof(int) );
	
	for (i = 0; i < pos; i++)
	{
		printf("%p\n", p);
		p++;
	}

	free(p);

	return 0;
}