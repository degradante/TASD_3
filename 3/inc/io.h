#ifndef _INC_IO_H
#define _INC_IO_H

#include "operations.h"

#define NO_ERRS          0
#define ERR_ARG         -1
#define ERR_FILE_NAME   -2
#define ERR_N_M         -3
#define ERR_ELEM        -4
#define ERR_EMPTY       -5
#define ERR_ALLOC       -6
#define ERR_DIM         -7

int input_matrix(matrix_t *matrix);
int input_vector(vector_t *vector);
int input_m_sparse(sparse_matrix_t *matrix);
int input_v_sparse(sparse_vector_t *vector);

int output_vector(vector_t *vector);
int output_matrix(matrix_t *matrix);
int output_m_sparse(sparse_matrix_t *matrix);
int output_v_sparse(sparse_vector_t *vector);

void print_user_guide(void);
void print_menu(void);
void print_error(int error_code);

#endif