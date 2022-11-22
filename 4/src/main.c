#include "../inc/io.h"
#include "menu.h"

int main(void)
{
    int err_code = NO_ERRS;

    print_user_guide();
    main_loop();

    printf("you see\n");
    
    return err_code;
}
