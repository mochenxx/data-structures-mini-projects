/*
 * File name: structure.h
 *
 * Author: Mo Chen
 *
 * Description: Header file for structure declaration
 */
#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <stdlib.h>
#include <stdio.h>

/* Define Node structure */
struct Node
{
	int info;			// Info part
	struct Node* link;	// Link part to the next node
};

#endif // !_STRUCTURE_H_
