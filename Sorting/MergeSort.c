/*
 *  File name: mergeSort.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Merge Sort
 */

#include "MergeSort.h"
#include "SortHelper.h"

/*
 * This function merges sorted sub-arrays back till the complete array is merged.
 * This is the previous functions that implements merging functionality.
 * Please check the next function for more updates.
 *
 * @param[in] arr[] - an integer array
 * @param[in] l - left index of the sub-array of arr to be sorted
 * @param[in] mid - middle index of the sub-array of arr to be sorted
 * @param[in] r - right index of the sub-array of arr to be sorted
 *
 * @returns - None
 */
static void previousMerge(int arr[], unsigned int l, unsigned int m, unsigned int r)
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

/*
 * This updated function merges sorted sub-arrays back till the complete array is merged.
 *
 * @param[in] arr[] - an integer array
 * @param[in] l - left index of the sub-array of arr to be sorted
 * @param[in] mid - middle index of the sub-array of arr to be sorted
 * @param[in] r - right index of the sub-array of arr to be sorted
 *
 * @returns - None
 */
static void merge(int arr[], unsigned int l, unsigned int mid, unsigned int r)
{
	// Arguments consistency check
	if (NULL == arr)
	{
		return;
	}

	unsigned int i, j, k; // k stores the index for merged array

	// Allocate memory for a temporary array to store input array
	int* temp = (int*)malloc((r - l + 1) * sizeof(int));
	
	// Consistency check
	if (temp == NULL)
	{
		printf("[ERROR] No such memory to allocate.\n");
		return;
	}
	else
	{
		// Copy contents of input array to temp, with range of [l, r]
		for (i = l; i <= r; i++)
		{
			temp[i - l] = arr[i];
		}

		i = l;			// Initial index of the first sub-array
		j = mid + 1;	// Initial index of the second sub-array
		
		// Merge sorted array from range of [l, r]
		for (k = l; k <= r; k++)
		{
			// 1. i is out of boundary
			if (i > mid)
			{
				arr[k] = temp[j - l];
				j++;
			}
			// 2. j is out of boundary
			else if (j > r)
			{
				arr[k] = temp[i - l];
				i++;
			}
			// 3. element of first sub-array is less than that of second sub-array
			else if (temp[i - l] < temp[j - l])
			{
				arr[k] = temp[i - l];
				i++;
			}
			else
			{
				arr[k] = temp[j - l];
				j++;
			}
		}
	}
}

void mergeSort(int arr[], unsigned int l, unsigned int r)
{
	// Arguments consistency check
	if (NULL == arr)
	{
		return;
	}

	unsigned int mid;

	if (l >= r)
	{
		return;
	}
	else
	{
		// middle index of the sub-array of the arr
		mid = l + (r - l) / 2;

		// Merge sort the first and the second halves
		mergeSort(arr, l, mid);
		mergeSort(arr, mid + 1, r);

		// Merge two sorted parts
		merge(arr, l, mid, r);
	}
}