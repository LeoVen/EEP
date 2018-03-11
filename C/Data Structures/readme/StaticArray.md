# Static Array

## How it works

Since it is difficult to implement an array in C without overflowing or underflowing and writing things to memory that normally a program should not, in every function a parameter __must__ be passed with the exact size of the array.

## Functions

	int * getArray(int arraySize);
	int initArray(int *array, int arraySize);
	int restartArray(int *array, int arraySize);
	int 

### Return a pointer linking to a new array

    int * getArray(int arraySize);

>@Param \[ int size \] size of the array

The array is initialized with 0s

### Restart array with 0s

    int restartArray(int *array, int arraySize);

### Insert value