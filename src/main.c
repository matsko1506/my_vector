#include <stdio.h>
#include "vector.h"

int main(int argc, char *argv[argc+1])
{
    vector *x;
    switch(init_vector(x, 5)) {
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
}