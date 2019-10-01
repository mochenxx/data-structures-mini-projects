/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Stack data structure program, implementation of stack using linked list
 */

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "stackHelper.h"
#include "display.h"

#define QUITKEY 6
#pragma warning(disable : 4996)

int main(void)
{
	struct StackNode* top = NULL;
	int poppedVal = 0, topVal;
	int returnVal = 0;				// flag indicating if there is an error
	int choice;						// input choice from keyboard
	int data;						// desired element data

	while (1)
	{
		/* Display main menu */
		displayMainMenu();

		/* Input choice */
		getChoice(&choice);

		/* If choosing to quit the program */
		if (QUITKEY == choice)
		{
			break;
		}

		/* Else, switch between various cases */
		switch (choice)
		{
			/* 1. Add an item to stack */
			case 1:
			{
				do 
				{
					// Get the integer to be added from input
					printf("\nEnter an integer to be added to stack : ");

					// Input validation
					if (scanf("%d", &data) != 1)
					{
						(void)getchar();
						printf("\n[ERROR] Input must be an integer!\n");
						continue;
					}
					else
					{
						break;
					}
				} while (1);
				
				// Add input data to stack
				push(&top, data);

				system("pause");
				break;
			}

			/* 2. Push an item from stack */
			case 2:
			{
				returnVal = pop(&top, &poppedVal);

				if (0 == returnVal)
				{
					printf("\n**Element %d has been popped from stack.\n", 
							poppedVal);
				}
				
				system("pause");
				break;
			}

			/* 3. Check the top element of stack */
			case 3:
			{
				returnVal = peek(top, &topVal);

				if (0 == returnVal)
				{
					printf("\n**Top element of stack is %d.\n", topVal);
				}
				
				system("pause");
				break;
			}

			/* 4. Display stack */
			case 4:
			{
				// Display stack in forward order
				printf("\n**Input Stack in forward order :\n");
				displayStack(top);

				// Display stack in backward order
				printf("\n**Input Stack in backward order :\n");
				printReversedStack(top);
				printf("\n\n");

				system("pause");
				break;
			}

			/* 5. Reverse stack using while loop */
			case 5:
			{
				reverseUsingWhile(&top);
				printf("\n**Successfully reverse the stack!\n");

				system("pause");
				break;
			}
		
			default:
			{
				printf("\n[ERROR] Invalid Input.\n");
				system("pause");
				break;
			}
		}
	}


	return 0;
}
