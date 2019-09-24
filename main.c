/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Doubly linked list mini program
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <conio.h>
#include <windows.h>
#include "structures.h"
#include "DoublyLinkdedList.h"
#include "FreeList.h"
#include "Display.h"

#define QUIT 13

 /*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

int main(void)
{
	/* Start with the empty list */
	struct Dllist* dllist = NULL;
	int choice;				// input choice for menu
	int data;				// desired element value
	int x;					// element value at specific position in the list
	unsigned int k;			// k-th position in the list
	int return_val = 0;		// flag indicating if there is an error
	int sum_val = 0;		// Sum of all elements in the list

	dllist = createDllist();
	
	while (1)
	{
		/* Display main menu */
		displayMainMenu();

		/* Get choice from input */
		getChoice(&choice);

		/* Check if user chooses to quit the program */
		if (choice == QUIT)
		{
			break;
		}

		switch (choice)
		{
			/* 1. Display list */
			case 1:
			{
				printList(dllist);

				system("pause");
				break;
			}

			/* 2. Count the number of nodes */
			case 2:
			{
				/* Count and display the number of nodes */
				countNode(dllist);

				system("pause");
				break;
			}

			/* 3. Search for an element */
			case 3:
			{
				/* Check if head is NULL */
				if (NULL == dllist->head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					do
					{
						/* Get the element to be searched from input */
						printf("\nEnter the element to be searched : ");

						/* Input validation */
						if (scanf("%d", &data) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}
						else
						{
							break;
						}
					} while (1);

					/* Traverse the list till find the desired data */
					search(dllist, data);
				}

				system("pause");
				break;
			}

			/* 4. Insert a node on the front of the list */
			case 4:
			{
				do
				{
					/* Get the element to be inserted */
					printf("\nEnter the element to be inserted on the front : ");

					/* Input validation */
					if (scanf("%d", &data) != 1)
					{
						(void)getchar();
						printf("\n[ERROR] Input must be integer.");
						continue;
					}

					/* Check if entered number is unique */
					if (!isUnique(dllist, data))
					{
						/* If not unique, then print error */
						printf("\n[ERROR] Element must be unique.");
						continue;
					}
					else
					{
						break;
					}
				} while (1);

				/* Insert input element to the front of the list*/
				insertAtFront(dllist, data);

				system("pause");
				break;
			}

			/* 5. Insert a node at the end of the list */
			case 5:
			{
				do
				{
					/* Get the element to be inserted */
					printf("\nEnter the element to be inserted at the end : ");

					/* Check if input is valid */
					if (scanf("%d", &data) != 1)
					{
						(void)getchar();
						printf("\n[ERROR] Input must be integer.");
						continue;
					}

					/* Check if entered number is unique */
					if (!isUnique(dllist, data))
					{
						/* If not unique, then print error */
						printf("\n[ERROR] Element must be unique.");
						continue;
					}
					else
					{
						break;
					}
				} while (1);

				/* Insert input element to the end of the list */
				insertAtEnd(dllist, data);

				system("pause");
				break;
			}

			/* 6. Insert a node after a specified node */
			case 6:
			{
				/* Check if head is NULL */
				if (NULL == dllist->head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* Get the element to be inserted */
					do
					{
						printf("\nEnter the element to be inserted : ");

						/* Check if input is valid */
						if (scanf("%d", &data) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}

						/* Check if entered number is unique */
						if (!isUnique(dllist, data))
						{
							/* If not unique, then print error */
							printf("\n[ERROR] Element must be unique!");
							continue;
						}
						else
						{
							break;
						}
					} while (1);

					/* Get the specific position */
					do
					{
						printf("\nEnter the element after which "
							"to insert this new data : ");

						/* Check if input is valid */
						if (scanf("%d", &x) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}
						else
						{
							break;
						}
					} while (1);
					/* Insert input data after element x */
					insertAfter(dllist, data, x);
				}

				system("pause");
				break;
			}

			/* 7. Insert a node before a specified node */
			case 7:
			{
				/* Check if head is NULL */
				if (NULL == dllist->head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* Get the element to be inserted */
					do
					{
						printf("\nEnter the element to be inserted : ");

						/* Check if input is valid */
						if (scanf("%d", &data) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}

						/* Check if entered number is unique */
						if (!isUnique(dllist, data))
						{
							/* If not unique, then print error */
							printf("\n[ERROR] Element must be unique.");
							continue;
						}
						else
						{
							break;
						}
					} while (1);

					/* Get specific position */
					do
					{
						printf("\nEnter the element before which "
							"to insert this new data : ");

						/* Check if input is valid */
						if (scanf("%d", &x) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}
						else
						{
							break;
						}
					} while (1);

					/* Insert input data before element x */
					insertBefore(dllist, data, x);
				}

				system("pause");
				break;
			}

			/* 8. Insert a node at a given position */
			case 8:
			{

				/* Get the element to be inserted */
				do
				{
					printf("\nEnter the element to be inserted : ");

					/* Check if input is valid */
					if (scanf("%d", &data) != 1)
					{
						(void)getchar();
						printf("\n[ERROR] Input must be integer.");
						continue;
					}

					/* Check if entered number is unique */
					if (!isUnique(dllist, data))
					{
						/* If not unique, then print error */
						printf("\n[ERROR] Element must be unique!");
						continue;
					}
					else
					{
						break;
					}
				} while (1);

				/* Get the position k from program input */
				do
				{
					printf("\nEnter the position at which to insert : ");

					/* Check if input is valid */
					if (scanf("%d", &k) != 1)
					{
						(void)getchar();
						printf("\n[ERROR] Input must be integer.");
						continue;
					}
					else
					{
						break;
					}
				} while (1);

				/* Insert new node at position k */
				insertAtPosition(dllist, data, k);

				system("pause");
				break;
			}

			/* 9. Delete a node */
			case 9:
			{
				/* Check if head is NULL */
				if (NULL == dllist->head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* Get the element to be inserted */
					do
					{
						printf("\nEnter the element to be deleted : ");

						/* Check if input is valid */
						if (scanf("%d", &x) != 1)
						{
							(void)getchar();
							printf("\n[ERROR] Input must be integer.");
							continue;
						}
						else
						{
							break;
						}
					} while (1);

					/* Delete input element x from the list */
					deleteNode(dllist, x);
				}

				system("pause");
				break;
			}

			/* 10. Reverse the list */
			case 10:
			{
				/* Check if head is NULL */
				if (NULL == dllist->head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* Reverse the list */
					reverseList(dllist);
					printf("\n**Successfully reverse the list!\n");
				}

				system("pause");
				break;
			}

			/* 11. Get the sum of all elements in the list */
			case 11:
			{
				/* Calculate the sum of all elements */
				return_val = sum(dllist, &sum_val);

				// Check if return_val is not 0, which indicates list is empty
				if (return_val != 0)
				{
					// Set sum value to 0
					sum_val = 0;
				}

				// Else, display the sum value
				printf("\nSum of all elements in the list is %d\n\n", sum_val);

				system("pause");
				break;
			}

			/* 12. Clear all elements in the list */
			case 12:
			{
				/* Free the memory of the linked list */
				freeList(dllist);

				printf("\n**Successfully clear all elements in the list.\n");

				system("pause");
				break;
			}

			default:
			{
				/* Print error message */
				printf("\n[ERROR] Invalid Input. Please try again.\n");

				system("pause");
				break;
			}
		}
	}

	/* Free the allocated memory for the complete list */
	freeList(dllist);

	/* Free the allocated memory for structure ddlist */
	free(dllist);

	return 0;
}