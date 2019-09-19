/*
 * File name: ListHelper.c
 *
 * Author: Mo Chen
 *
 * Description: C program for list helper functions
 */

#include "ListHelper.h"

int* inputList(unsigned int* size, unsigned int* count)
{
	unsigned int i, num = 0;

	// Arguments consistency checks
	if ((NULL == size) || (NULL == count)) {
		printf("Invalid arguments %u, %u", NULL == size, NULL == count);
		return NULL;
	}

	*size = 0;
	*count = 0;
	int buffer = 0;

	/* Get the size of list */
	printf("\nEnter the size of list [MAX: %d]: ", MAX_SIZE);
	scanf_s("%u", size);

	/* Allocate dynamic memory to list pointer */
	int* list = malloc((*size) * sizeof(int));
	
	// Return values consistency checks
	if (NULL == list) {
		printf("\nNot enough memory\n");
		return NULL;
	}

	/* Initialize list */
	for (i = 0; i < *size; i++)
	{
		list[i] = 0;
	}

	/* Input element one by one */
	printf("\nHow many elements do you want to initialize?");
	printf("\nEnter a number : ");
	scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		printf("\nEnter the element No. %u: ", i + 1);
		scanf_s("%d", &buffer);

		/* Check if entered number is unique */
		while (!isUnique(list, *size, buffer))
		{
			/* If not unique, then print error */
			printf("\n [ERROR] Element must be unique!Please try again.");

			/* Input that element once again */
			printf("\n Enter the element No. %u: ", i + 1);
			scanf_s("%d", &buffer);
		}

		/* Entered element is unique - store element to corresponding index */
		list[i] = buffer;
	}

	*count = num;
	return list;
}

bool isUnique(int* list, unsigned int count, int item)
{
	// Arguments consistency checks
	if (NULL == list) {
		printf("Invalid arguments");
		return false;
	}

	unsigned int i;
	for (i = 0; i < count; i++)
	{
		if (item == list[i])
		{
			return false;
		}
	}

	return true;
}

void addItem(int* list, unsigned int size, unsigned int* count, int new_item)
{
	unsigned int i;

	// Arguments consistency checks
	if ((NULL == list) || (NULL == count))
	{
		printf("\nInvalid arguments %d, %u", NULL == list, NULL == count);
		return;
	}

	/* Detect if list is full */
	for (i = 0; i < size; i++)
	{
		if ( 0 == list[i])
		{
			list[i] = new_item;
			printf("\n==>You have added element '%d' to the list!", list[i]);
			(*count)++;
			return;
		}
	}
}

bool isExisting(int* list, unsigned int count, int item)
{
	unsigned int i;

	// Arguments consistency checks
	if (NULL == list)
	{
		printf("\nInvalid argument");
		return false;
	}

	/* Check if item exists */
	for (i = 0; i < count; i++)
	{
		if (list[i] == item)
		{
			return true;
		}
	}

	return false;
}

void deleteItem(int* list, unsigned int* count, int delete_item)
{
	unsigned int i, j;
	unsigned int item_exist = 0;

	// Arguments consistency checks
	if ((NULL == list) || (NULL == count))
	{
		printf("\nInvalid arguments %d, %u", NULL == list, NULL == count);
		return;
	}

	/* Check if item to be deleted exists */
	for (i = 0; i < *count; i++)
	{
		if (list[i] == delete_item)
		{
			printf("\n==>You have deleted element '%d' from list!", list[i]);
			for (j = i; j < *count - 1; j++)
			{
				list[j] = list[j + 1];
			}

			list[j] = '\0';
			
			item_exist = 1;

			break;
		}
	}

	/* If item dose not exits */
	if (item_exist != 1)
	{
		/* Print error message */
		printf("\n [ERROR] Input element doesn't exist in the list!");
	}

	/* List count decrement */
	(*count)--;
	return;
}

void printList(int* list, unsigned int count)
{
	unsigned int i;

	// Arguments consistency checks
	if (NULL == list)
	{
		printf("\nInvalid argument");
		return;
	}

	if (0 == count)
	{
		printf(" [ List is empty! ]\n");
		return;
	}

	// If input list pointer is not NULL, then print the whole list
	for (i = 0; i < count; i++)
	{
		printf("%2d  ", list[i]);
	}
	printf("\n");
}

void clearList(int* list, unsigned int* count)
{
	unsigned int i;

	// Arguments consistency checks
	if ((NULL == list) || (NULL == count))
	{
		printf("\nInvalid arguments %d, %u", NULL == list, NULL == count);
		return;
	}

	// If input list pointer is not NULL, then clear all elements in the list
	for (i = 0; i < *count; i++)
	{
		list[i] = 0;
	}

	*count = 0;
}

int sum(int* list, unsigned int count, int* sum_val)
{
	*sum_val = 0;	// initialize sum
	unsigned int i;

	// Arguments consistency checks
	if ((NULL == list) || (NULL == sum_val))
	{
		printf("\nInvalid arguments %d, %d\n", NULL == list, NULL == sum_val);
		return -1;
	}

	// Iterate all elements and add them to sum
	for (i = 0; i < count; i++)
	{
		*sum_val += list[i];
	}

	return 0;
}