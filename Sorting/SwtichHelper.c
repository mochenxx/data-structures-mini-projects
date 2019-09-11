/*
 *  File name: SwitchHelper.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Switch Helper functions
 */

#include "SwitchHelper.h"
#include "SortHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "MergeSort.h"

void chooseSortMethod(int arr[], unsigned int size, char sort_method)
{
	char sort_name[50] = { 0 };	// Name of sort method

	switch (sort_method)
	{

		/* For Selection sort standard */
		case '1':
		{
			selectionSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name),"Selection sort (standard)");

			break;
		}

		/* For Insertion sort standard */
		case '2':
		{
			insertionSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Insertion sort (standard)");

			break;
		}

		/* For Bubble sort standard */
		case '3':
		{
			bubbleSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Bubble sort (standard)");

			break;
		}

		/* For Merge sort standard */
		case '4':
		{
			mergeSort(arr, 0, size - 1);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Merge sort (standard)");

			break;
		}

		/* For Selection sort optimized */
		case '5':
		{
			selectionSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Selection sort (optimized)");

			break;
		}

		/* For Insertion sort optimized */
		case '6':
		{
			insertionSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Insertion sort (optimized)");

			break;
		}

		/* For Bubble sort optimized */
		case '7':
		{
			bubbleSort(arr, size);

			// Copy name of sort method string to sort_name
			strcpy_s(sort_name, sizeof(sort_name), "Bubble sort (optimized)");

			break;
		}

		default:
		{
			printf("\n[ERROR] Invalid Input!\n");
			break;
		}
	}

	/* Print array after selected sort method */
	printf("\nArray after %s:\n", sort_name);
	printArray(arr, size);
}
