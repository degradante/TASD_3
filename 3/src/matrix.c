#include <stdlib.h>
#include <time.h>
#include "../inc/io.h"
#include "matrix.h"

int input_matrix(matrix_t *matrix)
{
    printf("Input n & m: ");

    if (scanf("%lu%lu", &matrix->n, &matrix->m) == 2 && matrix->n && matrix->m)
    {        
        if (alloc_matrix(matrix) == NO_ERRS)
        {
            for (size_t i = 0; i < matrix->n; ++i)
                for (size_t j = 0; j < matrix->m; ++j)
                    if (scanf("%d", &matrix->data[i][j]) != 1)
                        return ERR_ELEM;
        }
        else
            return ERR_ALLOC;
    }
    else
        return ERR_N_M;

    return NO_ERRS;
}



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


int random_matrix(matrix_t *matrix, char *dim_n, char *dim_m, char *sparse_procent)
{
    matrix->n = strtoull(dim_n, NULL, 10);
    matrix->m = strtoull(dim_m, NULL, 10);
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


int mul_matrix(matrix_t *matrix, matrix_t *vector, matrix_t *res_sparse)
{
    if (!matrix->data || !vector->data)
        return ERR_EMPTY;

    else if (matrix->m != vector->n)
        return ERR_DIM;

    res_sparse->n = matrix->n;
    res_sparse->m = vector->m;
    if (alloc_matrix(res_sparse) == ERR_ALLOC)
        return ERR_ALLOC;

    for (size_t i = 0; i < matrix->n; ++i)
        for (size_t j = 0; j < vector->m; ++j)
            for (size_t k = 0; k < matrix->m; ++k)
                res_sparse->data[i][j] += matrix->data[i][k] * vector->data[k][j];

    return NO_ERRS;
}


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


void free_matrix(matrix_t *matrix)
{
    if (matrix->data)
    {
        for (size_t i = 0; i < matrix->n; ++i)
            if (matrix->data[i])
                free(matrix->data[i]);

        free(matrix->data);
        matrix->data = NULL;
    }
    matrix->n = matrix->m = 0;
}


void output_matrix(matrix_t *matrix)
{
    if (matrix->data && matrix->n && matrix->m)
    {
        for (size_t i = 0; i < matrix->n; ++i)
        {
            for (size_t j = 0; j < matrix->m; ++j)
                printf("%d ", matrix->data[i][j]);
            puts("");
        }
        puts("");
    }
}

