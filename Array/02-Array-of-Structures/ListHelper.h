/*
 * File name: ListHelper.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for list helper functions
 */

#ifndef _LISTHELPER_H_
#define _LISTHELPER_H_

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

/* Define Element structure */
typedef struct
{
	int element;	// Integer value
	time_t time;	// Time of addition
} Element;

 /*
  * This function inputs an list
  *
  * @param[in] size - pointer to size of the list
  * @param[in] count - pointer to count of the list (current elements)
  *
  * @returns - pointer to ELement (user-defined structure) list
  */
Element* inputList(unsigned int* size, unsigned int* count);

/*
 * This function checks if input item is unique in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 * @param[in] item - new item to be checked if unique
 *
 * @returns - boolean value true if item is unique; Otherwise, returns false.
 */
bool isUnique(Element* list, unsigned int count, int item);

/*
 * This function checks if input item is existing in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 * @param[in] item - new item to be checked if it exists
 *
 * @returns - boolean value true if item exists; Otherwise, returns false.
 */
bool isExisting(Element* list, unsigned int count, int item);

/*
 * This function deletes an item from the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] size - size of the list (number of elements)
 * @param[in] new_item - item to be added
 *
 * @returns - None
 */
void addItem(Element* list, unsigned int size, unsigned int* count, int new_item);

/*
 * This function adds an item to the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - pointer to count of the list (number of elements)
 * @param[in] delete_item - item to be deleted
 *
 * @returns - None
 */
void deleteItem(Element* list, unsigned int* count, int delete_item);

/*
 * This function prints all elements with time of addition in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
void printListWithTime(Element* list, unsigned int count);

/*
 * This function prints all elements in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
void printListElements(Element* list, unsigned int count);

/*
 * This function clears all elements in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - pointer to count of the list (number of elements)
 *
 * @returns - None
 */
void clearList(Element* list, unsigned int* count);

/*
 * This function calculates sum of all elements in the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
int sum(Element* list, unsigned int count);

/*
 * This function chooses and implements a removal operation to the list
 *
 * -> There are three removal operations:
 *    1.  Delete last added element
 *    2. Delete oldest added element
 *    3. Delete specific element from the list
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
void chooseDeleteOP(Element* list, unsigned int* count);

/*
 * This function chooses and implements a records fetching operation to the list
 *
 * -> There are three records fetching operations:
 *    1. Fetch records after a time (e.g., 9:00)
 *    2. Fetch records before a time (e.g., 16:00)
 *    3. Fetch records between a time interval (e.g., b/w 11:00 and 12:00)
 *
 * @param[in] list - pointer to Element (user-defined structure) list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
void chooseFetchOP(Element* list, unsigned int* count);

#endif // _LISTHELPER_H_