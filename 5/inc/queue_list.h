#ifndef _INC_queue_list_H
#define _INC_queue_list_H

#include <stdbool.h>
#include "queue_array.h"

typedef struct node
{
    data_t value;
    struct node *next;
} node_t;


typedef struct
{
    node_t *begin;
} queue_list_t;


queue_list_t *queue_list_new();

void queue_list_push(queue_list_t *self, data_t character);

data_t queue_list_pop(queue_list_t *self);

bool queue_list_empty(queue_list_t *self);

void queue_list_delete(queue_list_t *self);

void queue_list_print(queue_list_t *self);

size_t queue_list_memsize(size_t size);

size_t nodes_memsize(queue_list_t *self);

#endif