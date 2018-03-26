/*
 * CSinglyLinkedList.h
 *
 * Author: Leonardo Vencovsky
 * Created on 14/03/2018
 *
 * Header for Singly Linked List Implementations in C
 *
 */

#pragma once



#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	typedef struct CSinglyLinkedNode {
		int data;
		struct CSinglyLinkedNode *next;
	} CSinglyLinkedNode;

	typedef struct CSinglyLinkedList {
		bool initialized;
		int size;
		CSinglyLinkedNode *head;
		CSinglyLinkedNode *tail;
	} CSinglyLinkedList;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes List. Obligatory! Or your application will crash.
	 *
	 * @see getCSinglyLinkedList() as an alternative
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int initListSLL(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+
	/* Inserts new node at first position
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertHeadSLL(CSinglyLinkedList **SinglyLinkedList, int value);

	/*
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 * @Param [ int position ] Position for new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int value, int position);

	/*
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertTailSLL(CSinglyLinkedList **SinglyLinkedList, int value);

	/*
	 * TODO insert pre-made node
	 *
	 */
	int insertNodeSLL(CSinglyLinkedList **SinglyLinkedList, CSinglyLinkedNode *node, int position);

	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+
	/* Removes first node
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeHeadSLL(CSinglyLinkedList **SinglyLinkedList);

	/* Removes middle node (or chosen node)
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int position ] Node at position to be removed
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeMiddleSLL(CSinglyLinkedList **SinglyLinkedList, int position);

	/* Removes last node
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int removeTailSLL(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	/* Displays list in console
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayListSLL(CSinglyLinkedList **SinglyLinkedList);

	/* Gets length of a list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] List length
	 */
	int getListSizeSLL(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+
	/*
	 * Utility function to reposition tail whenever needed
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ void ]
	 */
	void resetTail(CSinglyLinkedList *SinglyLinkedList);

	/* Delets list completely
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int deleteListSLL(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+
	/* Searches for data and returns how many were found
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be searched
	 *
	 * @Returns [ int ] The frequency count of that value
	 */
	int searchValueSLL(CSinglyLinkedList **SinglyLinkedList, int value);

	/*
	 *
	 *
	 */
	// TODO Get array with positions of matched values

	/* Gets the highest value in the list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Minimum value
	 */
	// int findMin(CSinglyLinkedList **SinglyLinkedList);

	/* Gets the highest value in the list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Maximum value
	 */
	// int findMax(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |               Getters               |
	// +-------------------------------------+
	/* Get a new Singly Linked List
	 *
	 * @Returns [ CSinglyLinkedList * ] Pointer to new Singly Linked List
	 */
	CSinglyLinkedList * getCSinglyLinkedList();

	/* Get a SLL Node
	 *
	 * @Param [ int value ] Node value
	 *
	 * @Returns [ CSinglyLinkedNode * ] Pointer to new node with data
	 */
	CSinglyLinkedNode * getCSinglyLinkedNode(int value);

	/* Get node value
	*
	* @Param [ int position ] Position of node to get value from
	*
	* @Returns [ int ] Value of node
	*/
	int getNodeValueSLL(CSinglyLinkedList **SinglyLinkedList, int position);

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	/* Get copy of a SLL Node
	 *
	 * @Param [ CSinglyLinkedNode *node ] Node to be copied
	 *
	 * @Returns [ CSinglyLinkedNode * ] Pointer to new node with data
	 */
	CSinglyLinkedNode * copyCSinglyLinkedNode(CSinglyLinkedNode *node);

	/* Get copy of a list
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] List to be copied
	 *
	 * @Returns [ CSinglyLinkedList * ] New copied list
	 */
	CSinglyLinkedList * copyCSinglyLinkedList(CSinglyLinkedList **SinglyLinkedList);

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	/* Reverse list using three pointers method
	 *
	 * @Param [ CSinglyLinkedList **SinglyLinkedList ] List to be reversed
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int reverseListSLL(CSinglyLinkedList **SinglyLinkedList);

	/*
	 *
	 *
	 */
	// TODO BubbleSort

	/*
	 *
	 *
	 */
	// TODO SelectionSort

	/*
	 *
	 *
	 */
	// TODO InsertionSort

#ifdef __cplusplus
}
#endif

