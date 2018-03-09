/*
	Leonardo Vencovsky
	09/03/2018
	Aula: Estrutura de Dados
	EEP

	Header file for SSLL

    +-----------------------------------------+
    |        Simple Singly Linked List        |
    +-----------------------------------------+

    All functions return a code that can be printed with raise()
*/

#ifndef SSLL_H
# define SSLL_H

typedef struct SimpleSinglyLinkedList SSLL;

/*
 * Points to null
 * Do not use this function
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int initSSLL(SSLL **ssll);

/*
 * Free memory of every node and points head to null
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int resetAndInitSSLL(SSLL **ssll);

/*
 * Insert node at the first position of the list
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int data is the data to be inserted
 */
int insertHeadSSLL(SSLL **ssll, int data);

/*
 * Insert node at chosen position
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int position is the desired position to insert new node
 */
int insertNodeSSLL(SSLL **ssll, int data, int position);

/*
 * Insert node at the end of the list
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int insertTailSSLL(SSLL **ssll, int data);

/*
 * Remove first node
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int removeHeadSSLL(SSLL **ssll);

/*
 * Remove a chosen node
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int position is the position of the desired node to be removed (default start is 0)
 */
int removeMiddleSSLL(SSLL **ssll, int position);

/*
 * Remove last node
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int removeTailSSLL(SSLL **ssll);

/*
 * Prints entire list.
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int printSSLL(SSLL *ssll);

/*
 * Prints data from single node
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int position is the position of the node to have its data printed
 */
// TODO int printNodeSSLL(SSLL *ssll, int position);

/*
 * Switch two nodes' position
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int position1 is the position of the first node
 * @Param int position2 is the position of the second node
 */
// TODO int switchNodesSSLL(SSLL *ssll, int position1, int position2);

/*
 * Inverts list
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
// TODO int invertList(SSLL **ssll);                             // Inverts list

/*
 * Transforms an array to a list
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int v* array to be converted to a list
 */
// TODO int arrayToList(SSLL **ssll, int v[]);

/*
 * Reset and Initialize list with random numbers
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int initRandomSSLL(SSLL **ssll);

/*
 * Insert n random nodes
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 * @Param int quantity how many nodes to be inserted at the end of the list
 */
int insertRandomSSLL(SSLL **ssll, int quantity);

/*
 * Returns a copy of the list
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list to be copied
 */
//TODO SSLL* cloneList(SSLL **ssll);

/*
 * Returns list's size
 *
 * @Param SSLL **ssll is the address of your pointer to the first position of the list
 */
int getListSize(SSLL *ssll);

#endif //SSLL_H
