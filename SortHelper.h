/*
 *  File name: SortHelper.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for Sort Helper functions
 */

#ifndef _SORTHELPER_H_
#define _SORTHELPER_H_

#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 100

/*
 * This function swap two integer variable
 *
 * @param[in] px - pointer that points to an input integer x
 * @param[in] px - pointer that points to an input integer x
 *
 * @ returns - None
 */
void swap(int* px, int* py);

/*
 * This function prints an array
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * @returns - nothing
 */
void printArray(int arr[], unsigned int n);

/*
 * This function is to input an array
 *
 * @param[in] size - pointer to array size (number of elements)
 *
 * @returns - nothing
 */
int* inputArray(unsigned int* size);

#endif // _SORTHELPER_H_
