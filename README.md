# Data Structures Mini Projects
Data structures mini projects for learning sharing.

## Table of Contents

- [Compatability](#compatability)
- [Projects](#projects)
- [Contact](#contact)

## Compatability

- Operating System: Windows 10
- Compiler: Microsoft Visual C++ 2019

## Projects
### Sorting Algorithms

- This program creates four standard sorting algorithms: 
  * Selection Sort
  * Insertion Sort
  * Bubble Sort
  * Merge Sort 
- Optimized approaches are added to improve sorting performance in terms of time complexity
- Program can sort array through two ways:
  * Input an integer array from keyboard
  * Read user-defined arrays from a csv. file
- C Source Code
  * [Sorting](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Sorting)

### Array

This projects achieves two goals in terms of simple lists, and implements frequently-used operations for lists.
  
#### Goal-1: Create an array of integers
- This list stores a list of integer values given by user input.
- Available operations are as follows: 
  * Add an element to the list - `Input element must be unique`
  * Delete an element from the list - `Need to enter an element value to be deleted`
  * Clear all elements in the list
  * Get Sum of all elements in the list
  * Print all elements in the list
- A List has the following properties:
  * list pointer
  * list size (from program input)
  * list count (number of elements in the list)

#### Goal-2: Enhance simple list
- Thie list stores a list of user-defined structures that contains not only integer values but the time of element addition.
- Therefore, program can diffference the sequence of each element based on stored time value.
- A List has the following properties:
  * list pointer
  * list size (from program input)
  * list count (number of elements in the list)
  * list current index (index of last element added to the list)
- In addition to deleting a specific element(the 2nd operation as above), two more operations are considered: 
  * Delete last added element
  * Delete oldest added element
- Program is also capable to fetch records within certain time requirements
  * Fetch records after a time (e.g., 9:00)
  * Fetch records before a time (e.g., 16:00)
  * Fetch records between a time interval (e.g., b/w 11:00 and 12:00)

#### C Source Code
  * [Array of integers](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Array/01-Array-of-Integers)
  * [Enhanced array of structures](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Array/02-Array-of-Structures)

### Linked List

This project implements two type of linked list: singly linked list and doubly linked list.
  
#### Singly Linked List
- This program allows to input a singly linked list of integers.
- Following is representation of a SLL node in C language.
```
/* Node structure of singly linked list */
struct Node
{
    int info;             // Info part
    struct Node* link;	  // Pointer to next node in SLL
};
```

#### Doubly Linked List
- This program allows to input a doubly linked list of integers.
- Following is representation of a DLL node in C language.
```
/* Node structure of doubly linked list */
struct Node
{
    int data;             // Data part
    struct Node* next;    // Pointer to next node in DLL
    struct Node* prev;    // Pointer to previous node in DLL
};
```
- Also, the program defines a doubly linked list structure `Dllist` which contains pointer to head node and pointer to tail node.
```
/* Doubly linked list structure */
struct Dllist {
	struct Node* head;	// Pointer to head node in DLL
	struct Node* tail;	// Pointer to tail node in DLL
};
```

#### Available Operations
1. Display (Print) the linked list in forward direction
2. Display (Print) the linked list in reverse direction
3. Count the number of current nodes
4. Search for a particular element
5. Insert a node on the front of the list
6. Insert a node at the end of the list
7. Insert a node after a specified node (e.g., insert value 8 after value 5)
8. Insert a node before a specified node (e.g., insert value 33 before value 9)
9. Insert a node at a given position (e.g., insert value 7 at the third position in the list )
10. Delete a node with a given value
11. Reverse the list
12. Get the sum of all elements in the list
13. Clear all elements in the list

__C Source Code__
  * [Singly Linked List](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Linked-List/Singly-Linked-List)
  * [Doubly Linked List](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Linked-List/Doubly-Linked-List)

### Stack
This project creates stack data structure and implements a stack in two ways:
  - Using array
  - Using linked list

#### Implementing Stack using Array
- Following is a representaion of Stack using array in C language:
```
/* A structure to represent a stack */
struct Stack
{
	unsigned int capacity;		// Maximum size of stack
	int top;			// Top index in stack
	int* array;			// Pointer to array
};

```
#### Implementing Stack using Linked List
- Following is a representaion of Stack using linked list in C language:
```
/* A structure to represent a stack node */
struct StackNode {
	int data;			// Stack node contains integer data
	struct StackNode* next;		// Pointer to the next stack pointer
};

```
Avaiable Operations
1. Push: Adds an item to the stack. If the stack is full, then it is said to be an Overflow condition.
2. Pop: Remove an iten frim the stack. The items are poped are in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
3. isEmpty: Returns true if stack is empty, else false
4. isFull: Returns true if stack is full, else false.
5. Peek: Returns the top element of stack.
6. Display stack both in forward and backward order.
7. Reverse: Reverse the stack
  
__C Source Code__
  * [Stack using Array](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Stack/Stack-using-array)
  * [Stack using Linked List](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Stack/Stack-using-linked-list)

### Binary Search Tree
- This project creates a binary search tree (BST) and implements binary search algorithm.
- Following is a representaion of BST node in C language:
```
/* Node structure of binary search tree */
struct Node {
	int key;			// node will store an integer
	struct Node* left;		// left child
	struct Node* right;		// right child
};
```
- Avaiable functionalities are as below:
  * Add new element in binary search tree (e.g. elements can be 2, 4, 10, etc.)
  * Search for a certain element
  * Remove element from binary tree
  * Print elements in ascending order
  * Print elements in descending order
  * Destroy complete tree (delete all leaves in BST)
- C Source Code
  * [Binary Search Tree](https://github.com/mochenxx/data-structures-mini-projects/tree/master/Binary-Search-Tree)


## Contact

You can reach me at mo.chen19@outlook.com for technical support or feel free to open an issue [here](https://github.com/mochenxx/data-structures-mini-projects/issues) :)
