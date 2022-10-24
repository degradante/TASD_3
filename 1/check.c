#include "check.h"
#include "print.h"
#include "view.h"

int check_input_float(char *number, char *type)
{
    int err_code = NO_ERRS;
    
    print_with_border(type);
    scanf("%s", number);

    char ch;
    int count_E = 0, count_points = 0;
    size_t ind_E = 100;
    int sign_mantissa = 0, sign_order = 0, len_order = 0, len_mantissa = 0;

    for (size_t i = 0; (ch = number[i]) && !err_code; i++)
    {
        if (ch >= '0' && ch <= '9')
        {
            if (count_E == 0)
                ++len_mantissa;
            else
                ++len_order;
        }
        else
        {
            if (ch == 'e' || ch == 'E')
            {
                count_E++;
                ind_E = i;
                if (count_E > 1)
                    err_code = ERROR_COUNT_E;
            }

            else if (ch == '.')
            {
                count_points++;
                if (count_points > 1)
                    err_code = ERROR_COUNT_POINTS;
                else if (count_E == 1)
                    err_code = ERROR_TYPE_ORDER;
            }

            else if (ch == '+' || ch == '-')
            {
                if (count_E == 0 && !sign_mantissa && i == 0)
                    sign_mantissa = 1;
                else if (count_E == 1 && ind_E == (i - 1) && !sign_order)
                    sign_order = 1;
                else
                    err_code = ERROR_COUNT_SIGNS;
            }

            else
                err_code = ERROR_CHAR;
        }
    }

    if (len_mantissa > MAX_MANTISSA_LEN)
        err_code = ERROR_SIZE_MANTISSA;
    if (len_order > MAX_ORDER_LEN)
        err_code = ERROR_SIZE_ORDER;

    return err_code;
}


int normalize_result(exponential *number)
{
    int err_code = NO_ERRS;

    int i;
    for (i = 0; number->mantissa[i]; ++i) {}
    --i;
    for (; number->mantissa[i] == '0'; --i)
        number->mantissa[i] = '\0';

    int j = 0;
    i = 0;
    while (number->mantissa[i] == '0')
    {
        for (j = i; number->mantissa[j]; ++j)
            number->mantissa[j] = number->mantissa[j + 1];
        number->mantissa[j] = number->mantissa[j + 1];
    }

    if (number->order > MAX_ORDER || number->order < MIN_ORDER)
        err_code = ERROR_OVERFLOW;

    return err_code;
}


bool is_zero(char *mantissa)
{
    return strtod(mantissa, NULL) ? false : true;
}
