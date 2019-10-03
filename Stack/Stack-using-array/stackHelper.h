/*
 * File name: stackHelper.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for stack helper functions
 */

#ifndef _STACKHELPER_H_
#define _STACKHELPER_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Data structure for stack */
struct Stack
{
	unsigned int capacity;
	int top;
	int* array;
};

/*
 * This function initializes a stack with a given capacity
 * and returns the stack pointer
 *
 * @param[in] capacity - maximum capacity of the stack
 *
 * @returns - new stack pointer
 */
struct Stack* createStack(unsigned int capacity);

/*
 * This function returns the size of the stack
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - size of the stack
 */
int size(struct Stack* stack);

/*
 * This function checks if the stack is empty or not
 * and returns the result
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - 1 if stack if empty, else 0.
 */
int isEmpty(struct Stack* stack);

/*
 * This function checks if the stack is full or not
 * and returns the result
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - 1 if stack if full, else 0.
 */
int isFull(struct Stack* stack);

/*
 * This function adds an item to the stack
 *
 * @param[in] stack - pointer to a given stack
 * @param[in] item - item to be added
 *
 * @returns - none
 */
void push(struct Stack* stack, int item);

/*
 * This function gets the top from the stack without removing it, 
 * and pass the popped item value as an argument
 *
 * @param[in] stack - pointer to a given stack
 * @param[in] pop_val - pointer to popped item value
 *
 * @returns - 0 if there is no error, else -1.
 */
int peek(struct Stack* stack, int* top_val);

/*
 * This function removes an item from stack, 
 * and pass the popped item value as an argument
 *
 * @param[in] stack - pointer to a given stack
 * @param[in] pop_val - pointer to popped item value
 *
 * @returns - 0 if there is no error, else -1.
 */
int pop(struct Stack* stack, int* pop_val);

/*
 * This function display a stack in forward order
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - none
 */
void displayStack(struct Stack* stack);

/*
 * This function display a stack in backward order
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - none
 */
void printReversedStack(struct Stack* stack);

/*
 * This function reverses a stack
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - none
 */
void reverse(struct Stack* stack);

/*
 * This function free the memory allocated to a given stack
 *
 * @param[in] stack - pointer to a given stack
 *
 * @returns - none
 */
void freeStack(struct Stack* stack);

#endif // !_STACKHELPER_H_