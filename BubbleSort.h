/*
 *  File name: BubbleSort.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for Bubble Sort
 */

#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * This function implements bubble sort
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * @returns - nothing
 */
void bubbleSort(int arr[], unsigned int n);

/*
 * This function implements an optimized bubble sort
 *
 * @param[in] arr[] - an integer array
 * @param[in] n - number of elements in array
 *
 * @returns - nothing
 */
void bubbleSortOptimized(int arr[], unsigned int n);

#endif // _BUBBLE_SORT_H_
