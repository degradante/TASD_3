#ifndef _INC_SPARSE_H
#define _INC_SPARSE_H

#include <stddef.h>
#include "node.h"
#include "matrix.h"

typedef struct
{
    size_t n;
    size_t m;
    size_t count;
    int *A;
    size_t *JA;
    node_t *IA;
} sparse_t;

int alloc_sparse(sparse_t *sparse);
void free_sparse(sparse_t *sparse);

int input_sparse(sparse_t *matrix);
void output_sparse(sparse_t *matrix);

int parse_matrix(matrix_t *matrix, sparse_t *sparse);
void nul_sparse(node_t *self);
int mul_sparse(sparse_t *matrix, sparse_t *vector, sparse_t *result, matrix_t *result_standart);

#endif