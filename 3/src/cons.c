#include <stdlib.h>
#include "cons.h"
#include "../inc/io.h"

int cons_get(cons_t *self, size_t ind)
{
    for (size_t i = 0; i < ind; ++i)
        self = self->next;
    
    return self->value;
}


cons_t *first_alloc_cons(void)
{
    cons_t *self = (cons_t*)calloc(1, sizeof(cons_t));
    self->next = NULL;

    return self;
}


void alloc_cons(cons_t *self)
{
    while (self->next)
        self = self->next;
    cons_t *now = (cons_t*)calloc(1, sizeof(cons_t));
    self->next = now;
}


void free_cons(cons_t *self)
{
    cons_t *prev = NULL;
    while (self)
    {
        prev = self;
        self = self->next;
        free(prev);
        prev = NULL;
    }
}


void print_cons(cons_t *self)
{
    cons_t *temp = self;
    while (temp)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

