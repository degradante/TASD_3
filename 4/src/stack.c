#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack_t stack_new(size_t size)
{
	stack_t self = { 0 };

	self.begin = calloc(size, sizeof(data_t));
	self.end = self.begin + size;
	self.pnow = self.begin - 1;

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
        free(self);
        self = NULL;
    }
}


int stack_empty(stack_t *self)
{
	return self->pnow < self->begin;
}


void stack_print(stack_t *self)
{
	if (stack_empty(self))
		puts("Stack is empty");
	else
    {
        puts("Stack is:");
        for (data_t *ch = self->pnow; ch >= self->begin; ch--)
            printf("%c ", *ch);
        printf("\n");
    }
}