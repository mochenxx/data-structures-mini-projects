#ifndef _STRUCTURES_H_
#define _STRUCTURES_H_

#include <stdlib.h>
#include <stdio.h>

/* Node of a doubly linked list */
struct Node {
    int data;             // Data part
    struct Node* next;    // Pointer to next node in DLL
    struct Node* prev;    // Pointer to previous node in DLL
};
#endif // !_STRUCTURES_H_