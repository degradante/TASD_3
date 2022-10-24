#include "operations.h"
#include "../inc/io.h"
#include "alloc.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PATH_STAND "./matrix_data/standart/"
#define EMPTY -1

int read_file_matrix(matrix_t *matrix, char *file_name)
{
    int rc = NO_ERRS;

    FILE *f = fopen(file_name, "r");
    if (!f)
        rc = ERR_FILE_NAME;
    else if (fscanf(f, "%lu%lu", &matrix->n, &matrix->m) != 2 || !matrix->n || !matrix->m)
        rc = ERR_N_M;
    else if (alloc_matrix(matrix) != NO_ERRS)
        rc = ERR_ALLOC;
    else
        for (size_t i = 0; i < matrix->n; ++i)
            for (size_t j = 0; j < matrix->m; ++j)
                if (fscanf(f, "%d", matrix->data[i] + j) != 1)// || (feof(f)))
                    rc = ERR_ELEM;

    if (f) fclose(f);

    return rc;
}


int read_file_vector(vector_t *vector, char *file_name)
{
    int rc = NO_ERRS;

    FILE *f = fopen(file_name, "r");
    if (!f)
        rc = ERR_FILE_NAME;
    else if (fscanf(f, "%lu", &vector->n) != 1 || !vector->n)
        rc = ERR_N_M;
    else if (alloc_vector(vector) != NO_ERRS)
        rc = ERR_ALLOC;
    else
        for (size_t i = 0; i < vector->n; ++i)
            if (fscanf(f, "%d", &vector->data[i]) != 1)// || (feof(f)))
                rc = ERR_ELEM;

    if (f) fclose(f);

    return rc;
}


int random_matrix(matrix_t *matrix, char *sizes, char *sparse_procent)
{
    matrix->n = strtoull(sizes, NULL, 10);
    matrix->m = strtoull(sizes, NULL, 10);
    int procent = strtol(sparse_procent, NULL, 10);
    if (matrix->n && matrix->m)
    {        
        if (alloc_matrix(matrix) == NO_ERRS)
        {
            int x;
            srand(time(NULL));
            for (size_t i = 0; i < matrix->n; ++i)
                for (size_t j = 0; j < matrix->m; ++j)
                {
                    if ((x = rand() % 100) > procent)
                        matrix->data[i][j] = rand() % 5 + 1;
                    else
                        matrix->data[i][j] = 0;
                }
        }
        else
            return ERR_ALLOC;
    }
    else
        return ERR_N_M;

    return NO_ERRS;
}


int random_vector(vector_t *vector, char *sizes, char *sparse_procent)
{
    vector->n = strtoull(sizes, NULL, 10);
    int procent = strtol(sparse_procent, NULL, 10);
    if (vector->n && procent >= 0)
    {        
        if (alloc_vector(vector) == NO_ERRS)
        {
            int x;
            //srand(time(NULL));
            for (size_t i = 0; i < vector->n; ++i)
            {
                if ((x = rand() % 100) > procent)
                    vector->data[i] = rand() % 5 + 1;
                else
                    vector->data[i] = 0;
            }
        }
        else
            return ERR_ALLOC;
    }
    else
        return ERR_N_M;

    return NO_ERRS;
}


int parse_matrix(matrix_t *matrix, sparse_matrix_t *sparse)
{
    if (!matrix->data)
        return ERR_EMPTY;

    for (size_t i = 0; i < matrix->n; ++i)
        for (size_t j = 0; j < matrix->m; ++j)
            if (matrix->data[i][j] != 0)
                sparse->count++;
    
    sparse->n = matrix->n;
    sparse->m = matrix->m;
    if (alloc_m_sparse(sparse) == ERR_ALLOC)
        return ERR_ALLOC;

    nul_sparse(sparse);
    size_t i_sparse = 0;
    for (size_t i = 0; i < matrix->n; ++i)
        for (size_t j = 0; j < matrix->m; ++j)
            if (matrix->data[i][j] != 0)
            {
                if (sparse->components[i] == EMPTY)
                    sparse->components[i] = i_sparse;
                sparse->data[i_sparse] = matrix->data[i][j];
                sparse->ind_cols[i_sparse] = j;
                ++i_sparse;
            }

    return NO_ERRS;
}


void nul_sparse(sparse_matrix_t *sparse)
{
    if (sparse->components)
        for (size_t i = 0; i < sparse->n; ++i)
            sparse->components[i] = EMPTY;
}


int parse_vector(vector_t *vector, sparse_vector_t *sparse)
{
    if (!vector->data)
        return ERR_EMPTY;

    for (size_t i = 0; i < vector->n; ++i)
        if (vector->data[i] != 0)
            sparse->count++;

    sparse->n = vector->n;
    if (alloc_v_sparse(sparse) == ERR_ALLOC)
        return ERR_ALLOC;

    size_t i_sparse = 0;
    for (size_t i = 0; i < vector->n; ++i)
        if (vector->data[i] != 0)
        {
            sparse->data[i_sparse] = vector->data[i];
            sparse->ind_cols[i_sparse] = i;
            ++i_sparse;
        }

    return NO_ERRS;
}


int mul_matrix(matrix_t *matrix, vector_t *vector, matrix_t *result)
{
    if (!matrix->data || !vector->data)
        return ERR_EMPTY;

    else if (matrix->m != vector->n)
        return ERR_DIM;

    result->n = matrix->n;
    result->m = 1;
    if (alloc_matrix(result) == ERR_ALLOC)
        return ERR_ALLOC;

    for (size_t i = 0; i < matrix->n; ++i)
        for (size_t j = 0; j < 1; ++j)
            for (size_t k = 0; k < matrix->m; ++k)
                result->data[i][j] += matrix->data[i][k] * vector->data[k];

    return NO_ERRS;
}


int mul_matrix_sparse(sparse_matrix_t *m_sparse, sparse_vector_t *v_sparse, sparse_matrix_t *result)
{
    int rc = NO_ERRS;

    if (!m_sparse->data || !v_sparse->data)
        rc = ERR_EMPTY;
    else if (m_sparse->m != v_sparse->n)
        rc = ERR_DIM;

    result->n = m_sparse->n;
    result->m = 1;
    result->count = m_sparse->count;
    if (alloc_m_sparse(result) == ERR_ALLOC)
        return ERR_ALLOC;

    for (size_t i = 0; i < m_sparse->n; ++i)
        for (int j = m_sparse->components[i]; j < m_sparse->components[i + 1]; ++j)
            if (v_sparse->data[m_sparse->ind_cols[j]])
            {
                result->data[i] += m_sparse->data[j] * v_sparse->data[m_sparse->ind_cols[j]];
            }

    return rc;
}

/* 0 1 -1 3
1 2
0 0
4 5
*/