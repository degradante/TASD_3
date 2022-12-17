#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "menu.h"
#include "stack_array.h"
#include "stack_list.h"
#include "io.h"
#include "my_task.h"
#include "my_memory.h"
#include "profile.h"

void main_loop(void)
{
    data_t str[250 + 1];
    data_t elem_new;

    stack_list_t *stack_list = stack_list_new();
    stack_array_t *stack_array = stack_array_new(1024);

    
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
                    stack_list_push(stack_list, elem_new);
                else
                    printf("\nInput error\n");
                break;

            case BTN_LIST_POP:
                if (!stack_list_empty(stack_list))
                    printf("Popped: %c\n", stack_list_pop(stack_list));
                else
                    printf("\nList is empty\n");
                break;

            case BTN_LIST_PRINT:
                if (!stack_list_empty(stack_list))
                    stack_list_print(stack_list);
                else
                    printf("\nList is empty\n");
                break;

            case BTN_LIST_MEMORY:
                printf("\nList stack_array size: %ld bytes\n", sizeof(stack_list) + nodes_memsize(stack_list));
                break;

            case BTN_ARRAY_ADD:
                printf("Input char: ");
                if (read_char(&elem_new))
                    stack_array_push(stack_array, elem_new);
                else
                    printf("\nInput error\n");
                break;

            case BTN_ARRAY_POP:
                if (!stack_array_empty(stack_array))
                    printf("Popped: %c\n", stack_array_pop(stack_array));
                else
                    printf("\nstack_array is empty\n");
                break;

            case BTN_ARRAY_PRINT:
                if (!stack_array_empty(stack_array))
                    stack_array_print(stack_array);
                else
                    printf("\nstack_array is empty\n");
                break;

            case BTN_ARRAY_MEMORY:
                printf("\nArray task size: %ld bytes\n", stack_array_memsize(stack_array_size(stack_array)));
                break;

            case BTN_BRACKETS_CHECK:
                fgets(str, 250 + 1, stdin);
                brackets_check_stack_array(str);
                brackets_check_stack_list(str);
                break;

            case BTN_DELETED_ADRESSES:
                log_print_deleted_addresses();
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

    stack_list_delete(stack_list);
    stack_array_delete(stack_array);
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
            "\t%2d. Log deleted adresses\n"
            "\t%2d. Profile memory\n"
            "\t%2d. Profile time\n"
            "\t%2d. Exit\n",
             BTN_LIST_ADD,
             BTN_LIST_POP,
             BTN_LIST_PRINT,
             BTN_LIST_MEMORY,
             BTN_ARRAY_ADD,
             BTN_ARRAY_POP,
             BTN_ARRAY_PRINT,
             BTN_ARRAY_MEMORY,
             BTN_BRACKETS_CHECK,
             BTN_DELETED_ADRESSES,
             BTN_MEMORY_PROFILE,
             BTN_TIME_PROFILE,
             BTN_END
    );
}