#include "vector.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

error_description_t array[] = {
    { VECTOR_INIT_SUCCESS, "TEST" },
    { VECTOR_INIT_MALLOC_ERROR, "TEST" },
    { VECTOR_INIT_ARGS_ERROR, "TEST" },
    { VECTOR_DESTROY_SUCCESS, "TEST" },
    { VECTOR_DESTROY_ERROR, "TEST" },
    { VECTOR_RESIZE_SUCCESS, "TEST" },
    { VECTOR_RESIZE_ERROR, "TEST" },
    { VECTOR_PUSH_SUCCESS, "TEST" },
    { VECTOR_PUSH_ERROR, "TEST" },
    { VECTOR_PUSH_FAILED_RESIZE_ERROR, "TEST" },
    { VECTOR_PRINT_SUCCESS, "TEST" },
    { VECTOR_PRINT_EMPTY_VECTOR_ERROR, "TEST" }
};

error_t vector_init(vector_t *vector_ptr, size_t vector_element_bytes_size) {
    if(!vector_ptr || !vector_element_bytes_size) 
        return VECTOR_INIT_ARGS_ERROR; 
    vector_ptr->vector_element_bytes_size = vector_element_bytes_size;    
    vector_ptr->vector_elements_count = VECTOR_INIT_ELEMENTS_COUNT;
    vector_ptr->vector_total_bytes_size = vector_ptr->vector_element_bytes_size * VECTOR_INIT_SIZE;
    if((vector_ptr->vector_data=malloc(vector_ptr->vector_total_bytes_size)) == NULL) 
        return VECTOR_INIT_MALLOC_ERROR;
    return VECTOR_INIT_SUCCESS;
}
error_t vector_destroy(vector_t *vector_ptr) {
    if(!vector_ptr)
        return VECTOR_DESTROY_ERROR;
    free(vector_ptr->vector_data);
    vector_ptr->vector_data = NULL;
    vector_ptr->vector_element_bytes_size = 0;
    vector_ptr->vector_elements_count = 0;
    vector_ptr->vector_total_bytes_size = 0;
    return VECTOR_DESTROY_SUCCESS;
}

error_t vector_resize(vector_t *vector_ptr) {
    if(!vector_ptr) 
        return VECTOR_RESIZE_ERROR;
    size_t new_size = vector_ptr->vector_total_bytes_size;
    new_size *= 2;
    void *temp;
    if((temp = realloc(vector_ptr->vector_data, new_size)) == NULL) {
        return VECTOR_RESIZE_ERROR;
    }
    vector_ptr->vector_total_bytes_size = new_size;
    vector_ptr->vector_data = temp;
    return VECTOR_RESIZE_SUCCESS;
}

error_t vector_push(vector_t *vector_ptr, void *value) {
    if(!vector_ptr || !value) 
        return VECTOR_PUSH_ERROR;
    if(vector_ptr->vector_element_bytes_size*vector_ptr->vector_elements_count >= vector_ptr->vector_total_bytes_size) {
        error_t error;
        if((error = vector_resize(vector_ptr)) == VECTOR_RESIZE_ERROR) 
            return VECTOR_PUSH_FAILED_RESIZE_ERROR;
    }
    VECTOR_ADD(vector_ptr, value);
    vector_ptr->vector_elements_count++;
    return VECTOR_PUSH_SUCCESS;
}

error_t vector_get(void *destination_ptr, vector_t *vector_ptr, int index) {
    if(!vector_ptr || !destination_ptr)
        return VECTOR_GET_INVALID_ARGS_ERROR;
    if(vector_ptr->vector_elements_count == 0) 
        return VECTOR_GET_NO_ELEMENTS;
    if(index < 0 || index >= vector_ptr->vector_elements_count)
        return VECTOR_GET_OUT_OF_BOUNDS_ERROR;
    VECTOR_GET(destination_ptr, vector_ptr, index);
    return VECTOR_GET_SUCCESS;
}

error_t vector_set(void *source_ptr, vector_t *vector_ptr, int index) {
    if(!source_ptr || !vector_ptr)
        return VECTOR_SET_INVALID_ARGS_ERROR;
    if(index < 0 || index >= vector_ptr->vector_elements_count)
        return VECTOR_SET_OUT_OF_BOUNDS_ERROR;
    if(vector_ptr->vector_elements_count == 0) 
        return VECTOR_SET_NO_ELEMENTS;
    VECTOR_SET(source_ptr, vector_ptr, index);
    return VECTOR_SET_SUCCESS;

    return 0;
}

error_t vector_print(vector_t *vector_ptr) {
    if(!vector_ptr || vector_ptr->vector_elements_count <= 0)
        return VECTOR_PRINT_EMPTY_VECTOR_ERROR;
    void *temp;
    temp = vector_ptr->vector_data;
    for (int i = 0; i < vector_ptr->vector_elements_count; i++) 
    {
        printf("Address of %d element: %p\n", i, temp);
        
    }
    return VECTOR_PRINT_SUCCESS;
}

void print_test() {
    for(int i = 0; i < 3; i++)
    {
        printf("%s\n", array[i].message);
    }
}