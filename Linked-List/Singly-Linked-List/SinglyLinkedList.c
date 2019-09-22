 /*
 * File name: SinglyLinkedList.c
 *
 * Author: Mo Chen
 *
 * Description: C program for singly linked list functions
 */

#include "SinglyLinkedList.h"
#include "structure.h"

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

#define MAX 20

int displayList(struct Node* head)
{
	struct Node* p;

	/* Check if the head node is NULL */
	if (NULL == head)
	{
		/* The list is empty */
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	/* pointer to the head of list*/
	p = head;

	/* Display the whole info in list */
	printf("\n**Input Linked List is :\n");
	while (p != NULL)
	{
		printf("%d  ", p->info);
		p = p->link;
	}

	printf("\n\n");
	return 0;
}   // End of displayList()

void printReverse(struct Node* head)
{
	// Base case
	if (NULL == head)
	{
		return;
	}

	// Print the node after head node
	printReverse(head->link);

	// After everything else is printed, print head
	printf("%d  ", head->info);
}

int countNode(struct Node* head)
{
	struct Node* current;	// pointer to current node
	unsigned int count = 0; // count stores the number of nodes in list

	/* Check if list is empty */
	if (NULL == head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	current = head;
	while (current != NULL)
	{
		count++;
		current = current->link;
	}

	/* Display the number of nodes in list */
	printf("\n**Number of nodes in list = %d\n\n", count);
	return count;
}	// End of countNode()

int search(struct Node* head, int data)
{
	struct Node* current; // node pointer starting from the head of list

	unsigned int position = 1; // position of nodes having the searching data
							   // initialized by 1 (head of the list)

	/* Check if list is empty */
	if (NULL == head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	current = head;
	/* Traverse the list to search for data */
	while (current != NULL)
	{
		/* If this node contains required data, then loop terminates */
		if (data == current->info)
		{
			break;
		}

		/* Else increment position, and points to the next node */
		position++;
		current = current->link;
	}

	/* Check if found required data */
	if (NULL == current)
	{
		printf("\n[ERROR] %d not found in list!\n", data);
		return -1;
	}
	else
	{
		printf("\n**%d is at position %d.\n", data, position);
		return 0;
	}
}	// End of search()

void insertAtFront(struct Node** head_ref, int new_data)
{
	/* Allocate a new node */
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	/* Check if there is memory for newly created node */
	if (NULL == temp)
	{
		printf("\n[ERROR] No more memory for new node!\n");
		return;
	}
	else
	{
		/* Put in the new data */
		temp->info = new_data;

		/* Make link of new node as head */
		temp->link = (*head_ref);
	}

	/* Move the head to point to the new node */
	(*head_ref) = temp;
}	// End of insertAtFront()

void insertAtEnd(struct Node** head_ref, int new_data)
{
	/* Allocate the new node */
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref;	// pointer to the last node

	/* Check if there is memory for newly created node */
	if (NULL == temp)
	{
		printf("\n[ERROR] No more memory for new node!\n");
		return;
	}
	else
	{
		/* Put in the new data */
		temp->info = new_data;

		/* This new node is going to be the last node,
		   so make the link of it as NULL */
		temp->link = NULL;
	}

	/* If the linked list is empty, then make the new node as head */
	if (NULL == *head_ref)
	{
		*head_ref = temp;
		return;
	}

	/* Else Traverse till the end */
	while (last->link != NULL)
	{
		last = last->link;
	}

	/* Change the link of the second last node*/
	last->link = temp;
}	// End of insertAtEnd()

void insertAfter(struct Node** head_ref, int new_data, int x)
{
	struct Node* temp;
	struct Node* prev_node = *head_ref;	// pointer to the previous node

	/* Check if list is empty */
	if (NULL == *head_ref)
	{
		printf("\n[ERROR] List is empty!\n");
		return;
	}

	/* Find pointer to predecessor of node containing x */
	while (NULL != prev_node)
	{
		if (prev_node->info == x)
		{
			break;
		}

		prev_node = prev_node->link;
	}

	/* Check if input data is not found after traversal of the list */
	if (NULL == prev_node)
	{
		printf("\n[ERROR] %d not present in the list!", x);
		return;
	}
	else
	{
		/* Allocate memory to the new node */
		temp = (struct Node*)malloc(sizeof(struct Node));

		/* Check if there is memory for newly created node */
		if (NULL == temp)
		{
			printf("\n[ERROR] No more memory for new node!\n");
			return;
		}
		else
		{
			/* Put in the new data to the new node */
			temp->info = new_data;

			/* Insert new node after found previous node */
			temp->link = prev_node->link;
		}

		/* Move the found node to point to the newly created node */
		prev_node->link = temp;

		printf("\n**Successfully inserted %d after %d in the list.\n",
			new_data, x);
	}
}	// End of insertAfter()

void insertBefore(struct Node** head_ref, int new_data, int x)
{
	struct Node* temp;
	struct Node* prev = *head_ref;	// pointer to the previous node

	/* 1. Check if list if empty */
	if (NULL == *head_ref)
	{
		printf("\n[ERROR] List is empty!");
		return;
	}

	/* 2. If x is in the first node, new node should be inserted as head */
	else if ((*head_ref)->info == x)
	{
		temp = (struct Node*)malloc(sizeof(struct Node));

		/* Check if there is memory for newly created node */
		if (NULL == temp)
		{
			printf("\n[ERROR] No more memory for new node!\n");
			return;
		}
		else {
			/* Put in new data */
			temp->info = new_data;

			/* Insert new node as head */
			temp->link = *head_ref;

			/* Move head to point to the newly inserted node */
			*head_ref = temp;

			printf("\n**Successfully inserted %d before %d in the list.\n",
				   new_data, x);

			return;
		}
	}

	/* 3. Else, traverse the link to search for the node before target data */
	while (prev != NULL)
	{
		if (prev->link->info == x)
		{
			break;
		}

		prev = prev->link;
	}

	/* 4. Check if input data is not found after traversal of the list */
	if (NULL == prev)
	{
		printf("\n[ERROR] %d is not found in the list!", x);
		return;
	}
	else
	{
		/* Allocate memory to the new node */
		temp = (struct Node*)malloc(sizeof(struct Node));

		/* Check if there is memory for newly created node*/
		if (NULL == temp)
		{
			printf("\n[ERROR] No more memory for new node!\n");
		}
		else
		{
			/* Put in the new data */
			temp->info = new_data;

			/* Insert new node after found node */
			temp->link = prev->link;

			/* Move the previous node to the new node */
			prev->link = temp;

			printf("\n**Successfully inserted %d before %d in the list.\n",
				new_data, x);
		}
	}
}	// End of insertBefore()

void insertAtPosition(struct Node** head_ref, int new_data, unsigned int k)
{
	struct Node* temp, * current;
	unsigned int i;

	/* 1. Check if input position is the head */
	if (1 == k)
	{
		insertAtFront(head_ref, new_data);
		return;
	}
	else if (NULL == *head_ref)
	{
		printf("\n[ERROR] List is empty. " 
				 "Data can only be insert at position 1.\n");
		return;
	}

	current = *head_ref;

	/* 2. Else, find a pointer to (k-1)th node */
	for (i = 1; i < k - 1 && current != NULL; i++)
	{
		current = current->link;
	}

	/* 3. Check if input value k is out of boundary */
	if (NULL == current)
	{
		printf("\n[ERROR] Invalid Input! "
			"You can insert only up to %dth position!\n",
			i);
		return;
	}
	else
	{
		/* Allocate memory for new node */
		temp = (struct Node*)malloc(sizeof(struct Node));

		/* Check if there is memory for new node */
		if (NULL == temp)
		{
			printf("\n[ERROR] No more memory for the new node!\n");
			return;
		}
		else
		{
			// Put in new data
			temp->info = new_data;

			// Insert new node at k-th position
			temp->link = current->link;

			// Move (k-1)th node pointing to the new node
			current->link = temp;

			printf("\n**Successfully inserted %d at %d-th position.\n",
				new_data, k);
		}
	}
}	// End of insertAtPosition()

bool isUnique(struct Node* head, int data)
{
	struct Node* current;

	if (NULL == head)
	{
		return true;
	}

	current = head;
	while (current != NULL)
	{
		if (data == current->info)
		{
			return false;
		}

		current = current->link;
	}

	return true;
}	// End of isUnique()

void deleteNode(struct Node** head_ref, int x)
{
	struct Node* temp, * ptr;

	if (NULL == *head_ref)
	{
		printf("\n[ERROR] List is empty\n");
		return;
	}

	/* 1. Deletion of the first node */
	if (x == (*head_ref)->info)
	{
		// Store head to temp node
		temp = *head_ref;

		// Move head to the next node
		*head_ref = (*head_ref)->link;

		// Free the first node memory
		free(temp);

		return;
	}

	/* 2. Deletion in between or at the end */
	ptr = *head_ref;
	while (ptr->link != NULL)
	{
		if (x == ptr->link->info)
		{
			break;
		}

		ptr = ptr->link;
	}

	/* If input element is not existing in the list */
	if (NULL == ptr->link)
	{
		printf("\n[ERROR] Element %d not in list!\n\n", x);
		return;
	}
	else
	{
		printf("\n**Successfully deleted element %d!\n", x);
		temp = ptr->link;
		ptr->link = temp->link;
		free(temp);
	}
}	// End of deleteNode()

void reverseList(struct Node** head_ref)
{
	struct Node* prev = NULL;	 // pointer to the previous node
	struct Node* current;		 // pointer to current node
	struct Node* next = NULL;	 // pointer to the next node

	if (NULL == *head_ref)
	{
		printf("\n[ERROR] List it empty!\n");
		return;
	}

	current = *head_ref;				// current node starts from the head

	// Reverse the linked list
	while (NULL != current)
	{
		// Store next node
		next = current->link;

		// Reverse current node's pointer
		current->link = prev;

		// Move pointers one position ahead
		prev = current;
		current = next;
	}

	*head_ref = prev;
}	// End of reverseList();

int sum(struct Node* head, int* sum_val)
{
	int sum = 0;	// Initialize sum
	struct Node* current;

	if (NULL == head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	current = head;
	while (NULL != current)
	{
		sum += current->info;
		current = current->link;
	}

	*sum_val = sum;
	return 0;
}