/*
	Leonardo Vencovsky
	09/03/2018
	Aula: Estrutura de Dados
	EEP

	Header file for SLL

    +-----------------------------------------+
    |            Singly Linked List           |
    +-----------------------------------------+

    All functions return a code that can be printed with raise()
*/

#ifndef SLL_H
# define SLL_H

typedef struct SinglyLinkedList SLL;

/*
 * Points to null
 * Do not use this function
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int initSLL(SLL **sll);

/*
 * Free memory of every node and points head to null
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int resetAndInitSLL(SLL **sll);

/*
 * Insert node at the first position of the list
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int data ] is the data to be inserted
 */
int insertHeadSLL(SLL **sll, int data);

/*
 * Insert node at chosen position
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int position ] is the desired position to insert new node
 */
int insertNodeSLL(SLL **sll, int data, int position);

/*
 * Insert node at the end of the list
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int insertTailSLL(SLL **sll, int data);

/*
 * Remove first node
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int removeHeadSLL(SLL **sll);

/*
 * Remove a chosen node
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int position ] is the position of the desired node to be removed (default start is 0)
 */
int removeNodeSLL(SLL **sll, int position);

/*
 * Remove last node
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int removeTailSLL(SLL **sll);

/*
 * Prints entire list.
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int printSLL(SLL *sll);

/*
 * Prints data from single node
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int position ] is the position of the node to have its data printed
 */
// TODO int printNodeSLL(SLL *sll, int position);

/*
 * Switch two nodes' position
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int position1 ] is the position of the first node
 * @Param [ int position2 ] is the position of the second node
 */
// TODO int switchNodesSLL(SLL *sll, int position1, int position2);

/*
 * Inverts list
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
// TODO int invertList(SLL **sll);                             // Inverts list

/*
 * Transforms an array to a list
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int *array ] array to be converted to a list
 */
// TODO int arrayToListSLL(SLL **sll, int *array);

/*
 * Reset and Initialize list with random numbers
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int initRandomSLL(SLL **sll);

/*
 * Insert n random nodes
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 * @Param [ int quantity ] how many nodes to be inserted at the end of the list
 */
int insertRandomSLL(SLL **sll, int quantity);

/*
 * Returns a copy of the list
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list to be copied
 */
//TODO SLL* cloneList(SLL **sll);

/*
 * Returns list's size
 *
 * @Param [ SLL **sll ] is the address of your pointer to the first position of the list
 */
int getListSize(SLL *sll);

/*
 * Clone SLL to new variable
 */
SLL ** cloneSLL(SLL **sll);

#endif //SLL_H
