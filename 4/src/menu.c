#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "menu.h"
#include "stack.h"
#include "list.h"
#include "io.h"
#include "my_task.h"
#include "profile.h"

void main_loop(void)
{
    data_t str[250 + 1];
    data_t elem_new;

    list_t *list = list_new();
    stack_t *stack = stack_new(1024);

    
    char choise;
    do
    {
        print_commands();
        printf("\nchoise: ");
        read_char(&choise);
        
        switch (choise)
        {
            case '1':
                printf("Input char: ");
                if (read_char(&elem_new))
                    list_push(list, elem_new);
                else
                    printf("Input error\n");
                break;
            case '2':
                if (!list_empty(list))
                    printf("Popped: %c\n", list_pop(list));
                else
                    printf("\nList is empty\n");
                break;
            case '3':
                if (!list_empty(list))
                    list_print(list);
                else
                    printf("List is empty\n");
                break;
            case '4':
                printf("Input char: ");
                if (read_char(&elem_new))
                    stack_push(stack, elem_new);
                else
                    printf("Input error\n");
                break;
            case '5':
                if (!stack_empty(stack))
                    printf("Popped: %c\n", stack_pop(stack));
                else
                    printf("\nStack is empty\n");
                break;
            case '6':
                if (!stack_empty(stack))
                    stack_print(stack);
                else
                    printf("\nStack is empty\n");
                break;
            case '7':
                // TODO
                break;
            case '8':
                fgets(str, 250 + 1, stdin);
                brackets_check_stack(str);
                brackets_check_list(str);
                break;
            case '9':
                profile_time();
                break;
            default:
                printf("Error command\n");
            case '0':
                break;
        }
    } while (choise != '0');

    list_delete(list);
    stack_delete(stack);
}
