# Simple Singly Linked List

## Structure

    struct SimpleSinglyLinkedList {
        int data;
        struct SimpleSinglyLinkedList *next;
    };

## Functions

    int initSSLL                 (SSLL **ssll);
    int resetAndInitSSLL         (SSLL **ssll);
    int insertHeadSSLL           (SSLL **ssll, int data);
    int insertNodeSSLL           (SSLL **ssll, int data, int position);
    int insertTailSSLL           (SSLL **ssll, int data);
    int removeHeadSSLL           (SSLL **ssll);
    int removeMiddleSSLL         (SSLL **ssll, int position);
    int removeTailSSLL           (SSLL **ssll);
    int printSSLL                (SSLL  *ssll);
    TODO int printNodeSSLL       (SSLL  *ssll, int position);
    TODO int switchNodesSSLL     (SSLL **ssll, int position1, int position2);
    TODO int invertSSLLLL        (SSLL **ssll);
    TODO int arrayToList         (SSLL **ssll, int v*);
    int initRandomSSLL           (SSLL **ssll);
    int insertRandomSSLL         (SSLL **ssll, int quantity);
    TODO SSLL* cloneList         (SSLL **ssll);
    int getListSize              (SSLL  *ssll);

### Initialize pointer

    int initSSLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

Points to null. Avoid using this function.

### Reset and Initialize List

    int resetAndInitSSLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

Free memory of every node and points head to null

### Insert node at the first position of the list

    int insertHeadSSLL(SSLL **ssll, int data);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int data \] data to be inserted

### Insert node at chosen position

    int insertNodeSSLL(SSLL **ssll, int data, int position);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int position \] desired position to insert new node

### Insert node at the end of the list

    int insertTailSSLL(SSLL **ssll, int data);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Remove first node

    int removeHeadSSLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Remove a chosen node

    int removeMiddleSSLL(SSLL **ssll, int position);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int position \] position of the desired node to be removed (default start is 0)

### Remove last node

    int removeTailSSLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Prints entire list

    int printSSLL(SSLL *ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Prints data from single node

    TODO int printNodeSSLL(SSLL *ssll, int position);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Switch two nodes' position

    TODO int switchNodesSSLL(SSLL *ssll, int position1, int position2);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int position1 \] position of the first node

>@Param \[ int position2 \] position of the second node

### Invert List

    TODO int invertSSLLLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Transform an array to a list

    TODO int arrayToList(SSLL **ssll, int v[]);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int v* \] array to be converted to a list

### Reset and Initialize list with random numbers

    int initRandomSSLL(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

### Insert n random nodes

    int insertRandomSSLL(SSLL **ssll, int quantity);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

>@Param \[ int quantity \] how many nodes to be inserted at the end of the list

### Returns a copy of the list

    TODO SSLL* cloneList(SSLL **ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list to be copied

### Returns list's size

    int getListSize(SSLL *ssll);

>@Param \[ SSLL **ssll \] address of your pointer to the first position of the list

Note that this function does not return a code and should not be treated with raise()
