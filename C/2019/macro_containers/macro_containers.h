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

#include <stdlib.h>
#include <stdbool.h>

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
/// @param C     : Container (LIST, STACK, QUEUE, DEQUE)
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
    };                                            \
/* HEADER ********************************************************************/
#define LIST_GENERATE_HEADER(PFX, SNAME, FMOD, T)                                      \
                                                                                       \
    typedef struct SNAME##_s SNAME;                                                    \
    typedef struct SNAME##_iter_s SNAME##_iter;                                        \
                                                                                       \
    FMOD SNAME *PFX##_new(size_t size);                                                \
    FMOD void PFX##_free(SNAME *_list_);                                               \
    FMOD bool PFX##_push_front(SNAME *_list_, T element);                              \
    FMOD bool PFX##_push(SNAME *_list_, T element, size_t index);                      \
    FMOD bool PFX##_push_back(SNAME *_list_, T element);                               \
    FMOD bool PFX##_pop_front(SNAME *_list_);                                          \
    FMOD bool PFX##_pop(SNAME *_list_, size_t index);                                  \
    FMOD bool PFX##_pop_back(SNAME *_list_);                                           \
    FMOD bool PFX##_insert_if(SNAME *_list_, T element, size_t index, bool condition); \
    FMOD bool PFX##_remove_if(SNAME *_list_, size_t index, bool condition);            \
    FMOD T PFX##_back(SNAME *_list_);                                                  \
    FMOD T PFX##_get(SNAME *_list_, size_t index);                                     \
    FMOD T PFX##_front(SNAME *_list_);                                                 \
    FMOD bool PFX##_empty(SNAME *_list_);                                              \
    FMOD bool PFX##_full(SNAME *_list_);                                               \
    FMOD size_t PFX##_count(SNAME *_list_);                                            \
    FMOD size_t PFX##_capacity(SNAME *_list_);                                         \
                                                                                       \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target);                           \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result);                          \
/* SOURCE ********************************************************************/
#define LIST_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                                     \
                                                                                      \
    FMOD bool PFX##_grow(SNAME *_list_);                                              \
                                                                                      \
    FMOD SNAME *PFX##_new(size_t size)                                                \
    {                                                                                 \
        if (size < 1)                                                                 \
            return NULL;                                                              \
                                                                                      \
        SNAME *_list_ = malloc(sizeof(SNAME));                                        \
                                                                                      \
        if (!_list_)                                                                  \
            return NULL;                                                              \
                                                                                      \
        _list_->buffer = malloc(sizeof(T) * size);                                    \
                                                                                      \
        if (!_list_->buffer)                                                          \
        {                                                                             \
            free(_list_);                                                             \
            return NULL;                                                              \
        }                                                                             \
                                                                                      \
        for (size_t i = 0; i < size; i++)                                             \
        {                                                                             \
            _list_->buffer[i] = 0;                                                    \
        }                                                                             \
                                                                                      \
        _list_->capacity = size;                                                      \
        _list_->count = 0;                                                            \
                                                                                      \
        return _list_;                                                                \
    }                                                                                 \
                                                                                      \
    FMOD void PFX##_free(SNAME *_list_)                                               \
    {                                                                                 \
        free(_list_->buffer);                                                         \
        free(_list_);                                                                 \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_push_front(SNAME *_list_, T element)                              \
    {                                                                                 \
        if (PFX##_full(_list_))                                                       \
        {                                                                             \
            if (!PFX##_grow(_list_))                                                  \
                return false;                                                         \
        }                                                                             \
                                                                                      \
        if (!PFX##_empty(_list_))                                                     \
        {                                                                             \
            for (size_t i = _list_->count; i > 0; i--)                                \
            {                                                                         \
                _list_->buffer[i] = _list_->buffer[i - 1];                            \
            }                                                                         \
        }                                                                             \
                                                                                      \
        _list_->buffer[0] = element;                                                  \
                                                                                      \
        _list_->count++;                                                              \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_push(SNAME *_list_, T element, size_t index)                      \
    {                                                                                 \
        if (index > _list_->count)                                                    \
            return false;                                                             \
                                                                                      \
        if (index == 0)                                                               \
        {                                                                             \
            return PFX##_push_front(_list_, element);                                 \
        }                                                                             \
        else if (index == _list_->count)                                              \
        {                                                                             \
            return PFX##_push_back(_list_, element);                                  \
        }                                                                             \
                                                                                      \
        if (PFX##_full(_list_))                                                       \
        {                                                                             \
            if (!PFX##_grow(_list_))                                                  \
                return false;                                                         \
        }                                                                             \
                                                                                      \
        for (size_t i = _list_->count; i > index; i--)                                \
        {                                                                             \
            _list_->buffer[i] = _list_->buffer[i - 1];                                \
        }                                                                             \
                                                                                      \
        _list_->buffer[index] = element;                                              \
                                                                                      \
        _list_->count++;                                                              \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_push_back(SNAME *_list_, T element)                               \
    {                                                                                 \
        if (PFX##_full(_list_))                                                       \
        {                                                                             \
            if (!PFX##_grow(_list_))                                                  \
                return false;                                                         \
        }                                                                             \
                                                                                      \
        _list_->buffer[_list_->count++] = element;                                    \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_pop_front(SNAME *_list_)                                          \
    {                                                                                 \
        if (PFX##_empty(_list_))                                                      \
            return false;                                                             \
                                                                                      \
        for (size_t i = 0; i < _list_->count; i++)                                    \
        {                                                                             \
            _list_->buffer[i] = _list_->buffer[i + 1];                                \
        }                                                                             \
                                                                                      \
        _list_->buffer[--_list_->count] = 0;                                          \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_pop(SNAME *_list_, size_t index)                                  \
    {                                                                                 \
        if (PFX##_empty(_list_))                                                      \
            return false;                                                             \
                                                                                      \
        if (index == 0)                                                               \
        {                                                                             \
            return PFX##_pop_front(_list_);                                           \
        }                                                                             \
        else if (index == _list_->count - 1)                                          \
        {                                                                             \
            return PFX##_pop_back(_list_);                                            \
        }                                                                             \
                                                                                      \
        for (size_t i = index; i < _list_->count - 1; i++)                            \
        {                                                                             \
            _list_->buffer[i] = _list_->buffer[i + 1];                                \
        }                                                                             \
                                                                                      \
        _list_->buffer[--_list_->count] = 0;                                          \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_pop_back(SNAME *_list_)                                           \
    {                                                                                 \
        if (PFX##_empty(_list_))                                                      \
            return false;                                                             \
                                                                                      \
        _list_->buffer[--_list_->count] = 0;                                          \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_insert_if(SNAME *_list_, T element, size_t index, bool condition) \
    {                                                                                 \
        if (condition)                                                                \
            return PFX##_push(_list_, element, index);                                \
                                                                                      \
        return false;                                                                 \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_remove_if(SNAME *_list_, size_t index, bool condition)            \
    {                                                                                 \
        if (condition)                                                                \
            return PFX##_pop(_list_, index);                                          \
                                                                                      \
        return false;                                                                 \
    }                                                                                 \
                                                                                      \
    FMOD T PFX##_front(SNAME *_list_)                                                 \
    {                                                                                 \
        if (PFX##_empty(_list_))                                                      \
            return 0;                                                                 \
                                                                                      \
        return _list_->buffer[0];                                                     \
    }                                                                                 \
                                                                                      \
    FMOD T PFX##_get(SNAME *_list_, size_t index)                                     \
    {                                                                                 \
        if (index >= _list_->count)                                                   \
            return 0;                                                                 \
                                                                                      \
        if (PFX##_empty(_list_))                                                      \
            return 0;                                                                 \
                                                                                      \
        return _list_->buffer[index];                                                 \
    }                                                                                 \
                                                                                      \
    FMOD T PFX##_back(SNAME *_list_)                                                  \
    {                                                                                 \
        if (PFX##_empty(_list_))                                                      \
            return 0;                                                                 \
                                                                                      \
        return _list_->buffer[_list_->count - 1];                                     \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_empty(SNAME *_list_)                                              \
    {                                                                                 \
        return _list_->count == 0;                                                    \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_full(SNAME *_list_)                                               \
    {                                                                                 \
        return _list_->count >= _list_->capacity;                                     \
    }                                                                                 \
                                                                                      \
    FMOD size_t PFX##_count(SNAME *_list_)                                            \
    {                                                                                 \
        return _list_->count;                                                         \
    }                                                                                 \
                                                                                      \
    FMOD size_t PFX##_capacity(SNAME *_list_)                                         \
    {                                                                                 \
        return _list_->capacity;                                                      \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_grow(SNAME *_list_)                                               \
    {                                                                                 \
        size_t new_capacity = _list_->capacity * 2;                                   \
                                                                                      \
        T *new_buffer = realloc(_list_->buffer, sizeof(T) * new_capacity);            \
                                                                                      \
        if (!new_buffer)                                                              \
            return false;                                                             \
                                                                                      \
        _list_->buffer = new_buffer;                                                  \
        _list_->capacity = new_capacity;                                              \
                                                                                      \
        return true;                                                                  \
    }                                                                                 \
                                                                                      \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target)                           \
    {                                                                                 \
        iter->target = target;                                                        \
        iter->cursor = 0;                                                             \
    }                                                                                 \
                                                                                      \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result)                          \
    {                                                                                 \
        if (iter->cursor < iter->target->count)                                       \
        {                                                                             \
            *result = iter->target->buffer[iter->cursor++];                           \
            return true;                                                              \
        }                                                                             \
                                                                                      \
        return false;                                                                 \
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
    struct SNAME##_iter_s                          \
    {                                              \
        struct SNAME##_s *target;                  \
        size_t cursor;                             \
    };                                             \
/* HEADER ********************************************************************/
#define STACK_GENERATE_HEADER(PFX, SNAME, FMOD, T)                      \
                                                                        \
    typedef struct SNAME##_s SNAME;                                     \
    typedef struct SNAME##_iter_s SNAME##_iter;                         \
                                                                        \
    FMOD SNAME *PFX##_new(size_t size);                                 \
    FMOD void PFX##_free(SNAME *_stack_);                               \
    FMOD bool PFX##_push(SNAME *_stack_, T element);                    \
    FMOD bool PFX##_pop(SNAME *_stack_);                                \
    FMOD T PFX##_top(SNAME *_stack_);                                   \
    FMOD bool PFX##_push_if(SNAME *_stack_, T element, bool condition); \
    FMOD bool PFX##_pop_if(SNAME *_stack_, bool condition);             \
    FMOD bool PFX##_empty(SNAME *_stack_);                              \
    FMOD bool PFX##_full(SNAME *_stack_);                               \
    FMOD size_t PFX##_count(SNAME *_stack_);                            \
    FMOD size_t PFX##_capacity(SNAME *_stack_);                         \
                                                                        \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target);            \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result);           \
/* SOURCE ********************************************************************/
#define STACK_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                          \
                                                                            \
    FMOD bool PFX##_grow(SNAME *_stack_);                                   \
                                                                            \
    FMOD SNAME *PFX##_new(size_t size)                                      \
    {                                                                       \
        if (size < 1)                                                       \
            return NULL;                                                    \
                                                                            \
        SNAME *_stack_ = malloc(sizeof(SNAME));                             \
                                                                            \
        if (!_stack_)                                                       \
            return NULL;                                                    \
                                                                            \
        _stack_->buffer = malloc(sizeof(T) * size);                         \
                                                                            \
        if (!_stack_->buffer)                                               \
        {                                                                   \
            free(_stack_);                                                  \
            return NULL;                                                    \
        }                                                                   \
                                                                            \
        for (size_t i = 0; i < size; i++)                                   \
        {                                                                   \
            _stack_->buffer[i] = 0;                                         \
        }                                                                   \
                                                                            \
        _stack_->capacity = size;                                           \
        _stack_->count = 0;                                                 \
                                                                            \
        return _stack_;                                                     \
    }                                                                       \
                                                                            \
    FMOD void PFX##_free(SNAME *_stack_)                                    \
    {                                                                       \
        free(_stack_->buffer);                                              \
        free(_stack_);                                                      \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_push(SNAME *_stack_, T element)                         \
    {                                                                       \
        if (PFX##_full(_stack_))                                            \
        {                                                                   \
            if (!PFX##_grow(_stack_))                                       \
                return false;                                               \
        }                                                                   \
                                                                            \
        _stack_->buffer[_stack_->count++] = element;                        \
                                                                            \
        return true;                                                        \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_pop(SNAME *_stack_)                                     \
    {                                                                       \
        if (PFX##_empty(_stack_))                                           \
            return false;                                                   \
                                                                            \
        _stack_->buffer[--_stack_->count] = 0;                              \
                                                                            \
        return true;                                                        \
    }                                                                       \
                                                                            \
    FMOD T PFX##_top(SNAME *_stack_)                                        \
    {                                                                       \
        if (PFX##_empty(_stack_))                                           \
            return 0;                                                       \
                                                                            \
        return _stack_->buffer[_stack_->count - 1];                         \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_push_if(SNAME *_stack_, T element, bool condition)      \
    {                                                                       \
        if (condition)                                                      \
            return PFX##_push(_stack_, element);                            \
                                                                            \
        return false;                                                       \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_pop_if(SNAME *_stack_, bool condition)                  \
    {                                                                       \
        if (condition)                                                      \
            return PFX##_pop(_stack_);                                      \
                                                                            \
        return false;                                                       \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_empty(SNAME *_stack_)                                   \
    {                                                                       \
        return _stack_->count == 0;                                         \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_full(SNAME *_stack_)                                    \
    {                                                                       \
        return _stack_->count >= _stack_->capacity;                         \
    }                                                                       \
                                                                            \
    FMOD size_t PFX##_count(SNAME *_stack_)                                 \
    {                                                                       \
        return _stack_->count;                                              \
    }                                                                       \
                                                                            \
    FMOD size_t PFX##_capacity(SNAME *_stack_)                              \
    {                                                                       \
        return _stack_->capacity;                                           \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_grow(SNAME *_stack_)                                    \
    {                                                                       \
        size_t new_capacity = _stack_->capacity * 2;                        \
                                                                            \
        T *new_buffer = realloc(_stack_->buffer, sizeof(T) * new_capacity); \
                                                                            \
        if (!new_buffer)                                                    \
            return false;                                                   \
                                                                            \
        _stack_->buffer = new_buffer;                                       \
        _stack_->capacity = new_capacity;                                   \
                                                                            \
        return true;                                                        \
    }                                                                       \
                                                                            \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target)                 \
    {                                                                       \
        iter->target = target;                                              \
        iter->cursor = 0;                                                   \
    }                                                                       \
                                                                            \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result)                \
    {                                                                       \
        if (iter->cursor < iter->target->count)                             \
        {                                                                   \
            *result = iter->target->buffer[iter->cursor++];                 \
            return true;                                                    \
        }                                                                   \
                                                                            \
        return false;                                                       \
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
    };                                             \
                                                   \
    struct SNAME##_iter_s                          \
    {                                              \
        struct SNAME##_s *target;                  \
        size_t cursor;                             \
    };                                             \
/* HEADER ********************************************************************/
#define QUEUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)                         \
                                                                           \
    typedef struct SNAME##_s SNAME;                                        \
    typedef struct SNAME##_iter_s SNAME##_iter;                            \
                                                                           \
    FMOD SNAME *PFX##_new(size_t size);                                    \
    FMOD void PFX##_free(SNAME *_queue_);                                  \
    FMOD bool PFX##_enqueue(SNAME *_queue_, T element);                    \
    FMOD bool PFX##_dequeue(SNAME *_queue_);                               \
    FMOD T PFX##_peek(SNAME *_queue_);                                     \
    FMOD bool PFX##_enqueue_if(SNAME *_queue_, T element, bool condition); \
    FMOD bool PFX##_dequeue_if(SNAME *_queue_, bool condition);            \
    FMOD bool PFX##_empty(SNAME *_queue_);                                 \
    FMOD bool PFX##_full(SNAME *_queue_);                                  \
    FMOD size_t PFX##_count(SNAME *_queue_);                               \
    FMOD size_t PFX##_capacity(SNAME *_queue_);                            \
                                                                           \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target);               \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result);              \
/* SOURCE ********************************************************************/
#define QUEUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                                                       \
                                                                                                         \
    FMOD bool PFX##_grow(SNAME *_queue_);                                                                \
                                                                                                         \
    FMOD SNAME *PFX##_new(size_t size)                                                                   \
    {                                                                                                    \
        if (size < 1)                                                                                    \
            return NULL;                                                                                 \
                                                                                                         \
        SNAME *_queue_ = malloc(sizeof(SNAME));                                                          \
                                                                                                         \
        if (!_queue_)                                                                                    \
            return NULL;                                                                                 \
                                                                                                         \
        _queue_->buffer = malloc(sizeof(T) * size);                                                      \
                                                                                                         \
        if (!_queue_->buffer)                                                                            \
        {                                                                                                \
            free(_queue_);                                                                               \
            return NULL;                                                                                 \
        }                                                                                                \
                                                                                                         \
        for (size_t i = 0; i < size; i++)                                                                \
        {                                                                                                \
            _queue_->buffer[i] = 0;                                                                      \
        }                                                                                                \
                                                                                                         \
        _queue_->capacity = size;                                                                        \
        _queue_->count = 0;                                                                              \
        _queue_->front = 0;                                                                              \
        _queue_->rear = 0;                                                                               \
                                                                                                         \
        return _queue_;                                                                                  \
    }                                                                                                    \
                                                                                                         \
    FMOD void PFX##_free(SNAME *_queue_)                                                                 \
    {                                                                                                    \
        free(_queue_->buffer);                                                                           \
        free(_queue_);                                                                                   \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_enqueue(SNAME *_queue_, T element)                                                   \
    {                                                                                                    \
        if (PFX##_full(_queue_))                                                                         \
        {                                                                                                \
            if (!PFX##_grow(_queue_))                                                                    \
                return false;                                                                            \
        }                                                                                                \
                                                                                                         \
        _queue_->buffer[_queue_->rear] = element;                                                        \
                                                                                                         \
        _queue_->rear = (_queue_->rear == _queue_->capacity - 1) ? 0 : _queue_->rear + 1;                \
        _queue_->count++;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_dequeue(SNAME *_queue_)                                                              \
    {                                                                                                    \
        if (PFX##_empty(_queue_))                                                                        \
            return false;                                                                                \
                                                                                                         \
        _queue_->buffer[_queue_->front] = 0;                                                             \
                                                                                                         \
        _queue_->front = (_queue_->front == _queue_->capacity - 1) ? 0 : _queue_->front + 1;             \
        _queue_->count--;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD T PFX##_peek(SNAME *_queue_)                                                                    \
    {                                                                                                    \
        if (PFX##_empty(_queue_))                                                                        \
            return 0;                                                                                    \
                                                                                                         \
        return _queue_->buffer[_queue_->front];                                                          \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_enqueue_if(SNAME *_queue_, T element, bool condition)                                \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_enqueue(_queue_, element);                                                      \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_dequeue_if(SNAME *_queue_, bool condition)                                           \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_dequeue(_queue_);                                                               \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_empty(SNAME *_queue_)                                                                \
    {                                                                                                    \
        return _queue_->count == 0;                                                                      \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_full(SNAME *_queue_)                                                                 \
    {                                                                                                    \
        return _queue_->count >= _queue_->capacity;                                                      \
    }                                                                                                    \
                                                                                                         \
    FMOD size_t PFX##_count(SNAME *_queue_)                                                              \
    {                                                                                                    \
        return _queue_->count;                                                                           \
    }                                                                                                    \
                                                                                                         \
    FMOD size_t PFX##_capacity(SNAME *_queue_)                                                           \
    {                                                                                                    \
        return _queue_->capacity;                                                                        \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_grow(SNAME *_queue_)                                                                 \
    {                                                                                                    \
                                                                                                         \
        size_t new_capacity = _queue_->capacity * 2;                                                     \
                                                                                                         \
        T *new_buffer = malloc(sizeof(T) * new_capacity);                                                \
                                                                                                         \
        if (!new_buffer)                                                                                 \
            return false;                                                                                \
                                                                                                         \
        for (size_t i = _queue_->front, j = 0; j < _queue_->count; i = (i + 1) % _queue_->capacity, j++) \
        {                                                                                                \
            new_buffer[j] = _queue_->buffer[i];                                                          \
        }                                                                                                \
                                                                                                         \
        free(_queue_->buffer);                                                                           \
                                                                                                         \
        _queue_->buffer = new_buffer;                                                                    \
        _queue_->capacity = new_capacity;                                                                \
        _queue_->front = 0;                                                                              \
        _queue_->rear = _queue_->count;                                                                  \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target)                                              \
    {                                                                                                    \
        iter->target = target;                                                                           \
        iter->cursor = target->front;                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result)                                             \
    {                                                                                                    \
        if (iter->cursor != iter->target->rear)                                                          \
        {                                                                                                \
            *result = iter->target->buffer[iter->cursor];                                                \
            iter->cursor = ++(iter->cursor) % iter->target->capacity;                                    \
            return true;                                                                                 \
        }                                                                                                \
                                                                                                         \
        return false;                                                                                    \
    }

/*****************************************************************************/
/********************************************************************* DEQUE */
/*****************************************************************************/

/* PRIVATE *******************************************************************/
#define DEQUE_GENERATE_HEADER_PRIVATE(PFX, SNAME, FMOD, T) \
    DEQUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define DEQUE_GENERATE_SOURCE_PRIVATE(PFX, SNAME, FMOD, T) \
    DEQUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T)             \
    DEQUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* PUBLIC ********************************************************************/
#define DEQUE_GENERATE_HEADER_PUBLIC(PFX, SNAME, FMOD, T) \
    DEQUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T)            \
    DEQUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)
#define DEQUE_GENERATE_SOURCE_PUBLIC(PFX, SNAME, FMOD, T) \
    DEQUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)
/* STRUCT ********************************************************************/
#define DEQUE_GENERATE_STRUCT(PFX, SNAME, FMOD, T) \
                                                   \
    struct SNAME##_s                               \
    {                                              \
        T *buffer;                                 \
        size_t capacity;                           \
        size_t count;                              \
        size_t front;                              \
        size_t rear;                               \
    };                                             \
                                                   \
    struct SNAME##_iter_s                          \
    {                                              \
        struct SNAME##_s *target;                  \
        size_t cursor;                             \
    };                                             \
/* HEADER ********************************************************************/
#define DEQUE_GENERATE_HEADER(PFX, SNAME, FMOD, T)                            \
                                                                              \
    typedef struct SNAME##_s SNAME;                                           \
    typedef struct SNAME##_iter_s SNAME##_iter;                               \
                                                                              \
    FMOD SNAME *PFX##_new(size_t size);                                       \
    FMOD void PFX##_free(SNAME *_deque_);                                     \
    FMOD bool PFX##_push_front(SNAME *_deque_, T element);                    \
    FMOD bool PFX##_push_back(SNAME *_deque_, T element);                     \
    FMOD bool PFX##_pop_front(SNAME *_deque_);                                \
    FMOD bool PFX##_pop_back(SNAME *_deque_);                                 \
    FMOD bool PFX##_push_front_if(SNAME *_deque_, T element, bool condition); \
    FMOD bool PFX##_push_back_if(SNAME *_deque_, T element, bool condition);  \
    FMOD bool PFX##_pop_front_if(SNAME *_deque_, bool condition);             \
    FMOD bool PFX##_pop_back_if(SNAME *_deque_, bool condition);              \
    FMOD T PFX##_back(SNAME *_deque_);                                        \
    FMOD T PFX##_front(SNAME *_deque_);                                       \
    FMOD bool PFX##_empty(SNAME *_deque_);                                    \
    FMOD bool PFX##_full(SNAME *_deque_);                                     \
    FMOD size_t PFX##_count(SNAME *_deque_);                                  \
    FMOD size_t PFX##_capacity(SNAME *_deque_);                               \
                                                                              \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target);                  \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result);                 \
/* SOURCE ********************************************************************/
#define DEQUE_GENERATE_SOURCE(PFX, SNAME, FMOD, T)                                                       \
                                                                                                         \
    FMOD bool PFX##_grow(SNAME *_deque_);                                                                \
                                                                                                         \
    FMOD SNAME *PFX##_new(size_t size)                                                                   \
    {                                                                                                    \
        if (size < 1)                                                                                    \
            return NULL;                                                                                 \
                                                                                                         \
        SNAME *_deque_ = malloc(sizeof(SNAME));                                                          \
                                                                                                         \
        if (!_deque_)                                                                                    \
            return NULL;                                                                                 \
                                                                                                         \
        _deque_->buffer = malloc(sizeof(T) * size);                                                      \
                                                                                                         \
        if (!_deque_->buffer)                                                                            \
        {                                                                                                \
            free(_deque_);                                                                               \
            return NULL;                                                                                 \
        }                                                                                                \
                                                                                                         \
        for (size_t i = 0; i < size; i++)                                                                \
            _deque_->buffer[i] = 0;                                                                      \
                                                                                                         \
        _deque_->capacity = size;                                                                        \
        _deque_->count = 0;                                                                              \
        _deque_->front = 0;                                                                              \
        _deque_->rear = 0;                                                                               \
                                                                                                         \
        return _deque_;                                                                                  \
    }                                                                                                    \
                                                                                                         \
    FMOD void PFX##_free(SNAME *_deque_)                                                                 \
    {                                                                                                    \
        free(_deque_->buffer);                                                                           \
        free(_deque_);                                                                                   \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_push_front(SNAME *_deque_, T element)                                                \
    {                                                                                                    \
        if (PFX##_full(_deque_))                                                                         \
        {                                                                                                \
            if (!PFX##_grow(_deque_))                                                                    \
                return false;                                                                            \
        }                                                                                                \
                                                                                                         \
        _deque_->front = (_deque_->front == 0) ? _deque_->capacity - 1 : _deque_->front - 1;             \
                                                                                                         \
        _deque_->buffer[_deque_->front] = element;                                                       \
                                                                                                         \
        _deque_->count++;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_push_back(SNAME *_deque_, T element)                                                 \
    {                                                                                                    \
        if (PFX##_full(_deque_))                                                                         \
        {                                                                                                \
            if (!PFX##_grow(_deque_))                                                                    \
                return false;                                                                            \
        }                                                                                                \
                                                                                                         \
        _deque_->buffer[_deque_->rear] = element;                                                        \
                                                                                                         \
        _deque_->rear = (_deque_->rear == _deque_->capacity - 1) ? 0 : _deque_->rear + 1;                \
                                                                                                         \
        _deque_->count++;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_pop_front(SNAME *_deque_)                                                            \
    {                                                                                                    \
        if (PFX##_empty(_deque_))                                                                        \
            return false;                                                                                \
                                                                                                         \
        _deque_->buffer[_deque_->front] = 0;                                                             \
                                                                                                         \
        _deque_->front = (_deque_->front == _deque_->capacity - 1) ? 0 : _deque_->front + 1;             \
                                                                                                         \
        _deque_->count--;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_pop_back(SNAME *_deque_)                                                             \
    {                                                                                                    \
        if (PFX##_empty(_deque_))                                                                        \
            return false;                                                                                \
                                                                                                         \
        _deque_->rear = (_deque_->rear == 0) ? _deque_->capacity - 1 : _deque_->rear - 1;                \
                                                                                                         \
        _deque_->buffer[_deque_->rear] = 0;                                                              \
                                                                                                         \
        _deque_->count--;                                                                                \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_push_front_if(SNAME *_deque_, T element, bool condition)                             \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_push_front(_deque_, element);                                                   \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_push_back_if(SNAME *_deque_, T element, bool condition)                              \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_push_back(_deque_, element);                                                    \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_pop_front_if(SNAME *_deque_, bool condition)                                         \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_pop_front(_deque_);                                                             \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_pop_back_if(SNAME *_deque_, bool condition)                                          \
    {                                                                                                    \
        if (condition)                                                                                   \
            return PFX##_pop_back(_deque_);                                                              \
                                                                                                         \
        return false;                                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD T PFX##_back(SNAME *_deque_)                                                                    \
    {                                                                                                    \
        if (PFX##_empty(_deque_))                                                                        \
            return 0;                                                                                    \
                                                                                                         \
        return _deque_->buffer[(_deque_->rear == 0) ? _deque_->capacity - 1 : _deque_->rear - 1];        \
    }                                                                                                    \
                                                                                                         \
    FMOD T PFX##_front(SNAME *_deque_)                                                                   \
    {                                                                                                    \
        if (PFX##_empty(_deque_))                                                                        \
            return 0;                                                                                    \
                                                                                                         \
        return _deque_->buffer[_deque_->front];                                                          \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_empty(SNAME *_deque_)                                                                \
    {                                                                                                    \
        return _deque_->count == 0;                                                                      \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_full(SNAME *_deque_)                                                                 \
    {                                                                                                    \
        return _deque_->count >= _deque_->capacity;                                                      \
    }                                                                                                    \
                                                                                                         \
    FMOD size_t PFX##_count(SNAME *_deque_)                                                              \
    {                                                                                                    \
        return _deque_->count;                                                                           \
    }                                                                                                    \
                                                                                                         \
    FMOD size_t PFX##_capacity(SNAME *_deque_)                                                           \
    {                                                                                                    \
        return _deque_->capacity;                                                                        \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_grow(SNAME *_deque_)                                                                 \
    {                                                                                                    \
                                                                                                         \
        size_t new_capacity = _deque_->capacity * 2;                                                     \
                                                                                                         \
        T *new_buffer = malloc(sizeof(T) * new_capacity);                                                \
                                                                                                         \
        if (!new_buffer)                                                                                 \
            return false;                                                                                \
                                                                                                         \
        for (size_t i = _deque_->front, j = 0; j < _deque_->count; i = (i + 1) % _deque_->capacity, j++) \
        {                                                                                                \
            new_buffer[j] = _deque_->buffer[i];                                                          \
        }                                                                                                \
                                                                                                         \
        free(_deque_->buffer);                                                                           \
                                                                                                         \
        _deque_->buffer = new_buffer;                                                                    \
        _deque_->capacity = new_capacity;                                                                \
        _deque_->front = 0;                                                                              \
        _deque_->rear = _deque_->count;                                                                  \
                                                                                                         \
        return true;                                                                                     \
    }                                                                                                    \
                                                                                                         \
    FMOD void PFX##_iter(SNAME##_iter *iter, SNAME *target)                                              \
    {                                                                                                    \
        iter->target = target;                                                                           \
        iter->cursor = target->front;                                                                    \
    }                                                                                                    \
                                                                                                         \
    FMOD bool PFX##_iter_next(SNAME##_iter *iter, T *result)                                             \
    {                                                                                                    \
        if (iter->cursor != iter->target->rear)                                                          \
        {                                                                                                \
            *result = iter->target->buffer[iter->cursor];                                                \
            iter->cursor = ++(iter->cursor) % iter->target->capacity;                                    \
            return true;                                                                                 \
        }                                                                                                \
                                                                                                         \
        return false;                                                                                    \
    }

#define FOR_EACH(PFX, SNAME, T, TARGET, BODY)  \
    do                                         \
    {                                          \
        T var;                                 \
        SNAME##_iter _iter_;                   \
        PFX##_iter(&_iter_, TARGET);           \
        while (PFX##_iter_next(&_iter_, &var)) \
        {                                      \
            BODY;                              \
        }                                      \
    } while (0);

#endif /* MACRO_CONTAINERS */