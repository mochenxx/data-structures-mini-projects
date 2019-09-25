/*
 * File name: Display.c
 *
 * Author: Mo Chen
 *
 * Description: C program to display main menu and get input
 */

#include "display.h"

#pragma warning(disable : 4996)

void displayMainMenu(void)
{
	unsigned int i = 1;
	system("cls");
	printf("\n\n");
	printf("----------------- Binary Search Tree -----------------\n\n");
	printf("  %u) %s\n", i++, "Add element in the binary search tree");
	printf("  %u) %s\n", i++, "Search for a certain element");
	printf("  %u) %s\n", i++, "Remove an element from binary tree");
	printf("  %u) %s\n", i++, "Print elements in ascending order");
	printf("  %u) %s\n", i++, "Print elements in descending order");
	printf("  %u) %s\n", i++, "Delete complete tree");
	printf("  %u) %s\n\n", i++, "QUIT the program");
}

void getChoice(int* choice)
{
	printf("Enter your choice: ");

	(void)scanf("%d", choice);
}
