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

#define MAX_SIZE 100

/* 
 * This function inputs an list 
 *
 * @param[in] size - pointer to size of the list
 * @param[in] count - pointer to count of the list (current elements)
 *
 * @returns - pointer to this input list
 */
int* inputList(unsigned int* size, unsigned int* count);

/*
 * This function checks if input item is unique in the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - count of the list (number of elements)
 * @param[in] item - new item to be checked if unique
 *
 * @returns - boolean value true if item is unique; Otherwise, returns false.
 */
bool isUnique(int* list, unsigned int count, int item);

/*
 * This function checks if input item is existing in the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - count of the list (number of elements)
 * @param[in] item - new item to be checked if it exists
 *
 * @returns - boolean value true if item exists; Otherwise, returns false.
 */
bool isExisting(int* list, unsigned int count, int item);

/*
 * This function deletes an item from the list
 *
 * @param[in] list - pointer to list
 * @param[in] size - size of the list (number of elements)
 * @param[in] new_item - item to be added
 *
 * @returns - None
 */
void addItem(int* list, unsigned int size, unsigned int* count, int new_item);

/*
 * This function adds an item to the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - pointer to count of the list (number of elements)
 * @param[in] delete_item - item to be deleted
 *
 * @returns - None
 */
void deleteItem(int* list, unsigned int* count, int delete_item);

/*
 * This function prints all elements in the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
void printList(int* list, unsigned int count);

/*
 * This function clears all elements in the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - pointer to count of the list (number of elements)
 *
 * @returns - None
 */
void clearList(int* list, unsigned int* count);

/*
 * This function calculates sum of all elements in the list
 *
 * @param[in] list - pointer to list
 * @param[in] count - count of the list (number of elements)
 *
 * @returns - None
 */
int sum(int* list, unsigned int count, int* sum_val);

#endif // _LISTHELPER_H_