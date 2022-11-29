#ifndef _INC_IO_H
#define _INC_IO_H

#include <stdio.h>
#include "stack.h"

enum { 
    NO_ERRS,
    ERR_ARG,
    ERR_FILE_NAME,
    ERR_BRACKETS,
    ERR_ELEM,
    ERR_EMPTY,
    ERR_ALLOC,
    ERR_DIM,
};

bool read_char(data_t *elem);
void separator(void);
void print_user_guide(void);
void print_commands(void);
void print_menu(void);
void print_error(int error_code);

#endif