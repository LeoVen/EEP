/**
 * @file macro_containers.h
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen)
 * @date 11/02/2019
 *
 * Macro based generic containers.
 *
 */

#ifndef MACRO_CONTAINERS
#define MACRO_CONTAINERS

// TODO Functions that can manipulate the desired data type
// compare_f  (CMPF)
// copy_f     (CPYF)
// display_f  (DSPF)
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

#define CONCATH_(C, P) C##_GENERATE_HEADER##_##P
#define CONCATC_(C, P) C##_GENERATE_SOURCE##_##P

#define CONCATH(C, P) CONCATH_(C, P)
#define CONCATC(C, P) CONCATC_(C, P)

/// Declares and creates all functions used by the generated container
///
/// @param C     : Container (LIST, STACK, QUEUE)
/// @param P     : Permission (PRIVATE, PUBLIC) - If struct fields are hidden or not
/// @param PFX   : Functions prefix (namespace)
/// @param SNAME : Structure name (typedef struct)
/// @param FMOD  : Functions modifier [optional](static)
/// @param T     : Data type to handle
#define CONTAINER_GENERATE(C, P, PFX, SNAME, FMOD, T)    \
    CONTAINER_GENERATE_HEADER(C, P, PFX, SNAME, FMOD, T) \
    CONTAINER_GENERATE_SOURCE(C, P, PFX, SNAME, FMOD, T)

#define CONTAINER_GENERATE_HEADER(C, P, PFX, SNAME, FMOD, T) \
    CONCATH(C, P)                                            \
    (PFX, SNAME, FMOD, T)

#define CONTAINER_GENERATE_SOURCE(C, P, PFX, SNAME, FMOD, T) \
    CONCATC(C, P)                                            \
    (PFX, SNAME, FMOD, T)

/*****************************************************************************/
/********************************************************************** LIST */
/*****************************************************************************/

/* PRIVATE *******************************************************************/
#define LIST_GENERATE_HEADER_PRIVATE(PFX, SNAME, FMOD, T) \
    LIST_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define LIST_GENERATE_SOURCE_PRIVATE(PFX, SNAME, FMOD, T) \
    LIST_GENERATE_STRUCT(PFX, SNAME, FMOD, T)             \
    LIST_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* PUBLIC ********************************************************************/
#define LIST_GENERATE_HEADER_PUBLIC(PFX, SNAME, FMOD, T) \
    LIST_GENERATE_STRUCT(PFX, SNAME, FMOD, T)            \
    LIST_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define LIST_GENERATE_SOURCE_PUBLIC(PFX, SNAME, FMOD, T) \
    LIST_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* STRUCT ********************************************************************/
#define LIST_GENERATE_STRUCT(PFX, SNAME, FMOD, T) \
                                                  \
    struct SNAME##_s                              \
    {                                             \
        T *buffer;                                \
        size_t capacity;                          \
        size_t count;                             \
    };                                            \
                                                  \
    struct SNAME##_iter_s                         \
    {                                             \
        struct SNAME##_s *target;                 \
        size_t cursor;                            \
    };
/* HEADER ********************************************************************/
#define LIST_GENERATE_HEADER(PFX, SNAME, FMOD, T)                                    \
                                                                                     \
    typedef struct SNAME##_s SNAME;                                                  \
    typedef struct SNAME##_iter_s SNAME##_iter;                                      \
                                                                                     \
    FMOD SNAME *PFX##_new(size_t size);                                              \
    FMOD void PFX##_free(SNAME *list);                                               \
    FMOD bool PFX##_push_front(SNAME *list, T element);                              \
    FMOD bool PFX##_push(SNAME *list, T element, size_t index);                      \
    FMOD bool PFX##_push_back(SNAME *list, T element);                               \
    FMOD bool PFX##_pop_front(SNAME *list);                                          \
    FMOD bool PFX##_pop(SNAME *list, size_t index);                                  \
    FMOD bool PFX##_pop_back(SNAME *list);                                           \
    FMOD bool PFX##_insert_if(SNAME *list, T element, size_t index, bool condition); \
    FMOD bool PFX##_remove_if(SNAME *list, size_t index, bool condition);            \
    FMOD T PFX##_back(SNAME *list);                                                  \
    FMOD T PFX##_get(SNAME *list, size_t index);                                     \
    FMOD T PFX##_front(SNAME *list);                                                 \
    FMOD bool PFX##_empty(SNAME *list);                                              \
    FMOD bool PFX##_full(SNAME *list);                                               \
    FMOD size_t PFX##_count(SNAME *list);                                            \
    FMOD size_t PFX##_capacity(SNAME *list);                                         \
                                                                                     \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target);                         \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result);                        \
/* SOURCE ********************************************************************/
#define LIST_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                                   \
                                                                                    \
    FMOD bool PFX##_grow(SNAME *list);                                              \
                                                                                    \
    FMOD SNAME *PFX##_new(size_t size)                                              \
    {                                                                               \
        if (size < 1)                                                               \
            return NULL;                                                            \
                                                                                    \
        SNAME *list = malloc(sizeof(SNAME));                                        \
                                                                                    \
        if (!list)                                                                  \
            return NULL;                                                            \
                                                                                    \
        list->buffer = malloc(sizeof(T) * size);                                    \
                                                                                    \
        if (!list->buffer)                                                          \
        {                                                                           \
            free(list);                                                             \
            return NULL;                                                            \
        }                                                                           \
                                                                                    \
        for (size_t i = 0; i < size; i++)                                           \
        {                                                                           \
            list->buffer[i] = 0;                                                    \
        }                                                                           \
                                                                                    \
        list->capacity = size;                                                      \
        list->count = 0;                                                            \
                                                                                    \
        return list;                                                                \
    }                                                                               \
                                                                                    \
    FMOD void PFX##_free(SNAME *list)                                               \
    {                                                                               \
        free(list->buffer);                                                         \
        free(list);                                                                 \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_push_front(SNAME *list, T element)                              \
    {                                                                               \
        if (PFX##_full(list))                                                       \
        {                                                                           \
            if (!PFX##_grow(list))                                                  \
                return false;                                                       \
        }                                                                           \
                                                                                    \
        if (!PFX##_empty(list))                                                     \
        {                                                                           \
            for (size_t i = list->count; i > 0; i--)                                \
            {                                                                       \
                list->buffer[i] = list->buffer[i - 1];                              \
            }                                                                       \
        }                                                                           \
                                                                                    \
        list->buffer[0] = element;                                                  \
                                                                                    \
        list->count++;                                                              \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_push(SNAME *list, T element, size_t index)                      \
    {                                                                               \
        if (index > list->count)                                                    \
            return false;                                                           \
                                                                                    \
        if (index == 0)                                                             \
        {                                                                           \
            return PFX##_push_front(list, element);                                 \
        }                                                                           \
        else if (index == list->count)                                              \
        {                                                                           \
            return PFX##_push_back(list, element);                                  \
        }                                                                           \
                                                                                    \
        if (PFX##_full(list))                                                       \
        {                                                                           \
            if (!PFX##_grow(list))                                                  \
                return false;                                                       \
        }                                                                           \
                                                                                    \
        for (size_t i = list->count; i > index; i--)                                \
        {                                                                           \
            list->buffer[i] = list->buffer[i - 1];                                  \
        }                                                                           \
                                                                                    \
        list->buffer[index] = element;                                              \
                                                                                    \
        list->count++;                                                              \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_push_back(SNAME *list, T element)                               \
    {                                                                               \
        if (PFX##_full(list))                                                       \
        {                                                                           \
            if (!PFX##_grow(list))                                                  \
                return false;                                                       \
        }                                                                           \
                                                                                    \
        list->buffer[list->count++] = element;                                      \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_pop_front(SNAME *list)                                          \
    {                                                                               \
        if (PFX##_empty(list))                                                      \
            return false;                                                           \
                                                                                    \
        for (size_t i = 0; i < list->count; i++)                                    \
        {                                                                           \
            list->buffer[i] = list->buffer[i + 1];                                  \
        }                                                                           \
                                                                                    \
        list->buffer[--list->count] = 0;                                            \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_pop(SNAME *list, size_t index)                                  \
    {                                                                               \
        if (PFX##_empty(list))                                                      \
            return false;                                                           \
                                                                                    \
        if (index == 0)                                                             \
        {                                                                           \
            return PFX##_pop_front(list);                                           \
        }                                                                           \
        else if (index == list->count - 1)                                          \
        {                                                                           \
            return PFX##_pop_back(list);                                            \
        }                                                                           \
                                                                                    \
        for (size_t i = index; i < list->count - 1; i++)                            \
        {                                                                           \
            list->buffer[i] = list->buffer[i + 1];                                  \
        }                                                                           \
                                                                                    \
        list->buffer[--list->count] = 0;                                            \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_pop_back(SNAME *list)                                           \
    {                                                                               \
        if (PFX##_empty(list))                                                      \
            return false;                                                           \
                                                                                    \
        list->buffer[--list->count] = 0;                                            \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_insert_if(SNAME *list, T element, size_t index, bool condition) \
    {                                                                               \
        if (condition)                                                              \
            return PFX##_push(list, element, index);                                \
                                                                                    \
        return false;                                                               \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_remove_if(SNAME *list, size_t index, bool condition)            \
    {                                                                               \
        if (condition)                                                              \
            return PFX##_pop(list, index);                                          \
                                                                                    \
        return false;                                                               \
    }                                                                               \
                                                                                    \
    FMOD T PFX##_front(SNAME *list)                                                 \
    {                                                                               \
        if (PFX##_empty(list))                                                      \
            return 0;                                                               \
                                                                                    \
        return list->buffer[0];                                                     \
    }                                                                               \
                                                                                    \
    FMOD T PFX##_get(SNAME *list, size_t index)                                     \
    {                                                                               \
        if (index >= list->count)                                                   \
            return 0;                                                               \
                                                                                    \
        if (PFX##_empty(list))                                                      \
            return 0;                                                               \
                                                                                    \
        return list->buffer[index];                                                 \
    }                                                                               \
                                                                                    \
    FMOD T PFX##_back(SNAME *list)                                                  \
    {                                                                               \
        if (PFX##_empty(list))                                                      \
            return 0;                                                               \
                                                                                    \
        return list->buffer[list->count - 1];                                       \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_empty(SNAME *list)                                              \
    {                                                                               \
        return list->count == 0;                                                    \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_full(SNAME *list)                                               \
    {                                                                               \
        return list->count >= list->capacity;                                       \
    }                                                                               \
                                                                                    \
    FMOD size_t PFX##_count(SNAME *list)                                            \
    {                                                                               \
        return list->count;                                                         \
    }                                                                               \
                                                                                    \
    FMOD size_t PFX##_capacity(SNAME *list)                                         \
    {                                                                               \
        return list->capacity;                                                      \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_grow(SNAME *list)                                               \
    {                                                                               \
        size_t new_capacity = list->capacity * 2;                                   \
                                                                                    \
        T *new_buffer = realloc(list->buffer, sizeof(T) * new_capacity);            \
                                                                                    \
        if (!new_buffer)                                                            \
            return false;                                                           \
                                                                                    \
        list->buffer = new_buffer;                                                  \
        list->capacity = new_capacity;                                              \
                                                                                    \
        return true;                                                                \
    }                                                                               \
                                                                                    \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target)                         \
    {                                                                               \
        iter->target = target;                                                      \
        iter->cursor = 0;                                                           \
    }                                                                               \
                                                                                    \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result)                        \
    {                                                                               \
        if (iter->cursor < iter->target->count)                                     \
        {                                                                           \
            *result = iter->target->buffer[iter->cursor++];                         \
            return true;                                                            \
        }                                                                           \
                                                                                    \
        return false;                                                               \
    }

/*****************************************************************************/
/********************************************************************* STACK */
/*****************************************************************************/

/* PRIVATE *******************************************************************/
#define STACK_GENERATE_HEADER_PRIVATE(PFX, SNAME, FMOD, T) \
    STACK_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define STACK_GENERATE_SOURCE_PRIVATE(PFX, SNAME, FMOD, T) \
    STACK_GENERATE_STRUCT(PFX, SNAME, FMOD, T)             \
    STACK_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* PUBLIC ********************************************************************/
#define STACK_GENERATE_HEADER_PUBLIC(PFX, SNAME, FMOD, T) \
    STACK_GENERATE_STRUCT(PFX, SNAME, FMOD, T)            \
    STACK_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define STACK_GENERATE_SOURCE_PUBLIC(PFX, SNAME, FMOD, T) \
    STACK_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* STRUCT ********************************************************************/
#define STACK_GENERATE_STRUCT(PFX, SNAME, FMOD, T) \
                                                   \
    struct SNAME##_s                               \
    {                                              \
        T *buffer;                                 \
        size_t capacity;                           \
        size_t count;                              \
    };                                             \
                                                   \
/* HEADER ********************************************************************/
#define STACK_GENERATE_HEADER(PFX, SNAME, FMOD, T)                    \
                                                                      \
    typedef struct SNAME##_s SNAME;                                   \
                                                                      \
    FMOD SNAME *PFX##_new(size_t size);                               \
    FMOD void PFX##_free(SNAME *stack);                               \
    FMOD bool PFX##_push(SNAME *stack, T element);                    \
    FMOD bool PFX##_pop(SNAME *stack);                                \
    FMOD T PFX##_top(SNAME *stack);                                   \
    FMOD bool PFX##_push_if(SNAME *stack, T element, bool condition); \
    FMOD bool PFX##_pop_if(SNAME *stack, bool condition);             \
    FMOD bool PFX##_empty(SNAME *stack);                              \
    FMOD bool PFX##_full(SNAME *stack);                               \
    FMOD size_t PFX##_count(SNAME *stack);                            \
    FMOD size_t PFX##_capacity(SNAME *stack);

/* SOURCE ********************************************************************/
#define STACK_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                        \
                                                                          \
    FMOD bool PFX##_grow(SNAME *stack);                                   \
                                                                          \
    FMOD SNAME *PFX##_new(size_t size)                                    \
    {                                                                     \
        if (size < 1)                                                     \
            return NULL;                                                  \
                                                                          \
        SNAME *stack = malloc(sizeof(SNAME));                             \
                                                                          \
        if (!stack)                                                       \
            return NULL;                                                  \
                                                                          \
        stack->buffer = malloc(sizeof(T) * size);                         \
                                                                          \
        if (!stack->buffer)                                               \
        {                                                                 \
            free(stack);                                                  \
            return NULL;                                                  \
        }                                                                 \
                                                                          \
        for (size_t i = 0; i < size; i++)                                 \
        {                                                                 \
            stack->buffer[i] = 0;                                         \
        }                                                                 \
                                                                          \
        stack->capacity = size;                                           \
        stack->count = 0;                                                 \
                                                                          \
        return stack;                                                     \
    }                                                                     \
                                                                          \
    FMOD void PFX##_free(SNAME *stack)                                    \
    {                                                                     \
        free(stack->buffer);                                              \
        free(stack);                                                      \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_push(SNAME *stack, T element)                         \
    {                                                                     \
        if (PFX##_full(stack))                                            \
        {                                                                 \
            if (!PFX##_grow(stack))                                       \
                return false;                                             \
        }                                                                 \
                                                                          \
        stack->buffer[stack->count++] = element;                          \
                                                                          \
        return true;                                                      \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_pop(SNAME *stack)                                     \
    {                                                                     \
        if (PFX##_empty(stack))                                           \
            return false;                                                 \
                                                                          \
        stack->buffer[--stack->count] = 0;                                \
                                                                          \
        return true;                                                      \
    }                                                                     \
                                                                          \
    FMOD T PFX##_top(SNAME *stack)                                        \
    {                                                                     \
        if (PFX##_empty(stack))                                           \
            return 0;                                                     \
                                                                          \
        return stack->buffer[stack->count - 1];                           \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_push_if(SNAME *stack, T element, bool condition)      \
    {                                                                     \
        if (condition)                                                    \
            return PFX##_push(stack, element);                            \
                                                                          \
        return false;                                                     \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_pop_if(SNAME *stack, bool condition)                  \
    {                                                                     \
        if (condition)                                                    \
            return PFX##_pop(stack);                                      \
                                                                          \
        return false;                                                     \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_empty(SNAME *stack)                                   \
    {                                                                     \
        return stack->count == 0;                                         \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_full(SNAME *stack)                                    \
    {                                                                     \
        return stack->count >= stack->capacity;                           \
    }                                                                     \
                                                                          \
    FMOD size_t PFX##_count(SNAME *stack)                                 \
    {                                                                     \
        return stack->count;                                              \
    }                                                                     \
                                                                          \
    FMOD size_t PFX##_capacity(SNAME *stack)                              \
    {                                                                     \
        return stack->capacity;                                           \
    }                                                                     \
                                                                          \
    FMOD bool PFX##_grow(SNAME *stack)                                    \
    {                                                                     \
        size_t new_capacity = stack->capacity * 2;                        \
                                                                          \
        T *new_buffer = realloc(stack->buffer, sizeof(T) * new_capacity); \
                                                                          \
        if (!new_buffer)                                                  \
            return false;                                                 \
                                                                          \
        stack->buffer = new_buffer;                                       \
        stack->capacity = new_capacity;                                   \
                                                                          \
        return true;                                                      \
    }

/*****************************************************************************/
/********************************************************************* QUEUE */
/*****************************************************************************/

/* PRIVATE *******************************************************************/
#define QUEUE_GENERATE_HEADER_PRIVATE(PFX, SNAME, FMOD, T) \
    QUEUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define QUEUE_GENERATE_SOURCE_PRIVATE(PFX, SNAME, FMOD, T) \
    QUEUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T)             \
    QUEUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* PUBLIC ********************************************************************/
#define QUEUE_GENERATE_HEADER_PUBLIC(PFX, SNAME, FMOD, T) \
    QUEUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T)            \
    QUEUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define QUEUE_GENERATE_SOURCE_PUBLIC(PFX, SNAME, FMOD, T) \
    QUEUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* STRUCT ********************************************************************/
#define QUEUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T) \
                                                   \
    struct SNAME##_s                               \
    {                                              \
        T *buffer;                                 \
        size_t capacity;                           \
        size_t count;                              \
        size_t front;                              \
        size_t rear;                               \
    };
/* HEADER ********************************************************************/
#define QUEUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)                       \
                                                                         \
    typedef struct SNAME##_s SNAME;                                      \
                                                                         \
    FMOD SNAME *PFX##_new(size_t size);                                  \
    FMOD void PFX##_free(SNAME *queue);                                  \
    FMOD bool PFX##_enqueue(SNAME *queue, T element);                    \
    FMOD bool PFX##_dequeue(SNAME *queue);                               \
    FMOD T PFX##_peek(SNAME *queue);                                     \
    FMOD bool PFX##_enqueue_if(SNAME *queue, T element, bool condition); \
    FMOD bool PFX##_dequeue_if(SNAME *queue, bool condition);            \
    FMOD bool PFX##_empty(SNAME *queue);                                 \
    FMOD bool PFX##_full(SNAME *queue);                                  \
    FMOD size_t PFX##_count(SNAME *queue);                               \
    FMOD size_t PFX##_capacity(SNAME *queue);
/* SOURCE ********************************************************************/
#define QUEUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                                                 \
                                                                                                   \
    FMOD bool PFX##_grow(SNAME *queue);                                                            \
                                                                                                   \
    FMOD SNAME *PFX##_new(size_t size)                                                             \
    {                                                                                              \
        if (size < 1)                                                                              \
            return NULL;                                                                           \
                                                                                                   \
        SNAME *queue = malloc(sizeof(SNAME));                                                      \
                                                                                                   \
        if (!queue)                                                                                \
            return NULL;                                                                           \
                                                                                                   \
        queue->buffer = malloc(sizeof(T) * size);                                                  \
                                                                                                   \
        if (!queue->buffer)                                                                        \
        {                                                                                          \
            free(queue);                                                                           \
            return NULL;                                                                           \
        }                                                                                          \
                                                                                                   \
        for (size_t i = 0; i < size; i++)                                                          \
        {                                                                                          \
            queue->buffer[i] = 0;                                                                  \
        }                                                                                          \
                                                                                                   \
        queue->capacity = size;                                                                    \
        queue->count = 0;                                                                          \
        queue->front = 0;                                                                          \
        queue->rear = 0;                                                                           \
                                                                                                   \
        return queue;                                                                              \
    }                                                                                              \
                                                                                                   \
    FMOD void PFX##_free(SNAME *queue)                                                             \
    {                                                                                              \
        free(queue->buffer);                                                                       \
        free(queue);                                                                               \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_enqueue(SNAME *queue, T element)                                               \
    {                                                                                              \
        if (PFX##_full(queue))                                                                     \
        {                                                                                          \
            if (!PFX##_grow(queue))                                                                \
                return false;                                                                      \
        }                                                                                          \
                                                                                                   \
        queue->buffer[queue->rear] = element;                                                      \
                                                                                                   \
        queue->rear = (queue->rear == queue->capacity - 1) ? 0 : queue->rear + 1;                  \
        queue->count++;                                                                            \
                                                                                                   \
        return true;                                                                               \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_dequeue(SNAME *queue)                                                          \
    {                                                                                              \
        if (PFX##_empty(queue))                                                                    \
            return false;                                                                          \
                                                                                                   \
        queue->buffer[queue->front] = 0;                                                           \
                                                                                                   \
        queue->front = (queue->front == queue->capacity - 1) ? 0 : queue->front + 1;               \
        queue->count--;                                                                            \
                                                                                                   \
        return true;                                                                               \
    }                                                                                              \
                                                                                                   \
    FMOD T PFX##_peek(SNAME *queue)                                                                \
    {                                                                                              \
        if (PFX##_empty(queue))                                                                    \
            return 0;                                                                              \
                                                                                                   \
        return queue->buffer[queue->front];                                                        \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_enqueue_if(SNAME *queue, T element, bool condition)                            \
    {                                                                                              \
        if (condition)                                                                             \
            return PFX##_enqueue(queue, element);                                                  \
                                                                                                   \
        return false;                                                                              \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_dequeue_if(SNAME *queue, bool condition)                                       \
    {                                                                                              \
        if (condition)                                                                             \
            return PFX##_dequeue(queue);                                                           \
                                                                                                   \
        return false;                                                                              \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_empty(SNAME *queue)                                                            \
    {                                                                                              \
        return queue->count == 0;                                                                  \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_full(SNAME *queue)                                                             \
    {                                                                                              \
        return queue->count >= queue->capacity;                                                    \
    }                                                                                              \
                                                                                                   \
    FMOD size_t PFX##_count(SNAME *queue)                                                          \
    {                                                                                              \
        return queue->count;                                                                       \
    }                                                                                              \
                                                                                                   \
    FMOD size_t PFX##_capacity(SNAME *queue)                                                       \
    {                                                                                              \
        return queue->capacity;                                                                    \
    }                                                                                              \
                                                                                                   \
    FMOD bool PFX##_grow(SNAME *queue)                                                             \
    {                                                                                              \
                                                                                                   \
        size_t new_capacity = queue->capacity * 2;                                                 \
                                                                                                   \
        T *new_buffer = malloc(sizeof(T) * new_capacity);                                          \
                                                                                                   \
        if (!new_buffer)                                                                           \
            return false;                                                                          \
                                                                                                   \
        for (size_t i = queue->front, j = 0; j < queue->count; i = (i + 1) % queue->capacity, j++) \
        {                                                                                          \
            new_buffer[j] = queue->buffer[i];                                                      \
        }                                                                                          \
                                                                                                   \
        free(queue->buffer);                                                                       \
                                                                                                   \
        queue->buffer = new_buffer;                                                                \
        queue->capacity = new_capacity;                                                            \
        queue->front = 0;                                                                          \
        queue->rear = queue->count;                                                                \
                                                                                                   \
        return true;                                                                               \
    }

#define FOR_EACH(C, PFX, SNAME, T, TARGET, BODY) \
    C##_FOR_EACH(PFX, SNAME, T, TARGET, BODY)

#define LIST_FOR_EACH(PFX, SNAME, T, TARGET, BODY) \
    do                                             \
    {                                              \
        T var;                                     \
        SNAME##_iter _iter_;                       \
        PFX##_iter(&_iter_, TARGET);               \
        while (PFX##_iter_next(&_iter_, &var))     \
        {                                          \
            BODY;                                  \
        }                                          \
    } while (0);

#endif /* MACRO_CONTAINERS */