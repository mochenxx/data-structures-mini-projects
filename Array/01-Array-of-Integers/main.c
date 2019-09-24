/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 * 
 * Description: Simple list mini program
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "ListHelper.h"
#include "Display.h"

int main(void)
{
	unsigned int size = 0, count = 0;
	int new_item = 0;
	char choice = 0;
	int* list;

	/* Print header */
	printf("\n------------------ Array Project ------------------\n");
	
	/* Input a list */
	list = inputList(&size, &count);

	do 
	{
		/* Display main menu */
		displayMainMenu();

		/* Get user choice from keyboard */
		choice = _getche();

		/* Switch between different cases based on choice */
		switch (choice)
		{
			// Add item to list
			case '1':	
			{
				/* Check if list is full */
				if (count >= size)
				{
					printf("\n [ERROR] List if full! Cannot add more item!\n");
					system("pause");
					break;
				}

				/* Get new item to be added */
				printf("\n Enter the item you want to ADD: ");
				scanf_s("%d", &new_item);
				
				/* Check if new item is unique */
				while (!isUnique(list, count, new_item))
				{
					/* If repeated - print error message */
					printf("\n [ERROR] Element must be unique!Please try again.");

					/* Input element once again */
					printf("\n Enter the item you want to ADD: ");
					scanf_s("%d", &new_item);
				}

				/* Add input item to the list */
				addItem(list, size, &count, new_item);

				/* Print list after addition */
				printf("\n List after addition:\n");
				printList(list, count);

				system("pause");
				break;
			}

			// Remove item from list
			case '2':	
			{
				/* Check if list is empty */
				if (count <= 0)
				{
					printf("\n [ERROR] The list is empty! Cannot delete more!\n");
					system("pause");
					break;
				}

				/* Get item to be deleted */
				printf("\n Enter the number you want to DELETE: ");
				scanf_s("%d", &new_item);

				while (!isExisting(list, count, new_item))
				{
					printf("\n [ERROR] Input element doesn't exist in the list!");

					/* Input element once again */
					printf("\n Enter the item you want to DELETE: ");
					scanf_s("%d", &new_item);
				}

				/* Delete input item from the list */
				deleteItem(list, &count, new_item);
				
				/* Print list after removal */
				printf("\n List after removal:\n");
				printList(list, count);

				system("pause");
				break;
			}

			// Clear all elements
			case '3':
			{
				clearList(list, &count);

				/* Print list after clearing */
				printf("\n\n List after clearing:\n");
				printList(list, count);

				system("pause");

				break;
			}

			// Get sum of all elements in the list
			case '4':
			{
				printf("\n\n Sum of given list is: %d.\n", sum(list, count));
				
				system("pause");

				break;
			}

			// Print list
			case '5':
			{
				printf("\n\n Printing given List: \n");
				printList(list, count);

				system("pause");

				break;
			}

			// Exit the program
			case '6':
			{
				exit(1);
			}

			default:
			{
				printf("\n\n [ERROR] Invalid Input! Please try again!\n");

				system("pause");

				break;
			}
		}
	} while (choice != '6');

	free(list);
}
