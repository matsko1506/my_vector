#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>

#define VECTOR_INIT_SIZE 4
#define VECTOR_INIT_ELEMENTS_COUNT 0
#define VECTOR_ADD(VECTOR, VALUE) memcpy(((uint8_t*)((VECTOR)->vector_data)+((VECTOR)->vector_elements_count*(VECTOR)->vector_element_bytes_size)), (VALUE), (VECTOR)->vector_element_bytes_size)
#define VECTOR_GET(DESTINATION, VECTOR, INDEX) memcpy((DESTINATION), ((uint8_t*)((VECTOR)->vector_data)+((INDEX)*(VECTOR)->vector_element_bytes_size)), (VECTOR)->vector_element_bytes_size)
#define VECTOR_SET(SOURCE, VECTOR, INDEX) memcpy(((uint8_t*)((VECTOR)->vector_data)+((INDEX)*(VECTOR)->vector_element_bytes_size)), (SOURCE), (VECTOR)->vector_element_bytes_size)

typedef enum error_codes_e error_t;
enum error_codes_e {
    VECTOR_INIT_SUCCESS = 0,
    VECTOR_INIT_MALLOC_ERROR = 1,
    VECTOR_INIT_ARGS_ERROR = 2,
    VECTOR_DESTROY_SUCCESS = 3,
    VECTOR_DESTROY_ERROR = 4,
    VECTOR_RESIZE_SUCCESS = 5,
    VECTOR_RESIZE_ERROR = 6, 
    VECTOR_PUSH_SUCCESS = 7,
    VECTOR_PUSH_ERROR = 8,
    VECTOR_PUSH_FAILED_RESIZE_ERROR = 9,
    VECTOR_PRINT_SUCCESS = 10,
    VECTOR_PRINT_EMPTY_VECTOR_ERROR = 11,
    VECTOR_GET_SUCCESS = 12,
    VECTOR_GET_INVALID_ARGS_ERROR = 13,
    VECTOR_GET_OUT_OF_BOUNDS_ERROR = 14,
    VECTOR_GET_NO_ELEMENTS = 15,
    VECTOR_SET_SUCCESS = 16,
    VECTOR_SET_OUT_OF_BOUNDS_ERROR = 17,
    VECTOR_SET_NO_ELEMENTS = 18,
    VECTOR_SET_INVALID_ARGS_ERROR = 19
};

typedef struct vector_s vector_t;
struct vector_s {
    void *vector_data;      
    size_t vector_elements_count; //changed from size_t
    size_t vector_total_bytes_size; 
    size_t vector_element_bytes_size;       
};

typedef struct error_description_s error_description_t;
struct error_description_s {
    int code;
    char *message;
};

error_t vector_init(vector_t *vector_ptr, size_t vector_element_bytes_size);
error_t vector_destroy(vector_t *vector_ptr);
error_t vector_push(vector_t *vector_ptr, void *value);
error_t vector_get(void *, vector_t *vector_ptr, int index);
error_t vector_set(void *, vector_t *vector_ptr, int index);
error_t vector_resize(vector_t *vector_ptr);
void vector_print_error(error_t code);

#endif