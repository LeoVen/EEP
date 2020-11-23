/**
 * Common data structures.
 */

#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "macro_collections.h"

/* Database */
#define CMC_DICTIONARY (dict, dictionary, , char *, char *)
CMC_CMC_HASHMAP_CORE(PUBLIC, HEADER, CMC_DICTIONARY)
CMC_EXT_CMC_HASHMAP_ITER(PUBLIC, HEADER, CMC_DICTIONARY)

extern struct dictionary_fkey dict_methods_key;
extern struct dictionary_fval dict_methods_val;

/* Maps a client ID to its file descriptor */
#define CMC_CLIENTS_IDS (cl, climap, , char *, int)
CMC_CMC_HASHBIDIMAP_CORE(PUBLIC, HEADER, CMC_CLIENTS_IDS)

extern struct climap_fkey climap_methods_key;
extern struct climap_fval climap_methods_val;

/* A list of messages */
#define CMC_MSG_LIST (ml, msglist, , , char *)
CMC_CMC_LIST_CORE(PUBLIC, HEADER, CMC_MSG_LIST)

extern struct msglist_fval msglist_methods_val;

/* Maps a client ID to a list of messages */
#define CMC_MAIL_QUEUE (mq, mailq, , char *, struct msglist *)
CMC_CMC_HASHMAP_CORE(PUBLIC, HEADER, CMC_MAIL_QUEUE)

extern struct mailq_fkey mailq_methods_key;
extern struct mailq_fval mailq_methods_val;

#endif /* COLLECTIONS_H */
