/*
 *  File name: SelectionSort.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for Selection Sort
 */

#ifndef _SELECTIONSORT_H_
#define _SELECTIONSORT_H_

#include <stdlib.h>
#include <stdio.h>
/*
 * This function implements selection sort
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * @returns - nothing
 */
void selectionSort(int arr[], unsigned int n);

/*
 * This function implements an optimized selection sort.
 *
 * 1) In every iteration, the minimum and maximum element can be both found. 
 * 2) It puts minimum element at the beginning, the maximum element at the end.
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * @returns - nothing
 */
void selectionSortOptimized(int arr[], unsigned int n);

#endif // _SELECTIONSORT_H_
