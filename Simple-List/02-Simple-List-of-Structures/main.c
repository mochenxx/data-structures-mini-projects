/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Enhanced list mini program (list of structs)
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "ListHelper.h"
#include "Display.h"

int main(void)
{
	unsigned int size = 0, count = 0;
	int new_item = 0;
	char choice = 0;
	Element* mylist;

	/* Print header */
	printf("\n------------------ Simple List Project ------------------\n");

	/* Input a list */
	mylist = inputList(&size, &count);

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
				while (!isUnique(mylist, count, new_item))
				{
					/* If repeated - print error message */
					printf("\n [ERROR] Element must be unique! "
						   "Please try again.\n");

					/* Input element once again */
					printf("\n Enter the item you want to ADD: ");
					scanf_s("%d", &new_item);
				}

				/* Add input item to the list */
				addItem(mylist, size, &count, new_item);

				/* Print list after addition */
				printf("\n List after addition:\n");
				printListElements(mylist, count);

				system("pause");
				break;
			}

			// Delete item from list
			case '2':
			{
				/* Check if list is empty */
				if (count <= 0)
				{
					printf("\n [ERROR] The list is empty! "
						   "Cannot delete more!\n");

					system("pause");
					break;
				}

				/* Display delete menu */
				displayDeleteMenu();

				/* Choose delete operation */
				chooseDeleteOP(mylist, &count);

				system("pause");
				break;
			}

			// Clear all elements
			case '3':
			{
				clearList(mylist, &count);

				/* Print list after clearing */
				printf("\n\n List after clearing:\n");
				printListElements(mylist, count);

				system("pause");

				break;
			}

			// Get sum of all elements in the list
			case '4':
			{
				printf("\n\n Sum of given list is: %d.\n", sum(mylist, count));

				system("pause");

				break;
			}

			// Print list
			case '5':
			{
				printf("\n\n Printing given List: \n");
				printListElements(mylist, count);

				system("pause");

				break;
			}

			// Fetch records within certain time interval
			case '6':
			{
				displayRecordFetchMenu();

				chooseFetchOP(mylist, &count);

				system("pause");

				break;
			}

			// Exit the program
			case '7':
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
	} while (choice != '7');
}

