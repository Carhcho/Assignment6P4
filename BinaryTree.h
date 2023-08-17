#pragma once
// Specification file for the IntBinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
private:
	struct TreeNode
	{
		int value;
		TreeNode* left;   // Pointer to left child node
		TreeNode* right;  // Pointer to right child node
	};

	TreeNode* root;       // Pointer to the root node

// Private member functions
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void deleteNode(int, TreeNode*&);
	void makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;

public:
	// Constructor
	BinaryTree()
	{
		root = nullptr;
	}

	// Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	// Binary tree operations
	void ADD(int);
	void REMOVE(int);
	int COUNT();


	void displayInOrder() const
	{
		displayInOrder(root);
	}
	int count = 0;

};
#endif