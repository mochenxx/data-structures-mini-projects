/*
 *  File name: display.h
 *
 *  Author: Mo Chen
 *
 *  Description: Header file for displaying menus
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

/* System dependent key codes */
enum KEYCODE {
	KEY_ESC = 27,
	ARROW_UP = 256 + 72,
	ARROW_DOWN = 256 + 80,
	ARROW_LEFT = 256 + 75,
	ARROW_RIGHT = 256 + 77,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_SEVEN = 55,
	KEY_ENTER = 13,
	KEY_A_CAPITAL = 65,
	KEY_A = 97,
	KEY_D = 100,
	KEY_D_CAPITAL = 68
};

/* This function displays the main menu 
 *
 * @param[in] choice - pointer to choice integer
 *
 * @returns - None
 */
void displayMainMenu(int* choice);

/* This function displays the sorting method
 *
 * @param[in] choice - pointer to choice char
 *
 * @returns - None
 */
void displaySortMethod(char* choice);

#endif // _DISPLAY_H_
