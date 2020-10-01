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

    char ctrl[MSG_MAX_CTRL_SIZE] = { 0 };

    size_t i = 0;

    while (i < msg_size && message[i] != ' ' && i < 49)
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
    if (message == NULL || msg_size == 0)
        return NULL;

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
    if (message == NULL || msg_size == 0)
        return NULL;

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

bool msg_parse(char *message, size_t msg_size,
               enum message_control *ctrl,
               char **key, size_t *key_size,
               char **val, size_t *val_size)
{
    if (message == NULL || msg_size == 0)
        goto error;

    // Get indices

    size_t ctrl_start = 0;
    size_t ctrl_end = ctrl_start;

    while (ctrl_end < msg_size && message[ctrl_end] != ' ')
    {
        ctrl_end++;
    }

    if (ctrl_end == msg_size || ctrl_end == ctrl_start) // Invalid message
        goto error;

    size_t key_start = ctrl_end + 1; // Skip white space
    size_t key_end = key_start;

    while (key_end < msg_size && message[key_end] != MSG_SEPARATOR)
    {
        key_end++;
    }

    if (key_end == msg_size || key_end == key_start) // Key is empty
        goto error;

    size_t val_start = key_end + 1;
    size_t val_end = msg_size;

    // Get actual values

    // Ctrl
    char ctrl_str[MSG_MAX_CTRL_SIZE] = { 0 };

    for (size_t i = ctrl_start, j = 0; i < ctrl_end && j < MSG_MAX_CTRL_SIZE; i++, j++)
        ctrl_str[j] = message[i];

    *ctrl = MSG_CTRL_INVALID;

    for (size_t i = 0; i < msg_map_len; i++)
    {
        if (strcmp(ctrl_str, msg_map[i]) == 0)
        {
            *ctrl = (enum message_control)i;
            break;
        }
    }

    if (*ctrl == MSG_CTRL_INVALID)
        return false;

    // Key

    *key_size = (key_end - key_start) + 2;
    *key = calloc(1, *key_size);

    for (size_t i = key_start, j = 0; i < key_end && j < *key_size; i++, j++)
        (*key)[j] = message[i];

    // Val
    *val_size = (val_end - val_start) + 2;
    *val = calloc(1, *val_size);

    for (size_t i = val_start, j = 0; i < val_end && j < *val_size; i++, j++)
    {
        if (message[i] == '\0')
            break;
        (*val)[j] = message[i];
    }

    return true;

    error:
    *ctrl = MSG_CTRL_INVALID;
    return false;
}
