/**
 * Common data structures.
 */

#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "macro_collections.h"

/* Database */
#define CMC_DICTIONARY (dict, dictionary, , char *, char *)
CMC_CMC_HASHMAP_CORE(PUBLIC, HEADER, CMC_DICTIONARY)

extern struct dictionary_fkey dict_methods_key;
extern struct dictionary_fval dict_methods_val;

/* Maps a client ID to its file descriptor */
#define CMC_CLIENTS_IDS (cl, climap, , char *, int)
CMC_CMC_HASHBIDIMAP_CORE(PUBLIC, HEADER, CMC_CLIENTS_IDS)

extern struct climap_fkey climap_methods_key;
extern struct climap_fval climap_methods_val;

/* Queue that stores Mails */
struct mail_queue_item
{
    // The destination's ID
    char *client_id;
    // Message content
    char *message;
};

#define CMC_MAIL_QUEUE (mq, mailq, , , struct mail_queue_item)
CMC_CMC_QUEUE_CORE(PUBLIC, HEADER, CMC_MAIL_QUEUE)

extern struct mailq_fval mailq_methods_val;

#endif /* COLLECTIONS_H */
