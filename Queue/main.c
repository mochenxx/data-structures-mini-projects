/*
 * File name: main.c
 *
 * Author: Mo Chen
 *
 * Copyright: 2019
 *
 * Description: Queue data structure mini program
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <Windows.h>
#include "display.h"
#include "queueHelper.h"

#define QUITKEY 6

#pragma warning (disable : 4996)

int main(void)
{
	struct Queue* queue;			// queue pointer
	int remove_val;					// removed value from queue
	int front_val, rear_val;		// front and rear element of queue
	int return_val = 0;				// flag indicating if there is an error
	int choice;						// input choice from keyboard
	int item;						// desired element data
	unsigned int capacity;			// maximum capacity of queue 

	do
	{
		// Get the maximum capacity of queue from input
		printf("\nEnter the maximum capacity of queue : \n");

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

	/* Create a queue with input capacity */
	queue = createQueue(capacity);

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
			/* 1. Add an item to queue */
			case 1:
			{
				// Check for full queue
				if (isFull(queue))
				{
					printf("\n[ERROR] Queue overflow! Cannot add more item!\n");
					system("pause");
					break;
				}

				// Else, push an item to queue
				do
				{
					// Get the integer to be added from input
					printf("\nEnter an integer to be added to queue : ");

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

				// Add input item to queue
				enqueue(queue, item);

				printf("\n**Element %d enqueued to queue.\n", item);

				system("pause");
				break;
			}

			/* 2. Dequeue (Remove) an item from queue */
			case 2:
			{
				// Check for empty queue
				if (isEmpty(queue))
				{
					printf("\n[ERROR] Queue underflow! No item to pop!\n");
					system("pause");
					break;
				}

				// Else, pop an item from stack
				return_val = dequeue(queue, &remove_val);

				// If there is no error, then print the dequeued value
				if (0 == return_val)
				{
					printf("\n**Element %d has been dequeued from queue.\n",
						remove_val);
				}

				system("pause");
				break;
			}

			/* 3. Check the front element of queue */
			case 3:
			{
				// Check for empty queue
				if (isEmpty(queue))
				{
					printf("\n[ERROR] Stack is empty!\n");
					system("pause");
					break;
				}

				// Else, get the front element from queue
				return_val = queueFront(queue, &front_val);

				// Check if return value is 0,
				// then print the front element of queue
				if (0 == return_val)
				{
					printf("\n**Front element of queue is %d.\n", front_val);
				}

				system("pause");
				break;
			}

			/* 4. Check the rear element of queue */
			case 4:
			{
				// Check for empty queue
				if (isEmpty(queue))
				{
					printf("\n[ERROR] Stack is empty!\n");
					system("pause");
					break;
				}

				// Else, get the rear element from queue
				return_val = queueRear(queue, &rear_val);

				// Check if return value is 0,
				// then print the rear element of queue
				if (0 == return_val)
				{
					printf("\n**Rear element of queue is %d.\n", rear_val);
				}

				system("pause");
				break;
			}

			/* 5. Display queue */
			case 5:
			{
				// Check for empty queue
				if (isEmpty(queue))
				{
					printf("\n[ERROR] Queue is empty!\n");
					system("pause");
					break;
				}

				// Else, display queue
				printf("\n**Input Queue :\n");
				displayQueue(queue);
				printf("\n");

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

	// Free memory allocated for queue
	freeQueue(queue);

	return 0;
}
