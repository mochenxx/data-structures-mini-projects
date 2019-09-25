/*
* File name: BSTHelper.h
*
* Author: Mo Chen
*
* Description: Header file for binary search tree helper functions
*/

#ifndef _BSTHELPER_H_
#define _BSTHELPER_H_

#include <stdlib.h>
#include <stdio.h>

/* Node structure in BST */
struct Node {
	int key;				// node will store an integer
	struct Node* left;		// left child
	struct Node* right;		// right child
};

/*
 * This function creates a new node in the binary tree
 *
 * @param[in] data - integer number to be added
 *
 * @returns - pointer to this newly created node
 */
struct Node* newNode(int data);

/*
 * This function inserts a new node in a given BST
 *
 * @param[in] root - pointer to the root node of the BST
 * @param[in] key - key to be inserted
 *
 * @returns - pointer to the new root
 */
struct Node* insert(struct Node* root, int key);

/*
 * This function searches a given key in a given BST
 *
 * @param[in] root - pointer to the root node of the BST
 * @param[in] key - key to be searched
 *
 * @returns - pointer to the new root
 */
struct Node* search(struct Node* root, int key);

/*
 * This function implements the postorder traversal of a given BST
 *
 * @param[in] root - pointer to the root node of the binary tree
 *
 * @returns - None
 */
void inOrder(struct Node* root);

/*
 * This function prints a given BST in descending order
 *
 * @param[in] root - pointer to the root node of the binary tree
 *
 * @returns - None
 */
void printReverse(struct Node* root);

/*
 * This function deletes a node with given key in a given BST,
 * and returns the new root
 *
 * @param[in] root - pointer to the root node of the BST
 * @param[in] key - key to be searched
 *
 * @returns - pointer to new root
 */
struct Node* deleteNode(struct Node* root, int key);

/*
 * This function destroy the complete tree by deleting all leaves in BST,
 * and returns the new root
 *
 * @param[in] root - pointer to the root node of the BST
 *
 * @returns - pointer to new root
 */
struct Node* destroyTree(struct Node* root);

#endif // !_BSTHELPER_H_