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

	typedef struct Vector {
		double x;
		double y;
		double z;
	} Vector;

	// +-------------------------------------+
	// |             Functions               |
	// +-------------------------------------+
	void displayVector(Vector *v);
	Vector* buildVector(double x, double y, double z);
	Vector* vectorSum(Vector *v1, Vector *v2);
	double vectorModulus(Vector *v);
	

#ifdef __cplusplus
}
#endif