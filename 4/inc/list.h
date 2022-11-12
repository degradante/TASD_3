#ifndef _INC_LIST_H
#define _INC_LIST_H

#include "stack.h"

typedef struct cons
{
    data_t value;
    struct cons *next;
} cons_t;


typedef struct
{
    cons_t *top;
} list_t;

list_t *first_alloc_list(void);
void list_add(list_t *self, data_t character);
data_t list_pop(list_t *self);
void alloc_list(list_t *self);
void free_list(list_t *self);
void print_list(list_t *self);

#endif