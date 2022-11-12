#include <stdio.h>
#include <assert.h>
#include "menu.h"
#include "my_task.h"

void main_loop(void)
{
   // char rabbish;
    char str[250 + 1];
    printf( "\t1. Input string\n"
            "\t2.\n"
            "\t3.\n"
            "\t4.\n"
            "\t5.\n"
            "\t6.\n"
            "\t7.\n");
    
    char choise;
    scanf("%c", &choise);
    getchar();
    switch (choise)
    {
        case '1':
            fgets(str, 250 + 1, stdin);
            brackets_check_list(str);
            break;
        default:
            puts("Err\n");
            break;
    }

}