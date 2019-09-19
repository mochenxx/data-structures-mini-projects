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

Array* readArrayFile2(unsigned int* lines_count)
{
	unsigned int i = 0, j = 0;
	unsigned int items_count = 0; 
	char buffer[BSIZE] = { 0 };
	char* token;
	
	*lines_count = 0;

	Array* ptr_arrays;	// pointer to Array struct
	char ch;

	/* Read array file */
	FILE* fp = fopen(CSV_FILENAME, "r");

	/* Check if file can be opened */
	if (NULL == fp)
	{
		/* Display error message */
		perror("\n[ERROR] Unable to open array file!");
		exit(1);
	}

	while ((ch = fgetc(fp)) != EOF)
	{
		if ('\n' == ch)
		{
			(*lines_count)++;
		}
	}
	(*lines_count)++;

	// First - allocate memory for array rows
	ptr_arrays =(Array*)malloc(sizeof(Array) * (*lines_count));

	// Check if the memory has been successfully 
	// allocated by malloc or not 
	if (ptr_arrays == NULL)
	{
		printf("\n[ERROR] Not so much memory for arrays from file!\n");
		return NULL;
	}
	else
	{
		// Memory has been successfully allocated
		// Rewind the file
		rewind(fp);

		/* Process the data per row */
		while (fgets(buffer, BSIZE, fp))
		{
			items_count = 0;

			/* Get the first token */
			token = strtok(buffer, ",");
			items_count++;

			while (token != NULL)
			{
				token = strtok(NULL, ",");
				if (NULL == token)
				{
					break;
				}
				items_count++;
			}

			ptr_arrays[i].num_items = items_count;
			i++;
		}

		// Second - allocate memory for columns in each row
		for (i = 0; i < *lines_count; i++)
		{
			ptr_arrays[i].arr =(int*)malloc(sizeof(int) * (ptr_arrays[i].num_items));
		}
	}

	rewind(fp);

	/* Add elements to each array per line */
	for (i = 0; i < *lines_count; i++)
	{
		if (NULL == ptr_arrays || NULL == ptr_arrays[i].arr)
		{
			printf("\n[ERROR] Not such memory!\n");
			return NULL;
		}
		else
		{
			if (fgets(buffer, BSIZE, fp))
			{
				j = 0;

				/* Get the first token */
				token = strtok(buffer, ",");

				ptr_arrays[i].arr[j] = atoi(token);
				j++;

				/* Store the rest tokens as elements */
				while (token != NULL && j < ptr_arrays[i].num_items)
				{
					token = strtok(NULL, ",");
					if (NULL == token)
					{
						break;
					}

					ptr_arrays[i].arr[j] = atoi(token);
					j++;
				}
			}
		}
	}

	fclose(fp);

	// Return pointer to structure Array
	return ptr_arrays;
}
