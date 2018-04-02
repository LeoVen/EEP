/*
 * ConversionTests.c
 *
 * Author: Leonardo Vencovsky
 * Created on 02/04/2018
 *
 * Test Cases for Conversions in C
 *
 * Feel free to break any of my implementations!
 * Just make sure to open an issue :D
 *
 */

#include "..\Headers\StructureConversions.h"

int ConversionTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |          C Conversion Tests         |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	int i;
	CSinglyLinkedList *sll;
	initListSLL(&sll);
	
	for (i = 0; i < 10; i++) {
		insertTailSLL(&sll, i);
	}

	CArray *array;
	if (convert_sll_to_array(sll, &array) != DS_OK)
		printf("\nError");
	
	displayCArray(array);

	DArray *darray;

	int err = convert_sll_to_darray(sll, &darray);
	printf("\nErr %d", err);

	displayDArray(darray);

	for (i = 0; i < 20; i++)
		pushValueDArray(&darray, 99);

	
	free(sll);

	convert_darray_to_sll(darray, &sll);

	displayListSLL(&sll);

	printf("\n");
	return 0;
}