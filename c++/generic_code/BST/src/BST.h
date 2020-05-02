#pragma once

/**
 * @class BST BST.h 
 * @brief BST class to traverse nodes and delete or re-organize
 * Class that builds and navigates a binary search tree
 */
class BST
{

private:
	struct node
	{
		char key;
		node* left = 0;
		node* right = 0;
	};

	node* root;
	void addLeafPrivate(int key, node* Ptr);
	void printPreOrderPrivate(node* Ptr);
	void searchKeyPrivate(char key, node* Ptr);
	void removeNodePrivate(int key, node* parent);
	void removeRootMatch();
	int findsmallestPrivate(node* Ptr);
	void removeMatch(node* parent, node* match, bool left);
	int countPrivate(node* Ptr, int &count);
	node* createLeaf(char key);
	void findPrivate(node* Ptr, char key);

public:
	BST();
	void addLeaf(char key);
	void printPreOrder();
	void searchKey(int key);
	void removeNode(int key);
	int findsmallest();
	int count();
	void find(char keyToFind);


};

