#ifndef _INC_STACK_ARRAY_H
#define _INC_STACK_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

#define data_t char

typedef struct
{
    data_t *data;
    data_t *end;
    data_t *begin;
    data_t *top;
} stack_array_t;


stack_array_t *stack_array_new(size_t size);

data_t stack_array_pop(stack_array_t *self);

void stack_array_push(stack_array_t *self, data_t value);

size_t stack_array_size(stack_array_t *self);

bool stack_array_empty(stack_array_t *self);

void stack_array_delete(stack_array_t *self);

void stack_array_print(stack_array_t *self);

size_t stack_array_memsize(size_t size);

#endif