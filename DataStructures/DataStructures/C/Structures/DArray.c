/*
 * DArray.c
 *
 * Author: Leonardo Vencovsky
 * Created on 20/03/2018
 *
 * Dynamic Array Implementations in C
 *
 * Dynamic Array grows and shrinks as you add and remove values
 */

#include "..\Headers\DArray.h"

DArray * getDArray(int maxSize)
{
	if (maxSize < 0) {
		printf("\nFATAL ERROR\n");
		return NULL;
	}
	DArray *newArr = (DArray *)malloc(sizeof(DArray));
	newArr->size = 0;
	newArr->maxSize = maxSize;
	newArr->threshold = false;
	newArr->array = (int *)malloc(sizeof(int) * maxSize);
	return newArr;
}

int pushValueDArray(DArray *array, int value)
{
	adjustSize(&array);
	array->array[array->size] = value;
	(array->size)++;
	return 0;
}

int popValueDArray(DArray *array)
{
	adjustSize(&array);
	array->array[array->size] = 0;
	(array->size)--;
	return 0;
}

int displayDArray(DArray *array)
{
	int i;
	if (array->size == 0) {
		printf("\n[ Empty ] \n");
		return 1;
	}
	printf("\n[ ");
	for (i = 0; i < array->size; i++) {
		printf("%d, ", array->array[i]);
	}
	printf("nil ]\n");
	return 0;
}

int adjustSize(DArray **arr)
{
	DArray *array = *arr;
	int i;
	if (array->size > array->maxSize / 2) array->threshold = true;
	if (array->size >= array->maxSize - 1) {
		// Grow
		DArray *nArray = getDArray(array->maxSize * 2);
		for (i = 0; i < array->size; i++) {
			nArray->array[i] = (*arr)->array[i];
		}
		nArray->size = array->size;
		nArray->threshold = false;
		*arr = nArray;
		//free(array);
		return 0; // OK
	}
	else if (array->threshold && array->size < array->maxSize / 2) {
		// Shrink
		DArray *nArray = getDArray(array->maxSize / 2 + 1);
		for (i = 0; i < array->size; i++) {
			nArray->array[i] = array->array[i];
		}
		nArray->size = array->size;
		nArray->threshold = false;
		*arr = nArray;
		//free(array);
		return 0; // OK
	}
	else {
		// OK
		return 0;
	}
}