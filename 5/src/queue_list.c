#include "queue_list.h"
#include <stdio.h>
#include <stdlib.h>


queue_list_t *queue_list_new()
{
    queue_list_t *self = calloc(1, sizeof(queue_list_t));
    self->begin = calloc(1, sizeof(node_t));
    self->begin->next = NULL;

    return self;
}


void queue_list_add(queue_list_t *self, data_t adding_value)
{
    node_t *new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->value = adding_value;

    node_t *temp_node;
    for(temp_node = self->begin; temp_node; ++temp_node)
        ;

    temp_node->next = new_node;
}


data_t queue_list_pop(queue_list_t *self)
{
    data_t val = self->begin->value;

    node_t *next = self->begin->next;
    free(self->begin);
    self->begin = next;

    return val;
}


bool queue_list_empty(queue_list_t *self)
{
    if (!self->begin)
        return true;
        
    return false;
}


void queue_list_delete(queue_list_t *self)
{
    while (self->begin)
    {
        node_t *next = self->begin->next;
        free(self->begin);
        self->begin = next;
    }
    free(self);
    self = NULL;
}


void queue_list_print(queue_list_t *self)
{
    node_t *node = self->begin;
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

    node_t *node = self->begin;
    for (; node; ++nodes_count)
        node = node->next;

    return sizeof(node_t) * nodes_count;
}
