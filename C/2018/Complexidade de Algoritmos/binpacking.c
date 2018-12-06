/**
* @file binpacking.c
*
* @author Leonardo Vencovsky
* @author Guilherme Pinazza
* @author Yan Trevizam
*
* @date 29/11/2018
*
* @brief Bin-packing algorithm
*
*/
#include <stdio.h>  // printf
#include <stdlib.h> // malloc/free
#include <math.h>   // used in RANDI macro
#include <string.h> // atoi
#include <time.h>   // srand(time(0))

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

// A block to be fit into plates
typedef struct block
{
	struct Node *fit;
	int width, height, x, y, id;
} block_t;

typedef struct Node
{
	struct Node *down, *right;
	int used, width, height, x, y;
} node_t;

///////////////////////////////////////////////////////////////// Functions ///

block_t *new_block(int w, int h, int id);

node_t *new_node(int x, int y, int width, int height);

int compare_block(block_t *b1, block_t *b2);

void quicksort(int(*d_compare)(block_t*, block_t*), block_t *buffer[],
                size_t length);

void display_blocks(block_t *blocks[], size_t size);

void sort_example();

void load_blocks(FILE *f, int *nplates, int *pwidth, int *pheight,
                 block_t **blocks[], int *bcount);

void free_tree(node_t *root);

node_t *find(node_t *node, int w, int h);

node_t *split(node_t *node, int w, int h);

void binpacking(FILE *output, block_t **blocks, int bcount, int nplates,
				int pwidth, int pheight);

////////////////////////////////////////////////////////// End of Functions ///

// Allocates a new block
block_t *new_block(int w, int h, int id)
{
	block_t *b = malloc(sizeof(block_t));

	if (!b)
		return NULL;

	b->width = w;
	b->height = h;

	b->x = 0;
	b->y = 0;

	b->fit = NULL;

	b->id = id;

	return b;
}

// Allocates a new node
node_t *new_node(int x, int y, int width, int height)
{
	node_t *node = malloc(sizeof(node_t));

	node->x = x;
	node->y = y;

	node->width = width;
	node->height = height;

	node->down = NULL;
	node->right = NULL;

	node->used = 0;

	return node;
}

// Compares by the maximum side. If both are the same, compare by their area.
int compare_block(block_t *b1, block_t *b2)
{
	int c1 = MAX(b1->width, b1->height);
	int c2 = MAX(b2->width, b2->height);

	if (c1 == c2)
		return b2->width * b2->height - b1->width * b1->height;

	return c2 - c1;
}

// Sorts and array of blocks using a compare function
void quicksort(int(*d_compare)(block_t*, block_t*), block_t *buffer[], size_t length)
{
	if (length < 2)
		return;

	block_t *pivot = buffer[length / 2];

	size_t i, j;
	for (i = 0, j = length - 1; ; i++, j--)
	{
		while (d_compare(buffer[i], pivot) < 0)
			i++;

		while (d_compare(buffer[j], pivot) > 0)
			j--;

		if (i >= j)
			break;

		block_t *temp = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = temp;
	}

	quicksort(d_compare, buffer, i);
	quicksort(d_compare, buffer + i, length - i);
}

// Displays an array of blocks
void display_blocks(block_t *blocks[], size_t size)
{
	printf("\n[ ");
	for (size_t i = 0; i < size - 1; i++)
	{
		printf("[ %d, %d ]", blocks[i]->width, blocks[i]->height);

		printf(", ");
	}

	printf("[ %d, %d ] ]\n", blocks[size - 1]->width, blocks[size - 1]->height);
}

// Example
void sort_example()
{

#define RANDI(MIN, MAX) floor(((double)rand() / (double)RAND_MAX) *  \
						((double)MAX - (double)MIN + 1.0) + (double)MIN)

	srand(time(0));

	const size_t size = 100;

	block_t **blocks = malloc(sizeof(block_t*) * size);

	for (size_t i = 0; i < size; i++)
	{
		blocks[i] = new_block(RANDI(1, 99), RANDI(1, 99), i);
	}

	display_blocks(blocks, size);

	quicksort(compare_block, blocks, size);

	printf("\nSorted blocks");

	display_blocks(blocks, size);

	for (size_t i = 0; i < size; i++)
	{
		free(blocks[i]);
	}

	free(blocks);
}

// Loads plates and blocks from a file
void load_blocks(FILE *f, int *nplates, int *pwidth, int *pheight,
                 block_t **blocks[], int *bcount)
{
	char buffer[500];

	*blocks = NULL;
	*nplates = -1;
	*pwidth = -1;
	*pheight = -1;
	*bcount = -1;

	int i = 0;
	int b = 0;

	int w, h, id = 0;

	while (fgets(buffer, 500, f))
	{
		switch (++i)
		{
		case 1:
			sscanf(buffer, "%d\n", &(*nplates));
			break;
		case 2:
			sscanf(buffer, "%d\n", &(*pwidth));
			break;
		case 3:
			sscanf(buffer, "%d\n", &(*pheight));
			break;
		case 4:
			sscanf(buffer, "%d\n", &(*bcount));
			break;
		default:
			if (!(*blocks))
				*blocks = malloc(sizeof(block_t*) * (*bcount));

			sscanf(buffer, "%d %d", &w, &h);

			(*blocks)[b++] = new_block(w, h, ++id);

			break;
		}
	}
}

void free_tree(node_t *root)
{
	if (root == NULL)
		return;

	free_tree(root->down);

	free_tree(root->right);

	free(root);
}

// Encontrar um no na arvore
node_t *find(node_t *node, int w, int h)
{
	if (node->used == 1)
	{
		node_t *right = find(node->right, w, h);
		if (right)
			return right;
		
		node_t *down = find(node->down, w, h);
		if (down)
			return down;
	}
	else if ((w <= node->width) && (h <= node->height))
		return node;
	else
		return NULL;
}

// Criar dois filhos
node_t *split(node_t *node, int w, int h)
{
	node->used = 1;

	node->down = new_node(node->x, node->y + h, node->width, node->height - h);

	node->right = new_node(node->x + w, node->y, node->width - w, h);

	return node;
}

// Arquivo para escrita, blocos, quantidade de blocos, quantidade de placas,
// largura e altura das placas
void binpacking(FILE *output, block_t **blocks, int bcount, int nplates,
				int pwidth, int pheight)
{
	// Remaining blocks
	int blocks_lt = 0;
	block_t **blocks_left = malloc(sizeof(block_t*) * bcount);

	// Tree root
	node_t *root = new_node(0, 0, pwidth, pheight);

	// Looping through all the plates
	for (int P = 1; P <= nplates; P++)
	{
		fprintf(output, "Plate %d\n", P);

		// Resetting
		root->used = 0;
		free_tree(root->down);
		free_tree(root->right);
		blocks_lt = 0;

		// Sorting blocks
		quicksort(compare_block, blocks, bcount);

		// Creating the tree
		for (int i = 0; i < bcount; i++)
		{
			block_t *sblock = blocks[i];
			node_t *node = NULL;

			if ((node = find(root, sblock->width, sblock->height)))
			{
				sblock->fit = split(node, sblock->width, sblock->height);
			}
		}

		block_t *scan;

		// Imprimindo os blocos que encaixaram no arquivo e os que nao encaixaram
		// reportar no terminal
		for (int i = 0; i < bcount; i++)
		{
			scan = blocks[i];

			if (scan->fit)
			{
				fprintf(output, "X%4d\tY%4d\tW%4d\tH%4d\n", scan->fit->x,
				        scan->fit->y, scan->width, scan->height);
				printf("Block %d fits in plate %d\n", scan->id, P);
				printf("X %2d Y %2d\n", scan->fit->x, scan->fit->y);
				printf("W %2d H %2d\n\n", scan->width, scan->height);
			}
			else
			{
				printf("Block %d won't fit in plate %d\n\n", scan->id, P);
				blocks_left[blocks_lt++] = scan;
			}
		}

		// Get remaining blocks for the next plate
		bcount = blocks_lt;
		for (int i = 0; i < blocks_lt; i++)
		{
			free(blocks[i]);
			blocks[i] = blocks_left[i];
		}
	}

	// Checking blocks that didn't fit in any plates
	for (int i = 0; i < blocks_lt; i++)
	{
		fprintf(output, "\nW%4d H%4d didn't fit", blocks[i]->width, blocks[i]->height);
		printf("\nBLOCK %d dont fit in any BOARD \n", blocks[i]->id);
	}

	free(blocks_left);
	free(root);
}

int main(int argc, char const *argv[])
{
	//sort_example();

	if (argc == 1)
		printf("\nUsage:\n%s <file_name>\n", argv[0]);

	FILE *f = fopen(argv[1], "r");

	if (!f)
	{
		printf("File not found\n");

		return -1;
	}

	// number of plates, plate width, plate height, blocks count
	int nplates, pwidth, pheight, bcount;

	block_t **blocks;

	load_blocks(f, &nplates, &pwidth, &pheight, &blocks, &bcount);

	printf("\nAvailable Blocks:");
	display_blocks(blocks, bcount);
	printf("\n\n");

	FILE *output = fopen("output.txt", "w+");

	if (!output)
	{
		printf("Could not open file\n");

		return -1;
	}

	binpacking(output, blocks, bcount, nplates, pwidth, pheight);

	for (int i = 0; i < bcount; i++)
		free(blocks[i]);

	free(blocks);

	fclose(f);
	fclose(output);

	return 0;
}
