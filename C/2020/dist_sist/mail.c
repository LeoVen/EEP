#include "mail.h"

int mail_server_thread(void *arguments);
int mail_client_thread(void *arguments);

bool keep_alive = true;

struct mail_thread_arg
{
    struct climap *clients;
    struct cmc_mutex *cl_mutex;
    struct mailq *mails;
    struct cmc_mutex *mq_mutex;
    char *client_id;
};

bool mail_server(struct climap *clients, struct cmc_mutex *cl_mutex,
                 struct mailq *mails, struct cmc_mutex *mq_mutex)
{

    struct cmc_thread thread = { 0 };
    struct mail_thread_arg *arg = calloc(1, sizeof(struct mail_thread_arg));
    arg->clients = clients;
    arg->cl_mutex = cl_mutex;
    arg->mails = mails;
    arg->mq_mutex = mq_mutex;
    arg->client_id = NULL;

    if (!cmc_thrd_create(&thread, mail_server_thread, arg))
    {
        cmc_log_error("Failed to spawn mail server thread.");
        perror("");
        return false;
    }

    return true;
}

bool mail_client(char *client_id)
{
    // TODO


    return true;
}

void mail_server_shutdown(void)
{
    keep_alive = false;
}

bool mail_server_alive(void)
{
    return keep_alive;
}

int mail_server_thread(void *arguments)
{
    cmc_log_info("[Mail] Starting mail server thread.");

    struct mail_thread_arg *arg = (struct mail_thread_arg *)arguments;
    struct climap *clients = arg->clients;
    struct cmc_mutex *cl_mutex = arg->cl_mutex;
    struct mailq *mails = arg->mails;
    struct cmc_mutex *mq_mutex = arg->mq_mutex;

    free(arg);

    while (keep_alive)
    {
        if (!keep_alive)
            break;

        sleep(NETAPI_MAIL_POLLING_INTERVAL);

        if (mq_empty(mails))
        {
            cmc_log_trace("[Mail] No mails to send.");
            continue;
        }

        /* Go through all the mails that are still pending */
        cmc_mtx_lock(mq_mutex);
        cmc_mtx_lock(cl_mutex);
        size_t qlen = mq_count(mails);

        /* Go through each mail once */
        for (size_t i = 0; i < qlen; i++)
        {
            struct mail_queue_item item = mq_peek(mails);
            mq_dequeue(mails);
            int dest_fd = cl_get_val(clients, item.client_id);

            /* Client is not connected */
            if (dest_fd == 0)
            {
                /* Persist mail back */
                mq_enqueue(mails, item);
                continue;
            }

            /* ISSUE: This fd is the client's main one that communicates with the server! Not its mail one */
            if (!net_send(dest_fd, item.message, strlen(item.message)))
            {
                cmc_log_warn("[Mail] Failed to send mail to connected client.");
                mq_enqueue(mails, item);
                continue;
            }

            free(item.client_id);
            free(item.message);
        }

        cmc_mtx_unlock(mq_mutex);
        cmc_mtx_unlock(cl_mutex);
    }

    cmc_log_info("[Mail] Shutting down mail server thread");

    keep_alive = false;

    return 0;
}

int mail_client_thread(void *arguments)
{
    cmc_log_info("[Mail] Starting mail client thread.");

    while (keep_alive)
    {
        
    }

    cmc_log_info("[Mail] Shutting down mail client thread");

    keep_alive = false;

    return 0;
}
