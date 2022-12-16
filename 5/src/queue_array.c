#include <stdlib.h>
#include <string.h>
#include "queue_array.h"
#include "io.h"


queue_array_t *queue_array_new(size_t size)
{
    queue_array_t *self = (queue_array_t*)calloc(1, sizeof(queue_array_t));
    self->data= calloc(size, sizeof(data_t));
    self->begin = self->end = self->data;
    self->max = size;
    self->count = 0;

    return self;
}


void queue_array_add(queue_array_t *self, data_t value)
{
    if (self->count == self->max)
        printf("Error queue is full\n");
    else
    {
        *self->end = value;
        self->end++;
        self->count++;
    }
}


data_t queue_array_get(queue_array_t *self)
{
    data_t ret_value = *self->begin;
    
    memcpy(self->data, self->data + 1, sizeof(data_t));
    self->end--;
    self->count--;

    return ret_value;
}



size_t queue_array_size(queue_array_t *self)
{
	return self->end - self->begin;
}


void queue_array_delete(queue_array_t *self)
{
    if (self)
    {
        if (self->data)
        {
            self->begin = self->end = NULL;
            free(self->data);
            self->data = NULL;
        }
        free(self);
    }
}


bool queue_array_empty(queue_array_t *self)
{
	return self->begin == self->end;
}


void queue_array_print(queue_array_t *self)
{
    printf("\nqueue_array:\n ");
    for (data_t *ch = self->begin; ch < self->end; ++ch)
        printf("%c ", *ch);
    printf("\n");
}


size_t queue_array_memsize(size_t size)
{
	return sizeof(queue_array_t) + sizeof(data_t) * size;
}

