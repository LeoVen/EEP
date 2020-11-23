#include "database.h"

bool database_load(struct dictionary *database, char *file_name)
{
    char line[NETAPI_RECV_BUFFER_SIZE];

    FILE *f = fopen(file_name, "r");

    if (f)
    {
        while (true)
        {
            if (!fgets(line, sizeof(line), f))
                break;

            size_t len = strlen(line);
            if (len > 0)
                line[--len] = '\0'; // Remove \n

            struct msg_message *msg = &(struct msg_message) { 0 };

            if (msg_parse(line, len, msg))
            {
                dict_insert(database, msg->key, msg->val);
            }
        }

        fclose(f);
        return true;
    }

    return false;
}

bool database_save(struct dictionary *database, char *file_name)
{
    FILE *f = fopen(file_name, "w");

    if (f)
    {
        CMC_FOREACH(dict, dictionary, iter, database)
        {
            char *key = dict_iter_key(&iter);
            char *val = dict_iter_value(&iter);

            if (key && val)
            {
                fprintf(f, "CREATE %s:%s\n", key, val);
            }
        }

        fclose(f);
        return true;
    }

    return false;
}

