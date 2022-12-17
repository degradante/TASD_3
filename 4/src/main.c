#include "../inc/io.h"
#include "menu.h"
#include "my_memory.h"

int main(void)
{
    int err_code = NO_ERRS;
    if (LOG_DELETED)
        log_init();
    print_user_guide();
    main_loop();
    
    return err_code;
}
