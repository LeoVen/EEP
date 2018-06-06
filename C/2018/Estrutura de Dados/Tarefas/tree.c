/* Tarefa 5: Árvore Binária
 * Nome: Leonardo Vencovsky
 * RA: 201710276 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>
//#include <math.h>
//#include <time.h>
//#include <ctype.h>
//#include <conio.h>

#define BT_PRINT_SPACES 4

/**
 * @brief Status code returned by functions
 *
 * These status codes are returned by almost all functions in the project.
 * They are used to prevent unwanted results when a function fails and can
 * also be used by the user to control his/her own program flow.
 *
 */
typedef enum Status {
	DS_OK                        =  0, /**< Returned by a function when all operations were successful */
	DS_ERR_INVALID_POSITION      =  1, /**< When an invalid position is passed as argument */
	DS_ERR_INVALID_OPERATION     =  2, /**< When an invalid operation is made (e.g. remove element of an empty list ) */
	DS_ERR_INVALID_SIZE          =  3, /**< When an invalid size is given */
	DS_ERR_NOT_FOUND             =  4, /**< When a search fails to find a value */
	DS_ERR_ALLOC                 =  5, /**< When a function fails to allocate memory  */
	DS_ERR_UNEXPECTED_RESULT     =  6, /**< When an unexpected result happens. Contact developers. */
	DS_ERR_ITER                  =  7, /**< When an iteration reaches an unexpected value */
	DS_ERR_NULL_POINTER          =  8, /**< When a @c NULL parameter is passed to a function */
	DS_ERR_FULL                  =  9, /**< When a structure reaches its maximum capacity */
	DS_ERR_INVALID_ARGUMENT      = 10  /**< When an argument passed is invalid for that operation */
} Status;

/**
 * A @c BinarySearchTreeNode is what a @c BinarySearchTree is composed of.
 * It it much like a @c BinaryTree (Node) with one pointer to its left
 * child, one to its right child and another to its parent, being NULL if
 * that Node is the @c root.
 */
typedef struct BinarySearchTreeNode {
	int data;                           /*!< Node's data */
	size_t level;                       /*!< On what level the Node is in */
	struct BinarySearchTreeNode *right; /*!< Pointer to right child */
	struct BinarySearchTreeNode *left;  /*!< Pointer to left child */
	struct BinarySearchTreeNode *parent;/*!< Pointer to parent Node */
} BinarySearchTreeNode;

/**
 * A @c BinarySearchTree is much like a @c BinaryTree but now with a rule
 * for inserting the nodes. This now makes every @c BinarySearchTreeNode
 * binded to its descriptor, the @c BinarySearchTree, which has a size
 * variable counting the amount of elements in that tree, a depth variable
 * which keeps track of the deepest leaf and a pointer to the first node
 * added, the @c root. The insertion rule is that every Node to the left
 * must have a lower (key) value (data in this case) than its parent,
 * higher values to the right and no duplicate nodes.
 *
 * @note For simplicity the keys of each node are actually its data.
 */
typedef struct BinarySearchTree {
	size_t depth;                       /*!< @c BinarySearchTree depth */
	size_t size;                        /*!< Total @c BinarySearchTree elements */
	struct BinarySearchTreeNode *root;  /*!< Pointer to the very first node in the @c BinarySearchTree */
} BinarySearchTree;

Status bst_init_tree(BinarySearchTree **bst);
Status bst_init_node(BinarySearchTreeNode **node);

BinarySearchTree * bst_get_tree(void);
BinarySearchTreeNode * bst_get_node(int value);

Status bst_make_node(BinarySearchTreeNode **node, int value);

Status bst_insert(BinarySearchTree *bst, int value);

Status bst_display_wrapper(BinarySearchTree *bst, int display);
Status bst_display_raw(BinarySearchTreeNode *node);
Status bst_display_interactive(BinarySearchTreeNode *node);
Status bst_display_clean(BinarySearchTreeNode *node);

bool bst_is_empty(BinarySearchTree *bst);

size_t bst_height(BinarySearchTreeNode *node);

Status bst_traversal_wrapper(BinarySearchTree *bst, int traversal);
Status bst_traversal_preorder(BinarySearchTreeNode *node);
Status bst_traversal_inorder(BinarySearchTreeNode *node);
Status bst_traversal_postorder(BinarySearchTreeNode *node);

Status bst_traversal_leaves(BinarySearchTreeNode *node);

char * status_repr(Status status);

void print_status_repr(Status status);

/**
 * @brief Visualize status codes
 *
 * This function returns a string that represents the status error for
 * better visualization.
 *
 * @param[in] status The status returned by a function
 *
 * @return A string equivalent of the status name
 */
char * status_repr(Status status)
{
	switch (status)
	{
		case DS_OK: return "DS_OK";
		case DS_ERR_INVALID_POSITION: return "DS_ERR_INVALID_POSITION";
		case DS_ERR_INVALID_OPERATION: return "DS_ERR_INVALID_OPERATION";
		case DS_ERR_INVALID_SIZE: return "DS_ERR_INVALID_SIZE";
		case DS_ERR_NOT_FOUND: return "DS_ERR_NOT_FOUND";
		case DS_ERR_ALLOC: return "DS_ERR_ALLOC";
		case DS_ERR_UNEXPECTED_RESULT: return "DS_ERR_UNEXPECTED_RESULT";
		case DS_ERR_ITER: return "DS_ERR_ITER";
		case DS_ERR_NULL_POINTER: return "DS_ERR_NULL_POINTER";
		case DS_ERR_FULL: return "DS_ERR_FULL";
		case DS_ERR_INVALID_ARGUMENT: return "DS_ERR_INVALID_ARGUMENT";
		default: return "DS_UNKNOWN_ERROR";
	}
}

/**
 * @brief Visualize status codes in the console
 *
 * This function automatically prints a status code in your console. Can be
 * used for debugging.
 *
 * @param[in] status The status returned by a function
 */
void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status bst_init_tree(BinarySearchTree **bst)
{
	(*bst) = malloc(sizeof(BinarySearchTree));

	if (!(*bst))
		return DS_ERR_ALLOC;

	(*bst)->root = NULL;

	(*bst)->depth = 0;
	(*bst)->size = 0;

	return DS_OK;
}

Status bst_init_node(BinarySearchTreeNode **node)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	if (!(*node))
		return DS_ERR_ALLOC;

	(*node)->left = NULL;
	(*node)->right = NULL;

	(*node)->parent = NULL;

	(*node)->level = 0;
	(*node)->data = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+*

BinarySearchTree * bst_get_tree(void)
{
	BinarySearchTree *bst = malloc(sizeof(BinarySearchTree));

	bst->root = NULL;

	bst->depth = 0;
	bst->size = 0;

	return bst;
}

BinarySearchTreeNode * bst_get_node(int value)
{
	BinarySearchTreeNode *node = malloc(sizeof(BinarySearchTreeNode));

	node->left = NULL;
	node->right = NULL;

	node->parent = NULL;

	node->level = 0;
	node->data = value;
	
	return node;
}

Status bst_make_node(BinarySearchTreeNode **node, int value)
{
	(*node) = malloc(sizeof(BinarySearchTreeNode));

	(*node)->data = value;

	(*node)->left = NULL;
	(*node)->right = NULL;

	(*node)->parent = NULL;

	(*node)->level = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status bst_insert(BinarySearchTree *bst, int value)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	BinarySearchTreeNode *node;

	Status st = bst_make_node(&node, value);

	if (st != DS_OK)
		return st;

	BinarySearchTreeNode *scan = bst->root;
	BinarySearchTreeNode *before = NULL;

	while (scan != NULL)
	{
		before = scan;

		if (scan->data < value)
			scan = scan->left;
		else if (scan->data > value)
			scan = scan->right;
		else {

			free(node);

			return DS_OK;
		}

	}

	if (before == NULL) {

		node->parent = NULL;

		bst->root = node;

		(bst->size)++;

		return DS_OK;
	}
	
	node->parent = before;
	node->level = before->level + 1;

	bst->depth = node->level;

	if (before->data < value)
		before->left = node;
	else
		before->right = node;

	(bst->size)++;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status bst_display_wrapper(BinarySearchTree *bst, int display)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	Status st;

	printf("\n+----------------------+");
	printf("\n|  Binary Search Tree  |");
	printf("\n+----------------------+\n");

	switch (display)
	{
	case -1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_clean(bst->root);
		break;
	case 0:
		st = bst_display_raw(bst->root);
		break;
	case 1:
		printf("\n<PARENT(DATA)[D-DEPTH|H-HEIGHT]\n\n");
		st = bst_display_interactive(bst->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	printf("\n");

	if (st != DS_OK)
		return st;

	return DS_OK;
}

Status bst_display_raw(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_raw(node->left);

	size_t i;
	for (i = 0; i < node->level * BT_PRINT_SPACES; i++)
		printf(" ");
	printf("%d\n", node->data);

	bst_display_raw(node->right);

	return DS_OK;
}

Status bst_display_interactive(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_interactive(node->left);

	size_t i;
	for (i = 0; i < node->level; i++)
		printf("|-------");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%u|H-%u]\n", node->parent->data, node->data, node->level, bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%u|H-%u]\n", 0, node->data, node->level, bst_height(node) - 1);


	bst_display_interactive(node->right);

	return DS_OK;
}

Status bst_display_clean(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_display_clean(node->left);

	size_t i;
	for (i = 0; i < node->level; i++)
		printf("|       ");

	if (node->parent != NULL)
		printf("<%d(%d)[D-%u|H-%u]\n", node->parent->data, node->data, node->level, bst_height(node) - 1);
	else
		printf("<%d(%d)[D-%u|H-%u]\n", 0, node->data, node->level, bst_height(node) - 1);


	bst_display_clean(node->right);

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool bst_is_empty(BinarySearchTree *bst)
{
	return (bst->root == NULL);
}

size_t bst_height(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return 0;

	size_t r_height = bst_height(node->right);

	size_t l_height = bst_height(node->left);

	return (l_height > r_height) ? l_height + 1 : r_height + 1;
}

// +-------------------------------------------------------------------------------------------------+
// |                                           Traversal                                             |
// +-------------------------------------------------------------------------------------------------+

Status bst_traversal_wrapper(BinarySearchTree *bst, int traversal)
{
	if (bst == NULL)
		return DS_ERR_NULL_POINTER;

	if (bst_is_empty(bst))
		return DS_ERR_INVALID_OPERATION;

	switch (traversal)
	{
	case -1:
		bst_traversal_preorder(bst->root);
		break;
	case 0:
		bst_traversal_inorder(bst->root);
		break;
	case 1:
		bst_traversal_postorder(bst->root);
		break;
	default:
		return DS_ERR_INVALID_ARGUMENT;
	}

	return DS_OK;
}

Status bst_traversal_preorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	printf(" %d", node->data);

	bst_traversal_preorder(node->right);

	bst_traversal_preorder(node->left);

	return DS_OK;
}

Status bst_traversal_inorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_inorder(node->right);

	printf(" %d", node->data);

	bst_traversal_inorder(node->left);

	return DS_OK;
}

Status bst_traversal_postorder(BinarySearchTreeNode *node)
{
	if (node == NULL)
		return DS_OK;

	bst_traversal_postorder(node->right);

	bst_traversal_postorder(node->left);

	printf(" %d", node->data);

	return DS_OK;
}

Status bst_traversal_leaves(BinarySearchTreeNode *node)
{
	if (node->right != NULL) {
		bst_traversal_leaves(node->right);
	}
	if (node->left != NULL) {
		bst_traversal_leaves(node->left);
	}
	if (node->left == NULL && node->right == NULL) {
		printf(" %d", node->data);
	}

	return DS_OK;
}

int main(int argc, char const *argv[])
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |         C Binary Search Tree        |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	BinarySearchTree *bst;

	bst_init_tree(&bst);

	print_status_repr(bst_insert(bst, 100));
	print_status_repr(bst_insert(bst, 20));
	print_status_repr(bst_insert(bst, 150));
	print_status_repr(bst_insert(bst, 10));
	print_status_repr(bst_insert(bst, 30));
	print_status_repr(bst_insert(bst, 149));
	print_status_repr(bst_insert(bst, 160));

	printf("\n");

	bst_display_wrapper(bst, 0);
	printf("\n ---------- ---------- ---------- ----------\n");
	bst_traversal_wrapper(bst, 0);

	int i;
	for (i = 0; i < 100; i++)
	{
		bst_insert(bst, rand() % 200);
	}

	bst_display_wrapper(bst, 0);
	printf("\n ---------- ---------- ---------- ----------\n");
	bst_traversal_wrapper(bst, 0);

	//bst_erase(&bst);

	BinarySearchTree *b;
	bst_init_tree(&b);

	for (i = 0; i < 50; i++)
		bst_insert(b, rand() % 50);
	
	bst_display_wrapper(b, 1);

	bst_traversal_wrapper(b,-1); // preorder
	printf("\n\n");
	bst_traversal_wrapper(b, 0); // inorder
	printf("\n\n");
	bst_traversal_wrapper(b, 1); // postorder
	
	printf("\nLeaves: \n");
	bst_traversal_leaves(b->root);

	printf("\nTree depth: %u", b->depth);

	BinarySearchTree *b2;

	bst_init_tree(&b2);

	for (i = 0; i < 200; i++)
		bst_insert(b2, rand() % 500);

	bst_display_wrapper(b2, -1);
	
	//bst_delete(&b);

	printf("\n");
	return 0;
}