#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define VECTOR_MEMORY_INIT_SUCCESS 0;
#define VECTOR_MEMORY_ALLOC_ERROR 1;
#define VECTOR_INITIAL_COUNT_ERROR 2;

typedef struct {
    int32_t *data;      
    size_t count;       
    size_t size;        
} vector;

int init_vector(vector *ptr_to_vector, size_t init_count);
void destroy_vector(vector *ptr_to_vector);

#endif