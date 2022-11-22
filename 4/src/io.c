#include "../inc/io.h"

void print_user_guide(void)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
        "\t Программа для работы со стеком "
        "\n"
        "\n"
        "     ");
}


void print_error(int error_code)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
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