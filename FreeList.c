/*
 * File name: FreeList.c
 *
 * Author: Mo Chen
 *
 * Description: C program to free memory of singly linked list
 */


#include "FreeList.h"
#include "structures.h"

void freeList(struct Dllist* dllist)
{
	struct Node* temp;

	/* Check if head_ref is NULL */
	if (NULL == dllist)
	{
		printf("\nInvalid argument!\n");
		return;
	}

	/* Check if head is NULL, if yes the list is empty, then we just return*/
	if (NULL == dllist->head)
	{
		printf("\nList is empty. No memory needed to free.\n");
		return;
	}

	while (NULL != dllist->head)
	{
		// Store head in the temp pointer
		temp = dllist->head;

		// Make head points to the next node in the list
		dllist->head = dllist->head->next;
		free(temp);
	}

	dllist->head = NULL;
	dllist->tail = NULL;
}