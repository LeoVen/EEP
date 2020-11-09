/**
 * Mailing threads for client and server.
 */

#ifndef MAIL_H
#define MAIL_H

#include <unistd.h>

#include "collections.h"
#include "messages.h"
#include "netapi.h"

/* Connections */
bool mail_server(struct climap *clients, struct cmc_mutex *cl_mutex,
                 struct mailq *mails, struct cmc_mutex *mq_mutex);
bool mail_client(char *client_id);

void mail_server_shutdown(void);
bool mail_server_alive(void);

#endif /* MAIL_H */
