#ifndef _VIEW_H
#define _VIEW_H

#include "stdlib.h"

void to_exponential(char *str, exponential *number);
void add_left_zeroes(exponential *number);
void add_right_zero(exponential *number, size_t count_zeroes);
void do_dividend_bigger(exponential *x, exponential *y);
int to_int(char ch);
char to_char(int i);

#endif