/*
 * File name: queueHelper.c
 *
 * Author: Mo Chen
 *
 * Description: C source code for queue helper functions
 */

#include "queueHelper.h"

struct Queue* createQueue(unsigned int capacity)
{
	// Allocate memory for a new queue
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

	// Check if there is enough memory for newly created queue
	if (NULL == queue)
	{
		printf("\n[ERROR] No such memory for a new queue!\n");
		return NULL;
	}

	// Else, initialize queue
	queue->capacity = capacity;
	queue->front = -1;
	queue->size = 0;
	queue->rear = -1;

	// Allocate memory for a new array
	queue->array = (int*)malloc(sizeof(int) * capacity);

	// Check if there is enough memory for newly created array
	if (NULL == queue->array)
	{
		printf("\n[ERROR] No such memory for a new array!\n");
		return NULL;
	}

	return queue;
}

bool isFull(struct Queue* queue)
{
	// Argument consistency check
	if (NULL == queue)
	{
		return false;
	}

	// Queue is full when size become equal to the capacity
	return (queue->size == queue->capacity);
}

bool isEmpty(struct Queue* queue)
{	
	// Argument consistency check
	if (NULL == queue)
	{
		return false;
	}

	// Queue is empty when size is 0
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check if queue is full already
	if (isFull(queue))
	{
		printf("\n[ERROR] Queue is full.\n");
		return;
	}

	// Check if queue is empty
	// If yes, make front and rear index as 0
	if (isEmpty(queue))
	{
		queue->front = queue->rear = 0;
	}
	// Else, increment rear index
	else 
	{
		queue->rear = (queue->rear + 1) % (queue->capacity);
	}

	// Add new item to queue
	queue->array[queue->rear] = item;
	(queue->size)++;
}

int dequeue(struct Queue* queue, int* remove)
{
	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return -1;
	}
	
	// Check if queue is empty
	if (isEmpty(queue))
	{
		printf("\n[ERROR] Queue is empty.\n");
		return -1;
	}

	// Store value of element to be removed, and decrement size of queue
	*remove = queue->array[queue->front];
	(queue->size)--;

	// Check if there is only one element in the queue
	if (queue->front == queue->rear)
	{
		// Make front and rear as -1
		queue->front = queue->rear = -1;
	}
	else
	{
		// Increment the front index by one
		queue->front = (queue->front + 1) % (queue->capacity);
	}
	
	return 0;
}

int queueFront(struct Queue* queue, int *front)
{
	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return -1;
	}

	// Check if queue is empty
	if (isEmpty(queue))
	{
		printf("\n[ERROR] Queue is empty.\n");
		return -1;
	}

	// Get the front of queue
	*front = queue->array[queue->front];
	return 0;
}

int queueRear(struct Queue* queue, int* rear)
{
	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return -1;
	}

	// Check if queue is empty
	if (isEmpty(queue))
	{
		printf("\n[ERROR] Queue is empty. Cannot remove more.\n");
		return -1;
	}

	// Get the rear of queue
	*rear = queue->array[queue->rear];
	return 0;
}

void displayQueue(struct Queue* queue)
{
	int i;
	int index;	// Index of element while traversing circularly from queue

	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check for empty queue
	if (isEmpty(queue))
	{
		printf("\nQueue is empty!\n");
		return;
	}

	// Print all elements in queue in forward order
	for (i = 0; i < queue->size; i++)
	{
		index = (queue->front + i) % queue->capacity;
		printf("  %d", queue->array[index]);
	}

	printf("\n");
}

void freeQueue(struct Queue* queue)
{
	int i;
	int index;	// Index of element when traversing circularly the queue

	// Argument consistency check
	if (NULL == queue)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check for empty queue
	if (isEmpty(queue))
	{
		return;
	}

	// Make elements in queue as zero
	for (i = 0; i < queue->size; i++)
	{
		index = (queue->front + i) % (queue->capacity);
		queue->array[index] = 0;
	}

	// Free allocated memory for array and queue
	free(queue->array);
	free(queue);

	queue = NULL;
}