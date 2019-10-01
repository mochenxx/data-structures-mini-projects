/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Stack data structure mini project
 */

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include "stackHelper.h"
#include "display.h"

#define QUITKEY 6

#pragma warning (disable: 4996)

int main(void)
{
	struct Stack* stack;			// stack pointer
	int pop_val, top_val;			// popped value, top value from stack
	int return_val = 0;				// flag indicating if there is an error
	int choice;						// input choice from keyboard
	int item;						// desired element data
	unsigned int capacity;			// maximum capacity of stack 
	
	do
	{
		// Get the maximum capacity of stack from input
		printf("\nEnter the maximum capacity of stack : \n");

		// Input validation
		if (scanf("%d", &capacity) != 1)
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
	
	/* Create a stack with input capacity */
	stack = createStack(capacity);

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
				// Check for full stack
				if (isFull(stack))
				{
					printf("\n[ERROR] Stack overflow! Cannot add more item!\n");
					system("pause");
					break;
				}

				// Else, push an item to stack
				do
				{
					// Get the integer to be added from input
					printf("\nEnter an integer to be added to stack : ");

					// Input validation
					if (scanf("%d", &item) != 1)
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

				// Add input item to stack
				push(stack, item);

				printf("\n**Element %d has been pushed to the stack.\n", item);

				system("pause");
				break;
			}

			/* 2. Push an item from stack */
			case 2:
			{
				// Check for empty stack
				if (isEmpty(stack))
				{
					printf("\n[ERROR] Stack underflow! No item to pop!\n");
					system("pause");
					break;
				}

				// Else, pop an item from stack
				return_val = pop(stack, &pop_val);

				// If there is a top element in stack, then print it
				if (0 == return_val)
				{
					printf("\n**Element %d has been popped from the stack.\n", 
						pop_val);
				}
				
				system("pause");
				break;
			}

			/* 3. Check the top element of stack */
			case 3:
			{
				// Check for empty stack
				if (isEmpty(stack))
				{
					printf("\n[ERROR] Stack is empty!\n");
					system("pause");
					break;
				}

				// Else, get the top element from stack
				return_val = peek(stack, &top_val);

				// Check if return value is 0,
				// then print the top element of stack
				if (0 == return_val)
				{
					printf("\n**Top element of stack is %d.\n", top_val);
				}

				system("pause");
				break;
			}

			/* 4. Display stack both in forward and backward order */
			case 4:
			{
				// Check for empty stack
				if (isEmpty(stack))
				{
					printf("\n[ERROR] Stack is empty!\n");
					system("pause");
					break;
				}

				// Else, display stack
				// 1. Display stack in forward order
				printf("\n**Input Stack in forward order :\n");
				displayStack(stack);

				// 2. Display stack in backward order
				printf("\n**Input Stack in backward order :\n");
				printReversedStack(stack);
				printf("\n\n");

				system("pause");
				break;
			}

			/* 5. Reverse stack */
			case 5:
			{
				// Check for empty stack
				if (isEmpty(stack))
				{
					printf("\n[ERROR] Stack is empty!\n");
					system("pause");
					break;
				}

				// Else, reverse the stack
				reverse(stack);
				printf("\n**Successfully reverse the stack!\n");

				system("pause");
				break;
			}

			default:
			{
				// Print error message
				printf("\n[ERROR] Invalid Input.\n");
				system("pause");
				break;
			}
		}
	}

	// Free memory allocated for stack
	freeStack(stack);

	return 0;
}
