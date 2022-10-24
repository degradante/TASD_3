#include "check.h"
#include "print.h"
#include "view.h"
#include "division.h"
#include <string.h>

int main(void)
{
    setbuf(stdout, NULL);

    int err_code = NO_ERRS;

    //               30      '± . e ±'             '\0'
    char str1[MAX_MANTISSA_LEN + 4 + MAX_ORDER_LEN + 1];
    char str2[MAX_MANTISSA_LEN + 4 + MAX_ORDER_LEN + 1];
    exponential result = {.sign = '+', .order = 0};

    print_user_guide();
    if (!(err_code = check_input_float(str1, "Введите делимое")) && 
        !(err_code = check_input_float(str2, "Введите делитель")))
    {
        exponential dividend = {.sign = '+', .order = 0};
        exponential divisor =  {.sign = '+', .order = 0};
    
        to_exponential(str1, &dividend);
        to_exponential(str2, &divisor);

        if (is_zero(divisor.mantissa))
            err_code = ERROR_ZERO_DIVISION;
        else if (is_zero(dividend.mantissa))
            strcpy(result.mantissa, "0");
        else
        {
            division(&dividend, &divisor, &result);
            err_code = normalize_result(&result);
        }
    }

    if (err_code)
        print_error(err_code);
    else
        print_normalize(&result);

    return err_code;
}