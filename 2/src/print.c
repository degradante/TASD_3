#include "../inc/print.h"

void print_user_guide(void)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n"
           "\n"
           " •"
           "\n");
}


void print_menu(void)
{
    printf(" ══════════════════════════════════════════════════════════════════════════\n");
    printf("| List of Commands  \n");
    printf("| 1: Add a Field  \n");
    printf("| 2: Delete a Field  \n");
    printf("| 3: Sort Table by Table of Keys and show it  \n");
    printf("| 4: Sort original Table and show it  \n");
    printf("| 5: Show a Table of Keys \n");
    printf("| 6: Show a Table  \n");
    printf("| 7: Compare 3 and 4 command  \n");
    printf("| 8: Compare different sorts  \n");
    printf("| 9: Find secondary apartm. with 2 rooms without animals and within certain price range  \n");
    printf("| 0: Exit  \n");
    printf(" ══════════════════════════════════════════════════════════════════════════\n");
    printf("| Input command: ");
}


void print_error(int error_code)
{
    switch (error_code)
    {
        case ERR_NO_ARG:
            puts("\tError: no argument");
            break;
        case ERR_FILE_NAME:
            puts("\tError: invalid file name");
            break;
        default:
            break;
    }
}