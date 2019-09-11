/*
 *  File name: InsertionSort.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for Insertion Sort
 */

#ifndef _INSERTIONSORT_H_
#define _INSERTIONSORT_H_

#include <stdlib.h>
#include <stdio.h>

/*
 * This function implements a insertion sort
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * returns - nothing
 */
void insertionSort(int arr[], unsigned int n);

/*
 * This function implements an optimized insertion sort
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * returns - nothing
 */
void insertionSortOptimized(int arr[], unsigned int n);

#endif // _INSERTIONSORT_H_
