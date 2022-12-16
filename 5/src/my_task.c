#include "../inc/io.h"
#include "queue_list.h"
#include "queue_array.h"

int brackets_check_queue_array()
{
    int err_code = NO_ERRS;

    queue_array_t *queue_array = queue_array_new(10 + 1);

    queue_array_delete(queue_array);

    return err_code;
}



int brackets_check_queue_list()
{
    int err_code = NO_ERRS;

    queue_list_t *queue_list = queue_list_new(); 

    queue_list_delete(queue_list);
    
    return err_code;
}


