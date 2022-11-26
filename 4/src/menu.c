#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include "stack.h"
#include "list.h"
#include "io.h"
#include "my_task.h"

void main_loop(void)
{
    data_t str[250 + 1];
    data_t elem_new;

    list_t *list = list_new();
    stack_t *stack = stack_new(1024);

    
    char choise, garbage;
    do
    {
        print_commands();
        scanf("%c", &choise);
        while ((garbage = getchar()) != EOF && garbage != '\n')
            ;

        switch (choise)
        {
            case '1':
                if (read_elem(&elem_new))
                    list_push(list, elem_new);
                break;
            case '2':
                if (!list_empty(list))
                    list_pop(list);
                break;
            case '3':
                list_print(list);
                break;
            case '4':
                if (read_elem(&elem_new))
                    stack_push(stack, elem_new);
                break;
            case '5':
                if (!stack_empty(stack))
                    stack_pop(stack);
                break;
            case '6':
                stack_print(stack);
                break;
            case '7':
                // TODO
                break;
            case '8':
                fgets(str, 250 + 1, stdin);
                brackets_check_list(str);
                brackets_check_array(str);
                break;
            default:
                break;
        }
    } while (choise != '0');

    list_delete(list);
    stack_delete(stack);
}