#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

data_t stack_pop(stack_t *self)
{
    return *(self->top--);
}


void stack_push(stack_t *self, data_t value)
{
    if (self->top < self->end)
    {
        *(self->top++) = value;
    }
}


stack_t *stack_new(size_t size)
{
    stack_t *self = (stack_t*)calloc(size + 1, sizeof(stack_t*));
	self->data = calloc(size + 1, sizeof(data_t));

    self->begin = self->data + 1;
	self->end = self->begin + size;
	self->top = self->data;

	return self;
}


size_t stack_size(stack_t *self)
{
	return self->end - self->begin;
}


void stack_delete(stack_t *self)
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


bool stack_empty(stack_t *self)
{
	return self->top < self->begin;
}


void stack_print(stack_t *self)
{
    printf("\nStack:\n ");
    for (data_t *ch = self->top; ch >= self->begin; ch--)
        printf("%c ", *ch);
    printf("\n");
}