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
	printf("\n %u) Press %u to %s.", 6, 6, "Fetch records within certain time");
	printf("\n %u) Press %u to %s.", 7, 7, "EXIT");
	printf("\n\n Enter a number: ");
}

void displayDeleteMenu(void)
{
	system("cls");
	printf("\n------------------ Delete Element ------------------\n");
	printf("\n %u) Press %u to %s.", 1, 1, "Delete last added element");
	printf("\n %u) Press %u to %s.", 2, 2, "Delete oldest added element");
	printf("\n %u) Press %u to %s.", 3, 3, 
		   "Delete specific element from the list");
}

void displayRecordFetchMenu(void)
{
	system("cls");
	printf("\n------------- Fetch Records within certain time -------------\n");
	printf("\n %u) Press %u to %s.", 1, 1, 
		   "Fetch records after a time (e.g., 9:00)");
	printf("\n %u) Press %u to %s.", 2, 2, 
		   "Fetch records before a time (e.g., 16:00)");
	printf("\n %u) Press %u to %s.", 3, 3,
		   "Fetch records between a time interval (e.g., b/w 11:00 and 12:00)");
}