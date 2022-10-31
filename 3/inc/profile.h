#ifndef _INC_PROFILE_H
#define _INC_PROFILE_H

#include "matrix.h"
#include "sparse.h"
#include "../inc/io.h"

size_t milliseconds_now(void);
int mark_time(matrix_t *matrix, matrix_t *vector, matrix_t *result, sparse_t *m_sparse, sparse_t *v_sparse, sparse_t *res_sparse);

#endif