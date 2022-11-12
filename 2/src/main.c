#include "print.h"
#include "init.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int err_code = NO_ERRS;

    FILE *f;

    if (argc < 2)
        err_code = ERR_ARG;
    else if (!(f = fopen(argv[1], "r+")))
        err_code = ERR_FILE_NAME;
    else 
    {
        //print_user_guide();

        char choise = '0';
        do
        {
            print_menu();
            scanf("%c", &choise);
            process(choise, f);
        } while (choise != '0');
    }

    if (err_code)
        print_error(err_code);

    return err_code;
}
