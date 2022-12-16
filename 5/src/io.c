#include "../inc/io.h"

bool read_char(data_t *elem)
{
    int rc = scanf("%c", elem);

    char garbage;
    while ((garbage = getchar()) != EOF && garbage != '\n')
            ;

    return rc == 1 ? true : false;
}


bool read_choise(short *value)
{
    int rc = scanf("%hd", value);

    char garbage;
    while ((garbage = getchar()) != EOF && garbage != '\n')
            ;

    return rc == 1 ? true : false;
}


void print_user_guide(void)
{
    separator();
    printf(
        "%80s\n",
        "Программа для работы с очередями"
        );
}


void print_error(int error_code)
{
    separator();
    printf(
        "\n"
        "\n"
        "     ");
    switch(error_code)
    {
        case ERR_BRACKETS:
            puts("Error: invalid matrix size\n");
            break;
        case ERR_DIM:
            puts("Error: inalid dimensions\n");
            break;
        case ERR_ELEM:
            puts("Error: invalid elem\n");
            break;
        case ERR_EMPTY:
            puts("Error: matrix is empty\n");
            break;
        case ERR_ALLOC:
            puts("Error: memory dont allocated\n");
            break;
    }
}


void separator(void)
{
    printf("\n");
    for (size_t i = 0; i < 80; ++i) 
        printf("═");
    printf("\n");
}