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
 * cor_ftable.h
 *
 * Creation Date: 27/05/2020
 *
 * Authors:
 * Leonardo Vencovsky (https://github.com/LeoVen)
 *
 */

/**
 * Type definitions for Functions Tables.
 */

#ifndef CMC_COR_FTABLE_H
#define CMC_COR_FTABLE_H

/**
 * Where T can either be K or V
 */
#define CMC_DEF_FTAB_CMP(T) int (*cmp)(T, T)
#define CMC_DEF_FTAB_CPY(T) T (*cpy)(T)
#define CMC_DEF_FTAB_STR(T) bool (*str)(FILE *, T)
#define CMC_DEF_FTAB_FREE(T) void (*free)(T)
#define CMC_DEF_FTAB_HASH(T) size_t (*hash)(T)
#define CMC_DEF_FTAB_PRI(T) int (*pri)(T, T)

#endif /* CMC_COR_FTABLE_H */
