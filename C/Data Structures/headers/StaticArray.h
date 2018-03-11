//
// Created by leona on 09/03/2018.
//

#ifndef STATICARRAY_H
#define STATICARRAY_H

/*
 * Return a pointer linking to an array of size n
 *
 * @Param [ int *array ] pointer address to your array
 * @Param [ int size ] size of the array
 */
int * getArray(int size);

/*
 * Initialize every position with 0s
 *
 * @Param [ int *array ] pointer address to your array
 * @Param [ int size ] size of the array
 */
int initArray(int *array, int size);

/*
 * Insert value to next available position
 *
 * @Param [ int *array ] pointer address to your array
 * @Param [ int size ] size of the array
 * @Param [ int value ] value to be inserted
 */
int pushValueArray(int *array, int size, int value);

/*
 * Insert value to specified position
 *
 * @Param [ int *array ] pointer address to your array
 * @Param [ int size ] size of the array
 * @Param [ int position ] desired position to insert a value
 * @Param [ int value ] value to be inserted
 */
int insertValueArray(int *array, int size, int position, int value);

/*
 * Print array
 *
 * @Param [ int *array ] pointer address to your array
 * @Param [ int size ] size of the array
 */
int printArray(int *array, int size);

#endif //STATICARRAY_H
