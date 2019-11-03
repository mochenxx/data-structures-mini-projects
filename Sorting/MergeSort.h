/*
 *  File name: MergeSort.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for Merge Sort
 */

#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdlib.h>
#include <stdio.h>

/*
 * This function implements merge sort.
 * 
 * @param[in] arr[] - an integer array 
 * @param[in] l - left index of the sub-array of arr to be sorted
 * @param[in] r - right index of the sub-array of arr to be sorted
 *
 * @returns - None
 */
void mergeSort(int arr[], unsigned int l, unsigned int r);

/*
 * This function implements merge sort.
 *
 * @param[in] arr[] - an integer array
 * @param[in] l - left index of the sub-array of arr to be sorted
 * @param[in] r - right index of the sub-array of arr to be sorted
 *
 * @returns - None
 */
void mergeSortOptimized(int arr[], unsigned int l, unsigned int r);

#endif // _MERGESORT_H_
