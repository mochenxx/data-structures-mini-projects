/*
 * File name: Display.h
 *
 * Author: Mo Chen
 *
 * Description: Header file to display menus
 */

#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

/* 
 * This function displays main menu
 */
void displayMainMenu(void);

/*
 * This function displays menu for delete operation
 */
void displayDeleteMenu(void);

/*
 * This function displays menu for fetching records 
 * within specific time requirements
 */
void displayRecordFetchMenu(void);

#endif // _DISPLAY_H_
