#include <stdlib.h>
#include "list.h"
#include "io.h"

list_t *list_new(void)
{
    list_t *self = (list_t*)calloc(1, sizeof(list_t));
    self->top = NULL;

    return self;
}


void list_push(list_t *self, data_t pushing_char)
{
    node_t *top = self->top; 
    node_t *new_node = (node_t*)calloc(1, sizeof(node_t));
    new_node->value = pushing_char;
    self->top = new_node;
    self->top->next = top;
}


data_t list_pop(list_t *self)
{
    data_t val = self->top->value;

    node_t *next = self->top->next;
    free(self->top);
    self->top = next;

    return val;
}


bool list_empty(list_t *self)
{
    if (!self->top)
        return true;
        
    return false;
}


void list_delete(list_t *self)
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


void list_print(list_t *self)
{
    node_t *node = self->top;
    printf("\nList:\n ");
    while (node)
    {
        printf("%c ", node->value);
        node = node->next;
    }
}

