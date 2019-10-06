/*
 * File name: display.c
 *
 * Author: Mo Chen
 *
 * Description: C program to display main menu and get input
 */

#include "display.h"

#pragma warning(disable : 4996)

void displayMainMenu(void)
{
	system("cls");
	printf("\n\n");
	printf("---------- Implementation of Queues ----------\n");
	printf("  %u) %s\n", 1, "Enqueue (Add)    an item to queue.");
	printf("  %u) %s\n", 2, "Dequeue (Remove) an item from stack.");
	printf("  %u) %s\n", 3, "Get the front element of queue.");
	printf("  %u) %s\n", 4, "Get the rear  element of queue.");
	printf("  %u) %s\n", 5, "Display input queue.");

	printf("  %u) %s\n\n", 6, "QUIT the program.");
}

void getChoice(int* choice)
{
	printf("Enter your choice: ");

	(void)scanf("%d", choice);
}