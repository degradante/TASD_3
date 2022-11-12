#include "../inc/io.h"

void print_error(int error_code)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
        "\n"
        "\n"
        "     ");
    switch(error_code)
    {
         case ERR_ARG:
            puts("Error: usage app.exe type i/f/r\n");
            break;
        case ERR_N_M:
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