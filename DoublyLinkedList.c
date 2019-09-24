/*
* File name: DoublyLinkedList.c
*
* Author: Mo Chen
*
* Description: C program for doubly linked list functions
*/

#include "DoublyLinkdedList.h"
#include "structures.h"

struct Dllist* createDllist(void)
{
	/* Allocate a new dllist */
	struct Dllist* dllist = (struct Dllist*)malloc(sizeof(struct Dllist));

	/* Check if there is memory for newly created dllist */
	if (NULL == dllist)
	{
		printf("\n[ERROR] No such memory!\n");
		return NULL;
	}

	/* Initialize DLL */
	dllist->head = NULL;
	dllist->tail = NULL;
	return dllist;
}

void insertAtFront(struct Dllist* dllist, int new_data)
{
	/* Allocate a new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("\n[ERROR] Invalid arguments.");
		return;
	}

	/* Check if there is memory for newly created node */
	if (NULL == new_node)
	{
		printf("\n[ERROR] No more memory for new node!\n");
		return;
	}
	else
	{
		/* Put in the new data */
		new_node->data = new_data;

		/* Make next of new node as head and previous as NULL */
		new_node->next = dllist->head;
		new_node->prev = NULL;
		
		/* Check if head is NULL */
		// If yes, then make new node also as the head of DLL
		if (NULL == dllist->head)
		{
			dllist->tail = new_node;
			dllist->tail->next = NULL;
		}
		// If no, then change previous of head node to new node
		else
		{
			dllist->head->prev = new_node;
		}

		/* Move the head to point to the new node */
		dllist->head = new_node;
	}
}	// End of insertAtFront()

void insertAtEnd(struct Dllist* dllist, int new_data)
{
	/* Allocate memory for new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	/* Check if there is memory for newly added node */
	if (NULL == new_node)
	{
		printf("\n[ERROR] No more such memory for new node!\n");
		return;
	}
	else
	{
		/* Put in the new data */
		new_node->data = new_data;

		/* Make next of new node as NULL */
		new_node->next = NULL;
	}

	/* If the linked list is empty, then make the new node as head */
	if (NULL == dllist->head)
	{
		new_node->prev = NULL;
		dllist->head = new_node;
		dllist->tail = new_node;
		return;
	}

	/* Else, make the new_node as the next of tail node */
	dllist->tail->next = new_node;

	/* Make last node as previous of new node */
	new_node->prev = dllist->tail;

	/* Update tail node*/
	dllist->tail = new_node;
}	// End of insertAtEnd()

void insertAfter(struct Dllist* dllist, int new_data, int x)
{
	struct Node* new_node;
	struct Node* prev_node;	// Pointer to the previous node

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	// Check empty list case
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty! Cannot insert new node!\n");
		return;
	}
	
	prev_node = dllist->head;

	/* Allocate memory for new node */
	new_node = (struct Node*)malloc(sizeof(struct Node));

	/* Check if there is memory for newly created node */
	if (NULL == new_node)
	{
		printf("\n[ERROR] No more memory for new node!\n");
		return;
	}

	/* Find pointer to predecessor of node containing data x*/
	while (prev_node != NULL)
	{
		if (x == prev_node->data)
		{
			break;
		}
		prev_node = prev_node->next;
	}

	/* Check if input data x is not found in the list */
	if (NULL == prev_node)
	{
		printf("\n[ERROR] %d is not found in the list!\n", x);
		return;
	}
	else
	{
		/* Put in the new data */
		new_node->data = new_data;
		
		/* Make next of new node as next of prev_node */
		new_node->next = prev_node->next;
		
		/* Make next of prev_node as new node */
		prev_node->next = new_node;

		/* Make prev_node as previous node of new node */
		new_node->prev = prev_node;

		/* Check if next of new node is NULL */
		// If yes, then make the new node as next of tail node 
		// and update tail node
		if (NULL == new_node->next)
		{
			dllist->tail->next = new_node;
			dllist->tail = new_node;
		}
		// If no, then change previous of new node's next node
		else
		{
			new_node->next->prev = new_node;
		}

		printf("\n**Successfully inserted %d after %d in the list.\n",
				new_data, x);
	}
}	// End of insertAfter()

void insertBefore(struct Dllist* dllist, int new_data, int x)
{
	struct Node* new_node;
	struct Node* next_node;		// Pointer to the next node

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	/* Check if list is empty */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty!\n");
		return;
	}
	
	next_node = dllist->head;

	/* Allocate memory for new node */
	new_node = (struct Node*)malloc(sizeof(struct Node));

	/* Check if there is memory for newly created node */
	if (NULL == new_node)
	{
		printf("\n[ERROR] No such memory for new node!\n");
		return;
	}
	
	/* Find pointer to predecessor of node containing data x*/
	while (next_node != NULL)
	{
		if (x == next_node->data)
		{
			break;
		}

		next_node = next_node->next;
	}
	/* Put in new data */
	new_node->data = new_data;

	if (NULL == next_node)
	{
		printf("\n[ERROR] %d not found in the list!\n", x);
		return;
	}
	else
	{
		/* Check if prev of next_node is NULL,
	       it means to insert node before head */
		if (NULL == next_node->prev)
		{
			new_node->prev = NULL;
		}
		else
		{
			/* Make prev of new node as prev of next_node */
			new_node->prev = next_node->prev;
		}
	}

	/* Make the prev of next_node as new node */
	next_node->prev = new_node;

	/* Make next_node as next of new node */
	new_node->next = next_node;

	/* If the prev of new node is NULL, it will be the new head node */
	if (NULL == new_node->prev)
	{
		dllist->head = new_node;
	}
	/* Else, change next of new node's previous node */
	else
	{
		new_node->prev->next = new_node;
	}
	printf("\n**Successfully inserted %d before %d in the list.\n",
			new_data, x);
}	// End of insertBefore()

void insertAtPosition(struct Dllist* dllist, int new_data, unsigned int k)
{
	struct Node* new_node, * current;	// current pointer to (k-1)th node
	unsigned int i;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	/* 1. Check if input position k is at the head */
	if (1 == k)
	{
		insertAtFront(dllist, new_data);
		printf("\n**Successfully inserted %d at %d-st position.\n",
			    new_data, k);
		return;
	}
	/* If k is not 1 whereas head is NULL, then print error and we return */
	else if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty. "
			"Data can only be inserted at position 1.\n");
		return;
	}

	current = dllist->head;

	/* 2. Else, find the pointer to (k-1)th node */
	for (i = 1; (i < k - 1) && (current != NULL); i++)
	{
		current = current->next;
	}

	/* 3. Check if input value k is out of boundary */
	if (NULL == current)
	{
		printf("\n[ERROR] Invalid Input. "
			   "You can only insert up to %d-th position!\n", i);
		return;
	}
	else
	{
		/* 4. Allocate memory for new node */
		new_node = (struct Node*)malloc(sizeof(struct Node));

		/* Check if there is memory for newly created node */
		if (NULL == new_node)
		{
			printf("\n[ERROR] Not enough memory for new node!\n");
			return;
		}

		/* Put in new data */
		new_node->data = new_data;

		/* Make prev of new node as current (k-1)th node */
		new_node->prev = current;

		/* Check if (k-1)th node is the tail node */
		// If yes, make the next of tail node as new_node
		// and update tail node
		if (NULL == current->next)
		{
			dllist->tail = new_node;
		}
		else
		{
			/* Make prev of k-th node as new node */
			current->next->prev = new_node;
		}

		/* Make next of new node as k-th node */
		new_node->next = current->next;

		/* Make next of (k-1)th node as new node */
		current->next = new_node;

		printf("\n**Successfully inserted %d at %d-th position.\n",
			new_data, k);
	}
}	// End of insertAtPosition()

bool isUnique(struct Dllist* dllist, int data)
{
	struct Node* temp;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return false;
	}

	/* Check if list is empty */
	/* If yes, then input data is absolutely unique */
	if (NULL == dllist->head)
	{
		return true;
	}

	temp = dllist->head;
	while (temp != NULL)
	{
		if (data == temp->data)
		{
			return false;
		}

		temp = temp->next;
	}

	return true;
}	// End of isUnique()

void deleteNode(struct Dllist* dllist, int del_data)
{
	struct Node* del_node, * temp;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	/* Base case */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty. Cannot delete more!");
		return;
	}

	/* 1. Deletion of head node */
	if (del_data == dllist->head->data)
	{
		// Make del_node to as head pointer
		del_node = dllist->head;

		// Move head node to the next of delete node
		dllist->head = del_node->next;
	}

	/* 2. Deletion in between or at the end */
	else
	{
		temp = dllist->head;
		while (temp->next != NULL)
		{
			if (del_data == temp->next->data)
			{
				break;
			}

			temp = temp->next;
		}
		
		/* If input element is not existing in the list */
		if (NULL == temp->next)
		{
			printf("\n[ERROR] Element %d is not in list!\n", del_data);
			return;
		}
		else
		{
			del_node = temp->next;
		}
	}
	
	/* Change next only if node to be deleted is the NOT last node */
	if (NULL != del_node->next)
	{
		del_node->next->prev = del_node->prev;
	}
	else
	{
		// Update tail node in DLL
		dllist->tail = del_node->prev;
	}

	/* Change prev only if node to be deleted is the NOT first node */
	if (NULL != del_node->prev)
	{
		del_node->prev->next = del_node->next;
	}

	/* Finally, free the memory occupied by del_node */
	free(del_node);
	return;
}	// End of deleteNode()

void reverseList(struct Dllist* dllist)
{
	struct Node* temp = NULL;
	struct Node* current;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return;
	}

	/* Check for case empty list */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty.");
		return;
	}

	/* Check for case the list with only one node */
	if (NULL == dllist->head->next)
	{
		printf("\nList has only one node.");
		return;
	}

	current = dllist->head;

	/* Swap next and prev for all nodes of doubly linked list */
	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
	{
		dllist->tail = dllist->head;
		dllist->head = temp->prev;
	}
}	// End of reverseList()

int sum(struct Dllist* dllist, int* sum_val)
{
	int sum = 0;
	struct Node* temp;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return -1;
	}

	/* Check for case empty list */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty.");
		return -1;
	}

	temp = dllist->head;
	while (temp != NULL)
	{
		sum += temp->data;
		temp = temp->next;
	}

	*sum_val = sum;
	return 0;
}	// End of sum()

int printList(struct Dllist* dllist)
{
	struct Node* temp;

	// Argument consistency checks
	if (NULL == dllist)
	{
		printf("\n[ERROR] Invalid argument!\n");
		return -1;
	}

	/* Check for case empty list */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	printf("\n******* Display Doubly Linked List *******");
	
	/* Print DLL in FORWARD direction */
	temp = dllist->head;
	printf("\nTraversal in forward direction:\n");
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}

	/* Print DLL in REVERSE direction */
	temp = dllist->tail;
	printf("\nTraversal in reverse direction:\n");
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->prev;
	}
	printf("\n\n");
	return 0;
}	// End of printList()

int countNode(struct Dllist* dllist)
{
	struct Node* temp;
	unsigned int count = 0;		// Number of nodes in DLL

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return -1;
	}

	/* Check for case empty list */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	temp = dllist->head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	/* Display the number of nodes in list */
	printf("\n**Number of nodes in list = %d\n\n", count);

	return count;
}	// End of countNode()

int search(struct Dllist* dllist, int data)
{
	struct Node* temp;

	unsigned int position = 1;

	// Arguments consistency checks
	if (NULL == dllist)
	{
		printf("Invalid arguments.");
		return -1;
	}

	/* Check for case empty list */
	if (NULL == dllist->head)
	{
		printf("\n[ERROR] List is empty!\n");
		return -1;
	}

	temp = dllist->head;

	/* Traverse the list to search for data */
	while (temp != NULL)
	{
		/* If this node contains required data, then loop terminates */
		if (data == temp->data)
		{
			break;
		}

		/* Else, increment position and points to next node */
		position++;
		temp = temp->next;
	}

	/* If desired data is not in the list */
	if (NULL == temp)
	{
		printf("\n[ERROR] Element %d is not found in the list!\n", data);
		return -1;
	}
	else
	{
		printf("\n**Element %d is at position %d.\n", data, position);
		return 0;
	}
}	// End of search()