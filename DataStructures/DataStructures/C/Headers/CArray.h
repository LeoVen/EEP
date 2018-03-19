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

	typedef struct CArray {
		int *array;
		int size;
	} CArray;

	// Returns array
	CArray * getCArray(int size);
	// IO
	int insertValueCArray(CArray *array, int position, int value);
	int removeValueCArray(CArray *array, int position);
	int pushValueCArray(CArray *array, int value);
	int updateValueCArray(CArray *array, int position, int value);
	// Erase
	int eraseCArray(CArray *array);
	// Others
	int displayCArray(CArray *array);
	// Switch
	int switchValuesCArray(CArray *array, int position1, int position2);
	int reverseCArray(CArray *array);
	// Sorting
	int bubbleSortCArray(CArray *array);

#ifdef __cplusplus
}
#endif