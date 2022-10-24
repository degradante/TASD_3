#ifndef _INC_CHECK_H
#define _INC_CHECK_H

#include "stdbool.h"

#define MAX_MANTISSA_LEN 30
#define MAX_ORDER_LEN 5
#define MAX_ORDER  99999
#define MIN_ORDER -99999

#define NO_ERRS              0
#define ERROR_COUNT_E       -1
#define ERROR_COUNT_POINTS  -2
#define ERROR_COUNT_SIGNS   -3
#define ERROR_SIZE_MANTISSA -4
#define ERROR_TYPE_ORDER    -5
#define ERROR_CHAR          -6
#define ERROR_ZERO_DIVISION -7
#define ERROR_SIZE_ORDER    -8
#define ERROR_OVERFLOW      -9

typedef struct
{
    char sign;
    char mantissa[MAX_MANTISSA_LEN + 1 + 1];
    int order;
} exponential;

int check_input_float(char *number, char *type);
int normalize_result(exponential *number);
bool is_zero(char *mantissa);

#endif
