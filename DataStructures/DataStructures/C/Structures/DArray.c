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

#include <stdio.h>
#include <stdlib.h>
#include "..\Headers\DArray.h"

DArray * getDArray(int maxSize, int minSize)
{
	DArray *newArr = (DArray *)malloc(sizeof(DArray));
	newArr->size = 0;
	newArr->minSize = minSize;
	newArr->maxSize = maxSize;
	newArr->array = (int *)malloc(sizeof(int) * maxSize);
	return newArr;
}