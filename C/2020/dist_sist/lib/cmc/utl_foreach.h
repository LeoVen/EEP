/**
 * Copyright (c) 2019 Leonardo Vencovsky
 *
 * This file is part of the C Macro Collections Libray.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * utl_foreach.h
 *
 * Creation Date: 25/02/2019
 *
 * Authors:
 * Leonardo Vencovsky (https://github.com/LeoVen)
 *
 */

/**
 * For-Each macros that work with all Collections within the library.
 *
 * PFX      - Functions prefix
 * SNAME    - Struct name
 * ITERNAME - Iterator variable name
 * TARGET   - Target variable
 */

#ifndef CMC_UTL_FOREACH_H
#define CMC_UTL_FOREACH_H

#include "cor_core.h"

#define CMC_FOREACH(PFX, SNAME, ITERNAME, TARGET) \
    for (struct CMC_DEF_ITER(SNAME) ITERNAME = CMC_(PFX, _iter_start)(TARGET); !CMC_(PFX, _iter_at_end)(&ITERNAME); \
         CMC_(PFX, _iter_next)(&ITERNAME))

#define CMC_FOREACH_REV(PFX, SNAME, ITERNAME, TARGET) \
    for (struct CMC_DEF_ITER(SNAME) ITERNAME = CMC_(PFX, _iter_end)(TARGET); !CMC_(PFX, _iter_at_start)(&ITERNAME); \
         CMC_(PFX, _iter_prev)(&ITERNAME))

#endif /* CMC_UTL_FOREACH_H */
