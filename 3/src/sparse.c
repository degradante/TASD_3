#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sparse.h"
#include "cons.h"
#include "../inc/io.h"

#define PATH_STAND "./matrix_data/standart/"
#define EMPTY -1


int parse_matrix(matrix_t *matrix, sparse_t *sparse)
{
    if (!matrix->data)
        return ERR_EMPTY;

    for (size_t i = 0; i < matrix->n; ++i)
        for (size_t j = 0; j < matrix->m; ++j)
            if (matrix->data[i][j] != 0)
                sparse->count++;
    
    sparse->n = matrix->n;
    sparse->m = matrix->m;
    if (alloc_sparse(sparse) == ERR_ALLOC)
        return ERR_DIM;

    nul_sparse(sparse->IA);
    size_t i_sparse = 0;
    cons_t *p_cons = sparse->IA;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
            if (matrix->data[i][j] != 0)
            {
                if (p_cons->value == EMPTY)
                    p_cons->value = i_sparse;
                sparse->A[i_sparse] = matrix->data[i][j];
                sparse->JA[i_sparse++] = j;
            }
        p_cons = p_cons->next;
    }

    return NO_ERRS;
}


void nul_sparse(cons_t *self)
{
    cons_t *p_cons = self;
    while (p_cons)
    {
        p_cons->value = EMPTY;
        p_cons = p_cons->next;
    }
}



int mul_sparse(sparse_t *m_sparse, sparse_t *v_sparse, sparse_t *res_sparse, matrix_t *res_matrix)
{
    if (!m_sparse->A || !v_sparse->A)
        return ERR_EMPTY;
    else if (m_sparse->m != v_sparse->n)
        return ERR_DIM;

    res_matrix->n = m_sparse->n;
    res_matrix->m = 1;

    if (alloc_matrix(res_matrix) == ERR_ALLOC)
        return ERR_ALLOC;

    for (size_t i = 0; i < m_sparse->n; ++i)
        res_sparse->m++;

    if (parse_matrix(res_matrix, res_sparse) != NO_ERRS)
        return ERR_ALLOC;

    return NO_ERRS;
}


int alloc_sparse(sparse_t *sparse)
{    
    sparse->A = calloc(sparse->count, sizeof(int));
    sparse->JA = calloc(sparse->count, sizeof(size_t));

    sparse->IA = first_alloc_cons();
    for (size_t i = 0; i < sparse->n - 1; ++i)
        alloc_cons(sparse->IA);

    if (!sparse->A || !sparse->JA || !sparse->IA)
    {
        free_sparse(sparse);
        return ERR_ALLOC;
    }
    
    return NO_ERRS;
}


void free_sparse(sparse_t *sparse)
{
    free(sparse->A);
    free(sparse->JA);
    free_cons(sparse->IA);
    sparse->A = NULL;
    sparse->JA = NULL;
    sparse->IA = NULL;
    sparse->n = 0;
    sparse->m = 0;
    sparse->count = 0;
}


int input_sparse(sparse_t *matrix)
{
    puts("Input n, m:");
    scanf("%lu", &matrix->n);

    return NO_ERRS;
}


void output_sparse(sparse_t *sparse)
{
    if (sparse->A && sparse->IA && sparse->JA)
    {
        printf("\nA:\n ");
        for (size_t i = 0; i < sparse->count; ++i)
            printf("%d ", sparse->A[i]);

        printf("\nJA:\n ");
        for (size_t i = 0; i < sparse->count; ++i)
            printf("%lu ", sparse->JA[i]);

        printf("\nNk:\n ");
        print_cons(sparse->IA);
        puts("");
    }
}
