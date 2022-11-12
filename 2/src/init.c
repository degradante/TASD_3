#include "init.h"

void process(char choise, FILE *f)
{
    switch (choise)
    {
        case '1':
            add_field(f);
            break;
        case '2':
            delete_field(f);
            break;
        default:
            puts("Invalid flag");
            break;
    }
}

void add_field(FILE *f)
{
    book_t book;
    printf("Input lastname, publisher, pages:\n");
    scanf("%s", book.last_name);
    scanf("%s", book.title);
    scanf("%s", book.publisher);
    scanf("%lu", &book.pages);

    scanf("%hd", &book.type);
    if (book.type == 1)
    {
        ;
    }

    fwrite(book.last_name, sizeof(book.last_name), 1, f);
    fwrite(book.title, sizeof(book.title), 1, f);
    fwrite(book.publisher, sizeof(book.publisher), 1, f);
    fwrite(&book.pages, sizeof(book.pages), 1, f);
}


void delete_field(FILE *f)
{
    size_t pos;

    if (scanf("%lu", &pos))
        ++pos;    
}