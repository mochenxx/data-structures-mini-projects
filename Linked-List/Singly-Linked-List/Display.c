/*
 * File name: Display.c
 *
 * Author: Mo Chen
 *
 * Description: C program to display main menu and get input
 */

#include "Display.h"

#pragma warning(disable : 4996)

void displayMainMenu(void)
{
	system("cls");
	printf("\n\n");
	printf("----------------- Singly Linked List Program -----------------\n");
	printf("  %u) %s\n", 1, "Display list");
	printf("  %u) %s\n", 2, "Print the reverse of linked list");
	printf("  %u) %s\n", 3, "Count the number of nodes");
	printf("  %u) %s\n", 4, "Search for an element");
	printf("  %u) %s\n", 5, "Insert a node on the Front of the list");
	printf("  %u) %s\n", 6, "Insert a node at the End of the list");
	printf("  %u) %s\n", 7, "Insert a node After a specified node");
	printf("  %u) %s\n", 8, "Insert a node Before a specified node");
	printf("  %u) %s\n", 9, "Insert a node At a given position");
	printf("  %u) %s\n", 10, "Delete a node");
	printf("  %u) %s\n", 11, "Reverse the list");
	printf("  %u) %s\n", 12, "Get the sum of all elements in the list");
	printf("  %u) %s\n", 13, "Clear all elements in the list");
	printf("  %u) %s\n\n", 14, "QUIT the program");
}

void getChoice(int* choice)
{
	printf("Enter your choice: ");

	(void)scanf("%d", choice);
}