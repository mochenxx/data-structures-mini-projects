/*
 *  File name: display.c
 *
 *  Author: Mo Chen
 *
 *  Description: C program to display menus
 */

#include "Display.h"

void displayMainMenu(int* choice)
{
	*choice = 0;

	while (1)
	{
		system("cls");
		printf("\n---------------- Array Sorting ----------------\n");
		printf("\n %u) Press %u to %s.\n", 1, 1, "input an array");
		printf("\n %u) Press %u to %s.\n", 2, 2, "read array from log file");
		printf("\n Enter a number: ");
		*choice = _getch();

		/* Store key ASCII code */
		if (0 == *choice || 224 == *choice)
		{
			*choice = 256 + _getch();
		}

		/* Entered key code '1' or '2' */
		if (KEY_ONE == *choice || KEY_TWO == *choice)
		{
			break;  // Go back
		}
		
		/* Entered key code 'ESC' */
		else if (KEY_ESC == *choice)
		{
			exit(1);	// Exit program
		}
		else
		{
			/* Print error message */
			printf("\n[ERROR] Invalid Input! Please try again!\n");
			system("pause");
		}
	}
}

void displaySortMethod(char* choice)
{
	*choice = 0;

	while (1)
	{
		system("cls");
		/* Display available sorting methods */
		printf("\n-------------- Available Sorting Algorithms --------------n");
		printf("\n Choose a sort method as below:\n");
		printf("\n %u) Press %u for %s.", 1, 1, "Selection Sort (Standard)");
		printf("\n %u) Press %u for %s.", 2, 2, "Insertion Sort (Standard)");
		printf("\n %u) Press %u for %s.", 3, 3, "Bubble Sort    (Standard)");
		printf("\n %u) Press %u for %s.", 4, 4, "Merge Sort     (Standard)");
		printf("\n %u) Press %u for %s.", 5, 5, "Selection Sort (Optimized)");
		printf("\n %u) Press %u for %s.", 6, 6, "Insertion Sort (Optimized)");
		printf("\n %u) Press %u for %s.\n", 7, 7, "Bubble Sort    (Optimized)");
		printf("\n Enter a number: ");
		
		/* Get input from keyboard */
		while (_kbhit() != 1){}
		*choice = _getche();

		/* Check if input valid (between number 1 and 7)*/
		if ('1' == *choice || '2' == *choice || '3' == *choice ||
			'4' == *choice || '5' == *choice || '6' == *choice || 
			'7' == *choice)
		{
			break;
		}
		else
		{
			/* Print error message */
			printf("\n[ERROR] Invalid Input! Please try again!\n");
			system("pause");
		}
	}

}