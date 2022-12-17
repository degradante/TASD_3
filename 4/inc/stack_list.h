#ifndef _INC_STACK_LIST_H
#define _INC_STACK_LIST_H

#include <stdbool.h>
#include "stack_array.h"

typedef struct node
{
    data_t value;
    struct node *next;
} node_t;


typedef struct
{
    node_t *top;
} stack_list_t;


stack_list_t *stack_list_new();

void stack_list_push(stack_list_t *self, data_t character);

data_t stack_list_pop(stack_list_t *self);

bool stack_list_empty(stack_list_t *self);

void stack_list_delete(stack_list_t *self);

void stack_list_print(stack_list_t *self);

size_t stack_list_memsize(size_t size);

size_t nodes_memsize(stack_list_t *self);

#endif