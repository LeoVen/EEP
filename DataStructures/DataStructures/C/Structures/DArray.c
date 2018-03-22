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

DArray * getDArray(int maxSize, int minSize)
{
	if (maxSize < minSize || maxSize < 0 || minSize < 0) {
		printf("\nFATAL ERROR\n");
		return NULL;
	}
	DArray *newArr = (DArray *)malloc(sizeof(DArray));
	newArr->size = 0;
	newArr->maxSize = maxSize;
	newArr->minSize = minSize;
	newArr->array = (int *)malloc(sizeof(int) * maxSize);
	return newArr;
}

int pushValueDArray(DArray *array, int value)
{
	array = checkGrow(array);
	array->array[array->size] = value;
	(array->size)++;
	return 0;
}

int popValueDArray(DArray *array)
{
	array = checkShrink(array);
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

DArray * checkGrow(DArray *array)
{
	if (array->size >= array->maxSize - 1) return growDArray(array);
	else return array;
}

DArray * checkShrink(DArray *array)
{
	if (array->size <= array->minSize) return growDArray(array);
	else return array;
}

DArray * growDArray(DArray *array)
{
	DArray *newArr = getDArray(array->maxSize * 2, array->minSize * 2);
	newArr->size = array->size;
	int i;
	for (i = 0; i < array->size; i++) {
		newArr->array[i] = array->array[i];
	}
	free(array);
	return newArr;
}

DArray * shrinkDArray(DArray *array)
{
	DArray *newArr = getDArray(array->maxSize / 2, array->minSize / 2);
	newArr->size = array->size;
	int i;
	for (i = 0; i < array->size; i++) {
		newArr->array[i] = array->array[i];
	}
	return newArr;
}