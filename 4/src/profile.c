#include <sys/time.h>
#include <time.h>
#include "profile.h"

int mark_time()
{
    size_t beg1, end1, beg2, end2;

    beg1 = milliseconds_now();
    int rc1 = mul_matrix(matrix, vector, result);
    end1 = milliseconds_now();

    beg2 = milliseconds_now();
    int rc2 = mul_sparse(m_sparse, v_sparse, res_sparse, result);
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

    return val.tv_sec * 1000000ULL + (size_t)val.tv_usec;
}