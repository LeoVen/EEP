/*
 * CArray.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header for Array in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

	typedef struct CArray {
		int *array;
		int size;
	} CArray;

	// +-------------------------------------+
	// |           Returns array             |
	// +-------------------------------------+
	CArray * getCArray(int size);
	CArray * getCopyCArray(CArray *array);

	// +-------------------------------------+
	// |                CRUD                 |
	// +-------------------------------------+
	int insertValueCArray(CArray *array, int position, int value);
	int removeValueCArray(CArray *array, int position);
	int pushValueCArray(CArray *array, int value);
	int updateValueCArray(CArray *array, int position, int value);

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseCArray(CArray *array);

	// +-------------------------------------+
	// |             Switching               |
	// +-------------------------------------+
	int switchValuesCArray(CArray *array, int position1, int position2);
	int reverseCArray(CArray *array);

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	int bubbleSortCArray(CArray *array);
	int selectionSortCArray(CArray *array);
	int insertionSortCArray(CArray *array);
	int blenderCArray(CArray *array);

	// +-------------------------------------+
	// |             Searching               |
	// +-------------------------------------+
	int valueOcurranceCArray(CArray *array, int value);
	CArray * valuePositionsCArray(CArray *array, int value);
	int findMaxCArray(CArray *array);
	int findMinCArray(CArray *array);

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	int displayCArray(CArray *array);

#ifdef __cplusplus
}
#endif