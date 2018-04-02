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
	DArray *newArr = malloc(sizeof(DArray));
	newArr->size = 0;
	newArr->maxSize = maxSize;
	newArr->threshold = false;
	newArr->array = malloc(sizeof(int) * maxSize);
	return newArr;
}

int pushValueDArray(DArray **array, int value)
{
	adjustSize(array);
	(*array)->array[(*array)->size] = value;
	((*array)->size)++;
	return 0;
}

int popValueDArray(DArray **array)
{
	adjustSize(array);
	(*array)->array[(*array)->size] = 0;
	((*array)->size)--;
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
	int i;
	if ((*arr)->size > (*arr)->maxSize / 2) (*arr)->threshold = true;
	if ((*arr)->size >= (*arr)->maxSize - 1) {
		// Grow
		DArray *nArray = getDArray((*arr)->maxSize * 2);
		DArray *kill = (*arr);
		// Copy values
		for (i = 0; i < (*arr)->size; i++) {
			nArray->array[i] = (*arr)->array[i];
		}
		nArray->size = (*arr)->size;
		nArray->threshold = false;
		*arr = nArray;
		// Free old array
		free(kill);
		return 0; // OK
	}
	else if ((*arr)->threshold && (*arr)->size < (*arr)->maxSize / 2) {
		// Shrink
		DArray *nArray = getDArray((*arr)->maxSize / 2 + 1);
		DArray *kill = (*arr);
		// Copy values
		for (i = 0; i < (*arr)->size; i++) {
			nArray->array[i] = (*arr)->array[i];
		}
		nArray->size = (*arr)->size;
		nArray->threshold = false;
		(*arr) = nArray;
		// Free old array
		free(kill);
		return 0; // OK
	}
	else {
		// OK
		return 0;
	}
}