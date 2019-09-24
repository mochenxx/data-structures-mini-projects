/*
 * File name: structure.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for structure declaration
 */

#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

#include <stdlib.h>
#include <stdio.h>

/* Node of a doubly linked list */
struct Node {
	int data;			// data part
	struct Node* next;	// Pointer to next node in DLL
	struct Node* prev;	// Pointer to previous node in DLL
};

/* Doubly linked list structure */
struct Dllist {
	struct Node* head;	// Pointer to head node in DLL
	struct Node* tail;	// Pointer to tail node in DLL
};
#endif // !_STRUCTURES_H_