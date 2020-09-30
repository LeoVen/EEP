/**
 * Create / Read Control Messages
 *
 * Every message is a string of the form:
 *      MESSAGE_CONTROL Key key key, key MSG_SEPARATOR value value value
 */

#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SEPARATOR ':'

enum message_control
{
    MSG_CTRL_PING = 0,
    MSG_CTRL_CREATE = 1,
    MSG_CTRL_READ = 2,
    MSG_CTRL_UPDATE = 3,
    MSG_CTRL_DELETE = 4,
    MSG_CTRL_SAVE = 5,
    MSG_CTRL_INVALID = -1
};

extern const size_t msg_map_len;

// CREATING

/**
 * Creates a new control message.
 */
char *msg_create(enum message_control ctrl, char *key, size_t key_size, char *val, size_t val_size);

// PARSING

/**
 * Maps enum message_control to its character representation. Returns NULL if it is not a valid enum message_control.
 */
const char *msg_ctrl_to_string(enum message_control ctrl);

/**
 * Tries to parse the message control part of the message. Returns MSG_CTRL_INVALID if is not a valid identifier.
 */
enum message_control msg_get_control(char *message, size_t msg_size);

/**
 * Tries to parse the key part of the message. Returns NULL on error.
 */
char *msg_get_key(char *message, size_t msg_size);

/**
 * Tries to parse the value part of the message. Returns NULL on error.
 */
char *msg_get_val(char *message, size_t msg_size);

/**
 * Parses an entire message. If anything fails, all out parameters are set to NULL and false is returned.
 */
bool msg_parse(char *message, enum message_control *ctrl, char **key, size_t *key_size, char **val, size_t *val_size);

#endif /* MESSAGES_H */
