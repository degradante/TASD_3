#include <stdlib.h>
#include "node.h"
#include "../inc/io.h"

int node_get(node_t *self, size_t ind)
{
    for (size_t i = 0; i < ind; ++i)
        self = self->next;
    
    return self->value;
}


node_t *first_alloc_node(void)
{
    node_t *self = (node_t*)calloc(1, sizeof(node_t));
    self->next = NULL;

    return self;
}


void alloc_node(node_t *self)
{
    while (self->next)
        self = self->next;
    node_t *now = (node_t*)calloc(1, sizeof(node_t));
    self->next = now;
}


void free_node(node_t *self)
{
    node_t *prev = NULL;
    while (self)
    {
        prev = self;
        self = self->next;
        free(prev);
        prev = NULL;
    }
}


void print_node(node_t *self)
{
    node_t *temp = self;
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

