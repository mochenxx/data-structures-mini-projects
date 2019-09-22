/*
 * File name: FreeList.c
 *
 * Author: Mo Chen
 *
 * Description: C program to free memory of singly linked list
 */


#include "FreeList.h"
#include "structures.h"

void freeList(struct Node** head_ref)
{
	struct Node* temp;

	/* Check if head_ref is NULL */
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
		// Store head in the temp pointer
		temp = *head_ref;

		// Make head points to the next node in the list
		*head_ref = (*head_ref)->next;
		free(temp);
	}

	*head_ref = NULL;
}