/**
 * @file SharedMemory.c
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/10/2018
 *
 * @brief Facilities to manage shared memory
 */

#include "SharedMemory.h"

int shm_create(key_t key, size_t size)
{
    // Creates a shared memory
    int shmid = shmget(key, size, 0600 | IPC_CREAT);

    // Failed to create a shared memory block
    if (shmid == -1)
    {
        printf("Failed to create shared memory.\n");
        return -1;
    }

    printf("Shared memory created. ID: %d\n", shmid);

    return shmid;
}

int shm_delete(key_t key, int shmid)
{
    int shm_ctl = shmctl(shmid, IPC_RMID, 0);

    if (shm_ctl != 0)
    {
        printf("Failed to delete shared memory.\n");
        return -1;
    }

    printf("Shared memory deleted. ID: %d\n", shmid);

    return 0;
}

int shm_getid(key_t key)
{
    int shmid = shmget(key, 0, 0);

    if (shmid == -1)
    {
        printf("Failed to locate shared memory ID.\n");

        return -1;
    }

    printf("Located shared memory. ID: %d\n", shmid);

    return shmid;
}
