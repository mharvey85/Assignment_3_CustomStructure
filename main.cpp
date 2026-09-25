#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[]) {

    //checking if correct array size was given by user
    if (argc < 2) {
        fprintf(stderr, "Error: Missing array size argument.\n");
        fprintf(stderr, "Usage: %s <array_size>\n", argv[0]);
        return 1;
    }

    int input_size = atoi(argv[1]);

    if (input_size <= 0){
        printf("Error: Input needs to be positive integer");
        return 1;
    }
    
    //Allocating memory space for array structure
    Array *my_struct = (Array*)malloc(sizeof(Array));
    if (my_struct == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for the structure.\n");
        return 1;
    }

    my_struct->size = (size_t)input_size;

    //Defining space for double array
    my_struct->data = (double*)malloc(my_struct->size * sizeof(double));
    if (my_struct->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for the internal data array.\n");
        free(my_struct);
        return 1;
    }

    //Assigning values for each array index for length of user given size
    for (size_t i = 0; i < my_struct->size; i++) {
        my_struct->data[i] = (double)(i * 2.0);
    }

    // printf("Successfully allocated structure and array of size %zu.\n", my_struct->size);
    // printf("Dis is da first one: %f\n", my_struct->data[0]);
    // printf("Dis is da middle I think: %f\n", my_struct->data[my_struct->size/2]);
    // printf("Dis is da last one: %f\n", my_struct->data[my_struct->size-1]);
    
    free(my_struct->data);
    free(my_struct);

    return 0;
}