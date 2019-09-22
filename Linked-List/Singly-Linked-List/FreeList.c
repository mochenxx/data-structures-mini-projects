/*
 * File name: FreeList.c
 *
 * Author: Mo Chen
 *
 * Description: C program to free memory of singly linked list
 */

#include "FreeList.h"
#include "structure.h"

void freeList(struct Node** head_ref)
{
	struct Node* temp;

	/* Check if reference to head is pointer is NULL */
	if (NULL == head_ref)
	{
		printf("\nInvalid argument!\n");
		return;
	}

	/* Check if head is NULL, if yes the list is empty, then we just return*/
	if (NULL == *head_ref)
	{
		printf("\nList is empty. No memory needed to free.\n");
		return;
	}

	while (NULL != *head_ref)
	{
		// Save head in the temp variable
		temp = *head_ref;

		// Make head points to the next node in the list
		*head_ref = (*head_ref)->link;
		free(temp);
	}

	*head_ref = NULL;
}