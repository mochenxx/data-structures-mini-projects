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
	printf("----------------- Doubly Linked List Program -----------------\n");
	printf("  %u) %s\n", 1, "Display doubly linked list");
	printf("  %u) %s\n", 2, "Count the number of nodes");
	printf("  %u) %s\n", 3, "Search for an element");
	printf("  %u) %s\n", 4, "Insert a node on the Front of the list");
	printf("  %u) %s\n", 5, "Insert a node at the End of the list");
	printf("  %u) %s\n", 6, "Insert a node After a specified node");
	printf("  %u) %s\n", 7, "Insert a node Before a specified node");
	printf("  %u) %s\n", 8, "Insert a node At a given position");
	printf("  %u) %s\n", 9, "Delete a node");
	printf("  %u) %s\n", 10, "Reverse the list");
	printf("  %u) %s\n", 11, "Get the sum of all elements in the list");
	printf("  %u) %s\n", 12, "Clear all elements in the list");
	printf("  %u) %s\n\n", 13, "QUIT the program");
}

void getChoice(int* choice)
{
	printf("Enter your choice: ");

	(void)scanf("%d", choice);
}