#include "BinaryTree.h"
#include "Employee.h"
#include <iostream>
using namespace std;

void BinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;                    // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);       // Search the left branch.
	else
		insert(nodePtr->right, newNode);      // Search the right branch.
}

void BinaryTree::destroySubTree(TreeNode* nodePtr)
{
	if (nodePtr) {
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);

		delete nodePtr;

	}
}

void BinaryTree::deleteNode(int num, TreeNode*& nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	if (num > nodePtr->right->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

void BinaryTree::makeDeletion(TreeNode*& nodePtr)
{
	TreeNode* tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}
//I choose the In Order way to print the contents of the binary tree
void BinaryTree::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}
// using the function insert to do the ADD
void BinaryTree::ADD(int num)
{
	TreeNode* newNode = nullptr;     // Pointer to a new node.
		  // Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
	count++;
}
//using the count variable in the ADD and REMOVE functions to keep count of the elements in the Tree
int BinaryTree::COUNT()
{
	cout << "#: " << count << endl;
	return count;
}
//using delete node to REMOVE the desired element
void BinaryTree::REMOVE(int num)
{
	deleteNode(num, root);
	count--;
}

