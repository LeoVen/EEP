/**
 * @file macro_list.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/02/2019
 *
 * Macro based generic list implemented as a dynamic array.
 *
 */

#ifndef MACRO_LIST
#define MACRO_LIST

// TODO Functions that can manipulate the desired data type
// compare_f
// copy_f
// display_f
// free_f
// hash_f
// compare_f

// TODO Add growth_rate parameter

// TODO Functions
// free - free_shallow
// erase - erase_shallow
// contains
// first
// last
// max
// min
// switch
// reverse
// sort
// from_array - to_array
// display

// TODO Iterator

/// Declares and creates all functions used by the generated list
///
/// @param PFX   : Functions prefix (namespace)
/// @param LNAME : List name (typedef struct)
/// @param MOD   : Functions modifiers (optional)
/// @param T     : Data type to handle
#define MLIST_GENERATE(PFX, LNAME, MOD, T)    \
    MLIST_GENERATE_HEADER(PFX, LNAME, MOD, T) \
    MLIST_GENERATE_SOURCE(PFX, LNAME, MOD, T)

#define MLIST_GENERATE_HEADER(PFX, LNAME, MOD, T)                                   \
                                                                                    \
    typedef struct LNAME##_s                                                        \
    {                                                                               \
        T *buffer;                                                                  \
        size_t capacity;                                                            \
        size_t length;                                                              \
    } LNAME;                                                                        \
                                                                                    \
    MOD LNAME *PFX##_new(size_t size);                                              \
    MOD void PFX##_free(LNAME *list);                                               \
    MOD bool PFX##_push_front(LNAME *list, T element);                              \
    MOD bool PFX##_push(LNAME *list, T element, size_t index);                      \
    MOD bool PFX##_push_back(LNAME *list, T element);                               \
    MOD bool PFX##_pop_front(LNAME *list);                                          \
    MOD bool PFX##_pop(LNAME *list, size_t index);                                  \
    MOD bool PFX##_pop_back(LNAME *list);                                           \
    MOD bool PFX##_insert_if(LNAME *list, T element, size_t index, bool condition); \
    MOD bool PFX##_remove_if(LNAME *list, size_t index, bool condition);            \
    MOD T PFX##_back(LNAME *list);                                                  \
    MOD T PFX##_get(LNAME *list, size_t index);                                     \
    MOD T PFX##_front(LNAME *list);                                                 \
    MOD bool PFX##_empty(LNAME *list);                                              \
    MOD bool PFX##_full(LNAME *list);                                               \
    MOD bool PFX##_grow(LNAME *list);

#define MLIST_GENERATE_SOURCE(PFX, LNAME, MOD, T)                                  \
                                                                                   \
    MOD LNAME *PFX##_new(size_t size)                                              \
    {                                                                              \
        if (size < 1)                                                              \
            return NULL;                                                           \
                                                                                   \
        LNAME *list = malloc(sizeof(LNAME));                                       \
                                                                                   \
        if (!list)                                                                 \
            return NULL;                                                           \
                                                                                   \
        list->buffer = malloc(sizeof(T) * size);                                   \
                                                                                   \
        if (!list->buffer)                                                         \
        {                                                                          \
            free(list);                                                            \
            return NULL;                                                           \
        }                                                                          \
                                                                                   \
        for (size_t i = 0; i < size; i++)                                          \
        {                                                                          \
            list->buffer[i] = 0;                                                   \
        }                                                                          \
                                                                                   \
        list->capacity = size;                                                     \
        list->length = 0;                                                          \
                                                                                   \
        return list;                                                               \
    }                                                                              \
                                                                                   \
    MOD void PFX##_free(LNAME *list)                                               \
    {                                                                              \
        free(list->buffer);                                                        \
        free(list);                                                                \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push_front(LNAME *list, T element)                              \
    {                                                                              \
        if (PFX##_full(list))                                                      \
        {                                                                          \
            if (!PFX##_grow(list))                                                 \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        if (!PFX##_empty(list))                                                    \
        {                                                                          \
            for (size_t i = list->length; i > 0; i--)                              \
            {                                                                      \
                list->buffer[i] = list->buffer[i - 1];                             \
            }                                                                      \
        }                                                                          \
                                                                                   \
        list->buffer[0] = element;                                                 \
                                                                                   \
        list->length++;                                                            \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push(LNAME *list, T element, size_t index)                      \
    {                                                                              \
        if (index > list->length)                                                  \
            return false;                                                          \
                                                                                   \
        if (index == 0)                                                            \
        {                                                                          \
            return PFX##_push_front(list, element);                                \
        }                                                                          \
        else if (index == list->length)                                            \
        {                                                                          \
            return PFX##_push_back(list, element);                                 \
        }                                                                          \
                                                                                   \
        if (PFX##_full(list))                                                      \
        {                                                                          \
            if (!PFX##_grow(list))                                                 \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        for (size_t i = list->length; i > index; i--)                              \
        {                                                                          \
            list->buffer[i] = list->buffer[i - 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[index] = element;                                             \
                                                                                   \
        list->length++;                                                            \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push_back(LNAME *list, T element)                               \
    {                                                                              \
        if (PFX##_full(list))                                                      \
        {                                                                          \
            if (!PFX##_grow(list))                                                 \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        list->buffer[list->length++] = element;                                    \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop_front(LNAME *list)                                          \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        for (size_t i = 0; i < list->length; i++)                                  \
        {                                                                          \
            list->buffer[i] = list->buffer[i + 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[--list->length] = 0;                                          \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop(LNAME *list, size_t index)                                  \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        if (index == 0)                                                            \
        {                                                                          \
            return PFX##_pop_front(list);                                          \
        }                                                                          \
        else if (index == list->length - 1)                                        \
        {                                                                          \
            return PFX##_pop_back(list);                                           \
        }                                                                          \
                                                                                   \
        for (size_t i = index; i < list->length - 1; i++)                          \
        {                                                                          \
            list->buffer[i] = list->buffer[i + 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[--list->length] = 0;                                          \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop_back(LNAME *list)                                           \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        for (size_t i = 0; i < list->length - 1; i++)                              \
        {                                                                          \
            list->buffer[i] = list->buffer[i + 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[--list->length] = 0;                                          \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_insert_if(LNAME *list, T element, size_t index, bool condition) \
    {                                                                              \
        if (condition)                                                             \
            return PFX##_push(list, element, index);                               \
                                                                                   \
        return false;                                                              \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_remove_if(LNAME *list, size_t index, bool condition)            \
    {                                                                              \
        if (condition)                                                             \
            return PFX##_pop(list, index);                                         \
                                                                                   \
        return false;                                                              \
    }                                                                              \
                                                                                   \
    MOD T PFX##_front(LNAME *list)                                                 \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[0];                                                    \
    }                                                                              \
                                                                                   \
    MOD T PFX##_get(LNAME *list, size_t index)                                     \
    {                                                                              \
        if (index >= list->length)                                                 \
            return 0;                                                              \
                                                                                   \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[index];                                                \
    }                                                                              \
                                                                                   \
    MOD T PFX##_back(LNAME *list)                                                  \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[list->length - 1];                                     \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_empty(LNAME *list)                                              \
    {                                                                              \
        return list->length == 0;                                                  \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_full(LNAME *list)                                               \
    {                                                                              \
        return list->length >= list->capacity;                                     \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_grow(LNAME *list)                                               \
    {                                                                              \
        size_t new_capacity = list->capacity * 2;                                  \
                                                                                   \
        T *new_buffer = realloc(list->buffer, sizeof(T) * new_capacity);           \
                                                                                   \
        if (!new_buffer)                                                           \
            return false;                                                          \
                                                                                   \
        list->buffer = new_buffer;                                                 \
        list->capacity = new_capacity;                                             \
                                                                                   \
        return true;                                                               \
    }

#endif /* MACRO_LIST */