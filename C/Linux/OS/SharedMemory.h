/**
 * @file SharedMemory.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 25/10/2018
 *
 * @brief Facilities to manage shared memory
 */

#ifndef OS_SHAREDMEMORY_H
#define OS_SHAREDMEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int shm_create(key_t key, size_t size);

int shm_delete(key_t key, int shmid);

int shm_getid(key_t key);

#endif //OS_SHAREDMEMORY_H
