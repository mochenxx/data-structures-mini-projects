/*
 *  File name: main.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program for different sorting algorithms
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "SortHelper.h"
#include "Display.h"
#include "SwitchHelper.h"
#include "LogFile.h"

#pragma warning(disable:6011)

int main(void) {

	int* arr1;				// pointer to input array
	unsigned int size = 0;	// number of elements in the input array
	unsigned int i, j, lines_count = 0;
	int key_code;			// User input from keyboard

	char sort_method = 0;
	char sort_name[50] = { 0 };
	
	int* arr2;
	Array* arr_from_file;
	
	do 
	{
		displayMainMenu(&key_code);

		switch (key_code)
		{
			case KEY_ONE:
			{
				arr1 = inputArray(&size);
				displaySortMethod(&sort_method);

				/* Print array before sort */
				printf("\n+-----------------------------------+");
				printf("\nArray before sort:\n");
				printArray(arr1, size);

				/* Choose an sort method and implement it */
				chooseSortMethod(arr1, size, sort_method);
				printf("\n+-----------------------------------+\n");
				sort_method = 0;

				free(arr1);
				system("pause");
				break;
			}

			case KEY_TWO:
			{
				arr_from_file = readArrayFile2(&lines_count);

				displaySortMethod(&sort_method);

				printf("\n==> Data from files:");

				for (i = 0; i < lines_count; i++)
				{
					arr2 =(int*) malloc(sizeof(int) * arr_from_file[i].num_items);

					for (j = 0; j < arr_from_file[i].num_items; j++)
					{
						arr2[j] = arr_from_file[i].arr[j];
					}

					/* Print array before sort */
					printf("\n+------------------------ Line No. %d -----"
							 "------------------+", i+1);
					printf("\nArray before sort:\n");
					printArray(arr2, arr_from_file[i].num_items);

					/* Choose an sort method and implement it */
					printf("\n");
					chooseSortMethod(arr2, arr_from_file[i].num_items, sort_method);
					printf("\n+--------------------------------------------"
						"----------------+\n");

					free(arr2);
				}

				sort_method = 0;

				for (i = 0; i < lines_count; i++)
				{
					free(arr_from_file[i].arr);
				}

				free(arr_from_file);

				system("pause");

				break;
			}
			default:
			{
				break;
			}
		}
	} while (key_code != KEY_ESC);
	
	return 0;
}

