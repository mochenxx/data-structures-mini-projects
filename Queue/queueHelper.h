/*
 * File name: queueHelper.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for queue helper functions
 */

#ifndef _QUEUEHELPER_H_
#define _QUEUEHELPER_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* Data structure for a queue */
struct Queue 
{
	int front;				// Index of the front element of queue
	int	rear;				// Index of the rear element of queue
	int size;				// Number of current elements in queue
	unsigned int capacity;	// Maximum capacity of queue
	int* array;
};

/*
 * This function creates a queue with a given capacity
 * 
 * @param[in] capacity - maximum number of elements can be added to a queue
 *
 * @returns - pointer to new queue
 */
struct Queue* createQueue(unsigned int capacity);

/*
 * This function checks is a queue is full
 *
 * @param[in] queue - pointer to a given queue
 *
 * @returns - boolean value true is queue is full, else false
 */
bool isFull(struct Queue* queue);

/*
 * This function checks is a queue is empty
 *
 * @param[in] queue - pointer to a given queue
 *
 * @returns - boolean value true is queue is empty, else false
 */
bool isEmpty(struct Queue* queue);

/*
 * This function adds an item to a given queue, and inserts at the rear
 *
 * @param[in] queue - pointer to a given queue
 * @param[in] item - item to be added
 *
 * @returns - none
 */
void enqueue(struct Queue* queue, int item);

/*
 * This function removes an item from a given queue
 *
 * @param[in] queue - pointer to a given queue
 * @param[in] remove - pointer to removed item
 *
 * @returns - 0 if there is no error, else -1
 */
int dequeue(struct Queue* queue, int* remove);

/*
 * This function gets the front element of a given queue
 *
 * @param[in] queue - pointer to a given queue
 * @param[in] front - pointer to the front element of queue
 *
 * @returns - 0 if there is no error, else -1
 */
int queueFront(struct Queue* queue, int* front);

/*
 * This function gets the rear element of a given queue
 *
 * @param[in] queue - pointer to a given queue
 * @param[in] rear - pointer to the rear element of queue
 *
 * @returns - 0 if there is no error, else -1
 */
int queueRear(struct Queue* queue, int* rear);

/*
 * This function display a queue in forward order
 *
 * @param[in] queue - pointer to a given queue
 *
 * @returns - none
 */
void displayQueue(struct Queue* queue);

/*
 * This function free the memory allocated to a given queue
 *
 * @param[in] queue - pointer to a given queue
 *
 * @returns - none
 */
void freeQueue(struct Queue* queue);

#endif // !_QUEUEHELPER_H_