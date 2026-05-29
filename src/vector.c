#include "vector.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

error_description_t array[] = {
    { VECTOR_INIT_SUCCESS, "TEST" },
    { VECTOR_INIT_MALLOC_ERROR, "TEST" },
    { VECTOR_INIT_ARGS_ERROR, "TEST" },
    { VECTOR_DESTROY_SUCCESS, "TEST" },
    { VECTOR_DESTROY_ERROR, "TEST" },
    { VECTOR_RESIZE_SUCCESS, "TEST" },
    { VECTOR_RESIZE_ERROR, "TEST" }
};

error_t vector_init(vector_t *vector_ptr, size_t vector_element_size) {
    if(!vector_ptr || !vector_element_size) 
        return VECTOR_INIT_ARGS_ERROR; 
    vector_ptr->destroy_vector_fptr = vector_destroy;
    vector_ptr->vector_elements_count = VECTOR_INIT_ELEMENTS_COUNT;
    vector_ptr->vector_total_size = VECTOR_INIT_SIZE;
    vector_ptr->vector_element_size = vector_element_size;
    if((vector_ptr->vector_data=malloc((vector_ptr->vector_total_size * vector_ptr->vector_element_size))) == NULL) 
        return VECTOR_INIT_MALLOC_ERROR;
    return VECTOR_INIT_SUCCESS;
}
error_t vector_destroy(vector_t *ptr_to_vector) {
    if(!ptr_to_vector)
        return VECTOR_DESTROY_ERROR;
    free(ptr_to_vector->vector_data);
    ptr_to_vector->vector_data = NULL;
    ptr_to_vector->vector_element_size = 0;
    ptr_to_vector->vector_elements_count = 0;
    ptr_to_vector->vector_total_size = 0;
    return VECTOR_DESTROY_SUCCESS;
}

void vector_resize(vector_t *vector_ptr) {
    if(!vector_ptr) 
        return;
    size_t new_size = vector_ptr->vector_total_size*=2;
    void *temp;
    if((temp = realloc(vector_ptr->vector_data, new_size)) == NULL) {
        vector_destroy(vector_ptr);
        return;
    }
    vector_ptr->vector_total_size = new_size;
    vector_ptr->vector_data = temp;
}

void print_test() {
    for(int i = 0; i < 3; i++)
    {
        printf("%s\n", array[i].message);
    }
}