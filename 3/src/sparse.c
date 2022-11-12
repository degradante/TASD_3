#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "sparse.h"
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
    node_t *p_node = sparse->IA;
    for (size_t i = 0; i < matrix->n; ++i)
    {
        for (size_t j = 0; j < matrix->m; ++j)
            if (matrix->data[i][j] != 0)
            {
                if (p_node->value == EMPTY)
                    p_node->value = i_sparse;
                sparse->A[i_sparse] = matrix->data[i][j];
                sparse->JA[i_sparse++] = j;
            }
        p_node = p_node->next;
    }

    return NO_ERRS;
}


void nul_sparse(node_t *self)
{
    node_t *p_node = self;
    while (p_node)
    {
        p_node->value = EMPTY;
        p_node = p_node->next;
    }
}



int mul_sparse(sparse_t *m_sparse, sparse_t *v_sparse, sparse_t *res_sparse, matrix_t *res_matrix)
{
    if (!m_sparse->A || !v_sparse->A)
        return ERR_EMPTY;
    else if (m_sparse->m != v_sparse->n)
        return ERR_DIM;

    res_matrix->n = m_sparse->n;
    res_matrix->m = v_sparse->m;

    if (alloc_matrix(res_matrix) == ERR_ALLOC)
        return ERR_ALLOC;

    for (size_t j = 0; j < m_sparse->m; ++j)
    {
        int beg = node_get(m_sparse->IA, j);
        int end = node_get(m_sparse->IA, j + 1);
        for (int ind_node = beg; ind_node < end; ++ind_node)
            for (size_t j_vector = 0; j_vector < v_sparse->n; ++j_vector)
            {
                if (j == j_vector)
                {
                    res_matrix->data[0][j] += v_sparse->A[j_vector] * m_sparse->A[ind_node];
                    break;
                }
            }
    }

    if (alloc_sparse(res_sparse) == ERR_ALLOC || parse_matrix(res_matrix, res_sparse) != NO_ERRS)
        return ERR_ALLOC;

    return NO_ERRS;
}


int alloc_sparse(sparse_t *sparse)
{    
    sparse->A = calloc(sparse->count, sizeof(int));
    sparse->JA = calloc(sparse->count, sizeof(size_t));

    sparse->IA = first_alloc_node();
    for (size_t i = 0; i < sparse->n - 1; ++i)
        alloc_node(sparse->IA);

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
    free_node(sparse->IA);
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
        print_node(sparse->IA);
        puts("");
    }
}
