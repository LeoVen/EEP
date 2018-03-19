/*
 * CArrayTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 19/03/2018
 *
 * Test Cases for Array Implementations in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\CArray.h"

int CArrayTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Array               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	CArray *array = getCArray(10);

	int i;
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i+1);
	}

	displayCArray(array);
	printf("\nCode: %d\n", pushValueCArray(array, 11)); // 5

	for (i = 0; i < array->size; i++) {
		removeValueCArray(array, i);
	}
	
	displayCArray(array);

	printf("\nCode: %d", removeValueCArray(array, -1)); // 1
	printf("\nCode: %d\n", insertValueCArray(array, -1, 1)); // 1

	// Erase
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i + 1);
	}
	eraseCArray(array);
	displayCArray(array); // Should give all 0s

	// Switching
	CArray *arr = getCArray(13);
	for (i = 0; i < arr->size; i++) {
		insertValueCArray(arr, i, i + 1);
	}
	displayCArray(arr);
	for (i = 0; i < arr->size / 2; i++) {
		switchValuesCArray(arr, i, arr->size - i - 1);
	}

	displayCArray(arr);

	// Or simply...
	reverseCArray(arr);

	displayCArray(arr);
	
	// Sorting
	srand(time(NULL));
	CArray *barray = getCArray(20);
	for (i = 0; i < barray->size; i++) {
		insertValueCArray(barray, i, rand());
	}
	printf("\nNot sorted Array:");
	displayCArray(barray);

	printf("\nSorted Array (Bubble Sort):");
	bubbleSortCArray(barray);
	displayCArray(barray);

	printf("\n");
	return 0;
}