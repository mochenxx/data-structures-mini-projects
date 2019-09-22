/*
 * File name: FreeList.h
 *
 * Author: Mo Chen
 *
 * Description: Header file to free memory of singly linked list
 */

#ifndef _FREELIST_H_
#define _FREELIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

/*
 * This function frees the memory of the singly linked list
 *
 * @param[in] head_ref - a reference (pointer to pointer) to the head of a list
 *
 * @returns - none
 */
void freeList(struct Node** head_ref);

#endif // !_FREELIST_H_
