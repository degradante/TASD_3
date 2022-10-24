#ifndef _INC_CHECK_TIME_H
#define _INC_CHECK_TIME_H

#include "operations.h"

size_t milliseconds_now(void);
int mark_time(matrix_t *matrix, vector_t *vector, matrix_t *result, 
sparse_matrix_t *m_sparse, sparse_vector_t *v_sparse, sparse_matrix_t *res_sparse);

#endif