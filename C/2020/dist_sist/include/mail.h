/**
 * Mailing threads for client and server.
 */

#ifndef MAIL_H
#define MAIL_H

#include <unistd.h>

#include "collections.h"
#include "messages.h"
#include "netapi.h"

bool net_mail_send(int server_fd, char *destination_id, char *message);
bool net_mail_recv(int server_fd, char *client_id, struct msglist **result);

#endif /* MAIL_H */
