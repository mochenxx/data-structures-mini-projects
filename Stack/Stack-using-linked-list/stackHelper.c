/*
 * File name: stackHelper.c
 *
 * Author: Mo Chen
 *
 * Description: C program to implement stack helper functions
 */

#include "stackHelper.h"
#pragma warning (disable: 4996)

struct Stack* createStack(unsigned int capacity)
{
	// Allocate memory to stack
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));

	// Check if there is memory for newly created stack
	if (NULL == stack)
	{
		printf("\n[ERROR] Not such memory!\n");
		return NULL;
	}

	// Put in the capacity of stack
	stack->capacity = capacity;

	// Initialize top index as -1
	stack->top = -1;

	// Allocate memory for array
	stack->array = (int*)malloc(sizeof(int) * capacity);
	
	return stack;
}

int size(struct Stack *stack)
{
	return stack->capacity + 1;
}

int isEmpty(struct Stack *stack)
{
	return -1 == stack->top;
}

int isFull(struct Stack *stack)
{
	return stack->top == (stack->capacity - 1);
}

void push(struct Stack *stack, int item)
{
	unsigned int capacity = 0;

	// Check for empty stack
	if (NULL == stack)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check if stack is already full. 
	// If yes, then inserting an element would lead to stack overflow
	if (isFull(stack))
	{
		printf("\n[ERROR] Stack Overflow!\n");
		return;
	}

	// Add an element and increments the top index by 1
	stack->array[++stack->top] = item;

}

int peek(struct Stack *stack, int *top_val)
{
	// Argument consistency checks
	if ((NULL == stack) || (NULL == top_val))
	{
		printf("\n[ERROR] Invalid Arguments %d, %d.\n", 
				NULL == stack, NULL == top_val);
		return -1;
	}

	// Check for empty stack
	if (!isEmpty(stack))
	{
		*top_val = stack->array[stack->top];
		return 0;
	}
	else
	{
		return -1;
	}
}

int pop(struct Stack *stack, int *pop_val)
{
	int return_val, top_val;

	// Argument consistency checks
	if ((NULL == stack) || (NULL == pop_val))
	{
		printf("\n[ERROR] Invalid Arguments %d, %d.\n",
				NULL == stack, NULL == pop_val);
		return -1;
	}

	// Check for stack underflow
	if (isEmpty(stack))
	{
		printf("\n[ERROR] Stack Underflow!\n");
		return -1;
	}

	// Get the top element from stack
	return_val = peek(stack, &top_val);
	
	if (0 == return_val)
	{
		// Decrement stack size by 1 and return the popped element
		*pop_val = stack->array[stack->top--];
		return 0;
	}
	else
	{
		return -1;
	}
}

void displayStack(struct Stack* stack)
{
	int i;

	// Argument consistency check
	if (NULL == stack)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check for empty stack
	if (isEmpty(stack))
	{
		printf("\nStack is empty!\n");
		return;
	}

	// Print all elements in stack in forward order
	for (i = stack->top; i >= 0; i--)
	{
		printf("  %d", stack->array[i]);
	}

	printf("\n");
}

void printReversedStack(struct Stack* stack)
{
	int i;

	// Argument consistency check
	if (NULL == stack)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Check for empty stack
	if (isEmpty(stack))
	{
		printf("\nStack is empty!\n");
		return;
	}

	// Print all elements in stack in backward order
	for (i = 0; i <= stack->top; i++)
	{
		printf("  %d", stack->array[i]);
	}

	printf("\n");
}

void reverse(struct Stack* stack)
{
	unsigned int i;
	int pop_val;

	// Argument consistency check
	if (NULL == stack)
	{
		printf("\n[ERROR] Invalid Argument!\n");
		return;
	}

	// Allocate memory for a temporary stack
	struct Stack* temp = createStack(stack->capacity);
	
	// Check if there is memory for newly created temp stack
	if (NULL == temp)
	{
		printf("\n[ERROR] No such memory!\n");
		return;
	}

	// Push all elements of target stack to temp
	for (i = 0; i < stack->capacity; i++)
	{
		push(temp, stack->array[i]);
	}

	// Pop all elements of target stack and put them back
	for (i = 0; i < stack->capacity; i++)
	{
		pop(temp, &pop_val);
		stack->array[i] = pop_val;
	}
}

void freeStack(struct Stack* stack)
{
	struct Stack* temp;
	unsigned int i;

	// Check for empty stack
	if (NULL == stack)
	{
		printf("\nStack is empty. No need to free memory.\n");
		return;
	}

	for (i = 0; i < stack->capacity; i++)
	{
		stack->array[i] = 0;
	}

	free(stack->array);
	free(stack);

	stack = NULL;
}