/*
* CStack.h
*
* Author: Leonardo Vencovsky
* Created on 31/03/2018
*
* Header for Common libs
*
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

	// TODO
	typedef enum Status {
		DS_OK                       = 0,
		DS_ERR_INVALID_POSITION     = 1,
		DS_ERR_INVALID_OPERATION    = 2,
		DS_ERR_INVALID_SIZE         = 3,
		DS_ERR_NOT_FOUND            = 4,
		DS_ERR_ALLOC                = 5,
		DS_ERR_OPERATION_FAILED     = 6,
		DS_ERR_UNEXPECTED_RESULT    = 7,
		DS_ERR_ITER                 = 8,
		DS_ERR_NULL_POINTER         = 9
	} Status;

#ifdef __cplusplus
}
#endif