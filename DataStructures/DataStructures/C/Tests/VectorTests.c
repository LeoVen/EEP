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

	// Vector Sum
	printf("\n---------- Vector Sum ----------");
	Vector *v1 = buildVector(12.1, -3.7, 0.3);
	displayVector(v1);
	printf("+");
	Vector *v2 = buildVector(1.1, -13.7, 4.3);
	displayVector(v2);
	printf("=");
	Vector *v3 = vectorSum(v1, v2);
	displayVector(v3);

	// Vector Subtraction
	printf("\n------ Vector Subtraction ------");
	Vector *v4 = vectorSubtraction(v1, v2);
	displayVector(v1);
	printf("-");
	displayVector(v2);
	printf("=");
	displayVector(v4);

	// Modulus
	printf("\n-------- Vector Modulus --------");
	Vector *v5 = buildVector(6.0, 2.0, 3.0);
	displayVector(v5);
	printf("Modulus: %.2lf\n", vectorModulus(v5));

	double a = 3.2;
	printf("\nScalar Multiplication by %.2lf", a);
	vectorScalarProduct(v5, a);
	displayVector(v5);

	printf("\n---------- Dot Product ----------");
	Vector *v6 = buildVector(3.0, -1.0, 6.0);
	displayVector(v6);
	Vector *v7 = buildVector(2.0, 1.0, -4.0);
	displayVector(v7);
	printf("\nDot Product: %.2lf", vectorDotProduct(v6, v7));

	printf("\n---- Angle between two Vectors ----");
	Vector *v8 = buildVector(1.0, 0.0, 3.0);
	displayVector(v8);
	Vector *v9 = buildVector(5.0, 5.0, 0.0);
	displayVector(v9);
	printf("\nAngle between the two: %.4lf radians", vectorAngle(v8, v9));

	printf("\n");
	return 0;
}