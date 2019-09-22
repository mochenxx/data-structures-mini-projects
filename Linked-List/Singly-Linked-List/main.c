/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Singly linked list mini program
 */

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <conio.h>
#include <windows.h>
#include "SinglyLinkedList.h"
#include "Display.h"
#include "FreeList.h"
#include "structure.h"

#define QUIT 14

/*
 * Disable warning of unsafe functions
 * _CRT_SECURE_NO_WARNINGS
 */
#pragma warning(disable : 4996)

int main(void)
{
	struct Node* head = NULL;
	int choice;				// input choice for menu
	int data;				// desired element value
	int x;					// element value at specific position in the list
	unsigned int k;			// k-th position in the list
	int return_val = 0;		// flag indicating if there is an error
	int sum_val = 0;		// Sum of all elements in the list

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
				displayList(head);

				system("pause");
				break;
			}

			/* 2. Print reverse of the linked list */
			case 2:
			{
				/* Check if head is NULL */
				if (NULL == head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* If head is not NULL, print the reverse of list */
					printf("\n**Input linked list in reverse order :\n");
					printReverse(head);
					printf("\n\n");
				}
				
				system("pause");
				break;
			}

			/* 3. Count the number of nodes */
			case 3:
			{
				/* Count and display the number of nodes */
				countNode(head);

				system("pause");
				break;
			}

			/* 4. Search for an element */
			case 4:
			{
				/* Check if head is NULL */
				if (NULL == head)
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
					search(head, data);
				}
			
				system("pause");
				break;
			}

			/* 5. Insert a node on the front of the list */
			case 5:
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
					if (!isUnique(head, data))
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
				insertAtFront(&head, data);

				system("pause");
				break;
			}

			/* 6. Insert a node at the end of the list */
			case 6:
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
					if (!isUnique(head, data))
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
				insertAtEnd(&head, data);

				system("pause");
				break;
			}

			/* 7. Insert a node after a specified node */
			case 7:
			{
				/* Check if head is NULL */
				if (NULL == head)
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
						if (!isUnique(head, data))
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
							"to insert this new data:");

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
					insertAfter(&head, data, x);
				}
				
				system("pause");
				break;
			}

			/* 8. Insert a node before a specified node */
			case 8:
			{
				/* Check if head is NULL */
				if (NULL == head)
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
						if (!isUnique(head, data))
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
								 "to insert this new data:");

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
					insertBefore(&head, data, x);
				}
				
				system("pause");
				break;
			}

			/* 9. Insert a node at a given position */
			case 9:
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
					if (!isUnique(head, data))
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
				insertAtPosition(&head, data, k);

				system("pause");
				break;
			}

			/* 10. Delete a node */
			case 10:
			{
				/* Check if head is NULL */
				if (NULL == head)
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
					deleteNode(&head, x);
				}

				system("pause");
				break;
			}

			/* 11. Reverse the list */
			case 11:
			{
				/* Check if head is NULL */
				if (NULL == head)
				{
					printf("\n[ERROR] List is empty!\n");
				}
				else
				{
					/* Reverse the list */
					reverseList(&head);
					printf("\nSuccessfully reverse the list!\n");
				}
	
				system("pause");
				break;
			}

			/* 12. Get the sum of all elements in the list */
			case 12:
			{
				/* Calculate the sum of all elements */
				return_val = sum(head, &sum_val);

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

			/* 13. Clear all elements in the list */
			case 13:
			{
				/* Free the memory of the linked list */
				freeList(&head);
				
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

	/* Free the list allocated in memory */
	freeList(&head);

	return 0;
}