/*
 * File name: ListHelper.c
 *
 * Author: Mo Chen
 *
 * Description: C program for list helper functions
 */

#include "ListHelper.h"
#include "TimeInfo.h"
#include "Display.h"

 /*
  * Disable warning of unsafe functions
  * _CRT_SECURE_NO_WARNINGS
  */
#pragma warning(disable : 4996)

Element* inputList(unsigned int* size, unsigned int* count)
{
	unsigned int i;
	*size = 0;
	*count = 0;
	int buffer = 0;

	/* Get the size of list */
	printf("\nEnter the size of list [MAX: %d]: ", MAX_SIZE);
	scanf_s("%u", size);

	/* Allocate dynamic memory to list pointer */
	Element* list = malloc((*size) * sizeof(Element));

	/* Input element one by one */
	for (i = 0; i < *size; i++)
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
		list[i].element = buffer;
		list[i].time = time(NULL);
	}

	*count = *size;
	return list;
}

bool isUnique(Element* list, unsigned int count, int item)
{
	unsigned int i;
	for (i = 0; i < count; i++)
	{
		if (item == list[i].element)
		{
			return false;
		}
	}
	return true;
}

void addItem(Element* list, unsigned int size, unsigned int* count, int new_item)
{
	list[*count].element = new_item;
	list[*count].time = time(NULL);

	printf("\n==> You have added element '%d' to the list!", new_item);
	(*count)++;
}

bool isExisting(Element* list, unsigned int count, int item)
{
	unsigned int i;
	/* Check if item exists */
	for (i = 0; i < count; i++)
	{
		if (list[i].element == item)
		{
			return true;
		}
	}

	return false;
}

void deleteItem(Element* list, unsigned int* count, int delete_item)
{
	unsigned int i, j;
	unsigned int item_exist = 0;

	/* Check if item to be deleted exists */
	for (i = 0; i < *count; i++)
	{
		if (list[i].element == delete_item)
		{
			printf("\n==> You have deleted element '%d' from list!", 
				   list[i].element);
			for (j = i; j < *count - 1; j++)
			{
				list[j] = list[j + 1];
			}

			list[j].element = 0;
			list[j].time = 0;

			item_exist = 1;

			break;
		}
	}

	if (item_exist != 1)
	{
		printf("\n [ERROR] Input element doesn't exist in the list!");
	}

	(*count)--;
	return;
}

void printListElements(Element* list, unsigned int count)
{
	unsigned int i;

	for (i = 0; i < count; i++)
	{
		printf("%2d  ",list[i].element);
	}
	printf("\n");

}

void printListWithTime(Element* list, unsigned int count)
{
	unsigned int i;

	for (i = 0; i < count; i++)
	{
		printf("%2d |Time of addition: %s|\n", 
			list[i].element, 
			getTimeString(list[i].time));
	}
	printf("\n");
}

void clearList(Element* list, unsigned int* count)
{
	unsigned int i;

	for (i = 0; i < *count; i++)
	{
		list[i].element = 0;
		list[i].time = 0;
	}

	*count = 0;
}

int sum(Element* list, unsigned int count)
{
	int sum = 0;	// initialize sum
	unsigned int i;

	// Iterate all elements and add them to sum
	for (i = 0; i < count; i++)
	{
		sum += list[i].element;
	}

	return sum;
}

void chooseDeleteOP(Element* list, unsigned int* count)
{
	int delete_item;
	unsigned int isValid = 0;		// Flag indicating if input choice is valid
	unsigned int i, lastIdx, oldestIdx;		// last & oldest added items index
	char choice = 0;						// Input choice from keyboard

	while (!isValid)
	{
		/* Get the input from the user */
		printf("\n\n Enter a number: ");
		choice = _getch();

		switch (choice)
		{
			// Delete last added element
			case '1':
			{
				lastIdx = 0;	// Initialize the minimum index

				// Find the last added element based on store time
				for (i = 0; i < *count; i++)
				{
					if (list[i].time > list[lastIdx].time)
					{
						lastIdx = i;
					}
				}

				// Print success message
				printf("\n\n==>You have deleted '%d' as last added element !\n",
					list[lastIdx].element);

				// Delete found element and move elements behind it one by one
				for (i = lastIdx; i < (*count) - 1; i++)
				{
					list[i].element = list[i + 1].element;
					list[i].time = list[i + 1].time;
				}

				// Decrement count number
				(*count)--;

				/* Print list after removal */
				printf("\n List after removal:\n");
				printListElements(list, *count);
				
				// Set isValid flag to one
				isValid = 1;

				break;
			}

			// Delete oldest added element
			case '2':
			{
				oldestIdx = 0;	// Initialize the minimum index

				// Find the last added element based on store time
				for (i = 0; i < *count; i++)
				{
					if (list[i].time < list[oldestIdx].time)
					{
						oldestIdx = i;
					}
				}

				// Print success message
				printf("\n\n==>You have deleted '%d' as oldest added element!\n",
					list[oldestIdx].element);

				// Delete found element and move elements behind it one by one
				for (i = oldestIdx; i < (*count) - 1; i++)
				{
					list[i].element = list[i + 1].element;
					list[i].time = list[i + 1].time;
				}

				// Decrement count number
				(*count)--;

				/* Print list after removal */
				printf("\n List after removal:\n");
				printListElements(list, *count);

				// Set flag to one
				isValid = 1;

				break;
			}

			// Delete specific element in the list
			case '3':
			{
				/* Get item to be deleted */
				printf("\n Enter the number you want to DELETE: ");
				scanf_s("%d", &delete_item);

				while (!isExisting(list, *count, delete_item))
				{
					printf("\n [ERROR] Input element doesn't exist!");

					/* Input element once again */
					printf("\n Enter the item you want to DELETE: ");
					scanf_s("%d", &delete_item);
				}

				/* Delete input item from the list */
				deleteItem(list, count, delete_item);

				/* Print list after removal */
				printf("\n List after removal:\n");
				printListElements(list, *count);

				// Decrement count number
				(*count)--;

				// Set flag to one
				isValid = 1;

				break;
			}

			default:
			{
				/* Print error message */
				printf("\n\n [ERROR] Invalid Input! Please try again!\n");

				// Set flag to zero (by default)
				isValid = 0;

				break;
			}
		}
	}
}

void chooseFetchOP(Element* list, unsigned int* count)
{
	unsigned int i, isValid = 0;	// Flag indicating if input choice is valid
	unsigned int record_exist = 0;	// Flag indicating if record exists
	char choice = 0;				// Input choice from keyboard
	unsigned int hour = 0, min = 0; // hour & minute of element addition time

	// FetchTime structure to store time interval
	FetchTime start_time = { 0 }, end_time = { 0 };

	while (!isValid)
	{
		/* Get the input from the user */
		printf("\n\n Enter a number: ");
		choice = _getch();

		switch (choice)
		{
			// Fetch all records after a time
			case '1':
			{
				// Get a time from keyboard
				printf("\n\n*** Fetch all records after a time ***\n");
				printf("\nEnter a time (format is HH:MM): ");
				(void)scanf("%d:%d", &start_time.hour, &start_time.minute);

				printf("\n +--------------------+");
				printf("\n |  Fetching Results  |");
				printf("\n +--------------------+\n");

				// Find elements after input time
				for (i = 0; i < *count; i++)
				{
					// Get time of element addition
					hour = getTimeHour(list[i].time);
					min = getTimeMinute(list[i].time);

					// Check if time of element addition is after input time
					if ((hour == start_time.hour && min > start_time.minute) 
						|| hour > start_time.hour)
					{
						// Print element value
						printf("%2d  ", list[i].element);

						record_exist = 1;
					}
				}

				// Check if record that meet requirements exists
				if (0 == record_exist)
				{
					// If no record exists, print error message
					printf("\n[ERROR] There is no record after this time!\n");
				}

				printf("\n");
				isValid = 1;	// Set flag to one
				
				break;
			}

			// Fetch all records before a time
			case '2':
			{
				// Get a time from input
				printf("\n*** Fetch all records before a time ***\n");
				printf("\nEnter a time (format is HH:MM): ");
				(void)scanf("%d:%d", &start_time.hour, &start_time.minute);

				printf("\n +--------------------+");
				printf("\n |  Fetching Results  |");
				printf("\n +--------------------+\n");

				// Find elements before input time
				for (i = 0; i < *count; i++)
				{
					// Get time of element addition
					hour = getTimeHour(list[i].time);
					min = getTimeHour(list[i].time);

					// Check if time of element addition is before input time
					if ((hour == start_time.hour && min < start_time.minute)
						|| hour < start_time.hour)
					{
						// Print element value
						printf("%2d  ", list[i].element);

						record_exist = 1;
					}
				}

				// Check if record that meet requirements exists
				if (0 == record_exist)
				{
					// If no record exists, print error message
					printf("\n[ERROR] There is no record before this time!\n");
				}

				printf("\n");
				isValid = 1;	// Set flag to one

				break;
			}

			// Fetch all records between a time interval
			case '3':
			{
				// Get a time interval from input
				printf("\n\n***"
					   " Fetch all records between a time interval "
					   "***\n");
				printf("\nEnter Start Time (format is HH:MM): ");
				(void)scanf("%d:%d", &start_time.hour, &start_time.minute);

				printf("\nEnter End Time (format is HH:MM): ");
				(void)scanf("%d:%d", &end_time.hour, &end_time.minute);

				printf("\n +--------------------+");
				printf("\n |  Fetching Results  |");
				printf("\n +--------------------+\n");

				// Find elements after input time
				for (i = 0; i < *count; i++)
				{
					// Get time of element addition
					hour = getTimeHour(list[i].time);
					min = getTimeHour(list[i].time);

					// Check if time of element addition is 
					// after input start time
					if ((hour == start_time.hour && min > start_time.minute)
						|| hour > start_time.hour)
					{
						// Check if time of element addition is 
						// before input end time
						if ((hour == end_time.hour && min < end_time.minute)
							|| hour < end_time.hour)
						{
							// Print element value
							printf("%2d  ", list[i].element);

							record_exist = 1;
						}
					}
				}

				// Check if record that meet requirements exists
				if (0 == record_exist)
				{
					// If no record exists, print error message
					printf("\n[ERROR] There is no record after this time!\n");
				}

				printf("\n");
				isValid = 1;	// Set flag to one
				break;
			}

			default:
			{
				// Print error message
				printf("\n\n [ERROR] Invalid Input! Please try again!\n");

				record_exist = 0;	// Set flag to zero by default
				isValid = 0;		// Set flag to zero by default
				break;
			}
		}
	}
}