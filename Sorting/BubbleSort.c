/*
 *  File name: BubbleSort.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Bubble Sort
 */

#include "BubbleSort.h"
#include "SortHelper.h"

void bubbleSort(int arr[], unsigned int n)
{
	unsigned int i, j;

	// Bubble sort requires (n-1) pass
	for (i = 0; i < n - 1; i++)
	{
		// For comparison
		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
		{
			// Check if adjacent elements are not in order
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bubbleSortOptimized(int arr[], unsigned int n)
{
	bool isSorted = false;	// flag indicating if array is sorted
	unsigned int i, lastUnsorted = n - 1;

	while (!isSorted)
	{
		isSorted = true;

		for (i = 0; i < lastUnsorted; i++)
		{
			// Check if adjacent elements are not in order
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				
				// Set flag to false
				isSorted = false;
			}
		}

		// Decrement last unsorted index
		lastUnsorted--;
	}
}
