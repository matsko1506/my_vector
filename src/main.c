#include <stdio.h>
#include "vector.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[argc+1])
{

    int arr_a[5] = {1, 2, 3, 4, 5};
    int arr_b[5] = {6, 7, 8, 9, 10};
    int arr_c[10] = {11, 12, 13, 14, 15,
                     16, 17, 18, 19, 20 };
    int *p = arr_a;
    int *p2 = arr_b;
    int *p3 = arr_c;
    vector_t x = { 0 };

    error_t error;
    
    if((error = vector_init(&x, sizeof(int))) != VECTOR_INIT_SUCCESS) {
        printf("Error during vector init...");
        return -1;
    }


    int a = 0;
    int b = 1000;

    if((error = vector_get(&a, &x, 1)) == VECTOR_GET_NO_ELEMENTS)
    {  
        printf("TEST");
    }
    printf("Vector value at index 1 is %d\n", a);
    vector_set(&b, &x, 1);
    vector_get(&a, &x, 1);
    printf("Vector value at index 1 is %d", a);

    vector_destroy(&x);
};