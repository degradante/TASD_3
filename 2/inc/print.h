#ifndef _INC_PRINT_H
#define _INC_PRINT_H

#include <stdio.h>

#define NO_ERRS     0
#define ERR_NO_ARG -1
#define ERR_FILE_NAME -2

void print_user_guide(void);
void print_menu(void);
void print_error(int error_code);

#endif