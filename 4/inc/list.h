#ifndef _INC_LIST_H
#define _INC_LIST_H

#include <stdbool.h>
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

list_t *list_new(void);
void list_push(list_t *self, data_t character);
data_t list_pop(list_t *self);
bool list_empty(list_t *self);
void list_free(list_t *self);
void list_print(list_t *self);

#endif