#include <sys/time.h>
#include <time.h>
#include <stdio.h>

#include "profile.h"
#include "stack.h"
#include "list.h"
#include "my_task.h"


void memory_profile()
{
	printf("Memory profile:\n");
	size_t sizes[] = { 1, 2, 3, 10, 100, 1000, 10000 };
	size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%15s|%30s|%30s|\n", "size", "stack", "list");
	for (size_t i = 0; i < n_sizes; i++)
		printf("|%15ld|%30ld|%30ld|\n", sizes[i], stack_memsize(sizes[i]), list_memsize(sizes[i]));
}


void time_profile()
{
    size_t sizes[] = { 1, 2, 3, 5, 10, 50, 100, 1000, 10000 };
    size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%15s|%31s|%31s|\n", "", "push", "pop");
	printf("|%15s|%15s|%15s|%15s|%15s|\n", "size", "stack", "list", "stack", "list");

	stack_t *stack = stack_new(sizes[n_sizes - 1]);
	list_t *list = list_new();

	for (size_t i_size = 0; i_size < n_sizes; i_size++)
	{
		time_t beg, end;
		time_t stack_push_time = 0, list_push_time = 0, stack_pop_time = 0, list_pop_time = 0;
        for (short j = 0; j < TIMES; j++)
		{
			beg = milliseconds_now();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_push(stack, 'q');
			end = milliseconds_now();
			stack_push_time += end - beg;

			beg = milliseconds_now();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				list_push(list, 'q');
			end = milliseconds_now();
			list_push_time += end - beg;

			beg = milliseconds_now();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_pop(stack);
			end = milliseconds_now();
			stack_pop_time += end - beg;

			beg = milliseconds_now();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				list_pop(list);
			end = milliseconds_now();
			list_pop_time += end - beg;
		}

		printf("|%15ld|%15ld|%15ld|%15ld|%15ld|\n", 
			sizes[i_size], stack_push_time / TIMES,  list_push_time / TIMES, stack_pop_time / TIMES,  list_pop_time / TIMES);
    }

	list_delete(list);
	stack_delete(stack);
}
	

time_t milliseconds_now(void)
{
    struct timeval val;

    gettimeofday(&val, NULL);
        //return (size_t) -1;

    return (time_t)val.tv_sec * 1000000LL + (time_t)val.tv_usec;
}