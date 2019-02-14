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
// compare_f  (CMPF)
// copy_f     (CPYF)
// display_f  (DSPY)
// free_f     (FREF)
// hash_f     (HSHF)
// priority_f (PRIF)

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

#define CONCATH_(C) C##_GENERATE_HEADER
#define CONCATC_(C) C##_GENERATE_SOURCE

#define CONCATH(C) CONCATH_(C)
#define CONCATC(C) CONCATC_(C)

/// Declares and creates all functions used by the generated list
///
/// @param C     : Container (LIST, STACK)
/// @param PFX   : Functions prefix (namespace)
/// @param SNAME : Structure name (typedef struct)
/// @param MOD   : Functions modifiers (optional)
/// @param T     : Data type to handle
#define CONTAINER_GENERATE(C, PFX, SNAME, MOD, T)    \
    CONTAINER_GENERATE_HEADER(C, PFX, SNAME, MOD, T) \
    CONTAINER_GENERATE_SOURCE(C, PFX, SNAME, MOD, T)

#define CONTAINER_GENERATE_HEADER(C, PFX, SNAME, MOD, T) \
    CONCATH(C)                                           \
    (PFX, SNAME, MOD, T)

#define CONTAINER_GENERATE_SOURCE(C, PFX, SNAME, MOD, T) \
    CONCATC(C)                                           \
    (PFX, SNAME, MOD, T)

#define LIST_GENERATE_HEADER(PFX, SNAME, MOD, T)                                    \
                                                                                    \
    typedef struct SNAME##_s                                                        \
    {                                                                               \
        T *buffer;                                                                  \
        size_t capacity;                                                            \
        size_t count;                                                               \
    } SNAME;                                                                        \
                                                                                    \
    MOD SNAME *PFX##_new(size_t size);                                              \
    MOD void PFX##_free(SNAME *list);                                               \
    MOD bool PFX##_push_front(SNAME *list, T element);                              \
    MOD bool PFX##_push(SNAME *list, T element, size_t index);                      \
    MOD bool PFX##_push_back(SNAME *list, T element);                               \
    MOD bool PFX##_pop_front(SNAME *list);                                          \
    MOD bool PFX##_pop(SNAME *list, size_t index);                                  \
    MOD bool PFX##_pop_back(SNAME *list);                                           \
    MOD bool PFX##_insert_if(SNAME *list, T element, size_t index, bool condition); \
    MOD bool PFX##_remove_if(SNAME *list, size_t index, bool condition);            \
    MOD T PFX##_back(SNAME *list);                                                  \
    MOD T PFX##_get(SNAME *list, size_t index);                                     \
    MOD T PFX##_front(SNAME *list);                                                 \
    MOD bool PFX##_empty(SNAME *list);                                              \
    MOD bool PFX##_full(SNAME *list);                                               \
    MOD bool PFX##_grow(SNAME *list);

#define LIST_GENERATE_SOURCE(PFX, SNAME, MOD, T)                                   \
                                                                                   \
    MOD SNAME *PFX##_new(size_t size)                                              \
    {                                                                              \
        if (size < 1)                                                              \
            return NULL;                                                           \
                                                                                   \
        SNAME *list = malloc(sizeof(SNAME));                                       \
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
        list->count = 0;                                                           \
                                                                                   \
        return list;                                                               \
    }                                                                              \
                                                                                   \
    MOD void PFX##_free(SNAME *list)                                               \
    {                                                                              \
        free(list->buffer);                                                        \
        free(list);                                                                \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push_front(SNAME *list, T element)                              \
    {                                                                              \
        if (PFX##_full(list))                                                      \
        {                                                                          \
            if (!PFX##_grow(list))                                                 \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        if (!PFX##_empty(list))                                                    \
        {                                                                          \
            for (size_t i = list->count; i > 0; i--)                               \
            {                                                                      \
                list->buffer[i] = list->buffer[i - 1];                             \
            }                                                                      \
        }                                                                          \
                                                                                   \
        list->buffer[0] = element;                                                 \
                                                                                   \
        list->count++;                                                             \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push(SNAME *list, T element, size_t index)                      \
    {                                                                              \
        if (index > list->count)                                                   \
            return false;                                                          \
                                                                                   \
        if (index == 0)                                                            \
        {                                                                          \
            return PFX##_push_front(list, element);                                \
        }                                                                          \
        else if (index == list->count)                                             \
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
        for (size_t i = list->count; i > index; i--)                               \
        {                                                                          \
            list->buffer[i] = list->buffer[i - 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[index] = element;                                             \
                                                                                   \
        list->count++;                                                             \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push_back(SNAME *list, T element)                               \
    {                                                                              \
        if (PFX##_full(list))                                                      \
        {                                                                          \
            if (!PFX##_grow(list))                                                 \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        list->buffer[list->count++] = element;                                     \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop_front(SNAME *list)                                          \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        for (size_t i = 0; i < list->count; i++)                                   \
        {                                                                          \
            list->buffer[i] = list->buffer[i + 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[--list->count] = 0;                                           \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop(SNAME *list, size_t index)                                  \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        if (index == 0)                                                            \
        {                                                                          \
            return PFX##_pop_front(list);                                          \
        }                                                                          \
        else if (index == list->count - 1)                                         \
        {                                                                          \
            return PFX##_pop_back(list);                                           \
        }                                                                          \
                                                                                   \
        for (size_t i = index; i < list->count - 1; i++)                           \
        {                                                                          \
            list->buffer[i] = list->buffer[i + 1];                                 \
        }                                                                          \
                                                                                   \
        list->buffer[--list->count] = 0;                                           \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop_back(SNAME *list)                                           \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return false;                                                          \
                                                                                   \
        list->buffer[--list->count] = 0;                                           \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_insert_if(SNAME *list, T element, size_t index, bool condition) \
    {                                                                              \
        if (condition)                                                             \
            return PFX##_push(list, element, index);                               \
                                                                                   \
        return false;                                                              \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_remove_if(SNAME *list, size_t index, bool condition)            \
    {                                                                              \
        if (condition)                                                             \
            return PFX##_pop(list, index);                                         \
                                                                                   \
        return false;                                                              \
    }                                                                              \
                                                                                   \
    MOD T PFX##_front(SNAME *list)                                                 \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[0];                                                    \
    }                                                                              \
                                                                                   \
    MOD T PFX##_get(SNAME *list, size_t index)                                     \
    {                                                                              \
        if (index >= list->count)                                                  \
            return 0;                                                              \
                                                                                   \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[index];                                                \
    }                                                                              \
                                                                                   \
    MOD T PFX##_back(SNAME *list)                                                  \
    {                                                                              \
        if (PFX##_empty(list))                                                     \
            return 0;                                                              \
                                                                                   \
        return list->buffer[list->count - 1];                                      \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_empty(SNAME *list)                                              \
    {                                                                              \
        return list->count == 0;                                                   \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_full(SNAME *list)                                               \
    {                                                                              \
        return list->count >= list->capacity;                                      \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_grow(SNAME *list)                                               \
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

#define STACK_GENERATE_HEADER(PFX, SNAME, MOD, T)                                  \
                                                                                   \
    typedef struct SNAME##_s                                                       \
    {                                                                              \
        T *buffer;                                                                 \
        size_t capacity;                                                           \
        size_t count;                                                              \
    } SNAME;                                                                       \
                                                                                   \
    MOD SNAME *PFX##_new(size_t size);                                             \
    MOD void PFX##_free(SNAME *stack);                                             \
    MOD bool PFX##_push(SNAME *stack, T element);                                  \
    MOD bool PFX##_pop(SNAME *stack);                                              \
    MOD T PFX##_top(SNAME *stack);                                                 \
    MOD bool PFX##_push_if(SNAME *stack, T element, size_t index, bool condition); \
    MOD bool PFX##_pop_if(SNAME *stack, size_t index, bool condition);             \
    MOD bool PFX##_empty(SNAME *stack);                                            \
    MOD bool PFX##_full(SNAME *stack);                                             \
    MOD bool PFX##_grow(SNAME *stack);

#define STACK_GENERATE_SOURCE(PFX, SNAME, MOD, T)                                  \
                                                                                   \
    MOD SNAME *PFX##_new(size_t size)                                              \
    {                                                                              \
        if (size < 1)                                                              \
            return NULL;                                                           \
                                                                                   \
        SNAME *stack = malloc(sizeof(SNAME));                                      \
                                                                                   \
        if (!stack)                                                                \
            return NULL;                                                           \
                                                                                   \
        stack->buffer = malloc(sizeof(T) * size);                                  \
                                                                                   \
        if (!stack->buffer)                                                        \
        {                                                                          \
            free(stack);                                                           \
            return NULL;                                                           \
        }                                                                          \
                                                                                   \
        for (size_t i = 0; i < size; i++)                                          \
        {                                                                          \
            stack->buffer[i] = 0;                                                  \
        }                                                                          \
                                                                                   \
        stack->capacity = size;                                                    \
        stack->count = 0;                                                          \
                                                                                   \
        return stack;                                                              \
    }                                                                              \
                                                                                   \
    MOD void PFX##_free(SNAME *stack)                                              \
    {                                                                              \
        free(stack->buffer);                                                       \
        free(stack);                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push(SNAME *stack, T element)                                   \
    {                                                                              \
        if (PFX##_full(stack))                                                     \
        {                                                                          \
            if (!PFX##_grow(stack))                                                \
                return false;                                                      \
        }                                                                          \
                                                                                   \
        stack->buffer[stack->count++] = element;                                   \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_pop(SNAME *stack)                                               \
    {                                                                              \
        if (PFX##_empty(stack))                                                    \
            return false;                                                          \
                                                                                   \
        stack->buffer[--stack->count] = 0;                                         \
                                                                                   \
        return true;                                                               \
    }                                                                              \
                                                                                   \
    MOD T PFX##_top(SNAME *stack)                                                  \
    {                                                                              \
        if (PFX##_empty(stack))                                                    \
            return 0;                                                              \
                                                                                   \
        return stack->buffer[stack->count - 1];                                    \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_push_if(SNAME *stack, T element, size_t index, bool condition); \
    MOD bool PFX##_pop_if(SNAME *stack, size_t index, bool condition);             \
                                                                                   \
    MOD bool PFX##_empty(SNAME *stack)                                             \
    {                                                                              \
        return stack->count == 0;                                                  \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_full(SNAME *stack)                                              \
    {                                                                              \
        return stack->count >= stack->capacity;                                    \
    }                                                                              \
                                                                                   \
    MOD bool PFX##_grow(SNAME *stack)                                              \
    {                                                                              \
        size_t new_capacity = stack->capacity * 2;                                 \
                                                                                   \
        T *new_buffer = realloc(stack->buffer, sizeof(T) * new_capacity);          \
                                                                                   \
        if (!new_buffer)                                                           \
            return false;                                                          \
                                                                                   \
        stack->buffer = new_buffer;                                                \
        stack->capacity = new_capacity;                                            \
                                                                                   \
        return true;                                                               \
    }

#endif /* MACRO_LIST */