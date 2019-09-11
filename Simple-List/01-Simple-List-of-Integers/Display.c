/*
 * File name: Display.c
 *
 * Author: Mo Chen
 *
 * Description: C program to display menus
 */
#include "Display.h"

void displayMainMenu(void)
{
	system("cls");
	printf("\n------------------ Simple List Project ------------------\n");
	printf("\n %u) Press %u to %s.", 1, 1, "Add element to the list");
	printf("\n %u) Press %u to %s.", 2, 2, "Delete element from the list");
	printf("\n %u) Press %u to %s.", 3, 3, "Clear all elements");
	printf("\n %u) Press %u to %s.", 4, 4, "Get Sum of all elements");
	printf("\n %u) Press %u to %s.", 5, 5, "Print all elements in list");
	printf("\n %u) Press %u to %s.", 6, 6, "EXIT");
	printf("\n\n Enter a number: ");
}