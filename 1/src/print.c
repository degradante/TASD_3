#include "check.h"
#include "print.h"

void print_user_guide(void)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
           "\n"
           "   • Данная программа выполняет операцию деления двух вещественных чисел.\n"
           "   • Дробная и целая части должны быть разделены точкой.\n"
           "   • Допустимые символы: '-', '+', '.', 'e', 'E' (латинские буквы).\n"
           "   • Длина манттиссы - не более 30 символов; порядка - не более 5 \n"
           "         (порядок - целое число в интервале [-99999; 99999]).\n"
           "\n");
}


void print_normalize(exponential *number)
{
    print_with_border("Result");
    printf("\r\t  %c0.%se%d\n", number->sign, number->mantissa, number->order);
}


void print_with_border(char *str)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
           "\n"
           "    %s:\n"
           "\n"
           "\t     1       10        20        30        40                     \n"
           "\t     |--------|---------|---------|---------|                     \n"
           "\t     ", str);


}


void print_error(int error_code)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
           "\n"
           "\n"
           "     ");
    switch(error_code)
    {
        case ERROR_COUNT_E:
            printf("Error: too much 'e'\n");
            break;
        case ERROR_COUNT_POINTS:
            printf("Error: too much points\n");
            break;
        case ERROR_COUNT_SIGNS:
            printf("Error: incorrect sign\n");
            break;
        case ERROR_SIZE_MANTISSA:
            printf("Error: mantissa cant be > 30 symbols\n");
            break;
        case ERROR_TYPE_ORDER:
            printf("Error: order must be digit\n");
            break;
        case ERROR_CHAR:
            printf("Error: incorrect symbol\n");
            break;
        case ERROR_ZERO_DIVISION:
            printf("Error: zero division\n");
            break;
        case ERROR_SIZE_ORDER:
            printf("Error: order must be [-99999; 99999]\n");
            break;
        case ERROR_OVERFLOW:
            printf("Error: order was overflowed after division\n");
            break;
        default:
            break;
    }
    printf("\n"
           "\n"
           " ══════════════════════════════════════════════════════════════════════════\n");
}