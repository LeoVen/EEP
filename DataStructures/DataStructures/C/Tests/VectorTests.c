/*
 * VectorTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Test Cases for Vector Implementations in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\Vector.h"

int VectorTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Vector               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	Vector *v1 = buildVector(12.1, -3.7, 0.3);
	displayVector(v1);
	printf("+");
	Vector *v2 = buildVector(1.1, -13.7, 4.3);
	displayVector(v2);
	printf("=");
	Vector *v3 = vectorSum(v1, v2);
	displayVector(v3);

	Vector *v4 = buildVector(6.0, 2.0, 3.0);
	displayVector(v4);
	printf("\nModulus: %.2lf", vectorModulus(v4));

	printf("\n");
	return 0;
}