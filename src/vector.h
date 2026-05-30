#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>

#define VECTOR_INIT_SIZE 4;
#define VECTOR_INIT_ELEMENTS_COUNT 0;

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
    VECTOR_PRINT_EMPTY_VECTOR_ERROR = 10
};

typedef enum error_codes_e error_t;

typedef struct vector_s vector_t;

struct vector_s {
    void *vector_data;      
    int vector_elements_count; //changed from size_t
    size_t vector_total_bytes_size; 
    size_t vector_element_bytes_size;       

    error_t (*destroy_vector_fptr)(vector_t *);
    error_t (*vector_push_fptr)(vector_t *, void *);
    error_t (*vector_get_fptr)(vector_t *, int);
    error_t (*vector_set_fptr)(vector_t *, int);
    error_t (*vector_print_fptr)(vector_t *);
};

struct error_description_s {
    int code;
    char *message;
};

typedef struct error_description_s error_description_t;

error_t vector_init(vector_t *vector_ptr, size_t vector_element_bytes_size);
error_t vector_destroy(vector_t *vector_ptr);
error_t vector_push(vector_t *vector_ptr, void *value);
error_t vector_get(vector_t *vector_ptr, int index);
error_t vector_set(vector_t *vector_ptr, int index);
error_t vector_print(vector_t *vector_ptr);
error_t vector_resize(vector_t *vector_ptr);
void vector_print_error(error_t code);
void print_test();

#endif