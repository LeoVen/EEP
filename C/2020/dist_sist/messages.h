/**
 * Create / Read Control Messages
 *
 * Every message is a string of the form:
 *      MESSAGE_CONTROL <message_key>MSG_SEPARATOR<optional_message_value>
 */

#ifndef MESSAGES_H
#define MESSAGES_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SEPARATOR ':'
#define MSG_MAX_CTRL_SIZE 20 // Max size + a few extra bytes
#define MSG_CREATE_FORMAT "%s %s%c%s"

/**
 * MSG_CTRL_SHUTDOWN : Shuts down the server
 *      <key: reason for shutdown>MSG_SEPARATOR<value: ignored>
 * MSG_CTRL_PING : Asks to receive a response from the server
 *      <key: ignored>MSG_SEPARATOR<value: ignored>
 * MSG_CTRL_CREATE : Creates a key mapping to a value
 *      <key>MSG_SEPARATOR<value>
 * MSG_CTRL_READ : Gets the value mapped to the provided key
 *      <key>MSG_SEPARATOR<value: ignored>
 * MSG_CTRL_UPDATE : Updates an existing key to map to another value
 *      <key>MSG_SEPARATOR<value: possibly new value>
 * MSG_CTRL_DELETE : Deletes an existing key
 *      <key>MSG_SEPARATOR<value: ignored>
 * MSG_CTRL_SAVE : Creates a file saving the database's state
 *      <key: file name>MSG_SEPARATOR<value: ignored>
 * MSG_CTRL_INVALID: An invalid control message
 */
enum message_control
{
    MSG_CTRL_SHUTDOWN = 0,
    MSG_CTRL_PING = 1,
    MSG_CTRL_CREATE = 2,
    MSG_CTRL_READ = 3,
    MSG_CTRL_UPDATE = 4,
    MSG_CTRL_DELETE = 5,
    MSG_CTRL_SAVE = 6,
    MSG_CTRL_INVALID = -1
};

extern const size_t msg_map_len;

// CREATING

/**
 * Creates a new control message.
 */
char *msg_create(enum message_control ctrl, char *key, size_t key_size, char *val, size_t val_size);

/**
 * Creates a new control message from strings only.
 */
char *msg_create_str(char *ctrl_str, char *key, size_t key_size, char *val, size_t val_size);

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
 * Parses an entire message. If anything fails, ctrl is set to MSG_CTRL_INVALID and false is returned.
 */
bool msg_parse(char *message, size_t msg_size,
               enum message_control *ctrl,
               char **key, size_t *key_size,
               char **val, size_t *val_size);

#endif /* MESSAGES_H */
