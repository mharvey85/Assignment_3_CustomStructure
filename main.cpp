#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void output_array(Array *a);
void shift_array(Array *a);
Array *average_adjacent(Array *a);

int main(int argc, char *argv[]) {

    //Checking if array size was given by user
    if (argc < 2){
        printf("Error: Missing array size argument\n");
        return 1;
    }

    int input_size = atoi(argv[1]);
    
    //Verifies input is greater than 0
    if (input_size <= 0){
        printf("Error: Input needs to be positive integer");
        return 1;
    }
    
    //Allocating memory space for array structure
    Array *my_struct = (Array*)malloc(sizeof(Array));
    Array *my_struct_copy = (Array*)malloc(sizeof(Array));

    //Verifies space was actually allocated
    if (my_struct == NULL){
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    //Saves size given by user to struct array
    my_struct->size = (size_t)input_size;
    my_struct_copy->size = (size_t)input_size;

    //Defining space for double array
    my_struct->data = (double*)malloc(my_struct->size * sizeof(double));
    my_struct_copy->data = (double*)malloc(my_struct->size * sizeof(double));

    //Verified space was actually defined for double array
    if (my_struct->data == NULL){
        printf("Error: Memory allocation failed for the internal data array.\n");
        free(my_struct);
        free(my_struct_copy);
        return 1;
    }

    //Assigns values for each array index for length of user given size
    for (size_t i = 0; i < my_struct->size; i++){
        my_struct->data[i] = (double)(i * 2.0);
        my_struct_copy->data[i] = (double)(i * 2.0);        
    }

    //calling functions

    output_array(my_struct);
    shift_array(my_struct);
    output_array(my_struct);

    Array* new_array = average_adjacent(my_struct_copy);
    output_array(new_array);
    
    //free memory
    free(my_struct->data);
    free(my_struct);
    free(my_struct_copy->data);
    free(my_struct_copy);
    return 0;
}

//will print the array in its entirety 
void output_array(Array *a){
    //printf("Array Size: %d\n", a->size);
    printf("Array Elements: ");
    for(int i = 0; i < a->size; i++){
        printf("%f, ", a->data[i]);
    }
    printf("\n\n");
}

//will shift all elements to the left by 1 
void shift_array(Array *a){
    double b = *a->data;
    for(int i = 0; i < a->size; i++){
       a->data[i] = a->data[i+1];
       if(i == a->size - 1){ a->data[i] = b; }
    }
}

//will average two elements next to each other
//and save to new array (new array is half size of OG)
Array *average_adjacent(Array *a){
    Array *half_struct = (Array*)malloc(sizeof(Array));
    half_struct->size = a->size/2;
    half_struct->data = (double*)malloc(sizeof(a->size/2));
    int count = 0;
    for (int i = 0; i < a->size; i++){
        half_struct->data[count] = ((a->data[i] + a->data[i+1])/2);
        count++;
        i++;
    }
    return half_struct;
}