#include <cstdlib>
#include <iostream>

#include "BST.h"

using namespace std;



BST::BST()
{
	root = NULL;
}
/**
 * @brief      Adds a leaf to the BST
 *
 * @param[in]  key   The value being added
 *
 * @return     returns node pointer to last value entered
 */
BST::node* BST::createLeaf(char key)
{
	node* n = new node;
	n->key = key;
	n->left = 0;
	n->right = 0;
	return n;
}
/**
 * @brief      Adds a leaf.
 *
 * @param[in]  key   The key/value to add
 * 
 */
void BST::addLeaf(char key)
{
	addLeafPrivate(key, root);
}

/**
 * @brief      Adds a leaf private.
 *
 * @param[in]  key   The key to be added
 * @param      Ptr   The node pointer
 */
void BST::addLeafPrivate(int key, node* Ptr)
{
	if (root == 0)
	{
		root = createLeaf(key);
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != 0)
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
		if (Ptr->right != 0)
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
		cout << " The key " << key << " has already been added to the tree." 
			<< endl;
	}
}
/**
 * @brief      Prints the BST in Pre-Order
 */
void BST::printPreOrder()
{
	// start at root and traverse the rest of the tree
	printPreOrderPrivate(root); 
	cout << endl;
}
/**
 * @brief      Prints the values of the BST's private members
 *
 * @param      Ptr   The pointer needed to recurse through tree
 */
void BST::printPreOrderPrivate(node* Ptr)
{
	
	if (root != 0)
	{
		cout << Ptr->key << " ";
		
		if (Ptr->left != 0 && Ptr->right != 0) { //case 3 both not null
			printf("%c   ", Ptr->left->key);
			printf("%c ", Ptr->right->key);
		}
		if (Ptr->left == 0)  { //case 1
			printf("NIL ");
		}
		if (Ptr->right == 0) { // case 2
			printf("NIL ");
		}
		if (Ptr->left != 0)
		{
			//printf("%c   ", Ptr->left->key);
			cout << "\n";
			printPreOrderPrivate(Ptr->left);
		}

		if (Ptr->right != 0)
		{	
			if (Ptr->left == 0) {
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

/**
 * @brief      Searches tree for a given value
 *
 * @param[in]  key   The key to find
 */
void BST::searchKey(int key)
{
	searchKeyPrivate(key, root);
}

void BST::searchKeyPrivate(char key, node* Ptr) //option 3
{
	if (root == 0)
	{
		cout << " There are no members in the binary search tree to search";
	}
	else if (key < Ptr->key)
	{
		if (Ptr->left != 0)
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
		if (Ptr->right != 0)
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
		cout << " The key " << key << " exists within the binary search tree." 
			<< endl;
	}
}
/**
 * @brief      Removes a node with a provided key
 * This is really a helper function for removeNodePrivate
 *
 * @param[in]  key   The key to be removed.
 */
void BST::removeNode(int key) {
	removeNodePrivate(key, root);
}

/**
 * @brief      Removes a node's private key value.
 *
 * @param[in]  key     The key to be removed
 * @param      parent  The parent above the removed key for reassigning child 
 *	node
 */
void BST::removeNodePrivate(int key, node* parent) {
	if (root != 0) 
	{
		if (root->key == key) 
		{
			removeRootMatch();
		}
		else
		{
			if (key < parent->key && parent->left != 0)
			{
				parent->left->key == key ?
				removeMatch(parent, parent->left, true) :
				removeNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != 0)
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
/**
 * @brief      Removes a root match.
 */
void BST::removeRootMatch() {
	if (root != 0)
	{
		node* deletePtr = root;
		char rootKey = root->key;
		char smallestRightSubtree;

		//case 0 - root has no children
		if (root->left == 0 && root->right == 0)
		{
			root = 0;
			delete deletePtr;
		}
		// case 1- one child
		else if (root->left == 0 && root->right != 0)
		{
			root = root->right;
			deletePtr->right = 0;	//disconnect the old root from the tree
			delete deletePtr;	//delete old root
			cout << " The key " << rootKey << "was deleted." 
				<< "The new root contains the key" << root->key << endl;
		}
		else if (root->left != 0 && root->right == 0)
		{
			root = root->left;
			deletePtr->left = 0;        //disconnect the old root from the tree
			delete deletePtr;	//delete old root
			cout << " The key " << rootKey << "was deleted." 
				<< "The new root contains the key" << root->key << endl;
		}
		else 	//case two root node has two children
		{
			//deleting root smallest in rigt subtree
			smallestRightSubtree = findsmallestPrivate(root->right); 
			removeNodePrivate(smallestRightSubtree, root);
			root->key = smallestRightSubtree;
			cout << " the leaf value " << rootKey << "was replaced by " 
				<< root->key << endl;
		}
	}
	else
	{
		cout << "cannot remove node as tree is empty.";
	}
	
}


/**
 * @brief      Helper function for findsmallestPrivate
 *
 * @return     returns to associated function to recurse tree again
 */
int BST::findsmallest() {
	return findsmallestPrivate(root);
}


/**
 * @brief      Finds the smallest node
 *
 * @param      Ptr   The pointer used to traverse the tree
 *
 * @return     return's node with smallest key
 */
int BST::findsmallestPrivate(node* Ptr) {
	if (root == 0)
	{
		cout << " The tree is empty.";
		return -1000;
	}
	else
	{
		if (Ptr->left != 0)
		{
			return findsmallestPrivate(Ptr->left);
		}
		else
		{
			return Ptr->key;
		}
	}
}

/**
 * @brief      Removes a match.
 *
 * @param      parent  The parent
 * @param      match   The match
 * @param[in]  left    The left
 */
void BST::removeMatch(node* parent, node* match, bool left)
{
	if (root != 0)
	{
		node* deletePtr;
		char matchKey = match->key;
		char smallestRightsubtree;

		if (match->left == 0 && match->right == 0)
		{
			deletePtr = match;
			left == true ? parent->left = 0 : parent->right = 0;
			delete deletePtr;
			cout << " The node containing " << matchKey << "has been moved.\n";
		}
		else if (match->left == 0 && match->right != 0)
		{
			left == true ? parent->left = match->right : parent->right = 
				match->right;
			match->right = 0;
			deletePtr = match;
			delete deletePtr;
			cout << "the node with the key" << matchKey << "was moved\n";
		}
		else if (match->left != 0 && match->right == 0)
		{
			left == true ? parent->left = match->left : parent->right = 
				match->left;
			match->right = 0;
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
/**
 * @brief      Counts how many leafs are in tree helper function
 *
 * @return     returns to helper function to traverse other side of tree
 */
int BST::count() {
	int counter = 0;
	return countPrivate(root, counter);
}
/**
 * @brief      Searches for the first match.
 *
 * @param[in]  key   The key to search for
 */
void BST::find(char key) {
	char keyToFind;
	keyToFind = key;
	return findPrivate(root, keyToFind);
}
/**
 * @brief      Finds a private.
 *
 * @param      Ptr   The pointer to traverse the tree
 * @param[in]  key   The key to be found
 */
void BST::findPrivate(node* Ptr, char key)
{

	if (root != 0)
	{
		if (Ptr->key == key) {
			if (Ptr->left->key != 0) {
				printf("The child of %c is %c  \n ", key, Ptr->left->key);
			}
			if (Ptr->right->key != 0) {
				printf("The child of %c is %c ", key, Ptr->right->key);
			}
			return;
		}
		if (Ptr->left != 0)
		{
			findPrivate(Ptr->left, key);
		}

		if (Ptr->right != 0)
		{
			findPrivate(Ptr->right, key);
		}
	}
	else
	{
		cout << "The tree is empty." << endl;
	}
}
/**
 * @brief      Counts the number of all leafs
 *
 * @param      Ptr    The pointer needed to traverse the tree
 * @param      count  The amount of trees
 *
 * @return     Number of leafs.
 */
int BST::countPrivate(node* Ptr, int &count) {
	
	if (root != 0)
	{
		++count;
		if (Ptr->left != 0)
		{
			countPrivate(Ptr->left, count);
		}

		if (Ptr->right != 0)
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

