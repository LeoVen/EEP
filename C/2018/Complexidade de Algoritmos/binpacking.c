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
	int width, height, x, y;
} block_t;

// Allocates a new block
block_t *new_block(int w, int h)
{
	block_t *b = malloc(sizeof(block_t));

	if (!b)
		return NULL;

	b->width = w;
	b->height = h;

	b->x = 0;
	b->y = 0;

	return b;
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
		blocks[i] = new_block(RANDI(1, 99), RANDI(1, 99));
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

	int w, h;

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

			(*blocks)[b++] = new_block(w, h);

			break;
		}
	}
}

void binpacking(/* TODO */)
{
	// TODO
}

int main(int argc, char const *argv[])
{
	//sort_example();

	if (argc == 1)
		printf("\nUsage:\n%s <file_name>\n", argv[0]);

	FILE *f = fopen(argv[1], "r");

	if (!f)
	{
		printf("File not found");

		return -1;
	}

	// number of plates, plate width, plate height, blocks count
	int nplates, pwidth, pheight, bcount;

	block_t **blocks;

	load_blocks(f, &nplates, &pwidth, &pheight, &blocks, &bcount);

	printf("\nNumber of plates: %d", nplates);
	printf("\nDimensions: W: %d, H: %d", pwidth, pheight);
	printf("\nSorted Blocks:");

	quicksort(compare_block, blocks, bcount);

	display_blocks(blocks, bcount);

	for (int i = 0; i < bcount; i++)
		free(blocks[i]);

	free(blocks);

	fclose(f);

	return 0;
}
