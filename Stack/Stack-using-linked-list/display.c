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
	printf("------------ Implementation of Stack using Array ------------\n\n");
	printf("  %u) %s\n", 1, "Push an item to stack.");
	printf("  %u) %s\n", 2, "Pop an item from stack.");
	printf("  %u) %s\n", 3, "Get the top element of stack.");
	printf("  %u) %s\n", 4, "Display input stack (forward & backward order).");
	printf("  %u) %s\n", 5, "Reverse stack using while loop.");

	printf("  %u) %s\n\n", 6, "QUIT the program.");
}

void getChoice(int* choice)
{
	printf("Enter your choice: ");

	(void)scanf("%d", choice);
}