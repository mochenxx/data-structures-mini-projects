/*
 * File name: Display.h
 *
 * Author: Mo Chen
 *
 * Description: Header file to display main menu and get input
 */

#ifndef _DISPALY_H_
#define _DISPALY_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

/* 
 * This function displays main menu for the linked list program
 *
 * @returns - None
 */
void displayMainMenu(void);

/*
 * This function gets choice from program input
 *
 * @param[in] choice - pointer to user choice for operations
 *
 * @returns - None
 */
void getChoice(int* choice);

#endif // _DISPALY_H_
