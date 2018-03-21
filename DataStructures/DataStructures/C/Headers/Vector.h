/*
* Vector.h
*
* Author: Leonardo Vencovsky
* Created on 20/03/2018
*
* Header for Vector in C
*
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	typedef struct VectorBase {
		double i;
		double j;
		double k;
	} VectorBase;

	typedef struct Vector {
		double x;
		double y;
		double z;
		//VectorBase *base;
	} Vector;

	// +-------------------------------------+
	// |             Operations              |
	// +-------------------------------------+
	double vectorModulus(Vector *v);
	Vector* vectorSum(Vector *v1, Vector *v2);
	Vector* vectorSubtraction(Vector *v1, Vector *v2);
	void vectorScalarProduct(Vector *v, double scalar);
	double vectorDotProduct(Vector *v1, Vector *v2);
	double vectorAngle(Vector *v1, Vector *v2);
	// Cross Product

	// +-------------------------------------+
	// |                Misc                 |
	// +-------------------------------------+
	void displayVector(Vector *v);
	Vector* buildVector(double x, double y, double z);
	Vector* copyVector(Vector *v);

#ifdef __cplusplus
}
#endif