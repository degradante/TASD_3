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

    
    short choise;
    do
    {
        print_menu();
        printf("\nchoise: ");
        read_choise(&choise);
        
        switch (choise)
        {
            case BTN_LIST_ADD:
                printf("Input char: ");
                if (read_char(&elem_new))
                    list_push(list, elem_new);
                else
                    printf("\nInput error\n");
                break;

            case BTN_LIST_POP:
                if (!list_empty(list))
                    printf("Popped: %c\n", list_pop(list));
                else
                    printf("\nList is empty\n");
                break;

            case BTN_LIST_PRINT:
                if (!list_empty(list))
                    list_print(list);
                else
                    printf("\nList is empty\n");
                break;

            case BTN_LIST_MEMORY:
                printf("\nList stack size: %ld bytes\n", sizeof(list) + nodes_memsize(list));
                break;

            case BTN_STACK_ADD:
                printf("Input char: ");
                if (read_char(&elem_new))
                    stack_push(stack, elem_new);
                else
                    printf("\nInput error\n");
                break;

            case BTN_STACK_POP:
                if (!stack_empty(stack))
                    printf("Popped: %c\n", stack_pop(stack));
                else
                    printf("\nStack is empty\n");
                break;

            case BTN_STACK_PRINT:
                if (!stack_empty(stack))
                    stack_print(stack);
                else
                    printf("\nStack is empty\n");
                break;

            case BTN_STACK_MEMORY:
                printf("\nArray task size: %ld bytes\n", stack_memsize(stack_size(stack)));
                break;

            case BTN_BRACKETS_CHECK:
                fgets(str, 250 + 1, stdin);
                brackets_check_stack(str);
                brackets_check_list(str);
                break;

            case BTN_MEMORY_PROFILE:
                memory_profile();
                break;

            case BTN_TIME_PROFILE:
                time_profile();
                break;

            case BTN_END:
                break;
                
            default:
                printf("Error command\n");
        }
    } while (choise != BTN_END);

    list_delete(list);
    stack_delete(stack);
}



void print_menu(void)
{
    separator();
    printf(
            "\t%2d. List add element\n"
            "\t%2d. List pop element\n"
            "\t%2d. List print\n"
            "\t%2d. List memory\n"
            "\t%2d. Array add element\n"
            "\t%2d. Array pop element\n"
            "\t%2d. Array print\n"
            "\t%2d. Array memory\n"
            "\t%2d. Input string\n"
            "\t%2d. Profile memory\n"
            "\t%2d. Profile time\n"
            "\t%2d. Exit\n",
             BTN_LIST_ADD,
             BTN_LIST_POP,
             BTN_LIST_PRINT,
             BTN_LIST_MEMORY,
             BTN_STACK_ADD,
             BTN_STACK_POP,
             BTN_STACK_PRINT,
             BTN_STACK_MEMORY,
             BTN_BRACKETS_CHECK,
             BTN_MEMORY_PROFILE,
             BTN_TIME_PROFILE,
             BTN_END
    );
}