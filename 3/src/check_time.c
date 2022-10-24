#include <sys/time.h>
#include <time.h>
#include "../inc/check_time.h"

int mark_time(matrix_t *matrix, vector_t *vector, matrix_t *result, 
sparse_matrix_t *m_sparse, sparse_vector_t *v_sparse, sparse_matrix_t *res_sparse)
{
    size_t beg1, end1, beg2, end2;

    beg1 = milliseconds_now();
    int rc1 = mul_matrix(matrix, vector, result);
    end1 = milliseconds_now();

    beg2 = milliseconds_now();
    int rc2 = mul_matrix_sparse(m_sparse, v_sparse, res_sparse);
    end2 = milliseconds_now();

    if (!rc1 && !rc2)
        printf("Milliseconds1: %lu\nMilliseconds2: %lu\n", end1 - beg1, end2 - beg2);

    return 0;
}


size_t milliseconds_now(void)
{
    struct timeval val;

    gettimeofday(&val, NULL);
        //return (size_t) -1;

    return val.tv_sec * 1000ULL + (size_t)val.tv_usec;
}