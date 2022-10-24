#ifndef _INC_INIT_H
#define _INC_INIT_H

#include <stdio.h>
#include <string.h>

#define LAST_NAME_LEN 25


typedef struct
{
    char last_name[LAST_NAME_LEN + 1];
    char izdatelstvo[LAST_NAME_LEN + 1];
    size_t pages;
    union type
    {
        struct technical
        {
            size_t year;
        } tech;
        struct fiction
        {
            char c;
        } fic;
        struct children
        {
            double d;
        } child;
    } tp;
} book_t;


void process(char choise, FILE *f);
void add_field(FILE *f);
void delete_field(FILE *f);

#endif