# Lab Assignment 3
Create a custom structure that stores an array along with the size in a single data type.  
The size of the array will be chosen by the user using command line arguments. 
User input will then pass to the array for various functions that operate on the data inside.

# Part 1
Create a structure data type in a header file called array.h.  
Define the structure containing two variables: size and data
```
struct _my_array
{
  int size;
  double *data;
};
typedef struct _my_array Array;
```

# Part 2
Create a main.c file. Dynamically allocate a single structure of type _my_array.  
The user will run the program as follows:

`
./main 1024
`

where the second argument is the size of the array to make inside the structure. Taking this value, 
allocate more space for the data inside the structure. Fill this array with values of your choice.  

# Step 3
Write three functions:
- `void output_array(Array *a);`
- `void shift_array(Array *a);`
- `Array *average_adjacent(Array *a);`

`output_array` will output the array in it's entirety.  

`shift_array` will shift all elements to the left by 1.  That is, the value at index 1 will become the value at index 0, 
the value at index 2 will become the value at index 1, etc.  The value at index 0 should become the last element in the array.

`average_adjacent` will average two elements next to each other and return a new array of average values.
The new array is half the size of the original and if the original array was odd sized, the last element is ignored.
