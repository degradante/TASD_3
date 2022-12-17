#include <stdlib.h>
#include "stack_list.h"
#include "io.h"
#include "my_memory.h"

stack_list_t *stack_list_new(void)
{
    stack_list_t *self = (stack_list_t*)calloc(1, sizeof(stack_list_t));
    self->top = NULL;

    return self;
}


void stack_list_push(stack_list_t *self, data_t pushing_char)
{
    node_t *top = self->top; 
    node_t *new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->value = pushing_char;
    self->top = new_node;
    self->top->next = top;
}


data_t stack_list_pop(stack_list_t *self)
{
    data_t val = self->top->value;

    if (LOG_DELETED)
		log_delete(self->top);

    node_t *next = self->top->next;
    free(self->top);
    self->top = next;

    return val;
}


bool stack_list_empty(stack_list_t *self)
{
    if (!self->top)
        return true;
        
    return false;
}


void stack_list_delete(stack_list_t *self)
{
    while (self->top)
    {
        node_t *next = self->top->next;
        free(self->top);
        self->top = next;
    }
    free(self);
    self = NULL;
}


void stack_list_print(stack_list_t *self)
{
    node_t *node = self->top;
    printf("\nstack_list:\n ");
    while (node)
    {
        printf("%c ", node->value);
        node = node->next;
    }
}


size_t stack_list_memsize(size_t size)
{
	return sizeof(stack_list_t) + sizeof(node_t) * size;
}


size_t nodes_memsize(stack_list_t *self)
{
    size_t nodes_count = 0;

    node_t *node = self->top;
    for (; node; ++nodes_count)
        node = node->next;

    return sizeof(node_t) * nodes_count;
}
