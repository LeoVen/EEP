#include "collections.h"

/* Database */
CMC_CMC_HASHMAP_CORE(PUBLIC, SOURCE, CMC_DICTIONARY)
CMC_EXT_CMC_HASHMAP_ITER(PUBLIC, SOURCE, CMC_DICTIONARY)

void collect_str_free(char *data)
{
    free(data);
}

struct dictionary_fkey dict_methods_key = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    .free = collect_str_free
};

struct dictionary_fval dict_methods_val = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    .free = collect_str_free
};

/* Maps a client ID to its file descriptor */
CMC_CMC_HASHBIDIMAP_CORE(PUBLIC, SOURCE, CMC_CLIENTS_IDS)

struct climap_fkey climap_methods_key = {
    .str = cmc_str_str,
    .cmp = cmc_str_cmp,
    .hash = cmc_str_hash_sdbm,
    .free = collect_str_free
};

struct climap_fval climap_methods_val = {
    .str = cmc_i32_str,
    .cmp = cmc_i32_cmp,
    .hash = cmc_i32_hash
};

/* A list of messages */
CMC_CMC_LIST_CORE(PUBLIC, SOURCE, CMC_MSG_LIST)

struct msglist_fval msglist_methods_val = {
    .free = collect_str_free
};

/* Maps a client ID to a list of messages */
CMC_CMC_HASHMAP_CORE(PUBLIC, SOURCE, CMC_MAIL_QUEUE)

struct mailq_fkey mailq_methods_key = {
    .free = collect_str_free
};

struct mailq_fval mailq_methods_val = {
    .free = ml_free
};
