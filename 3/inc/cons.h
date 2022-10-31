#ifndef _INC_CONS_H
#define _INC_CONS_H

typedef struct cons
{
    int value;
    struct cons *next;
} cons_t;

cons_t *first_alloc_cons(void);
void alloc_cons(cons_t *self);
void free_cons(cons_t *self);
void print_cons(cons_t *self);

#endif