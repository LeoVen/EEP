#include "messages.h"

#include "utl_test.h"

bool msg_create_and_test(enum message_control ctrl, char *key, size_t key_size, char *val, size_t val_size)
{
    char *message = msg_create(ctrl, key, key_size, val, val_size);

    if (!message)
        return false;

    struct msg_message msg;

    bool result = msg_parse(message, strlen(message), &msg);

    free(message);

    cmc_assert(result);
    cmc_assert_equals(int32_t, ctrl, msg.ctrl);
    cmc_assert(strcmp(key, msg.key) == 0);
    cmc_assert(strcmp(val, msg.val) == 0);
    cmc_assert_equals(size_t, strlen(msg.key), msg.key_len);
    cmc_assert_equals(size_t, strlen(msg.val), msg.val_len);
    cmc_assert_equals(size_t, key_size, msg.key_len);
    cmc_assert_equals(size_t, val_size, msg.val_len);

    result = result && msg.ctrl == ctrl &&
            strcmp(key, msg.key) == 0 &&
            strcmp(val, msg.val) == 0 &&
            strlen(msg.key) == msg.key_len &&
            strlen(msg.val) == msg.val_len &&
            key_size == msg.key_len &&
            val_size == msg.val_len;

    msg_message_destroy(&msg);

    return result;
}

CMC_CREATE_UNIT(ControlMessagesTest, true, {
    CMC_CREATE_TEST(msg_create, {
        char *key = "LOREM IPSUM";
        char *val = "A popular text generator";
        char *msg = msg_create(MSG_CTRL_CREATE, key, strlen(key), val, strlen(val));

        cmc_assert(msg != NULL);

        free(msg);

        msg = msg_create(MSG_CTRL_INVALID, key, strlen(key), val, strlen(val));

        cmc_assert(msg == NULL);
    });

    CMC_CREATE_TEST(msg_ctrl_to_string, {
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_SHUTDOWN), "SHUTDOWN") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_WAIT), "WAIT") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_CREATE), "CREATE") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_READ), "READ") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_UPDATE), "UPDATE") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_DELETE), "DELETE") == 0);
        cmc_assert(strcmp(msg_ctrl_to_string(MSG_CTRL_BACKUP), "BACKUP") == 0);
        cmc_assert(msg_ctrl_to_string(MSG_CTRL_INVALID) == NULL);
    });

    CMC_CREATE_TEST(msg_get_control, {
        char *key = "LOREM IPSUM";
        char *val = "A popular text generator";
        char *msg = msg_create(MSG_CTRL_CREATE, key, strlen(key), val, strlen(val));

        cmc_assert(msg != NULL);

        enum message_control ctrl = msg_get_control(msg, strlen(msg));

        cmc_assert_equals(int32_t, MSG_CTRL_CREATE, ctrl);
        cmc_assert_equals(int32_t, MSG_CTRL_INVALID, msg_get_control(msg, 0));
        cmc_assert_equals(int32_t, MSG_CTRL_INVALID, msg_get_control(NULL, strlen(msg)));

        free(msg);

        for (size_t i = 0; i < msg_map_len; i++)
        {
            char *msg = msg_create((enum message_control)i, key, strlen(key), val, strlen(val));
            cmc_assert_not_equals(ptr, NULL, msg);
            cmc_assert_equals(int32_t, i, msg_get_control(msg, strlen(msg)));
            free(msg);
        }
    });

    CMC_CREATE_TEST(msg_get_key, {
        char *key = "LOREM IPSUM";
        char *val = "A popular text generator";
        char *msg = msg_create(MSG_CTRL_CREATE, key, strlen(key), val, strlen(val));
        cmc_assert(msg != NULL);

        char *msg_key = msg_get_key(msg, strlen(msg));
        cmc_assert(msg_key != NULL);
        cmc_assert(strcmp(msg_key, key) == 0);

        free(msg_key);
        free(msg);

        msg = msg_create(MSG_CTRL_WAIT, key, strlen(key), "", strlen(""));
        cmc_assert(msg != NULL);

        msg_key = msg_get_key(msg, strlen(msg));
        cmc_assert(msg_key != NULL);
        cmc_assert(strcmp(msg_key, key) == 0);

        free(msg);
        free(msg_key);

        msg = msg_create(MSG_CTRL_WAIT, "", strlen(""), "", strlen(""));
        cmc_assert(msg != NULL);

        msg_key = msg_get_key(msg, strlen(msg));
        cmc_assert(msg_key == NULL);

        free(msg);
    });

    CMC_CREATE_TEST(msg_get_val, {
        char *key = "LOREM IPSUM";
        char *val = "A popular text generator";
        char *msg = msg_create(MSG_CTRL_CREATE, key, strlen(key), val, strlen(val));
        cmc_assert(msg != NULL);

        char *msg_val = msg_get_val(msg, strlen(msg));
        cmc_assert(msg_val != NULL);
        cmc_assert(strcmp(msg_val, val) == 0);

        free(msg_val);
        free(msg);

        msg = msg_create(MSG_CTRL_WAIT, key, strlen(key), "", strlen(""));
        cmc_assert(msg != NULL);

        msg_val = msg_get_val(msg, strlen(msg));
        cmc_assert(msg_val != NULL);

        free(msg);
        free(msg_val);

        msg = msg_create(MSG_CTRL_WAIT, "", strlen(""), "", strlen(""));
        cmc_assert(msg != NULL);

        msg_val = msg_get_val(msg, strlen(msg));
        cmc_assert(msg_val == NULL);

        free(msg);
    });

    CMC_CREATE_TEST(msg_parse, {
        char *my_key = "My Keys";
        char *my_val = "My Values";
        char *my_empty_val = "";

        // Non-empty value
        cmc_assert(msg_create_and_test(MSG_CTRL_SHUTDOWN, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_WAIT, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_CREATE, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_READ, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_UPDATE, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_DELETE, my_key, strlen(my_key), my_val, strlen(my_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_BACKUP, my_key, strlen(my_key), my_val, strlen(my_val)));

        // Empty value
        cmc_assert(msg_create_and_test(MSG_CTRL_SHUTDOWN, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_WAIT, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_CREATE, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_READ, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_UPDATE, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_DELETE, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
        cmc_assert(msg_create_and_test(MSG_CTRL_BACKUP, my_key, strlen(my_key), my_empty_val, strlen(my_empty_val)));
    });
});

int main(void)
{
    return (int)ControlMessagesTest();
}
