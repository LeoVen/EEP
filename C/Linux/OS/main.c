#include "SharedMemory.h"

int main()
{
    // IPC Key
    key_t key = ftok("/tmp", 'a');

    // Generating key not successful
    if (key == -1)
        return -1;

    // size of shared memory in bytes
    size_t size = 8;

    size_t *content = NULL;

    // Search for shared memory
    int shmid = shm_getid(key);

    // If shared memory was deleted, create a new one
    if (shmid == -1)
    {
        shmid = shm_create(key, size);

        if (shmid == -1)
            return -1;

        content = shmat(shmid, 0, 0);

        // Initialize content to 0
        *content = 0;
    }

    content = shmat(shmid, 0, 0);

    if (*content > 5)
    {
        printf("Content: %lu\n", *content);
        shm_delete(key, shmid);
    }
    else
    {
        (*content)++;
        printf("Content: %lu\n", *content);
    }

    return 0;
}