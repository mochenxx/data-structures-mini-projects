/*
 *  File name: LogFile.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program to read log file
 */

#include "LogFile.h"

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

int** readArrayFile(void)
{
	unsigned int i, j;
	int** ptr_arr;	// pointer to pointer of 2D int array

	/* Allocate memory for ptr_arr */
	// First - allocate memory for rows
	ptr_arr = malloc(sizeof(int*) * ROW);

	if (ptr_arr)
	{
		//**ptr_arr = 0;
		// Second - allocate memory for columns in each row
		for (i = 0; i < ROW; i++)
		{
			ptr_arr[i] = malloc(sizeof(int) * COL);
		}
	}
	

	/* Read array file */
	FILE* fp = fopen(ARRAY_FILENAME, "r");

	/* Check if file can be opened */
	if (NULL == fp)
	{
		/* Display error message */
		perror("\n[ERROR] Unable to open array file!");
		exit(1);
	}

	/* Process the data */
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (ptr_arr && ptr_arr[i])
			{
				/* Get element one by one from each row */
				if (fscanf(fp, "%d", &ptr_arr[i][j]) != 1)
				{
					exit(1);
				}
			}
			
		}
	}
	
	fclose(fp);
	
	// Return pointer to pointer of 2d integer array
	return ptr_arr;
}