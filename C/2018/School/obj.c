#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Num Num;
void square_root(Num **n);

typedef struct Num {
	double n;
	void (*square_root) (Num **n);
} Num;

void square_root(Num **n)
{
	(*n)->n = sqrt((*n)->n);
}

int main(int argc, char const *argv[])
{
	// Alloc structure
	Num *n = malloc(sizeof(Num));

	// Assign member pointer *square_root point to function square_root
	n->square_root = square_root;

	// Assign member variable
	n->n = 4;

	// Performs a square root on member variable n
	n->square_root(&n);
	n->square_root(&n);

	// Printing results
	printf("\nSQRT: %lf", n->n);
	return 0;
}