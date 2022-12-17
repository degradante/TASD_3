#include <time.h>
#include <stdio.h>

#include "profile.h"
#include "stack_array.h"
#include "stack_list.h"
#include "my_task.h"


void memory_profile()
{
	printf("\n%50s\n\n", "array/list stack memory profile");
	size_t sizes[] = { 1, 2, 3, 10, 100, 1000, 10000 };
	size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%13s|%27s|%27s|\n", "size", "array", "list");
	for (size_t i = 0; i < n_sizes; i++)
		printf("|%13ld|%27ld|%27ld|\n", sizes[i], stack_array_memsize(sizes[i]), stack_list_memsize(sizes[i]));
}


void time_profile()
{
	printf("\n%50s\n\n", "array/list time profile");

    size_t sizes[] = { 1, 2, 3, 5, 10, 50, 100, 1000, 10000 };
    size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%13s|%27s|%27s|\n", "", "push", "pop");
	printf("|%13s|%13s|%13s|%13s|%13s|\n", "size", "array", "list", "array", "list");

	stack_array_t *stack_array = stack_array_new(sizes[n_sizes - 1]);
	stack_list_t *stack_list = stack_list_new();

	for (size_t i_size = 0; i_size < n_sizes; i_size++)
	{
		clock_t start, end;
		double stack_array_push_time = 0, stack_list_push_time = 0, stack_array_pop_time = 0, stack_list_pop_time = 0;
        for (short j = 0; j < TIMES; j++)
		{
			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_array_push(stack_array, 'q');
			end = clock();
			stack_array_push_time += end - start;

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_list_push(stack_list, 'q');
			end = clock();
			stack_list_push_time += (double)(end - start);

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_array_pop(stack_array);
			end = clock();
			stack_array_pop_time += end - start;

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				stack_list_pop(stack_list);
			end = clock();
			stack_list_pop_time += end - start;
		}

		printf("|%13ld|%13.3f|%13.3f|%13.3f|%13.3f|\n", 
			sizes[i_size], stack_array_push_time / TIMES,  stack_list_push_time / TIMES, stack_array_pop_time / TIMES,  stack_list_pop_time / TIMES);
    }

	stack_list_delete(stack_list);
	stack_array_delete(stack_array);
}
	
/*
time_t clock(void)
{
    struct timeval val;

    gettimeofday(&val, NULL);
        //return (size_t) -1;

    return (time_t)val.tv_sec * 1000000LL + (time_t)val.tv_usec;
}
*/
