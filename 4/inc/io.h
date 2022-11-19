#ifndef _INC_IO_H
#define _INC_IO_H

#include <stdio.h>

#define NO_ERRS          0
#define ERR_ARG         -1
#define ERR_FILE_NAME   -2
#define ERR_BRACKETS    -3
#define ERR_ELEM        -4
#define ERR_EMPTY       -5
#define ERR_ALLOC       -6
#define ERR_DIM         -7

void print_user_guide(void);
void print_menu(void);
void print_error(int error_code);

#endif