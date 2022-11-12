#ifndef _INC_INIT_H
#define _INC_INIT_H

#include <stdio.h>

#define SIZE 25


//enum tech_book_e {fict_fairytail, tech_poem};

typedef struct
{
    char field[SIZE + 1];
    int year;
    int language;
} tech_book_t;


enum fict_book_e {fict_novel, fict_play, fict_poem};

typedef struct
{
    short genre;
} fiction_book_t;


enum kid_book_e {kid_fairytail, kid_poem};

typedef struct
{
    short genre;
} kid_book_t;


typedef union
{
    tech_book_t tech;
    fiction_book_t fiction;
    kid_book_t kid;
} book_kind_t;


typedef struct
{
    char last_name[SIZE + 1];
    char title[SIZE + 1];
    char publisher[SIZE + 1];
    size_t pages;
    short type;
    book_kind_t kind;
} book_t;


void process(char choise, FILE *f);
void add_field(FILE *f);
void delete_field(FILE *f);

#endif