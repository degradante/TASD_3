#include <time.h>
#include <stdio.h>

#include "profile.h"
#include "queue_array.h"
#include "queue_list.h"
#include "my_task.h"


void memory_profile()
{
	printf("Memory profile:\n");
	size_t sizes[] = { 1, 2, 3, 10, 100, 1000, 10000 };
	size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%15s|%30s|%30s|\n", "size", "queue_array", "queue_list");
	for (size_t i = 0; i < n_sizes; i++)
		printf("|%15ld|%30ld|%30ld|\n", sizes[i], queue_array_memsize(sizes[i]), queue_list_memsize(sizes[i]));
}


void time_profile()
{
    size_t sizes[] = { 1, 2, 3, 5, 10, 50, 100, 1000, 10000 };
    size_t n_sizes = sizeof(sizes) / sizeof(sizes[0]);

	printf("|%15s|%31s|%31s|\n", "", "add", "get");
	printf("|%15s|%15s|%15s|%15s|%15s|\n", "size", "queue_array", "queue_list", "queue_array", "queue_list");

	queue_array_t *queue_array = queue_array_new(sizes[n_sizes - 1]);
	queue_list_t *queue_list = queue_list_new();

	for (size_t i_size = 0; i_size < n_sizes; i_size++)
	{
		clock_t start, stop;
		clock_t queue_array_add_time = 0, queue_list_add_time = 0, queue_array_get_time = 0, queue_list_get_time = 0;
        for (short j = 0; j < TIMES; j++)
		{
			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				queue_array_add(queue_array, 'q');
			stop = clock();
			queue_array_add_time += stop - start;

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				queue_list_add(queue_list, 'q');
			stop = clock();
			queue_list_add_time += stop - start;

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				queue_array_get(queue_array);
			stop = clock();
			queue_array_get_time += stop - start;

			start = clock();
			for (size_t elems_count = 0; elems_count < sizes[i_size]; ++elems_count)
				queue_list_get(queue_list);
			stop = clock();
			queue_list_get_time += stop - start;
		}

		printf("|%15ld|%15ld|%15ld|%15ld|%15ld|\n", 
			sizes[i_size], queue_array_add_time / TIMES,  queue_list_add_time / TIMES, queue_array_get_time / TIMES,  queue_list_get_time / TIMES);
    }

	queue_list_delete(queue_list);
	queue_array_delete(queue_array);
}
	