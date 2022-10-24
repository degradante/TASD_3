#ifndef _INC_OPERATIONS_H
#define _INC_OPERATIONS_H

#include <stdio.h>


typedef struct
{
    size_t n;
    int *data;
} vector_t;


typedef struct
{
    size_t n;
    size_t m;
    int **data;
} matrix_t;


typedef struct
{
    size_t n;
    size_t count;
    size_t *ind_cols;
    int *data;
} sparse_vector_t;


typedef struct
{
    size_t n;
    size_t m;
    size_t count;
    size_t *ind_cols;
    int *data;
    int *components;
} sparse_matrix_t;


int read_file_matrix(matrix_t *matrix, char *file_name);
int random_matrix(matrix_t *matrix, char *sizes, char *sparse_procent);

int read_file_vector(vector_t *vector, char *file_name);
int random_vector(vector_t *vector, char *sizes, char *sparse_procent);

int parse_matrix(matrix_t *matrix, sparse_matrix_t *sparse);
void nul_sparse(sparse_matrix_t *sparse);
int parse_vector(vector_t *vector, sparse_vector_t *sparse);

int mul_matrix_sparse(sparse_matrix_t *matrix, sparse_vector_t *vector, sparse_matrix_t *result);
int mul_matrix(matrix_t *matrix, vector_t *vector, matrix_t *result);

#endif