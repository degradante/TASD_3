#ifndef _INC_MY_MEMORY_H_
#define _INC_MY_MEMORY_H_

#include <stdio.h>

#define LOG_SIZE 1000
#define LOG_DELETED 1

static void **deleted_addresses;
static size_t log_index;

void log_init(void);

void log_delete(void* address);

void log_print_deleted_addresses(void);

#endif