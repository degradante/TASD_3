#ifndef _INC_queue_array_H
#define _INC_queue_array_H

#include <stddef.h>
#include <stdbool.h>

#define data_t char

typedef struct
{
    data_t *data;
    data_t *end;
    data_t *begin;
    size_t count;
    size_t max;  
} queue_array_t;


queue_array_t *queue_array_new(size_t size);

data_t queue_array_get(queue_array_t *self);

void queue_array_add(queue_array_t *self, data_t value);

size_t queue_array_size(queue_array_t *self);

bool queue_array_empty(queue_array_t *self);

void queue_array_delete(queue_array_t *self);

void queue_array_print(queue_array_t *self);

size_t queue_array_memsize(size_t size);

#endif