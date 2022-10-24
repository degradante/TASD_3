#ifndef _INC_ALLOC_H
#define _INC_ALLOC_H

#include "operations.h"

int alloc_matrix(matrix_t *matrix);
int alloc_vector(vector_t *vector);
int alloc_m_sparse(sparse_matrix_t *sparse);
int alloc_v_sparse(sparse_vector_t *sparse);

void free_matrix(matrix_t *matrix);
void free_vector(vector_t *vector);
void free_m_sparse(sparse_matrix_t *sparse);
void free_v_sparse(sparse_vector_t *sparse);

#endif