#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macro_list.h"

MLIST_GENERATE_HEADER(il, int_list, , int)
MLIST_GENERATE_HEADER(sl, size_list, , size_t)
MLIST_GENERATE_HEADER(dl, double_list, , double)
MLIST_GENERATE_HEADER(cl, char_list, , char)