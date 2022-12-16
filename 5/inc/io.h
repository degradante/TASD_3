#ifndef _INC_IO_H
#define _INC_IO_H

#include <stdio.h>
#include "queue_array.h"

enum { 
    NO_ERRS,
    ERR_ARG,
    ERR_FILE_NAME,
    ERR_BRACKETS,
    ERR_ELEM,
    ERR_EMPTY,
    ERR_ALLOC,
    ERR_DIM,
} error_t;

bool read_choise(short *value);

bool read_char(data_t *elem);

void separator();

void print_user_guide();

void print_error(int error_code);


#endif