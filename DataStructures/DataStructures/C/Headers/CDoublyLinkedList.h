/*
 * CDoublyLinkedList.h
 *
 * Author: Leonardo Vencovsky
 * Created on 18/03/2018
 *
 * Header for Doubly Linked List Implementations in C
 *
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

	typedef struct CDoublyLinkedNode {
		int data;
		struct CSinglyLinkedNode *next;
		struct CSinglyLinkedNode *prev;
	} CDoublyLinkedNode;

	typedef struct CDoublyLinkedList {
		bool initialized;
		int size;
		CDoublyLinkedNode *head;
		CDoublyLinkedNode *tail;
	} CDoublyLinkedList;

	// +-------------------------------------+
	// |             Initialize              |
	// +-------------------------------------+
	/* Initializes List. Obligatory! Or your application will crash.
	 *
	 * @see getCDoublyLinkedList() as an alternative
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int initListDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |              Getters                |
	// +-------------------------------------+
	/* Get a new Doubly Linked List
	 *
	 * @Returns [ CDoublyLinkedList * ] Pointer to new Doubly Linked List
	 */
	CDoublyLinkedList * getCDoublyLinkedList();

	/* Get a DLL Node
	 *
	 * @Param [ int value ] Node value
	 *
	 * @Returns [ CDoublyLinkedNode * ] Pointer to new node with data
	 */
	CDoublyLinkedNode * getCDoublyLinkedNode(int value);

	// +-------------------------------------+
	// |              Insertion              |
	// +-------------------------------------+
	/* Inserts new node at first position
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertHeadDLL(CDoublyLinkedList **DoublyLinkedList, int value);

	/*
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 * @Param [ int position ] Position for new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int value, int position);

	/*
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 * @Param [ int value ] Value to be inserted to new node
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int insertTailDLL(CDoublyLinkedList **DoublyLinkedList, int value);

	/*
	 * TODO insert pre-made node
	 *
	 */
	int insertNodeDLL(CDoublyLinkedList **DoublyLinkedList, CDoublyLinkedNode *node, int position);

	// +-------------------------------------+
	// |               Removal               |
	// +-------------------------------------+
	/* Removes first node
	*
	* @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	*
	* @Returns [ int ] Return Code (see code table)
	*/
	int removeHeadDLL(CDoublyLinkedList **DoublyLinkedList);

	/* Removes middle node (or chosen node)
	*
	* @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	* @Param [ int position ] Node at position to be removed
	*
	* @Returns [ int ] Return Code (see code table)
	*/
	int removeMiddleDLL(CDoublyLinkedList **DoublyLinkedList, int position);

	/* Removes last node
	*
	* @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	*
	* @Returns [ int ] Return Code (see code table)
	*/
	int removeTailDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |               Display               |
	// +-------------------------------------+
	/* Displays list in console
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int displayListDLL(CDoublyLinkedList **DoublyLinkedList);

	/* Gets length of a list
	*
	* @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	*
	* @Returns [ int ] List length
	*/
	int getListSizeDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |               Resets                |
	// +-------------------------------------+
	/*
	* Utility function to reposition head and tail whenever needed
	*
	* @Param [ CDoublyLinkedList *DoublyLinkedList ] Reference to list
	*
	* @Returns [ void ]
	*/
	void resetHeadTail(CDoublyLinkedList *DoublyLinkedList);

	// +-------------------------------------+
	// |               Search                |
	// +-------------------------------------+

	/*
	 *
	 *
	 */
	// TODO int searchValueDLL(CDoublyLinkedList **DoublyLinkedList, int value);

	/* Gets the smallest value in the list
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Minimum value
	 */
	// TODO int findMinDLL(CDoublyLinkedList **DoublyLinkedList);

	/* Gets the highest value in the list
	 *
	 * @Param [ CDoublyLinkedList **DoublyLinkedList ] Reference to list
	 *
	 * @Returns [ int ] Maximum value
	 */
	// TODO int findMaxDLL(CDoublyLinkedList **DoublyLinkedList);

	// +-------------------------------------+
	// |                 Copy                |
	// +-------------------------------------+

	// Copy List
	// Copy Node

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	/*
	 *
	 *
	 */
	// Reverse List

	/*
	 *
	 *
	 */
	// BubbleSort

	/*
	 *
	 *
	 */
	// SelectionSort

	/*
	 *
	 *
	 */
	// InsertionSort


#ifdef __cplusplus
}
#endif

