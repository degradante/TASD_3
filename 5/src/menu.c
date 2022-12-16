#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "menu.h"
#include "queue_list.h"
#include "queue_array.h"
#include "io.h"


void main_loop(void)
{
    queue_list_t *queue_list = queue_list_new();
    queue_array_t *queue_array = queue_array_new(1024);
    char ch;
    
    short choise;
    do
    {
        print_menu();
        printf("\nchoise: ");
        read_choise(&choise);
        
        switch (choise)
        {
            case 1:
                if (read_char(&ch))
                    queue_array_add(queue_array, ch);
                else
                    printf("Error char input\n");
                break;
            case 2:
                if (queue_array_empty(queue_array))
                    printf("Error empty queue\n");
                else
                {
                    ch = queue_array_get(queue_array);
                    printf("Char: %c\n", ch);
                }
                break;
            case 3:
                queue_array_print(queue_array);
            case BTN_END:
                break;
                
            default:
                printf("Error command\n");
        }
    } while (choise != BTN_END);

    queue_list_delete(queue_list);
    queue_array_delete(queue_array);
}



void print_menu(void)
{
    separator();
    printf(
            "\t%2d. Array add\n"
            "\t%2d. Array pop\n"
            "\t%2d. Array print\n"
            "\t%2d. Exit\n",
             1,
             2,
             3,
             BTN_END
    );
}