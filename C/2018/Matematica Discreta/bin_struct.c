/**
 * @file bin_struct.c
 * 
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/06/2018
 *
 * Let E = {0, 1} a binary set.
 * The operation @ is a composition between Fi and Fj where i,j = 1, 2, 3, 4
 * 
 * Operation table of @
 * 
 * Study the structure (E, @)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ****************************************************************************
 *
 * Function Declarations and typedefs
 *
 *************************************************************************** */

/* A binary object containing two bits */
struct binary_object_t {
	bool b1;
	bool b2;
};

typedef void (*func_t)(struct binary_object_t *obj);

/* Checks commutativity */
void comm(struct binary_object_t *obj, func_t f1, func_t f2);

/* Checks associativity*/
void assoc(struct binary_object_t *obj, func_t f1, func_t f2, func_t f3);

/* Translates object to function output equivalent */
int bo_translate(struct binary_object_t *obj);

/* Resets structure */
void bo_reset(struct binary_object_t *obj);

/* Translates function representation */
int f_translate(func_t f);

/* Binary functions */
void f1(struct binary_object_t *obj);
void f2(struct binary_object_t *obj);
void f3(struct binary_object_t *obj);
void f4(struct binary_object_t *obj);

/* ****************************************************************************
 *
 * Function Implementations
 *
 *************************************************************************** */

void comm(struct binary_object_t *obj, func_t f1, func_t f2)
{
	bo_reset(obj);

	/* X @ Y */
	f1(obj);
	f2(obj);

	int t1 = bo_translate(obj);

	bo_reset(obj);

	/* Y @ X */
	f2(obj);
	f1(obj);

	int t2 = bo_translate(obj);

	printf("\nComm(0, 1) -> f[%d %d] = [%d] & [%d]", f_translate(f1), f_translate(f2), f_translate(f3), t1, t2);
}

void assoc(struct binary_object_t *obj, func_t f1, func_t f2, func_t f3)
{
	bo_reset(obj);

	/* X @ (Y @ Z) */
	f3(obj);
	f2(obj);
	f1(obj);

	int t1 = bo_translate(obj);

	bo_reset(obj);

	/* (X @ Y) @ Z*/
	f2(obj);
	f1(obj);
	f3(obj);

	int t2 = bo_translate(obj);

	printf("\nAssoc(0, 1) -> f[%d %d %d] = [%d] & [%d]", f_translate(f1), f_translate(f2), f_translate(f3), t1, t2);
}

int bo_translate(struct binary_object_t *obj)
{
	if (!obj->b1 &&  obj->b2) /* [ 0 , 1 ] */
		return 1;
	if ( obj->b1 && !obj->b2) /* [ 1 , 0 ] */
		return 2;
	if (!obj->b1 && !obj->b2) /* [ 0 , 0 ] */
		return 3;
	if ( obj->b1 &&  obj->b2) /* [ 1 , 1 ]*/
		return 4;

	return 0;
}

void bo_reset(struct binary_object_t *obj)
{
	obj->b1 = false;
	obj->b2 = true;
}

int f_translate(func_t f)
{
	if (f == f1)
		return 1;
	if (f == f2)
		return 2;
	if (f == f3)
		return 3;
	if (f == f4)
		return 4;

	return 0;
}

/* Bijective */
void f1(struct binary_object_t *obj)
{
	obj->b1 = obj->b1;
	obj->b2 = obj->b2;
}

/* Bijective */
void f2(struct binary_object_t *obj)
{
	obj->b1 = (obj->b1) ? false : true;
	obj->b2 = (obj->b2) ? false : true;
}

/* Not Bijective */
void f3(struct binary_object_t *obj)
{
	obj->b1 = false;
	obj->b2 = false;
}

/* Not Bijective */
void f4(struct binary_object_t *obj)
{
	obj->b1 = true;
	obj->b2 = true;
}

/* ****************************************************************************
 *
 * Entry Point (main)
 *
 *************************************************************************** */

int main(int argc, char const *argv[])
{
	/* An array of all functions later used in permutation */
	func_t f[4] = {f1, f2, f3, f4};

	/* Initializing binary object */
	struct binary_object_t *bin_o = malloc(sizeof(struct binary_object_t));

	size_t a, b, c;

	/* Associativity */
	for (a = 0; a < 4; a++)
		for (b = 0; b < 4; b++)
			for (c = 0; c < 4; c++)
				assoc(bin_o, f[a], f[b], f[c]);
				
	/* Commutativity */
	for (a = 0; a < 4; a++)
		for (b = 0; b < 4; b++)
			comm(bin_o, f[a], f[b]);

	/* Operation table */
	int table[4][4];

	/**
	 * Table should evaluate to:
	 * +----+-----+----+----+----+
	 * |  @ || f1 | f2 | f3 | f4 |
	 * +====++====+====+====+====+
	 * | f1 || f1 | f2 | f3 | f4 |
	 * +----++----+----+----+----+
	 * | f2 || f2 | f1 | f3 | f4 |
	 * +----++----+----+----+----+
	 * | f3 || f3 | f4 | f3 | f4 |
	 * +----++----+----+----+----+
	 * | f4 || f4 | f3 | f3 | f4 |
	 * +----++----+----+----+----+
	 * 
	 * 
	 */

	// TODO

	free(bin_o);

	return 0;
}
