#include <string.h>

#include "../inc/io.h"
#include "list.h"
#include "stack.h"

int brackets_check_stack(const char *str)
{
    int err_code = NO_ERRS;

    size_t len = strlen(str);
    stack_t *stack = stack_new(len + 1);

    for (size_t i = 0; i < len; ++i)
    {
        switch (str[i])
        {
            case '{':
                stack_push(stack, '}');
                break;
            case '(':
                stack_push(stack, ')');
                break;
            case '[':
                stack_push(stack, ']');
                break;
            case '}':
            case ')':
            case ']':
                if (stack_empty(stack) || stack_pop(stack) != str[i])
                    err_code = ERR_BRACKETS; 
                break;
            default:
                break;
        }   
    }

    if (!stack_empty(stack))
        err_code = ERR_BRACKETS;

    printf("Check with stack: ");
    !err_code ? puts("Correct") : puts("Invalid");

    // stack_print(stack);
    stack_delete(stack);

    return err_code;
}



int brackets_check_list(data_t *str)
{
    int err_code = NO_ERRS;

    list_t *list = list_new(); 

    for (size_t i = 0; str[i] && !err_code; ++i)
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

    printf("Check with list: ");
    !err_code ? puts("Correct") : puts("Invalid");
    //print_list(list);

    list_delete(list);
    
    return err_code;
}


