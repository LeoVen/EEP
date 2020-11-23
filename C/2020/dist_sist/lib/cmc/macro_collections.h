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
 * macro_collections.h
 *
 * Creation Date: 11/02/2019
 *
 * Authors:
 * Leonardo Vencovsky (https://github.com/LeoVen)
 *
 */

/**
 * This file provides everything from the C Macro Collections library.
 *
 * Every data structure and features are available through this header. There is
 * also three macros that can help you generate whichever Collection you need
 * from any given sub-library. They are:
 *
 * - C_MACRO_COLLECTIONS
 * - C_MACRO_COLLECTIONS_INLINE
 * - C_MACRO_COLLECTIONS_EXTENDED
 *     - C_MACRO_COLLECTIONS_EXTENDED_HEADER
 *     - C_MACRO_COLLECTIONS_EXTENDED_SOURCE
 * - C_MACRO_COLLECTIONS_ALL
 *     - C_MACRO_COLLECTIONS_ALL_HEADER
 *     - C_MACRO_COLLECTIONS_ALL_SOURCE
 */
#ifndef CMC_MACRO_COLLECTIONS_H
#define CMC_MACRO_COLLECTIONS_H

// clang-format off
#include "cmc_hashbidimap.h"      /* Added in 26/09/2019 */
#include "cmc_hashmap.h"          /* Added in 03/04/2019 */
#include "cmc_list.h"             /* Added in 12/02/2019 */

#include "cor_alloc.h"            /* Added in 24/05/2020 */
#include "cor_callbacks.h"        /* Added in 24/05/2020 */
#include "cor_core.h"             /* Added in 17/03/2020 */
#include "cor_flags.h"            /* Added in 14/05/2020 */
#include "cor_ftable.h"           /* Added in 27/05/2020 */
#include "cor_hashtable.h"        /* Added in 17/03/2020 */

#include "ext_cmc_hashmap.h"      /* Added in 25/05/2020 */

#include "utl_assert.h"           /* Added in 27/06/2019 */
#include "utl_foreach.h"          /* Added in 25/02/2019 */
#include "utl_futils.h"           /* Added in 15/04/2020 */
#include "utl_log.h"              /* Added in 21/06/2019 */
#include "utl_mutex.h"            /* Added in 14/05/2020 */
#include "utl_test.h"             /* Added in 26/06/2019 */
#include "utl_thread.h"           /* Added in 14/05/2020 */
#include "utl_timer.h"            /* Added in 12/04/2019 */
// clang-format on

/**
 * C_MACRO_COLLECTIONS
 *
 * Generate a specific part of a specific collection from a specific library.
 *
 * \param LIB The collection's sub-library
 * \param COLLECTION The name of the collection in all uppercase
 * \param PART The part of the collection (either CORE or one available at EXT)
 * \param ACCESS Either PUBLIC or PRIVATE
 * \param FILE Either HEADER or SOURCE
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 */
#define C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    C_MACRO_COLLECTIONS_(LIB, COLLECTION, PART, ACCESS, FILE)(PARAMS)

#define C_MACRO_COLLECTIONS_(LIB, COLLECTION, PART, ACCESS, FILE) CMC_##LIB##_##COLLECTION##_##PART##_##ACCESS##_##FILE

/**
 * C_MACRO_COLLECTIONS_INLINE
 *
 * Generates both HEADER and SOURCE one after the other of a certain PART of a certain LIB.
 *
 * \param LIB The collection's sub-library
 * \param COLLECTION The name of the collection in all uppercase
 * \param PART The part of the collection (either CORE or one available at EXT)
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 */
#define C_MACRO_COLLECTIONS_INLINE(LIB, COLLECTION, PART, PARAMS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, PUBLIC, HEADER, PARAMS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, PUBLIC, SOURCE, PARAMS)

/**
 * C_MACRO_COLLECTIONS_EXTENDED
 *
 * Generate the CORE of a collection along with one or more part from EXT. The
 * headers are generated first, then the source code.
 *
 * \param LIB The collection's sub-library
 * \param COLLECTION The name of the collection in all uppercase
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 * \param PARTS A non-empty tuple of all desired EXT parts
 */
#define C_MACRO_COLLECTIONS_EXTENDED(LIB, COLLECTION, PARAMS, PARTS) \
    C_MACRO_COLLECTIONS_EXTENDED_HEADER(LIB, COLLECTION, PUBLIC, PARAMS, PARTS) \
    C_MACRO_COLLECTIONS_EXTENDED_SOURCE(LIB, COLLECTION, PUBLIC, PARAMS, PARTS)

/**
 * C_MACRO_COLLECTIONS_EXTENDED_HEADER
 *
 * Generate all headers of CORE and the specified header parts of a collection.
 *
 * \param LIB The collection's sub-library
 * \param COLLECTION The name of the collection in all uppercase
 * \param ACCESS Either PUBLIC or PRIVATE
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 * \param PARTS A non-empty tuple of all desired EXT parts
 */
#define C_MACRO_COLLECTIONS_EXTENDED_HEADER(LIB, COLLECTION, ACCESS, PARAMS, PARTS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, CORE, ACCESS, HEADER, PARAMS) \
    CMC_MAP(CMC_(EXT_, LIB), COLLECTION, ACCESS, HEADER, PARAMS, CMC_EVAL PARTS)

/**
 * C_MACRO_COLLECTIONS_EXTENDED_SOURCE
 *
 * Generate all sources of CORE and the specified source parts of a collection.
 *
 * \param LIB The collection's sub-library
 * \param COLLECTION The name of the collection in all uppercase
 * \param ACCESS Either PUBLIC or PRIVATE
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 * \param PARTS A non-empty tuple of all desired EXT parts
 */
#define C_MACRO_COLLECTIONS_EXTENDED_SOURCE(LIB, COLLECTION, ACCESS, PARAMS, PARTS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, CORE, ACCESS, SOURCE, PARAMS) \
    CMC_MAP(CMC_(EXT_, LIB), COLLECTION, ACCESS, SOURCE, PARAMS, CMC_EVAL PARTS)

/**
 * C_MACRO_COLLECTIONS_ALL
 *
 * Generate everything provided by a collection included in the EXT library. The
 * headers are generated first, then the source code.
 *
 * \param LIB The collection's library
 * \param COLLECTION The name of the collection in all uppercase
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 */
#define C_MACRO_COLLECTIONS_ALL(LIB, COLLECTION, PARAMS) \
    C_MACRO_COLLECTIONS_ALL_HEADER(LIB, COLLECTION, PUBLIC, PARAMS) \
    C_MACRO_COLLECTIONS_ALL_SOURCE(LIB, COLLECTION, PUBLIC, PARAMS)

/**
 * C_MACRO_COLLECTIONS_ALL_HEADER
 *
 * Generates all headers (CORE and those at EXT) from a given collection.
 *
 * \param LIB The collection's library
 * \param COLLECTION The name of the collection in all uppercase
 * \param ACCESS Either PUBLIC or PRIVATE
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V)
 */
#define C_MACRO_COLLECTIONS_ALL_HEADER(LIB, COLLECTION, ACCESS, PARAMS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, CORE, ACCESS, HEADER, PARAMS) \
    CMC_MAP(CMC_(EXT_, LIB), COLLECTION, ACCESS, HEADER, PARAMS, C_MACRO_COLLECTIONS_PARTS(LIB, COLLECTION))

/**
 * C_MACRO_COLLECTIONS_ALL_SOURCE
 *
 * Generates all sources (CORE and those at EXT) from a given collection.
 *
 * \param LIB The collection's library
 * \param COLLECTION The name of the collection in all uppercase
 * \param ACCESS Either PUBLIC or PRIVATE
 * \param PARAMS A tuple of form (PFX, SNAME, SIZE, K, V
 */
#define C_MACRO_COLLECTIONS_ALL_SOURCE(LIB, COLLECTION, ACCESS, PARAMS) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, CORE, ACCESS, SOURCE, PARAMS) \
    CMC_MAP(CMC_(EXT_, LIB), COLLECTION, ACCESS, SOURCE, PARAMS, C_MACRO_COLLECTIONS_PARTS(LIB, COLLECTION))

/**
 * C_MACRO_COLLECTIONS_PARTS
 *
 * Gets the macro with all EXT parts of a collection. Every collection has this
 * macro defined in the EXT libraries.
 */
#define C_MACRO_COLLECTIONS_PARTS(LIB, COLLECTION) CMC_EXT_##LIB##_##COLLECTION##_PARTS,

/* Evaluates a tuple so that (A, B) -> A, B, */
#define CMC_EVAL(...) __VA_ARGS__,

/**
 * A __VA_ARGS__ argument counter. This argument counter is slightly shifted:
 *
 * CMC_NARG(HELLO)         -> 0
 * CMC_NARG(HELLO,)        -> 1
 * CMC_NARG(HELLO, WORLD,) -> 2
 */
#define CMC_NARG(...) CMC_NARG_(__VA_ARGS__, CMC_SEQ_N())
#define CMC_NARG_(...) CMC_ARG_N(__VA_ARGS__)
#define CMC_ARG_N(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, \
                  _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, \
                  _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, \
                  _62, _63, N, ...) \
    N
#define CMC_SEQ_N() \
    63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, \
        35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, \
        7, 6, 5, 4, 3, 2, 1, 0

/* Generates the FILE for each part (__VA_ARGS__) of a collection */
#define CMC_MAP(LIB, COLLECTION, ACCESS, FILE, PARAMS, ...) \
    CMC_(CMC_MAP_, CMC_NARG(__VA_ARGS__)) \
    (LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)

#define CMC_MAP_9(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_8(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_8(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_7(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_7(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_6(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_6(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_5(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_5(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_4(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_4(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_3(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_3(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_2(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_2(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_1(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_1(LIB, COLLECTION, ACCESS, FILE, PARAMS, PART, ...) \
    C_MACRO_COLLECTIONS(LIB, COLLECTION, PART, ACCESS, FILE, PARAMS) \
    CMC_MAP_0(LIB, COLLECTION, ACCESS, FILE, PARAMS, __VA_ARGS__)
#define CMC_MAP_0(LIB, COLLECTION, ACCESS, FILE, PARAMS, ...)

#endif /* CMC_MACRO_COLLECTIONS_H */
