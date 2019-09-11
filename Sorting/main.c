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
	unsigned int i, j;
	int key_code;			// User input from keyboard

	char sort_method = 0;
	char sort_name[50] = { 0 };
	int** ptr_arr2;
	int* arr2;
	
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
				ptr_arr2 = readArrayFile();

				displaySortMethod(&sort_method);

				printf("\n==> Data from files:");

				for (i = 0; i < ROW; i++)
				{
					arr2 = malloc(sizeof(int) * COL);

					for (j = 0; j < COL; j++)
					{
						arr2[j] = ptr_arr2[i][j];
					}

					/* Print array before sort */
					printf("\n+------------------------ Line No. %2d -----"
							 "------------------+", i+1);
					printf("\nArray before sort:\n");
					printArray(arr2, COL);

					/* Choose an sort method and implement it */
					printf("\n");
					chooseSortMethod(arr2, COL, sort_method);
					printf("\n+--------------------------------------------"
						"----------------+\n");
				}

				sort_method = 0;

				for (i = 0; i < ROW; i++)
				{
					free(ptr_arr2[i]);
				}

				free(ptr_arr2);
				free(arr2);

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

