/*
* vector.c
*
* Author: Leonardo Vencovsky
* Created on 20/03/2018
*
* Vector implementations
*
*/

/* Build Vector
 * Sum two vectors
 * 
 *
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
	double x;
	double y;
	double z;
} Vector;

Vector* buildVector(double x, double y, double z);

int main(int argc, char const *argv[])
{
	Vector *v1 = buildVector(12.1, -3.7, 0.3);
	Vector *v2 = buildVector(1.1, -13.7, 4.3);

	return 0;
}

Vector* buildVector(double x, double y, double z)
{
	Vector *v = (Vector *)malloc(sizeof(Vector));
	v->x = x;
	v->y = y;
	v->z = z;
	return v;
}

void displayVector(Vector *v)