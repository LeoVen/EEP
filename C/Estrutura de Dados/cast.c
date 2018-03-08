#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *p, i;

	for (i = 0; i < 10; i++)
	{
		p = (int *) malloc( sizeof(int) );
	}

	for (i = 0; i < 10; i++)
	{
		*p = i;
		p--;
	}

	for (i = 0; i < 10; i++)
	{
		p++;
		printf("\n%d", *p);
	}

	return 0;
}