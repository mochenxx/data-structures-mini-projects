/*
 *  File name: SelectionSort.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Selection Sort
 */

#include "SelectionSort.h"
#include "SortHelper.h"

void selectionSort(int arr[], unsigned int n)
{
	unsigned int i, j, minIndex;

	// One by one move boundary of unsorted sub-array
	for (i = 0 ; i < n; i++)
	{
		minIndex = i;

		// Find the minimum element in unsorted array
		for (j = i + 1 ; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		// Swap the found minimum element with the first element
		swap(&arr[i], &arr[minIndex]);
	}
}

void selectionSortOptimized(int arr[], unsigned int n)
{
	unsigned int left = 0, right = n - 1;
	unsigned int minIndex, maxIndex;
	unsigned int i;

	while (left < right)
	{
		minIndex = left; 
		maxIndex = right;

		// Make sure arr[minIndex] <= arr[maxIndex]
		if (arr[minIndex] > arr[maxIndex])
		{
			swap(&arr[minIndex], &arr[maxIndex]);
		}

		// Find the minimum and the maximum element in unsorted array
		for ( i = left + 1; i < right; i++)
		{
			if (arr[i] < arr[minIndex])
			{
				minIndex = i;
			}
			else if (arr[i] > arr[maxIndex])
			{
				maxIndex = i;
			}
		}

		// Swap the found minimum element with the first element
		swap(&arr[left], &arr[minIndex]);

		// Swap the found maximum element with the last element
		swap(&arr[right], &arr[maxIndex]);

		left++;
		right--;
	}
}
