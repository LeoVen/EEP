#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macro_list.h"

CONTAINER_GENERATE_HEADER(LIST, PUBLIC, il, int_list, , int)
CONTAINER_GENERATE_HEADER(STACK, PRIVATE, cs, char_stack, , char)