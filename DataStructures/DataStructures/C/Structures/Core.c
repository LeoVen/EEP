/**
 * Core.c
 *
 * Author: Leonardo Vencovsky
 * Created on 04/03/2018
 *
 * Core implementations that contains Status codes, functions related to
 * status codes and other commonly used by all structures.
 *
 */

#include "..\Headers\Core.h"

char * status_repr(Status status)
{
	switch (status)
	{
		case DS_OK: return "DS_OK";
		case DS_ERR_INVALID_POSITION: return "DS_ERR_INVALID_POSITION";
		case DS_ERR_INVALID_OPERATION: return "DS_ERR_INVALID_OPERATION";
		case DS_ERR_INVALID_SIZE: return "DS_ERR_INVALID_SIZE";
		case DS_ERR_NOT_FOUND: return "DS_ERR_NOT_FOUND";
		case DS_ERR_ALLOC: return "DS_ERR_ALLOC";
		case DS_ERR_OPERATION_FAILED: return "DS_ERR_OPERATION_FAILED";
		case DS_ERR_UNEXPECTED_RESULT: return "DS_ERR_UNEXPECTED_RESULT";
		case DS_ERR_ITER: return "DS_ERR_ITER";
		case DS_ERR_NULL_POINTER: return "DS_ERR_NULL_POINTER";
	}
}