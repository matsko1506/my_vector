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
    { VECTOR_PRINT_EMPTY_VECTOR_ERROR, "TEST" }
};

error_t vector_init(vector_t *vector_ptr, size_t vector_element_bytes_size) {
    if(!vector_ptr || !vector_element_bytes_size) 
        return VECTOR_INIT_ARGS_ERROR; 
    vector_ptr->destroy_vector_fptr = vector_destroy;
    vector_ptr->vector_push_fptr = vector_push;
    vector_ptr->vector_get_fptr = vector_get;
    vector_ptr->vector_set_fptr = vector_set;
    vector_ptr->vector_print_fptr = vector_print;
    vector_ptr->vector_element_bytes_size = vector_element_bytes_size;    
    vector_ptr->vector_elements_count = VECTOR_INIT_ELEMENTS_COUNT;
    vector_ptr->vector_total_bytes_size = vector_ptr->vector_element_bytes_size * VECTOR_INIT_SIZE;
    if((vector_ptr->vector_data=malloc(vector_ptr->vector_total_bytes_size)) == NULL) 
        return VECTOR_INIT_MALLOC_ERROR;
    return VECTOR_INIT_SUCCESS;
}
error_t vector_destroy(vector_t *ptr_to_vector) {
    if(!ptr_to_vector)
        return VECTOR_DESTROY_ERROR;
    free(ptr_to_vector->vector_data);
    ptr_to_vector->vector_data = NULL;
    ptr_to_vector->vector_element_bytes_size = 0;
    ptr_to_vector->vector_elements_count = 0;
    ptr_to_vector->vector_total_bytes_size = 0;
    return VECTOR_DESTROY_SUCCESS;
}

error_t vector_resize(vector_t *vector_ptr) {
    if(!vector_ptr) 
        return VECTOR_RESIZE_ERROR;
    size_t new_size = vector_ptr->vector_total_bytes_size*=2;
    printf("NEW SIZE:%zu\n",new_size);
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
    memcpy((uint8_t*)(vector_ptr->vector_data)+(vector_ptr->vector_elements_count*vector_ptr->vector_element_bytes_size), value, vector_ptr->vector_element_bytes_size);
    vector_ptr->vector_elements_count++;
    return VECTOR_PUSH_SUCCESS;
}

error_t vector_get(vector_t *vector_ptr, int index) {
    //todo
    return 0;
}

error_t vector_set(vector_t *vector_ptr, int index) {
    //todo
    return 0;
}

error_t vector_print(vector_t *vector_ptr) {
    //todo
    return 0;
}

void print_test() {
    for(int i = 0; i < 3; i++)
    {
        printf("%s\n", array[i].message);
    }
}