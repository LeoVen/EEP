/*
 * DArray.h
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Header for Dynamic Array in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	typedef struct DArray {
		int *array;     // Array of integers
		int size;       // Actual Size
		int maxSize;    // Maximum size.
		bool threshold; // maxSize / 2
	} DArray;

	// +-------------------------------------+
	// |           Returns array             |
	// +-------------------------------------+
	DArray * getDArray(int maxSize);

	// +-------------------------------------+
	// |             Push / Pop              |
	// +-------------------------------------+
	int pushValueDArray(DArray **array, int value);
	int popValueDArray(DArray **array);

	// +-------------------------------------+
	// |          Insert / Remove            |
	// +-------------------------------------+
	int insertValueDArray(DArray *array, int position, int value);
	int removeValueDArray(DArray *array, int position);

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseDArray(DArray *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	int displayDArray(DArray **array);

	// +-------------------------------------+
	// |              Resize                 |
	// +-------------------------------------+
	DArray * checkGrow(DArray *array);
	DArray * checkShrink(DArray *array);
	DArray * growDArray(DArray *array);
	DArray * shrinkDArray(DArray *array);

	int adjustSize(DArray **array);

#ifdef __cplusplus
}
#endif