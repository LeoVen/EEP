#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macro_list.h"

CONTAINER_GENERATE_HEADER(LIST, il, int_list, , int)
CONTAINER_GENERATE_HEADER(STACK, cs, char_stack, , char)