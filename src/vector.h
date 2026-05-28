#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdint.h>

#define VECTOR_INIT_SIZE 10;
#define VECTOR_INIT_ELEMENTS_COUNT 0;

enum _error_codes_e {
    VECTOR_INIT_SUCCESS = 0,
    VECTOR_MEMORY_ALLOC_ERROR = 1,
    VECTOR_INIT_ARGS_ERROR = 2
};

typedef enum _error_codes_e error_t;

struct _vector_s {
    void *vector_data;      
    size_t vector_elements_count;       
    size_t vector_total_size; 
    size_t vector_element_size;       
};

typedef struct _vector_s vector_t;

struct _error_description_s {
    int code;
    char *message;
};

typedef struct _error_description_s error_description_t;

int vector_init(vector_t *vector_ptr, size_t vector_element_size);
void vector_destroy(vector_t *vector_ptr);
void vector_print_error(error_t code);
void print_test();

#endif