#include <stdlib.h>
#include "alloc.h"
#include "../inc/io.h"

int alloc_matrix(matrix_t *matrix)
{
    matrix->data = calloc(matrix->n, sizeof(int *));
    if (!matrix->data)
        return ERR_ALLOC;

    for (size_t i = 0; i < matrix->n; ++i)
    {
        matrix->data[i] = calloc(matrix->m, sizeof(int));
        if (!matrix->data[i])
            return ERR_ALLOC;
    }

    return NO_ERRS;
}


int alloc_vector(vector_t *vector)
{
    vector->data = calloc(vector->n, sizeof(int));
    if (!vector->data)
        return ERR_ALLOC;

    return NO_ERRS;
}


int alloc_m_sparse(sparse_matrix_t *sparse)
{    
    sparse->data = calloc(sparse->count, sizeof(int));
    sparse->ind_cols = calloc(sparse->count, sizeof(size_t));
    sparse->components = calloc(sparse->n, sizeof(int));

    if(!sparse->data || !sparse->ind_cols || !sparse->components)
    {
        free_m_sparse(sparse);
        return ERR_ALLOC;
    }
    
    return NO_ERRS;
}


int alloc_v_sparse(sparse_vector_t *sparse)
{    
    sparse->data = calloc(sparse->count, sizeof(int));
    sparse->ind_cols = calloc(sparse->count, sizeof(size_t));
    if (!sparse->data || !sparse->ind_cols)
    {
        free_v_sparse(sparse);
        return ERR_ALLOC;
    }
    
    return NO_ERRS;
}


void free_matrix(matrix_t *matrix)
{
    if (matrix->data)
    {
        for (size_t i = 0; i < matrix->n; ++i)
            if (matrix->data[i])
                free(matrix->data[i]);

        free(matrix->data);
    }
    matrix->data = NULL;
    matrix->n = matrix->m = 0;
}


void free_vector(vector_t *vector)
{
    if (vector->data)
        free(vector->data);
    vector->data = NULL;
    vector->n = 0;
}


void free_m_sparse(sparse_matrix_t *sparse)
{
    if (sparse->data)
        free(sparse->data);
    if (sparse->ind_cols)
        free(sparse->ind_cols);
    if (sparse->components)
        free(sparse->components);

    sparse->data = NULL;
    sparse->ind_cols = NULL;
    sparse->components = NULL;
    sparse->n = 0;
    sparse->m = 0;
    sparse->count = 0;
}


void free_v_sparse(sparse_vector_t *sparse)
{
    if (sparse->data)
        free(sparse->data);
    if (sparse->ind_cols)
        free(sparse->ind_cols);

    sparse->data = NULL;
    sparse->ind_cols = NULL;
    sparse->n = 0;
    sparse->count = 0;
}
