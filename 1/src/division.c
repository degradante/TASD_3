#include "check.h"
#include "print.h"
#include "view.h"
#include "division.h"
#include <string.h>

void division(exponential *x, exponential *y, exponential *result)
{
    if (x->sign != y->sign)
        result->sign = '-';

    do_dividend_bigger(x, y);
    // На выходе получаем X; а в норм. представлении должно быть 0.X
    result->order = x->order - y->order + 1;

    // 31
    char zero[] = "0000000000000000000000000000000";
    strcpy(result->mantissa, zero);

    char vichitaemoe[MAX_MANTISSA_LEN + 1 + 1];

    // 31 вместо 30 для того чтоб можно было округилить по 31ой цифре
    for (size_t i = 0; i < MAX_MANTISSA_LEN + 1 && !is_zero(x->mantissa); ++i)
    {
        if (strcmp(x->mantissa, y->mantissa) < 0)
            do_dividend_bigger(x, y);

        strcpy(vichitaemoe, zero);
 
        size_t numeral = 0;
        do
        {
            ++numeral;
            get_vichitaemoe(vichitaemoe, y->mantissa, numeral);
        } while (strcmp(x->mantissa, vichitaemoe) >= 0);
        // берем предыдущее число для деления т.к. вычитаемое больше
        --numeral;
        strcpy(vichitaemoe, zero);
        get_vichitaemoe(vichitaemoe, y->mantissa, numeral);
        subtract(x->mantissa, vichitaemoe);

        result->mantissa[i] = to_char(numeral);
    }
    normalize_result(result);
    round_up(result);
}


void get_vichitaemoe(char *vichitaemoe, char *divisor, size_t numeral)
{
    
    size_t v_ume = 0;
    for (int i = MAX_MANTISSA_LEN; i >= 0; --i)
    {
        int proizvedenie = numeral * to_int(divisor[i]) + v_ume;
        vichitaemoe[i] = to_char(proizvedenie % 10);
        v_ume = proizvedenie / 10;
    }
}


void subtract(char *mantissa, char *vichitaemoe)
{
    int v_ume = 0;

    int x, y, z;

    char *p = strpbrk(mantissa, "123456789");
    for (int i = MAX_MANTISSA_LEN; mantissa + i >= p; --i)
    {
        x = to_int(mantissa[i]);
        y = to_int(vichitaemoe[i]);
        if ((z = x - v_ume - y) >= 0)
        {
            mantissa[i] = to_char(z);
            v_ume = 0;
        }
        else
        {
            mantissa[i] = to_char(z + 10);
            v_ume = 1;
        }
    }
}


void round_up(exponential *result)
{
    // 31ый символ нужен для округления предудыщих
    if (strlen(result->mantissa) == MAX_MANTISSA_LEN + 1)
    { 
        if (result->mantissa[MAX_MANTISSA_LEN] >= '5')
        {
            int i = MAX_MANTISSA_LEN - 1;
            while (result->mantissa[i] == '9' && i >= 1)
                --i;
            if (result->mantissa[0] == '9' && i == 0)
            {
                result->mantissa[0] = '1';
                result->mantissa[1] = '\0';
                result->order += i;
            }
            else
            {
                for (; i < MAX_MANTISSA_LEN; ++i)
                    result->mantissa[i] = to_char((to_int(result->mantissa[i]) + 1) % 10);
            }
        }
        result->mantissa[MAX_MANTISSA_LEN] = '\0';
    }   
}
