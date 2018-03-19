/*
 * CArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 19/03/2018
 *
 * Array Implementations in C
 *
 */

 /*
 Return Codes

 -1 - Array Erased
 0 - Success
 1 - Invalid Position
 2 - Position already initialized (use update function)
 3 - Position not initialized (use insert function)
 4 - Position already empty
 5 - Array is full

 */

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\CArray.h"

void swap(CArray *array, int position1, int position2);

CArray * getCArray(int size)
{
	CArray *array = (CArray *) malloc(sizeof(CArray));
	array->array = (int *) malloc(sizeof(int) * size);
	array->size = size;
	int i;
	for (i = 0; i < size; i++) {
		array->array[i] = 0;
	}
	return array;
}

int insertValueCArray(CArray *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] == 0) {
			array->array[position] = value;
			return 0; // OK
		}
		else return 2; // Position already initialized (use update function)
	}
	return 1; // Invalid position
}

int removeValueCArray(CArray *array, int position)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] != 0) {
			array->array[position] = 0;
		}
		else return 4; // Position already empty
	}
	return 1; // Invalid position
}

int pushValueCArray(CArray *array, int value)
{
	int i;
	int ok = 0;
	for (i = 0; i < array->size; i++) {
		if (array->array[i] == 0) {
			array->array[i] = value;
			ok = 1;
			break;
		}
	}
	if (ok == 1) return 0;
	else return 5; // Array is full
}

int updateValueCArray(CArray *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] != 0) {

		}
		else return 3; // Position not initialized (use insert function)
	}
	return 1; // Invalid Position
}

int eraseCArray(CArray *array)
{
	int i;
	for (i = 0; i < array->size; i++) {
		array->array[i] = 0;
	}
	return 0;
}

int switchValuesCArray(CArray *array, int position1, int position2)
{
	if (position1 >= 0 && position1 < array->size 
		&& position2 >= 0 && position2 < array->size) {
		int temp = array->array[position1];
		array->array[position1] = array->array[position2];
		array->array[position2] = temp;
	}
	return 1; // Invalid Position
}

int reverseCArray(CArray *array)
{
	int i;
	for (i = 0; i < array->size / 2; i++) {
		swap(array, i, array->size - i - 1);
	}
	return 0;
}

int displayCArray(CArray *array)
{
	int i;
	printf("\nC ARRAY\n");
	for (i = 0; i < array->size; i++) {
		printf("%d ", array->array[i]);
	}
	printf("\n");
	return 0;
}

int bubbleSortCArray(CArray *array)
{
	int i, j;
	for (i = 0; i < array->size - 1; i++) {
		for (j = 0; j < array->size - i - 1; j++) {
			if (array->array[j] > array->array[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
	return 0;
}

void swap(CArray *array, int position1, int position2)
{
	int temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
}