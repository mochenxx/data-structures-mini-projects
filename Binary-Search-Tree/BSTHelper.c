/*
* File name: BSTHelper.c
*
* Author: Mo Chen
*
* Description: C source code for binary search tree helper functions
*/

#include "BSTHelper.h"

/*
 * This function implements the preorder traversal of a given BST
 *
 * @param[in] root - pointer to the root node of the binary tree
 *
 * @returns - None
 */
static void preOrder(struct Node* root);

/*
 * This function implements the postorder traversal of a given BST
 *
 * @param[in] root - pointer to the root node of the binary tree
 *
 * @returns - None
 */
static void postOrder(struct Node* root);

/*
 * This function returns the node with the minimum key value found in BST
 *
 * @param[in] node - pointer to the root of the binary tree
 *
 * @returns - node with the minimum key value found in BST
 */
static struct Node* minValueNode(struct Node* node);

/*
 * This function returns the node with the maximum key value found in BST
 *
 * @param[in] node - pointer to the root of the binary tree
 *
 * @returns - node with the maximum key value found in BST
 */
static struct Node* maxValueNode(struct Node* node);

struct Node* newNode(int data)
{
	struct Node* temp;

	// Allocate memory and initialize node pointer
	temp = (struct Node*)malloc(sizeof(struct Node));

	if (NULL == temp)
	{
		printf("\n No such memory!\n");
		return NULL;
	}
	else
	{
		temp->key = data;
		temp->left = NULL;
		temp->right = NULL;

		// Return the new node pointer
		return temp;
	}
}

struct Node* insert(struct Node* root, int key)
{
	/* If the tree is empty, return a new node */
	if (NULL == root)
	{
		return newNode(key);
	}

	/* Otherwise, recursive down the tree */
	if (key > root->key)
	{
		root->right = insert(root->right, key);
	}
	else if (key < root->key)
	{
		root->left = insert(root->left, key);
	}

	/* Return the root pointer */
	return root;
}

// Search a given key in a BST
struct Node* search(struct Node* root, int key)
{
	// Base case: root is NULL or key is present at root
	if ((NULL == root) || key == (root->key))
	{
		return root;
	}

	// Key if greater than root's key
	if (key > root->key)
	{
		return search(root->right, key);
	}
	// Key is smaller than root's key
	else
	{
		return search(root->left, key);
	}
}

static void preOrder(struct Node* root)
{
	// Check if BST is empty
	if (NULL == root)
	{
		return;
	}

	// Check if the root is not NULL
	if (root != NULL)
	{
		printf(" %d ", root->key);	// Print data at root
		preOrder(root->left);		// Visit left child
		preOrder(root->right);		// Visit right child
	}
}

void inOrder(struct Node* root)
{
	// Check if BST is empty
	if (NULL == root)
	{
		return;
	}

	// Check if the root is not NULL
	if (root != NULL)
	{
		
		inOrder(root->left);		// Visit left child
		printf(" %d ", root->key);	// Print data at root
		inOrder(root->right);		// Visit right child
	}
}

static void postOrder(struct Node* root)
{
	// Check if the root is not NULL
	if (root != NULL)
	{
		postOrder(root->left);		// Visit left child
		postOrder(root->right);		// Visit right child
		printf(" %d ", root->key);	// Print data at root
	}
}

void printReverse(struct Node* root)
{
	// Check if BST is empty
	if (NULL == root)
	{
		return;
	}

	printReverse(root->right);
	printf(" %d ", root->key);
	printReverse(root->left);
}

static struct Node* minValueNode(struct Node* node)
{
	// Argument consistency check
	if (NULL == node)
	{
		return NULL;
	}

	if (NULL == node->left)
	{
		return node;
	}

	return minValueNode(node->left);
}

static struct Node* maxValueNode(struct Node* node)
{
	// Argument consistency check
	if (NULL == node)
	{
		return NULL;
	}

	if (NULL == node->right)
	{
		return node;
	}

	return maxValueNode(node->right);
}

struct Node* deleteNode(struct Node* root, int key)
{
	struct Node* temp, *successor;

	// Check if root is NULL, which means given key is not found in BST
	// Then we just return NULL
	if (NULL == root)
	{
		return NULL;
	}

	// If the key to be deleted is smaller than the root's key
	// then it lies in left subtree
	if (key < root->key)
	{
		root->left = deleteNode(root->left, key);
	}

	// If the key to be deleted is greater than the root's key
	// then it lies in right subtree
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
	}

	// If key is same as root's key
	// then this is the node to be deleted
	else
	{
		// 1. Node with only one child or no child
		if (NULL == root->left)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		else if (NULL == root->right)
		{
			temp = root->left;
			free(root);
			return temp;
		}

		// 2. Node with two children
		// root->left != NULL && root->right != NULL
		else
		{
			// Get the successor (smallest in the right subtree)
			successor = minValueNode(root->right);
		
			// Copy the inorder successor's content to this node
			root->key = successor->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, successor->key);
		}
	}
	return root;
}


struct Node* destroyTree(struct Node* root)
{
	if (NULL == root)
	{
		return NULL;
	}
	if ((NULL == root->left) && (NULL == root->right))
	{
		free(root);
		return NULL;
	}
	
	// Else recursively destroy in left and right subtrees 
	destroyTree(root->left);
	destroyTree(root->right);
	
	return root;
}