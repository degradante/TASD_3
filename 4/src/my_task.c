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



int brackets_check_list(data_t *str)
{
    int err_code = NO_ERRS;

    size_t len = strlen(str);
    list_t *list = list_new(); 

    size_t i = 0;
    for (i = 0; i < len && !err_code; ++i)
    {
        switch (str[i])
        {
            case '{':
                list_push(list, '}');
                break;
            case '(':
                list_push(list, ')');
                break;
            case '[':
                list_push(list, ']');
                break;
            case '}':
            case ')':
            case ']':
                if (list_empty(list) || list_pop(list) != str[i])
                    err_code = ERR_BRACKETS; 
                break;
            default:
                break;
        }      
    }
    
    if (!list_empty(list))
        err_code = ERR_BRACKETS;

    !err_code ? puts("Correct") : puts("Invalid");
    //print_list(list);

    list_free(list);
    
    return err_code;
}


