#include <stdlib.h>
#include "list.h"
#include "io.h"

list_t *list_new(void)
{
    list_t *self = (list_t*)calloc(1, sizeof(list_t));
    self->top = NULL;

    return self;
}


void list_push(list_t *self, data_t character)
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


bool list_empty(list_t *self)
{
    if (!self->top)
        return true;
        
    return false;
}


void list_free(list_t *self)
{
    while (self->top)
    {
        cons_t *next = self->top->next;
        free(self->top);
        self->top = next;
    }
    free(self);
    self = NULL;
}


void list_print(list_t *self)
{
    cons_t *cons = self->top;
    while (cons)
    {
        printf("%c\n", cons->value);
        cons = cons->next;
    }
}

