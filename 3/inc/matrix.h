#ifndef _INC_MATRIX_H
#define _INC_MATRIX_H

typedef struct
{
    size_t n;
    size_t m;
    int **data;
} matrix_t;

int alloc_matrix(matrix_t *matrix);
void free_matrix(matrix_t *matrix);

int input_matrix(matrix_t *matrix);
int read_file_matrix(matrix_t *matrix, char *file_name);
int random_matrix(matrix_t *matrix, char *dim_n, char *dim_m, char *sparse_procent);
void output_matrix(matrix_t *matrix);

int mul_matrix(matrix_t *matrix, matrix_t *vector, matrix_t *result);

#endif