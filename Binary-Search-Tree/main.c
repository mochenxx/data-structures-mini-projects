/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Binary search tree mini program
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "BSTHelper.h"
#include "display.h"

#define QUIT 7

/*
* Disable warning of unsafe functions
* _CRT_SECURE_NO_WARNINGS
*/
#pragma warning(disable : 4996)

int main(void)
{
	struct Node* root = NULL;
	struct Node* temp = NULL;
	
	int key;				// input key
	int choice;				// input choice for menu

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
			/* 1. Add element in the binary search tree*/
			case 1:
			{
				/* Get a key to insert */
				printf("\nInput an integer number to insert : ");
				fflush(stdout);
				(void)scanf("%d", &key);

				/* Insert input key to BST */
				root = insert(root, key);

				printf("\n**Successfully inserted %d.\n", key);
	
				system("pause");
				break;
			}

			/* 2. Search for an element */
			case 2:
			{
				/* Get a key to search */
				printf("\nInput an integer number to search : ");
				fflush(stdout);
				(void)scanf("%d", &key);

				/* Search input key */
				temp = search(root, key);

				/* If temp is NULL, then input key does not exist in BST */
				if (NULL == temp)
				{
					/* Print error message */
					printf("\n**The number %d does not exist!\n", key);
				}
				else
				{
					/* Print success message */
					printf("\n**Found number %d in binary tree!\n", key);
				}

				system("pause");
				break;
			}

			/* 3. Remove element from binary tree */
			case 3:
			{
				printf("\nInput an integer number to delete : ");
				(void)scanf("%d", &key);

				/* Check if input key exists in BST */
				// If not, then prints error message
				if (NULL == search(root, key))
				{
					printf("\n[ERROR] The number %d does not exist!\n", key);
				}
				// Else, delete the node with input key
				else
				{
					root = deleteNode(root, key);
					printf("\b**Deleted element %d from binary tree.\n", key);
				}
				
				system("pause");
				break;
			}

			/* 4. Print element in ascending order */
			case 4:
			{
				printf("\n**Traversal of the binary tree in ascending order : \n");
				
				// Implement inorder traversal to print BST in ascending order 
				inOrder(root);
				printf("\n\n");

				system("pause");
				break;
			}

			/* 5. Print element in descending order */
			case 5:
			{
				printf("\n**Traversal of the binary tree in descending order : \n");

				// Print BST in descending order
				printReverse(root);
				printf("\n\n");

				system("pause");
				break;
			}

			/* 6. Delete complete tree */
			case 6:
			{
				// Destroy the complete tree
				destroyTree(root);

				// Make root as NULL
				root = NULL;

				printf("\n**Delete the complete tree!\n");
				system("pause");
				break;
			}

			default:
			{
				/* Print error message */
				printf("\n[ERROR] Invalid input!\n");
				system("pause");
				break;
			}
		}
	}

	// Destroy the complete tree
	destroyTree(root);

	// Make root as NULL
	root = NULL;

	return 0;
}
