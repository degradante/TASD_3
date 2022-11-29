#include <sys/time.h>
#include <time.h>

#include "profile.h"
#include "my_task.h"

int profile_time(void)
{
    size_t sizes[] = { 5, 10, 50, 100, 500, 1000, 5000, 10000 };
    size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%15s|%31s|%31s|\n", "", "push", "pop");
	printf("|%15s|%15s|%15s|%15s|%15s|\n", "size", "stack", "list", "stack", "list");

	stack_t *stack = stack_new(10000);
	list_t *list = list_new();

	for (size_t i_size = 0; i_size < n_sizes; i_size++)
	{
		size_t beg, end;
		size_t stack_push_time = 0, list_push_time = 0, stack_pop_time = 0, list_pop_time = 0;
        for (short j = 0; j < TIMES; j++)
		{
			beg = milliseconds_now();
			for (size_t k = 0; k < sizes[i_size]; k++)
				stack_push(stack, 'q');
			end = milliseconds_now();
			stack_push_time += end - beg;

			beg = milliseconds_now();
			for (size_t k = 0; k < sizes[i_size]; k++)
				list_push(list, 'q');
			end = milliseconds_now();
			list_push_time += end - beg;

			beg = milliseconds_now();
			for (size_t k = 0; k < sizes[i_size]; k++)
				stack_pop(stack);
			end = milliseconds_now();
			stack_pop_time += end - beg;

			beg = milliseconds_now();
			for (size_t k = 0; k < sizes[i_size]; k++)
				list_pop(list);
			end = milliseconds_now();
			list_pop_time += end - beg;
		}

		printf("|%15lu|%15lu|%15lu|%15lu|%15lu|\n", 
			sizes[i_size], stack_push_time / TIMES,  list_push_time / TIMES, stack_pop_time / TIMES,  list_pop_time / TIMES);
    }

	list_delete(list);
	stack_delete(stack);

    return 0;
}
	

size_t milliseconds_now(void)
{
    struct timeval val;

    gettimeofday(&val, NULL);
        //return (size_t) -1;

    return val.tv_sec * 1000000ULL + (size_t)val.tv_usec;
}