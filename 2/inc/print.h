#ifndef __PRINT_H__
#define __PRINT_H__

#define NO_ERRS     0
#define ERR_ARG -1
#define ERR_FILE_NAME -2

void print_user_guide(void);
void print_menu(void);
void print_error(int error_code);

#endif