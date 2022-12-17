#include <string.h>

#include "../inc/io.h"
#include "stack_list.h"
#include "stack_array.h"
#include "my_task.h"

int brackets_check_stack_array(const char *str)
{
    int err_code = NO_ERRS;

    size_t len = strlen(str);
    stack_array_t *stack_array = stack_array_new(len + 1);

    for (size_t i = 0; i < len; ++i)
    {
        switch (str[i])
        {
            case '{':
                stack_array_push(stack_array, '}');
                break;
            case '(':
                stack_array_push(stack_array, ')');
                break;
            case '[':
                stack_array_push(stack_array, ']');
                break;
            case '}':
            case ')':
            case ']':
                if (stack_array_empty(stack_array) || stack_array_pop(stack_array) != str[i])
                    err_code = ERR_BRACKETS; 
                break;
            default:
                break;
        }   
    }

    if (!stack_array_empty(stack_array))
        err_code = ERR_BRACKETS;

    printf("Check with stack_array: ");
    !err_code ? puts("Correct") : puts("Invalid");

    // stack_array_print(stack_array);
    stack_array_delete(stack_array);

    return err_code;
}


int brackets_check_stack_list(data_t *str)
{
    int err_code = NO_ERRS;

    stack_list_t *stack_list = stack_list_new(); 

    for (size_t i = 0; str[i] && !err_code; ++i)
    {
        switch (str[i])
        {
            case '{':
                stack_list_push(stack_list, '}');
                break;
            case '(':
                stack_list_push(stack_list, ')');
                break;
            case '[':
                stack_list_push(stack_list, ']');
                break;
            case '}':
            case ')':
            case ']':

                if (stack_list_empty(stack_list) || stack_list_pop(stack_list) != str[i])
                    err_code = ERR_BRACKETS; 
                break;
            default:
                break;
        }      
    }
    
    if (!stack_list_empty(stack_list))
        err_code = ERR_BRACKETS;

    printf("Check with stack_list: ");
    !err_code ? puts("Correct") : puts("Invalid");
    //print_stack_list(stack_list);

    stack_list_delete(stack_list);
    
    return err_code;
}


