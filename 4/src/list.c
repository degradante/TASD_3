#include <stdlib.h>
#include "list.h"
#include "../inc/io.h"

list_t *first_alloc_list(void)
{
    list_t *self = (list_t*)calloc(1, sizeof(list_t));
    self->top = NULL;

    return self;
}


void list_add(list_t *self, data_t character)
{
    // if (self->top)
    cons_t *top = self->top; 
    cons_t *new = (cons_t*)calloc(1, sizeof(cons_t));
    new->value = character;
    self->top = new;
    self->top->next = top;
}


data_t list_pop(list_t *self)
{
    data_t val = self->top->value;

    cons_t *next = self->top->next;
    free(self->top);
    self->top = next;

    return val;
}


void list_free(list_t *self)
{
    cons_t *next = self->top->next;
    free(self->top);
    self->top = next;
}


void print_list(list_t *self)
{
    cons_t *cons = self->top;
    while (cons)
    {
        printf("%c\n", cons->value);
        cons = cons->next;
    }
}

