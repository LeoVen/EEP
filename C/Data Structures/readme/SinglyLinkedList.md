# Singly Linked List

## Structure

    struct SinglyLinkedList {
        int data;
        struct SinglyLinkedList *next;
    };

## Functions

    int initSLL                 (SLL **sll);
    int resetAndInitSLL         (SLL **sll);
    int insertHeadSLL           (SLL **sll, int data);
    int insertNodeSLL           (SLL **sll, int data, int position);
    int insertTailSLL           (SLL **sll, int data);
    int removeHeadSLL           (SLL **sll);
    int removeNodeSLL         (SLL **sll, int position);
    int removeTailSLL           (SLL **sll);
    int printSLL                (SLL  *sll);
    TODO int printNodeSLL       (SLL  *sll, int position);
    TODO int switchNodesSLL     (SLL **sll, int position1, int position2);
    TODO int invertSLLLL        (SLL **sll);
    TODO int arrayToList         (SLL **sll, int v*);
    int initRandomSLL           (SLL **sll);
    int insertRandomSLL         (SLL **sll, int quantity);
    TODO SLL* cloneList         (SLL **sll);
    int getListSize              (SLL  *sll);

### Initialize pointer

    int initSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

Points to null. Avoid using this function.

### Reset and Initialize List

    int resetAndInitSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

Free memory of every node and points head to null

### Insert node at the first position of the list

    int insertHeadSLL(SLL **sll, int data);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int data \] data to be inserted

### Insert node at chosen position

    int insertNodeSLL(SLL **sll, int data, int position);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int position \] desired position to insert new node

### Insert node at the end of the list

    int insertTailSLL(SLL **sll, int data);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Remove first node

    int removeHeadSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Remove a chosen node

    int removeNodeSLL(SLL **sll, int position);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int position \] position of the desired node to be removed (default start is 0)

### Remove last node

    int removeTailSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Prints entire list

    int printSLL(SLL *sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Prints data from single node

    TODO int printNodeSLL(SLL *sll, int position);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Switch two nodes' position

    TODO int switchNodesSLL(SLL *sll, int position1, int position2);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int position1 \] position of the first node

>@Param \[ int position2 \] position of the second node

### Invert List

    TODO int invertSLLLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Transform an array to a list

    TODO int arrayToList(SLL **sll, int v[]);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int v* \] array to be converted to a list

### Reset and Initialize list with random numbers

    int initRandomSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

### Insert n random nodes

    int insertRandomSLL(SLL **sll, int quantity);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

>@Param \[ int quantity \] how many nodes to be inserted at the end of the list

### Returns a copy of the list

    TODO SLL* cloneListSLL(SLL **sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list to be copied

### Returns list's size

    int getListSizeSLL(SLL *sll);

>@Param [ SLL \*\*sll \] address of your pointer to the first position of the list

Note that this function does not return a code and should not be treated with raise()
