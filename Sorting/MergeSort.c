/*
 *  File name: mergeSort.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Merge Sort
 */

#include "MergeSort.h"
#include "SortHelper.h"

void merge(int arr[], unsigned int l, unsigned int m, unsigned int r)
{
	unsigned int i, j, k;
	const unsigned int n1 = m - l + 1;
	const unsigned int n2 = r - m;

	/* Create temp arrays */
	unsigned int L[MAX_SIZE];
	unsigned int R[MAX_SIZE];


	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
	{
		L[i] = arr[l + i];
	}

	for (j = 0; j < n2; j++)
	{
		R[j] = arr[m + 1 + j];
	}

	/* Merge the temp array back int arr[l...r] */
	i = 0;	// Initial index of the first sub-array
	j = 0;	// Initial index of the second sub-array
	k = l;  // Initial index of the merged array

	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining element in L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}


	/* Copy the remaining element in R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], unsigned int l, unsigned int r)
{
	int m; // middle index of the sub-array of the arr

	if (l < r)
	{
		m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
