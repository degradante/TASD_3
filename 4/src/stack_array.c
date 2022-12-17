#include "stack_array.h"
#include <stdio.h>
#include <stdlib.h>

data_t stack_array_pop(stack_array_t *self)
{
    return *(self->top--);
}


void stack_array_push(stack_array_t *self, data_t value)
{
    if (self->top < self->end)
    {
        *(self->top++) = value;
    }
}


stack_array_t *stack_array_new(size_t size)
{
    stack_array_t *self = (stack_array_t*)calloc(size + 1, sizeof(stack_array_t*));
	self->data = calloc(size + 1, sizeof(data_t));

    self->begin = self->data + 1;
	self->end = self->begin + size;
	self->top = self->data;

	return self;
}


size_t stack_array_size(stack_array_t *self)
{
	return self->end - self->begin;
}


void stack_array_delete(stack_array_t *self)
{
    if (self)
    {
        if (self->data)
        {
            self->end = NULL;
            self->top = NULL;
            self->begin = NULL;
            
            free(self->data);
            self->data = NULL;
        }
        free(self);
    }
}


bool stack_array_empty(stack_array_t *self)
{
	return self->top < self->begin;
}


void stack_array_print(stack_array_t *self)
{
    printf("\nstack_array:\n ");
    for (data_t *ch = self->top; ch >= self->begin; ch--)
        printf("%c ", *ch);
    printf("\n");
}


size_t stack_array_memsize(size_t size)
{
	return sizeof(stack_array_t) + sizeof(data_t) * size;
}