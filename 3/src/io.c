
#include <stdlib.h>
#include "../inc/io.h"
#include "alloc.h"

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


int input_vector(vector_t *vector)
{
    printf("Input n: ");

    if (scanf("%lu", &vector->n) == 1 && vector->n)
    {        
        if (alloc_vector(vector) == NO_ERRS)
        {
            for (size_t i = 0; i < vector->n; ++i)
                if (scanf("%d", &vector->data[i]) != 1)
                    return ERR_ELEM;
        }
        else
            return ERR_ALLOC;
    }
    else
        return ERR_N_M;

    return NO_ERRS;
}


int output_matrix(matrix_t *matrix)
{
    if (!matrix->data || !matrix->n || !matrix->m)
        return ERR_EMPTY;

    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
            printf("%d ", matrix->data[i][j]);
        puts("");
    }
    puts("");

    return NO_ERRS;
}


int output_vector(vector_t *vector)
{
    if (!vector->data || !vector->n)
        return ERR_EMPTY;

    for (size_t i = 0; i < vector->n; ++i)
        printf("%d ", vector->data[i]);
    puts("");

    return NO_ERRS;
}


int input_m_sparse(sparse_matrix_t *matrix)
{
    puts("Input n, m:");
    scanf("%lu", &matrix->n);

    return NO_ERRS;
}


int input_v_sparse(sparse_vector_t *vector)
{
    puts("Input n:");
    scanf("%lu", &vector->n);

    return NO_ERRS;
}


int output_m_sparse(sparse_matrix_t *sparse)
{
    if (!sparse->data || !sparse->count || !sparse->n || !sparse->components || !sparse->ind_cols)
        return ERR_EMPTY;
    
    printf("\nA:\n ");
    for (size_t i = 0; i < sparse->count; ++i)
        printf("%d ", sparse->data[i]);

    printf("\nJA:\n ");
    for (size_t i = 0; i < sparse->count; ++i)
        printf("%lu ", sparse->ind_cols[i]);

    printf("\nNk:\n ");
    for (size_t i = 0; i < sparse->n; ++i)
        printf("%d ", sparse->components[i]);
    puts("");

    return NO_ERRS;
}


int output_v_sparse(sparse_vector_t *sparse)
{
    if (!sparse->count || !sparse->data || !sparse->ind_cols)
        return ERR_EMPTY;
    
    printf("\nA:\n ");
    for (size_t i = 0; i < sparse->count; ++i)
        printf("%d ", sparse->data[i]);

    printf("\nJA:\n ");
    for (size_t i = 0; i < sparse->count; ++i)
        printf("%lu ", sparse->ind_cols[i]);
    puts("");

    return NO_ERRS;
}


void print_error(int error_code)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
        "\n"
        "\n"
        "     ");
    switch(error_code)
    {
         case ERR_ARG:
            puts("Error: usage app.exe type i/f/r\n");
            break;
        case ERR_N_M:
            puts("Error: invalid matrix size\n");
            break;
        case ERR_ELEM:
            puts("Error: invalid elem\n");
            break;
        case ERR_EMPTY:
            puts("Error: matrix is empty\n");
            break;
        case ERR_ALLOC:
            puts("Error: memory dont allocated\n");
            break;
    }
}