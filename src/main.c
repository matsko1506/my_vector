#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[argc+1])
{
    vector_t x = {0};
    switch(vector_init(&x, sizeof(int))) {
        case 0:
            printf("SUCCESS");
            break;
        case 1:
            printf("VECTOR_MEMORY_ALLOC_ERROR");
            break;
        case 2:
            printf("VECTOR_INITIAL_COUNT_ERROR");
            break;
    }

    vector_destroy(&x);
    print_test();
}