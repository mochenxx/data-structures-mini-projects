/*
* File name: DoublyLinkedList.h
*
* Author: Mo Chen
*
* Description: Header file for doubly linked list functions
*/

#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

/*
 * This function creates a doubly linked list and
 * return a pointer to newly created DLL
 *
 * @returns - pointer to newly created struct Dllist
 */
struct Dllist* createDllist(void);

/*
 * This function inserts a new node on the front of the list
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] new_data - info part of the new node
 *
 * @returns - None
 */
void insertAtFront(struct Dllist* dllist, int new_data);

/*
 * This function inserts a new node at the end of the list
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] new_data - info part of the new node
 *
 * @returns - None
 */
void insertAtEnd(struct Dllist* dllist, int new_data);

/*
 * This function inserts a new node after a specific data in the list,
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] new_data - info part of the new node
 * @param[in] x - the element after which to insert new node
 *
 * @returns - None
 */
void insertAfter(struct Dllist* dllist, int new_data, int x);

/*
 * This function inserts a new node before a specific data in the list,
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] new_data - info part of the new node
 * @param[in] x - the element after which to insert new node
 *
 * @returns - None
 */
void insertBefore(struct Dllist* dllist, int new_data, int x);

/*
 * This function inserts a new node at k-th position in the list
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] new_data - info part of the new node
 * @param[in] k - k-th position in the list
 *
 * @returns - None
 */
void insertAtPosition(struct Dllist* dllist, int new_data, unsigned int k);

/*
 * This function checks if input data is unique in the list
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] data - data to be checked
 *
 * @returns - boolean value 1 is input data is unique; Otherwise, it returns 0.
 */
bool isUnique(struct Dllist* dllist, int data);

/*
 * This function deletes a node having value data
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] del_data - data to be deleted
 *
 * @returns - None
 */
void deleteNode(struct Dllist* dllist, int del_data);

/*
 * This function reverses the linked list
 *
 * @param[in] dllist - pointer to the doubly linked list
 *
 * @returns - None
 */
void reverseList(struct Dllist* dllist);

/*
 * This function returns the sum of all elements in the list
 *
 * @param[in] dllist - pointer to the doubly linked list
 * @param[in] sum_val - pointer to sum value of the list
 *
 * @returns - value 0 if there is no exception; Otherwise, it returns -1.
 */
int sum(struct Dllist* dllist, int* sum_val);

/*
 * This function displays the doubly linked list 
 * in two directions (forward & reverse)
 *
 * @param[in] dllist - pointer to the doubly linked list
 *
 * @returns - integer 0 if there is no exception; Otherwise, it returns -1.
 */
int printList(struct Dllist* dllist);

/*
 * This function counts the number of nodes in the doubly linked list
 *
 * @param[in] dllist - pointer to the doubly linked list
 *
 * @returns - number of nodes if there is no exception; Otherwise, it returns -1.
 */
int countNode(struct Dllist* dllist);

/*
 * This function search a specific element in the doubly linked list
 *
 * @param[in] dllist - pointer to the doubly linked list
 *
 * @returns - integer 0 if there is no exception; Otherwise, it returns -1.
 */
int search(struct Dllist* dllist, int data);

#endif // !_DOUBLY_LINKED_LIST_H_