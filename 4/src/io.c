#include "../inc/io.h"

bool read_elem(data_t *elem)
{
    int rc;

    printf("\nInput elem: ");
    rc = scanf("%c", elem);
    getchar();

    return rc == 1 ? true : false;
}


void print_user_guide(void)
{
    separator();
    printf(
        "\t Программа для работы со стеком "
        "\n"
        "\n"
        "     ");
}


void print_commands(void)
{
    separator();
    printf(
            "\t1. List add element\n"
            "\t2. List pop element\n"
            "\t3. List print\n"
            "\t4. Array add element\n"
            "\t5. Array pop element\n"
            "\t6. Array print\n"
            "\t7.\n"
            "\t8. Input string\n");
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
    printf("\n ══════════════════════════════════════════════════════════════════════════\n");
}