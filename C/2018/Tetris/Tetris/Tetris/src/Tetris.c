/*
* Tetris.c
*
* Author: Leonardo Vencovsky
* Created on 23/03/2018
*
* Tetris Functions
*
*/

#include "..\include\CArray.h"
#include "..\include\Tetris.h"


CArray** getTetris()
{
	CArray **tetris = (CArray**)malloc(10 * sizeof(CArray*));
	int i;
	for (i = 0; i < 10; i++) {
		tetris[i] = getCArray(10);
	}
	return tetris;
}

int addTetrisBit(CArray **tetris, int posx, int posy)
{
	return insertValueCArray(tetris[posy], posx, 1);
}

int displayTetris(CArray **tetris)
{
	printf("\n");
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%d ", tetris[j]->array[i]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}

int fallTetris(CArray **tetris)
{
	//int i;
	shiftArray(tetris[0]);
	return 0;
}

int shiftArray(CArray *array)
{
	int j, k, i = 0;
	while (array->array[i] != 1) i++;
	j = i;
	while (array->array[j] != 0) j++;
	if (j - 1 == array->size) return 1; //Reached the end
	for (k = i; k < j; k++) {
		array->array[k + 1] = array->array[k];
	}
	array->array[i] = 0;
	return 0; // Shifted
}