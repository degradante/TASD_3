#include "queue_list.h"
#include <stdio.h>
#include <stdlib.h>


queue_list_t *queue_list_new()
{
    queue_list_t *self = calloc(1, sizeof(queue_list_t));
    self->top = calloc(1, sizeof(node_t));

    return self;
}


void queue_list_add(queue_list_t *self, data_t pushing_value)
{
    node_t *top = self->top; 
    node_t *new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->value = pushing_value;
    self->top = new_node;
    self->top->next = top;
}


data_t queue_list_pop(queue_list_t *self)
{
    data_t val = self->top->value;

    node_t *next = self->top->next;
    free(self->top);
    self->top = next;

    return val;
}


bool queue_list_empty(queue_list_t *self)
{
    if (!self->top)
        return true;
        
    return false;
}


void queue_list_delete(queue_list_t *self)
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


void queue_list_print(queue_list_t *self)
{
    node_t *node = self->top;
    printf("\nqueue_list:\n ");
    while (node)
    {
        printf("%c ", node->value);
        node = node->next;
    }
}


size_t queue_list_memsize(size_t size)
{
	return sizeof(queue_list_t) + sizeof(node_t) * size;
}


size_t nodes_memsize(queue_list_t *self)
{
    size_t nodes_count = 0;

    node_t *node = self->top;
    for (; node; ++nodes_count)
        node = node->next;

    return sizeof(node_t) * nodes_count;
}
