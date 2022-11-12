#ifndef _INC_STACK_H
#define _INC_STACK_H

#include <stddef.h>

#define data_t char

typedef struct
{
    data_t *end;
    data_t *begin;
    data_t *pnow;
} stack_t;


size_t stack_size(stack_t *self);

stack_t alloc_stack(size_t size);

void stack_delete(stack_t *self);

int stack_empty(stack_t *self);

void stack_print(stack_t *self);

#endif