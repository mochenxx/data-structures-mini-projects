#ifndef _STACKHELPER_H
#define _STACKHELPER_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// A structure to represent a stack node
struct StackNode {
	int data;				// Stack node contains integer data
	struct StackNode* next;	// Pointer to the next stack pointer
};

/* 
 * This functions creates a new node to the stack with a given data,
 * and returns this newly created stack node
 *
 * @param[in] data - a given integer number
 *
 * @returns - pointer to this newly created stack node
 */
struct StackNode* newNode(int data);

/*
 * This functions checks if a given stack is empty
 *
 * @param[in] top - pointer to top element of stack
 *
 * @returns - boolean value true if the stack is empty, else false
 */
bool isEmpty(struct StackNode* top);

/*
 * This functions adds an item to stack with a given data
 *
 * @param[in] top_ref - reference (pointer to pointer) to top node of stack
 * @param[in] data - a given integer number
 *
 * @returns - none
 */
void push(struct StackNode** top_ref, int data);

/*
 * This functions removes an item from stack,
 * and returns the removed data
 *
 * @param[in] top_ref - reference (pointer to pointer) to top Node of stack
 *
 * @returns - integer data of removed item
 */
int pop(struct StackNode** top_ref, int* poppedVal);

/*
 * This functions returns the top element from stack without removing it
 *
 * @param[in] top_ref - reference (pointer to pointer) to top Node of stack
 *
 * @returns - data of the top element from stack
 */
int peek(struct StackNode* top_ref, int* topVal);

/*
 * This functions display a stack in forward order
 *
 * @param[in] top - pointer to top element of stack
 *
 * @returns - none
 */
void displayStack(struct StackNode* top);

/*
 * This functions display a stack in backward order
 *
 * @param[in] top - pointer to top element of stack
 *
 * @returns - none
 */
void printReversedStack(struct StackNode* top);

void reverseUsingWhile(struct StackNode** top_ref);

#endif // !_STACKHELPER_H
