#include "vector.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int init_vector(vector *ptr_to_vector, size_t init_count) {
    if(init_count <= 0) {
        return VECTOR_INITIAL_COUNT_ERROR;
    }
    else {
        ptr_to_vector->count = init_count;
        printf("%d", ptr_to_vector->count);
        ptr_to_vector->size = init_count*2;
        if((ptr_to_vector->data = (int32_t*)malloc(ptr_to_vector->size*(sizeof(ptr_to_vector->data)))) == NULL) {
            return VECTOR_MEMORY_ALLOC_ERROR;
        }
        else {
            for(int i = 0; i < ptr_to_vector->count; i++) {
                ptr_to_vector->data[i] = 0;
                printf("%d", ptr_to_vector->data[i]);
            }
            return VECTOR_MEMORY_INIT_SUCCESS;
        }
    }
}

void destroy_vector(vector *ptr_to_vector) {
    free(ptr_to_vector->data);
}