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
		STATUS_OK                       = 0,
		STATUS_ERR_INVALID_POSITION     = 1,
		STATUS_ERR_INVALID_OPERATION    = 2,
		STATUS_ERR_NOT_FOUND            = 3
	} Status;

#ifdef __cplusplus
}
#endif