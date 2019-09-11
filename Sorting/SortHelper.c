/*
 *  File name: SortHelper.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for Sort Helper functions
 */

#include "SortHelper.h"

void swap(int* px, int* py)
{
	int temp = *px;		// a variable to facilitate exchange
	*px = *py;
	*py = temp;
}

void printArray(int arr[], unsigned int n)
{
	unsigned int i;

	printf("** ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

int* inputArray(unsigned int* size)
{
	unsigned int i;
	*size = 0;

	printf("\n\n Enter the size of array [MAX %d]: ", MAX_SIZE);
	scanf_s("%u", size);

	int* arr = malloc(sizeof(int) * (*size));

	for (i = 0; i < *size; i++)
	{
		printf(" Enter the Element No.%2d: ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	return arr;
}
