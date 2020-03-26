#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;



BST::BST()
{
	root = NULL;
}

BST::node* BST::createLeaf(char key)
{
	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::addLeaf(char key)
{
	addLeafPrivate(key, root);
}


void BST::addLeafPrivate(int key, node* Ptr)
{
	if (root == NULL)
	{
		root = createLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			addLeafPrivate(key, Ptr->left);
		}
		else
		{
			Ptr->left = createLeaf(key);
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			addLeafPrivate(key, Ptr->right);
		}
		else
		{
			Ptr->right = createLeaf(key);
		}
	}
	else
	{
		cout << " The key " << key << " has already been added to the tree." << endl;
	}
}
void BST::printPreOrder()
{
	printPreOrderPrivate(root); // start at root and traverse the rest of the tree
	cout << endl;
}

void BST::printPreOrderPrivate(node* Ptr)
{
	
	if (root != NULL)
	{
		cout << Ptr->key << " ";
		
		if (Ptr->left != NULL && Ptr->right != NULL) { //case 3 both not null
			printf("%c   ", Ptr->left->key);
			printf("%c ", Ptr->right->key);
		}
		if (Ptr->left == NULL)  { //case 1
			printf("NIL ");
		}
		if (Ptr->right == NULL) { // case 2
			printf("NIL ");
		}
		if (Ptr->left != NULL)
		{
			//printf("%c   ", Ptr->left->key);
			cout << "\n";
			printPreOrderPrivate(Ptr->left);
		}

		if (Ptr->right != NULL)
		{	
			if (Ptr->left == NULL) {
				cout << Ptr->right->key;
			}
			cout << "\n";
			printPreOrderPrivate(Ptr->right);
		}

	}
	else
	{
		cout << "The tree is empty." << endl;
	}
}


void BST::searchKey(int key)
{
	searchKeyPrivate(key, root);
}

void BST::searchKeyPrivate(char key, node* Ptr) //option 3
{
	if (root == NULL)
	{
		cout << " There are no members in the binary search tree to search";
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != NULL)
		{
			searchKeyPrivate(key, Ptr->left);
		}
		else
		{
			cout << "The value entered does not exist in the binary tree.";
		}
	}
	else if (key > Ptr->key)
	{
		if (Ptr->right != NULL)
		{
			searchKeyPrivate(key, Ptr->right);
		}
		else
		{
			cout << "The value entered does not exist in the binary tree.";
		}
	}
	else
	{
		cout << " The key " << key << " exists within the binary search tree." << endl;
	}
}

void BST::removeNode(int key) {
	removeNodePrivate(key, root);
}


void BST::removeNodePrivate(int key, node* parent) {
	if (root != NULL) 
	{
		if (root->key == key) 
		{
			removeRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != NULL)
			{
				parent->left->key == key ?
				removeMatch(parent, parent->left, true) :
				removeNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != NULL)
			{
				parent->right->key == key ?
				removeMatch(parent, parent->left, false) :
				removeNodePrivate(key, parent->right);
			}
			else
			{
				cout << " The key doesn't exist in the tree." << endl;
			}
		}
	}
	else 
	{
		cout << "The tree is empty.";
	}

}

void BST::removeRootMatch() {
	if (root != NULL)
	{
		node* deletePtr = root;
		char rootKey = root->key;
		char smallestRightSubtree;

		//case 0 - root has no children
		if (root->left == NULL && root->right == NULL)
		{
			root = NULL;
			delete deletePtr;
		}
		// case 1- one child
		else if (root->left == NULL && root->right != NULL)
		{
			root = root->right;
			deletePtr->right = NULL;	//disconnect the old root from the tree
			delete deletePtr;	//delete old root
			cout << " The key " << rootKey << "was deleted." << "The new root contains the key" <<
				root->key << endl;
		}
		else if (root->left != NULL && root->right == NULL)
		{
			root = root->left;
			deletePtr->left = NULL;        //disconnect the old root from the tree
			delete deletePtr;	//delete old root
			cout << " The key " << rootKey << "was deleted." << "The new root contains the key" <<
				root->key << endl;
		}
		else 	//case two root node has two children
		{
			smallestRightSubtree = findsmallestPrivate(root->right); //deleting root smallest in rigt subtree
			removeNodePrivate(smallestRightSubtree, root);
			root->key = smallestRightSubtree;
			cout << " the leaf value " << rootKey << "was replaced by " << root->key << endl;
		}
	}
	else
	{
		cout << "cannot remove node as tree is empty.";
	}
	
}



int BST::findsmallest() {
	return findsmallestPrivate(root);
}



int BST::findsmallestPrivate(node* Ptr) {
	if (root == NULL)
	{
		cout << " The tree is empty.";
		return -1000;
	}
	else
	{
		if (Ptr->left != NULL)
		{
			return findsmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

void BST::removeMatch(node* parent, node* match, bool left)
{
	if (root != NULL)
	{
		node* deletePtr;
		char matchKey = match->key;
		char smallestRightsubtree;

		if (match->left == NULL && match->right == NULL)
		{
			deletePtr = match;
			left == true ? parent->left = NULL : parent->right = NULL;
			delete deletePtr;
			cout << " The node containing " << matchKey << "has been moved.\n";
		}
		else if (match->left == NULL && match->right != NULL)
		{
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = NULL;
			deletePtr = match;
			delete deletePtr;
			cout << "the node with the key" << matchKey << "was moved\n";
		}
		else if (match->left != NULL && match->right == NULL)
		{
			left == true ? parent->left = match->left : parent->right = match->left;
			match->right = NULL;
			deletePtr = match;
			delete deletePtr;
			cout << "the node with the key" << matchKey << "was moved\n";
		}
		else //case where matching node has two children
		{
			smallestRightsubtree = findsmallestPrivate(match->right);
			removeNodePrivate(smallestRightsubtree, match);
			match->key = smallestRightsubtree;
		}
	}
	else
	{
		cout << "Cannot remove match" << endl;
	}
}

int BST::count() {
	int counter = 0;
	return countPrivate(root, counter);
}

void BST::find(char key) {
	char keyToFind;
	keyToFind = key;
	return findPrivate(root, keyToFind);
}

void BST::findPrivate(node* Ptr, char key)
{

	if (root != NULL)
	{
		if (Ptr->key == key) {
			if (Ptr->left->key != NULL) {
				printf("The child of %c is %c  \n ", key, Ptr->left->key);
			}
			if (Ptr->right->key != NULL) {
				printf("The child of %c is %c ", key, Ptr->right->key);
			}
			return;
		}
		if (Ptr->left != NULL)
		{
			findPrivate(Ptr->left, key);
		}

		if (Ptr->right != NULL)
		{
			findPrivate(Ptr->right, key);
		}
	}
	else
	{
		cout << "The tree is empty." << endl;
	}
}

int BST::countPrivate(node* Ptr, int &count) {
	
	if (root != NULL)
	{
		++count;
		if (Ptr->left != NULL)
		{
			countPrivate(Ptr->left, count);
		}

		if (Ptr->right != NULL)
		{	
			countPrivate(Ptr->right, count);
		}
		
	}
	else
	{
		cout << "The tree is empty." << endl;
	}
	
	return count;
}

