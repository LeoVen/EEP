/*
* Vector.c
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
#include <math.h>
#include "..\Headers\Vector.h"

Vector* buildVector(double x, double y, double z)
{
	Vector *v = (Vector *)malloc(sizeof(Vector));
	v->x = x;
	v->y = y;
	v->z = z;
	return v;
}

void displayVector(Vector *v)
{
	printf("\nVector( %.2lf i + %.2lf j + %.2lf k )\n", v->x, v->y, v->z);
}

Vector* vectorSum(Vector *v1, Vector *v2)
{
	Vector *v = buildVector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
	return v;
}

double vectorModulus(Vector *v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}