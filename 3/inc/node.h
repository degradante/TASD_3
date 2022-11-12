#ifndef _INC_NODE_H
#define _INC_NODE_H

typedef struct node
{
    int value;
    struct node *next;
} node_t;

int node_get(node_t *self, size_t ind);
node_t *first_alloc_node(void);
void alloc_node(node_t *self);
void free_node(node_t *self);
void print_node(node_t *self);

#endif