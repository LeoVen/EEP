/*
 * StructureConversions.h
 *
 * Author: Leonardo Vencovsky
 * Created on 02/04/2018
 *
 * Structure Conversions Header in C
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "Common.h"
#include "CStructures.h"

	// +-------------------------------------+
	// |              SLL -> X               |
	// +-------------------------------------+
	Status convert_sll_to_array(CSinglyLinkedList *sll, CArray **array);

	Status convert_sll_to_darray(CSinglyLinkedList *sll, DArray **darr);

	// +-------------------------------------+
	// |              DAR -> X               |
	// +-------------------------------------+

	Status convert_darray_to_sll(DArray *darr, CSinglyLinkedList **sll);

	// +-------------------------------------+
	// |              AAR -> X               |
	// +-------------------------------------+

	Status convert_array_to_darray(CArray *arr, DArray **darr);

#ifdef __cplusplus
}
#endif