#include <string.h>
#include "../inc/io.h"
#include "list.h"
#include "stack.h"

/*
int brackets_check_array(const char *str)
{
    size_t len = strlen(str);
    stack_t stack = alloc_stack(len + 1);

    for (size_t i = 0; i < len; ++i)
    {
        stack.pnow++;
        stack.pnow = 
    }

    return NO_ERRS;
} */



int brackets_check_list(char *str)
{
    int rc = NO_ERRS;

    size_t len = strlen(str);
    list_t *list = first_alloc_list(); 

    size_t i = 0;
    for (i = 0; i < len; ++i)
    {
        if (str[i] != '}' && str[i] != ')' && str[i] != ']')
            list_add(list, str[i]);
    }
    
    print_list(list);

    free_list(list);
    
    return rc;
}


