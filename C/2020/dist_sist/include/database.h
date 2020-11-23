/**
 * Loading and Saving the Database
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <unistd.h>

#include "collections.h"
#include "messages.h"
#include "netapi.h"

#define DATABASE_DEFAULT_FILE_NAME "database.txt"

bool database_load(struct dictionary *database, char *file_name);
bool database_save(struct dictionary *database, char *file_name);

#endif /* DATABASE_H */
