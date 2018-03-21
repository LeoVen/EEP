/*
* Vector.c
*
* Author: Leonardo Vencovsky
* Created on 20/03/2018
*
* Vector implementations
*
*/

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
	printf("\nVector\n[%8.2lf i ]\n[%8.2lf j ]\n[%8.2lf k ]\n", v->x, v->y, v->z);
}

Vector* vectorSum(Vector *v1, Vector *v2)
{
	return buildVector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
}

Vector* vectorSubtraction(Vector *v1, Vector *v2)
{
	return buildVector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
}

double vectorModulus(Vector *v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double vectorDotProduct(Vector *v1, Vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void vectorScalarProduct(Vector *v, double scalar)
{
	v->x *= scalar;
	v->y *= scalar;
	v->z *= scalar;
}

double vectorAngle(Vector *v1, Vector *v2)
{
	return acos(vectorDotProduct(v1, v2) / (vectorModulus(v1) * vectorModulus(v2)));
}

Vector* copyVector(Vector *v)
{
	return buildVector(v->x, v->y, v->z);
}