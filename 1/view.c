#include "check.h"
#include "print.h"
#include "view.h"
#include "division.h"
#include <string.h>


void to_exponential(char *str, exponential *number)
{
    char *p_num, *p_point, *p_e;

    if (str[0] == '-')
        number->sign = '-';
    
    p_e = strpbrk(str, "eE");
    if (p_e)
    {
        number->order = strtod((p_e + 1), NULL);
        *p_e = '\0';
    }

    p_point = strchr(str, '.');
    // 12345
    if (!p_point)
    {
        p_num = strtok(str, "+-");
        strcpy(number->mantissa, p_num);
        number->order += strlen(p_num);
    }
    // .12345
    else if (p_point < strpbrk(str, "0123456789"))
    {
        p_num = strtok(str, "+-.");
        p_num = strtok(str, ".");
        strcpy(number->mantissa, p_num);
    }
    // 12.345 or 12.
    else if (p_point > strpbrk(str, "0123456789"))
    {
        // 12
        p_num = strtok(str, "+-.");
        strcpy(number->mantissa, p_num);
        number->order += strlen(p_num);
        // 345
        p_num = strtok(NULL, ".");
        if (p_num)
            strcat(number->mantissa, p_num);
    }

    number->mantissa[MAX_MANTISSA_LEN + 1] = '\0';

    add_left_zeroes(number);
}


void add_left_zeroes(exponential *number)
{
    size_t count = strlen(number->mantissa);
    
    for (size_t i = MAX_MANTISSA_LEN + 1; i >= MAX_MANTISSA_LEN + 1 - count; --i)
        number->mantissa[i] = number->mantissa[i - (MAX_MANTISSA_LEN + 1) + count];
    for (size_t j = 0; j < MAX_MANTISSA_LEN + 1 - count; ++j)
       number->mantissa[j] = '0';

    number->order += MAX_MANTISSA_LEN - count;
}


void add_right_zero(exponential *number, size_t count_zeroes)
{
    for (size_t k = 0; k < count_zeroes; ++k)
    {
        for (size_t i = 0; i < MAX_MANTISSA_LEN + 1 - k; ++i)
            number->mantissa[i] = number->mantissa[i + 1];
        number->mantissa[MAX_MANTISSA_LEN - k] = '0';
    }

    number->order -= count_zeroes;
}


void do_dividend_bigger(exponential *num1, exponential *num2)
{
    char *p1 = strpbrk(num1->mantissa, "123456789");
    char *p2 = strpbrk(num2->mantissa, "123456789");
    int n = strlen(p1) - strlen(p2);

    if (n == 0 && (strcmp(num1->mantissa, num2->mantissa) < 0))
        add_right_zero(num1, 1);
    else
    {
        if (n > 0)
            add_right_zero(num2, n);
        else if (n < 0)
            add_right_zero(num1, -n);

        if (strcmp(num1->mantissa, num2->mantissa) < 0)
            add_right_zero(num1, 1);
    }
}


int to_int(char ch)
{
    return (int) ch - 48;
}


char to_char(int i)
{
    return (char) i + 48;
}