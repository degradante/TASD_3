#ifndef _INC_STACK_H
#define _INC_STACK_H

#include <stddef.h>
#include <stdbool.h>

#define data_t char

typedef struct
{
    data_t *data;
    data_t *end;
    data_t *begin;
    data_t *top;
} stack_t;


stack_t *stack_new(size_t size);

data_t stack_pop(stack_t *self);

void stack_push(stack_t *self, data_t value);

size_t stack_size(stack_t *self);

bool stack_empty(stack_t *self);

void stack_delete(stack_t *self);

void stack_print(stack_t *self);

#endif