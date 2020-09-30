#include "messages.h"

static const char *msg_map[] = {
    "SHUTDOWN",
    "PING",
    "CREATE",
    "READ",
    "UPDATE",
    "DELETE",
    "SAVE",
};

const size_t msg_map_len = 7;

char *msg_create(enum message_control ctrl, char *key, size_t key_size, char *val, size_t val_size)
{
    const char *ctrl_str = msg_ctrl_to_string(ctrl);

    if (ctrl_str == NULL)
        return NULL;

    size_t size = strlen(ctrl_str) + key_size + val_size + 5;

    char *result = calloc(1, size);

    if (!result)
        return NULL;

    if (snprintf(result, size, "%s %s%c%s", ctrl_str, key, MSG_SEPARATOR, val) < 0)
    {
        free(result);
        return NULL;
    }

    return result;
}

const char *msg_ctrl_to_string(enum message_control ctrl)
{
    if (ctrl < 0 || ctrl > msg_map_len)
        return NULL;

    return msg_map[(int)ctrl];
}

enum message_control msg_get_control(char *message, size_t msg_size)
{
    if (message == NULL || msg_size == 0)
        return MSG_CTRL_INVALID;

    char ctrl[20] = { 0 };

    size_t i = 0;

    while (i < msg_size && message[i] != ' ' && i < 19)
    {
        ctrl[i] = message[i];
        i++;
    }

    for (size_t idx = 0; idx < msg_map_len; idx++)
    {
        if (strcmp(ctrl, msg_map[idx]) == 0)
            return (enum message_control)idx;
    }

    return MSG_CTRL_INVALID;
}

char *msg_get_key(char *message, size_t msg_size)
{
    size_t ctrl_idx = 0;

    while (ctrl_idx < msg_size && message[ctrl_idx] != ' ')
    {
        ctrl_idx++;
    }

    if (ctrl_idx == msg_size)
        return NULL;

    size_t start = ctrl_idx + 1;
    size_t end = start;

    while (end < msg_size && message[end] != MSG_SEPARATOR)
    {
        end++;
    }

    if (end == msg_size || end == start)
        return NULL;

    size_t res_size = (end - start) + 2;
    char *result = calloc(1, res_size);

    if (!result)
        return NULL;

    for (size_t i = start, j = 0; i < end && j < res_size; i++, j++)
        result[j] = message[i];

    return result;
}

char *msg_get_val(char *message, size_t msg_size)
{
    size_t ctrl_idx = 0;

    while (ctrl_idx < msg_size && message[ctrl_idx] != ' ')
    {
        ctrl_idx++;
    }

    if (ctrl_idx == msg_size) // Invalid message
        return NULL;

    size_t key_idx = ctrl_idx + 1;

    while (key_idx < msg_size && message[key_idx] != MSG_SEPARATOR)
    {
        key_idx++;
    }

    if (key_idx == msg_size || key_idx == ctrl_idx + 1) // Key is empty
        return NULL;

    size_t start = key_idx + 1;
    size_t end = msg_size;

    if (start == end || message[start] == '\0')
    {
        return calloc(1, 1); // An empty value
    }

    size_t res_size = (end - start) + 2;
    char *result = calloc(1, res_size);

    if (!result)
        return NULL;

    for (size_t i = start, j = 0; i < end && j < res_size; i++, j++)
    {
        if (message[i] == '\0')
            break;
        result[j] = message[i];
    }

    return result;
}

bool msg_parse(char *message, enum message_control *ctrl, char **key, size_t *key_size, char **val, size_t *val_size)
{
    return false;
}
