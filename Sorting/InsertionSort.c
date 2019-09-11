/*
 *  File name: InsertionSort.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Insertion Sort
 */

#include "InsertionSort.h"
#include "SortHelper.h"

void insertionSort(int arr[], unsigned int n)
{
	unsigned int i, j;

	for (i = 1; i < n ; i++)
	{
		// Find proper position for arr[i] to insert
		for (j = i; j > 0 && arr[j] < arr[j-1] ; j--)
		{
			swap(&arr[j], &arr[j - 1]);
		}
	}
}

void insertionSortOptimized(int arr[], unsigned int n)
{
	unsigned int i, j;
	int e;

	for (i = 1; i < n; i++)
	{
		// Store element arr[i] in variable e
		e = arr[i];

		// Compare e with previous element
		// If e is less than previous element
		for (j = i; j > 0 && arr[j-1] > e; j--)
		{
			// Assign value of current index to the previous one
			arr[j] = arr[j - 1];
		}

		// Store variable e to proper position in array
		arr[j] = e;
	}
}
