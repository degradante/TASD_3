#ifndef _INC_LIST_H
#define _INC_LIST_H

#include <stdbool.h>
#include "stack.h"

typedef struct node
{
    data_t value;
    struct node *next;
} node_t;


typedef struct
{
    node_t *top;
} list_t;


list_t *list_new();

void list_push(list_t *self, data_t character);

data_t list_pop(list_t *self);

bool list_empty(list_t *self);

void list_delete(list_t *self);

void list_print(list_t *self);

size_t list_memsize(size_t size);

size_t nodes_memsize(list_t *self);

#endif