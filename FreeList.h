/*
 * File name: FreeList.h
 *
 * Author: Mo Chen
 *
 * Description: Header file to free memory of doubly linked list
 */

#ifndef _FREELIST_H_
#define _FREELIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/*
 * This function frees the memory of the singly linked list
 *
 * @param[in] dllist - pointer to the doubly linked list
 *
 * @returns - none
 */
void freeList(struct Dllist* dllist);

#endif // !_FREELIST_H_