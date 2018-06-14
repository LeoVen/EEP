/* Tarefa 6: Hashing
 * Nome: Leonardo Vencovsky
 * RA: 201710276 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//#include <math.h>
//#include <time.h>
//#include <ctype.h>
//#include <conio.h>

typedef enum Status {
	DS_OK                        =  0,
	DS_ERR_INVALID_POSITION      =  1,
	DS_ERR_INVALID_OPERATION     =  2,
	DS_ERR_INVALID_SIZE          =  3,
	DS_ERR_NOT_FOUND             =  4,
	DS_ERR_ALLOC                 =  5,
	DS_ERR_UNEXPECTED_RESULT     =  6,
	DS_ERR_ITER                  =  7,
	DS_ERR_NULL_POINTER          =  8,
	DS_ERR_FULL                  =  9,
	DS_ERR_INVALID_ARGUMENT      = 10
} Status;

char * status_repr(Status status);

void print_status_repr(Status status);

int dev_short_cut(void);

#ifndef HASH_FUNCTION_TYPE
#define HASH_FUNCTION_TYPE
	typedef Status(*hash_function_t)(char *, size_t *);
#endif

#ifndef REHASH_FUNCTION_TYPE
#define REHASH_FUNTION_TYPE
	typedef Status(*rehash_function_t)(size_t *);
#endif

typedef struct HashSetEntry {
	char *value;
	size_t hash;
} HashSetEntry;

typedef struct HashSet {
	struct HashSetEntry **buckets;
	size_t size;
	size_t max_size;
	Status(*hash_function) (char *, size_t *);
	Status(*rehash_function) (size_t *);
} HashSet;

Status set_init_table(HashSet **set, size_t max_size, hash_function_t hash_function, rehash_function_t rehash_function);

Status set_init_entry(HashSetEntry **entry, char *value);

Status set_make_entry(HashSetEntry **entry, char *key, size_t hash);

Status set_insert(HashSet *set, char *value);

Status set_remove(HashSet *set, char *value);

Status set_display_entry(HashSetEntry *entry);
Status set_display_entry_raw(HashSetEntry *entry);
Status set_display_table(HashSet *set);
Status set_display_table_raw(HashSet *set);

Status set_delete_table(HashSet **set);
Status set_erase_table(HashSet **set);

bool set_is_full(HashSet *set);
bool set_is_empty(HashSet *set);

Status set_contains(HashSet *set, char *value, bool *result);
bool set_exists(HashSet *set, char *value);

Status set_count_elements(HashSet *set, size_t *result);
Status set_count_empty(HashSet *set, size_t *result);

Status set_hash_string_djb2(char *key, size_t *hash);
Status set_hash_string_sdbm(char *key, size_t *hash);
Status set_hash_string_fnv(char *key, size_t *hash);

Status set_rehash_rj(size_t *hash);
Status set_rehash_prime(size_t *hash);

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

void print_status_repr(Status status)
{
	printf("\n%s", status_repr(status));
}

// +-------------------------------------------------------------------------------------------------+
// |                                          Initializers                                           |
// +-------------------------------------------------------------------------------------------------+

Status set_init_table(HashSet **set, size_t max_size, hash_function_t hash_function, rehash_function_t rehash_function)
{
	if (max_size == 0)
		return DS_ERR_INVALID_SIZE;

	if (hash_function == NULL)
		return DS_ERR_INVALID_ARGUMENT;

	*set = malloc(sizeof(HashSet));

	if (!(*set))
		return DS_ERR_ALLOC;

	(*set)->buckets = malloc(sizeof(HashSetEntry *) * max_size);

	if (!((*set)->buckets))
		return DS_ERR_ALLOC;

	size_t i;
	for (i = 0; i < max_size; i++) {

		((*set)->buckets)[i] = NULL;
	}

	(*set)->size = 0;
	(*set)->max_size = max_size;

	(*set)->hash_function = hash_function;
	(*set)->rehash_function = rehash_function;

	return DS_OK;
}

Status set_init_entry(HashSetEntry **entry, char *value)
{
	*entry = malloc(sizeof(HashSetEntry));

	if (!(*entry))
		return DS_ERR_ALLOC;

	(*entry)->value = _strdup(value);
	(*entry)->hash = 0;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Getters                                              |
// +-------------------------------------------------------------------------------------------------+

Status set_make_entry(HashSetEntry **entry, char *value, size_t hash)
{
	*entry = malloc(sizeof(HashSetEntry));

	if (!(*entry))
		return DS_ERR_ALLOC;

	(*entry)->value = _strdup(value);
	(*entry)->hash = hash;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                            Insertion                                            |
// +-------------------------------------------------------------------------------------------------+

Status set_insert(HashSet *set, char *value)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	if (set_is_full(set))
		return DS_ERR_FULL;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] == NULL) {

		st = set_make_entry(&((set->buckets)[pos]), value, hash);

		if (st != DS_OK)
			return st;

		(set->size)++;
	}
	else {

		if (((set->buckets)[pos])->hash == hash)
			return DS_OK;

		bool found = false;

		size_t i, rehash = hash;
		for (i = 1; i <= 10; i++) {
			
			st = set->rehash_function(&rehash);

			if (st != DS_OK)
				return st;

			pos = (hash + i * rehash) % set->max_size;

			if ((set->buckets)[pos] == NULL) {

				st = set_make_entry(&((set->buckets)[pos]), value, hash);

				if (st != DS_OK)
					return st;

				(set->size)++;

				found = true;

				break;
			}
			else if (((set->buckets)[pos])->hash == hash)
				return DS_OK;

		}

		if (!found) {

			while (!found)
			{
				pos++;

				if ((set->buckets)[pos % set->max_size] == NULL) {

					st = set_make_entry(&((set->buckets)[pos % set->max_size]), value, hash);

					if (st != DS_OK)
						return st;

					(set->size)++;

					found = true;
				}
				else if (((set->buckets)[pos % set->max_size])->hash == hash)
					return DS_OK;

			}
		}

	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Removal                                             |
// +-------------------------------------------------------------------------------------------------+

Status set_remove(HashSet *set, char *value)
{
	if (set_is_empty(set))
		return DS_ERR_INVALID_OPERATION;

	if (!set_exists(set, value))
		return DS_ERR_NOT_FOUND;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] != NULL) {

		if (((set->buckets)[pos])->hash == hash) {

			free((set->buckets)[pos]);
			(set->buckets)[pos] = NULL;

			(set->size)--;
		}
		else {

			bool found = false;

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++) {

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->buckets)[pos] != NULL) {

					if (((set->buckets)[pos])->hash == hash) {

						free((set->buckets)[pos]);
						(set->buckets)[pos] = NULL;

						(set->size)--;
					}
				}
			}

			if (!found) {

				for (i = 0; i < set->max_size; i++, pos++) {

					if ((set->buckets)[pos % set->max_size] != NULL) {

						if (((set->buckets)[pos % set->max_size])->hash == hash) {

							free((set->buckets)[pos]);
							(set->buckets)[pos] = NULL;

							(set->size)--;
						}
					}
				}

			}
		}
	}
	else
		return DS_ERR_NOT_FOUND;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Display                                             |
// +-------------------------------------------------------------------------------------------------+

Status set_display_entry(HashSetEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n| %21u | %52s |", entry->hash, entry->value);

	return DS_OK;
}

Status set_display_entry_raw(HashSetEntry *entry)
{
	if (entry == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n %21u %52s ", entry->hash, entry->value);

	return DS_OK;
}

Status set_display_table(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n+------------------------------------------------------------------------------+");
	printf("\n|                                 Hash Set                                     |");
	printf("\n+-----------------------+------------------------------------------------------+");
	printf("\n|         HASH          |                         VALUE                        |");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		printf("\n+-----------------------+------------------------------------------------------+");

		if ((set->buckets)[i] == NULL)
			printf("\n|         NULL          |                           NULL                       |");
		else {

			st = set_display_entry((set->buckets)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n+-----------------------+------------------------------------------------------+");

	printf("\n");

	return DS_OK;
}

Status set_display_table_raw(HashSet *set)
{
	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	printf("\n");

	Status st;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] == NULL)
			printf("\n");
		else {

			st = set_display_entry_raw((set->buckets)[i]);

			if (st != DS_OK)
				return st;
		}
	}

	printf("\n");

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Resets                                              |
// +-------------------------------------------------------------------------------------------------+

Status set_delete_table(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < (*set)->max_size; i++) {

		if (((*set)->buckets)[i] != NULL)
			free((((*set)->buckets)[i])->value);

		free(((*set)->buckets)[i]);
	}

	free((*set)->buckets);
	free(*set);

	*set = NULL;

	return DS_OK;
}

Status set_erase_table(HashSet **set)
{
	if ((*set) == NULL)
		return DS_ERR_NULL_POINTER;

	size_t size = (*set)->max_size;
	Status(*hash_function) (char *, size_t *) = (*set)->hash_function;
	Status(*rehash_function) (size_t*) = (*set)->rehash_function;

	Status st = set_delete_table(set);

	if (st != DS_OK)
		return st;

	st = set_init_table(set, size, hash_function, rehash_function);

	if (st != DS_OK)
		return st;

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Search                                              |
// +-------------------------------------------------------------------------------------------------+

bool set_is_full(HashSet *set)
{
	return (set->max_size == set->size);
}

bool set_is_empty(HashSet *set)
{
	return (set->size == 0);
}

Status set_contains(HashSet *set, char *value, bool *result)
{
	*result = false;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	if (set_is_empty(set))
		return DS_OK;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] != NULL) {

		if (((set->buckets)[pos])->hash == hash)
			*result = true;
		else {

			bool found = false;

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++) {

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->buckets)[pos] != NULL) {

					if (((set->buckets)[pos])->hash == hash) {

						*result = true;

						found = true;

						break;
					}
				}
			}

			if (!found) {

				for (i = 0; i < set->max_size; i++, pos++) {

					if ((set->buckets)[pos % set->max_size] != NULL) {

						if (((set->buckets)[pos % set->max_size])->hash == hash) {

							*result = true;

							found = true;

							break;
						}
					}
				}

			}
		}
	}
	else
		*result = false;

	return DS_OK;
}

bool set_exists(HashSet *set, char *value)
{
	if (set == NULL)
		return false;

	if (set_is_empty(set))
		return false;

	size_t hash;

	Status st = set->hash_function(value, &hash);

	if (st != DS_OK)
		return st;

	size_t pos = hash % set->max_size;

	if ((set->buckets)[pos] != NULL) {

		if (((set->buckets)[pos])->hash == hash)
			return true;
		else {

			size_t i, rehash = hash;

			for (i = 0; i < 10; i++) {

				st = set->rehash_function(&rehash);

				if (st != DS_OK)
					return st;

				pos = (hash + i * rehash) % set->max_size;

				if ((set->buckets)[pos] != NULL) {

					if (((set->buckets)[pos])->hash == hash) {

						return true;
					}
				}
			}

			for (i = 0; i < set->max_size; i++, pos++) {

				if ((set->buckets)[pos % set->max_size] != NULL) {

					if (((set->buckets)[pos % set->max_size])->hash == hash) {

						return true;
					}
				}
			}

			
		}
	}
	else
		return false;

	return false;
}

Status set_count_elements(HashSet *set, size_t *result)
{
	*result = 0;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] != NULL)
			(*result)++;
	}

	return DS_OK;
}

Status set_count_empty(HashSet *set, size_t *result)
{
	*result = 0;

	if (set == NULL)
		return DS_ERR_NULL_POINTER;

	size_t i;
	for (i = 0; i < set->max_size; i++) {

		if ((set->buckets)[i] == NULL)
			(*result)++;
	}

	return DS_OK;
}

// +-------------------------------------------------------------------------------------------------+
// |                                             Set                                                 |
// +-------------------------------------------------------------------------------------------------+

//Status set_union(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_intersection(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_difference(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_complement(HashSet *set1, HashSet *set2, HashSet **result)
//Status set_sym_diff(HashSet *set1, HashSet *set2, HashSet **result)

// +-------------------------------------------------------------------------------------------------+
// |                                             Hash                                                |
// +-------------------------------------------------------------------------------------------------+

Status set_hash_string_djb2(char *key, size_t *hash)
{
	*hash = 5381;

	int c;

	while ((c = *key++) != 0)
		(*hash) = (((*hash) << 5) + (*hash)) + c;

	return DS_OK;
}

Status set_hash_string_sdbm(char *key, size_t *hash)
{
	*hash = 0;

	int c;

	while ((c = *key++) != 0)
		(*hash) = c + (((*hash) << 6) + ((*hash) << 16)) - (*hash);

	return DS_OK;
}

Status set_hash_string_fnv(char *key, size_t *hash)
{
	*hash = 2166136261;

	int c;

	while ((c = *key++) != 0)
		*hash = ((*hash) * 16777619) ^ key[c];

	return DS_OK;
}

Status set_rehash_rj(size_t *hash)
{
	*hash = ((*hash) + 0x7ed55d16) + ((*hash) << 12);
	*hash = ((*hash) ^ 0xc761c23c) ^ ((*hash) >> 19);
	*hash = ((*hash) + 0x165667b1) + ((*hash) << 5);
	*hash = ((*hash) + 0xd3a2646c) ^ ((*hash) << 9);
	*hash = ((*hash) + 0xfd7046c5) + ((*hash) << 3);
	*hash = ((*hash) ^ 0xb55a4f09) ^ ((*hash) >> 16);

	return DS_OK;
}

Status set_rehash_prime(size_t *hash)
{
	size_t prime = 7;

	*hash = prime - ((*hash) % prime);

	return DS_OK;
}

int main(void)
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |              C Hash Set             |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");

	HashSet *set;
	Status st;

	size_t size = 600;

	set_init_table(&set, size, set_hash_string_djb2, set_rehash_rj);

	size_t i, j, len;
	const char charset[] = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const size_t c_len = strlen(charset);
	const size_t str_len = 31;

	char *str = malloc(sizeof(char) * str_len);

	while (!set_is_full(set))
	{
		len = rand() % (str_len + 1 - 5) + 5;

		for (j = 0; j < len - 1; j++) {
			str[j] = charset[rand() % c_len];
		}

		str[j + 1] = '\0';

		st = set_insert(set, str);
	}

	set_display_table(set);

	printf("\nSet size: %u", set->size);

	set_delete_table(&set);

	set_init_table(&set, 30, set_hash_string_sdbm, set_rehash_prime);

	printf("\nSet size: %u", set->size);

	set_insert(set, "Hello World!");
	set_insert(set, "Hello World");
	set_insert(set, "Fire and Blood");
	set_insert(set, "Hear me Roar");
	set_insert(set, "Ours is the Fury");
	set_insert(set, "Winter is Coming");
	set_insert(set, "As High as Honor");
	set_insert(set, "We do not Sow");
	set_insert(set, "Unbowed, Unbent, Unbroken");
	set_insert(set, "Growing Strong");
	set_insert(set, "Lorem Ipsum");
	set_insert(set, "Ada Lovelace");
	set_insert(set, "Thomas Edson");
	set_insert(set, "Alan Turing");
	set_insert(set, "Bernhard Riemann");
	set_insert(set, "Leonhard Euler");
	set_insert(set, "Carl Friedrich Gauss");
	set_insert(set, "Isaac Newton");
	set_insert(set, "Winter is Coming"); // Not allowed
	set_insert(set, "Isaac Newton");     // Not allowed

	set_display_table(set);

	printf("\nSet size: %u", set->size);

	size_t r, s;
	set_count_empty(set, &r);
	set_count_elements(set, &s);

	printf("\nThere are %u entries and %u empty spaces", s, r);

	bool res;
	if (set_contains(set, "Isaac Newton", &res) == DS_OK)
		printf("\nThe set %s Isaac Newton", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Insertion Sort", &res) == DS_OK)
		printf("\nThe set %s Insertion Sort", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Fire and Blood", &res) == DS_OK)
		printf("\nThe set %s Fire and Blood", (res) ? "contains" : "does not contains");

	if (set_contains(set, "Barack Obama", &res) == DS_OK)
		printf("\nThe set %s Barack Obama", (res) ? "contains" : "does not contains");

	char *words[8] = { "Hello World!", "Lorem Ipsum", "The Ring", "Thomas Muller",
		"Winter is Coming", "Turing Machine", "Hear me Roar", "Ramanujan"};

	for (i = 0; i < 8; i++) {

		if (set_exists(set, words[i]))
			printf("\nThe element [ %s ] exists", words[i]);
		else
			printf("\nThe element [ %s ] does not exists", words[i]);
	}

	st = set_remove(set, "Winter is Coming");
	print_status_repr(st);
	st = set_remove(set, "Lorem Ipsum");
	print_status_repr(st);
	st = set_remove(set, "As High as Honor");
	print_status_repr(st);
	st = set_remove(set, "Bernhard Riemann");
	print_status_repr(st);
	st = set_remove(set, "Unbowed, Unbent, Unbroken");
	print_status_repr(st);
	printf("\nShouldn't find:");
	st = set_remove(set, "Unbowed, Unbent, Unbroken");
	print_status_repr(st);

	set_display_table(set);

	printf("\nSet size: %u", set->size);

	set_count_empty(set, &r);
	set_count_elements(set, &s);

	printf("\nThere are %u entries and %u empty spaces", s, r);

	set_delete_table(&set);

	printf("\n");
	return 0;
}