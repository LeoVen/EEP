/**
 * @file hash_void.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/09/2018
 *
 * @brief Hash function that hashes structs
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct my_struct
{
	int id;
	double price;
	char code;
	size_t bar_code;
};

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} node_t;

size_t hash_djb2(void *param, size_t size)
{
	size_t i, hash = 5381;

	unsigned char *key = (unsigned char*)param;

	int c;

	for (i = 0, c = *(key + i); i < size; i++)
		hash = (hash << 5) + hash + c;

	return hash;
}

size_t hash_sdbm(void *param, size_t size)
{
	size_t i, hash = 0;

	unsigned char *key = (unsigned char*)param;

	int c;

	for (i = 0, c = *(key + i); i < size; i++)
		hash = c + (hash << 6) + (hash << 16) - hash;

	return hash;
}

int main(int argc, char const *argv[])
{
	struct my_struct *var = malloc(sizeof(struct my_struct));

	var->bar_code = (size_t)9378412982;
	var->code = 'c';
	var->id = 12;
	var->price = 29.9;

	if (!var)
		return -1;

	printf("%u\n", hash_sdbm(var, sizeof(var)));

	free(var);

	var = malloc(sizeof(struct my_struct));

	var->bar_code = (size_t)131313;
	var->code = 'K';
	var->id = 2221;
	var->price = 229.9;

	if (!var)
		return -1;

	printf("%u\n", hash_sdbm(var, sizeof(var)));

	free(var);

	node_t *node = malloc(sizeof(node));

	node->data = 19;
	node->next = NULL;
	node->next = NULL;

	printf("%u\n", hash_djb2(node, sizeof(node)));

	node->next = node;

	printf("%u\n", hash_djb2(node, sizeof(node)));

	double a = 4443321.331;
	int b = 122333;
	char *str = "Hello World!";

	printf("\n");
	printf("%u\n", hash_djb2(&a, sizeof(a)));
	printf("%u\n", hash_djb2(&b, sizeof(b)));
	printf("%u\n", hash_djb2(&str, sizeof(str)));

	return 0;
}
