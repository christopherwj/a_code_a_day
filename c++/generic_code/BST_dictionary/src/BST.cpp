#include <iostream>
#include <cstdlib>
#include <cstring>

#include "BST.h"

using namespace std;

BST::BST() {
	root = NULL;
}

/**
 * @brief      Creates a leaf to add
 *
 * @param      word  The word to add
 * @param      def   The definition attached to that word
 *
 * @return     returns pointer for adding later
 */
BST::Node* BST::createLeaf(char *word, char *def) { //string word imported from user
	Node* n = new Node;
	n->word = word;
	n->def  = def;
	n->left = NULL;
	n->right= NULL;

	return n;
}
/**
 * @brief      Adds a leaf.
 *
 * @param      word  The word to be added
 * @param      def   The definition associated with word to be added.
 * @param      ptr   The pointer to traverse the tree.
 *
 * @return     returns 0 on success -1 on failure
 */
int BST::addLeaf(char *word, char *def, Node* ptr)
{
	if (root == NULL)
	{
		root = createLeaf(word, def);
		return 0;
	}
	if (strcmp(word, ptr->word) < 0) {      //When we integrate words we need to use string compare
		if (ptr->left != NULL) {
			addLeaf(word, def, ptr->left);
		}
		else {
			ptr->left = createLeaf(word, def);
			return 0;
		}
	}
	else if (strcmp(word, ptr->word) > 0) { //When we integrate words we need to use string compare
		if (ptr->right != NULL) {
			addLeaf(word, def, ptr->right);
		}
		else {
			ptr->right = createLeaf(word, def);
			return 0;
		}
	}
	else
	{
		return -1; /* if word already exists */
	}
}
/**
 * @brief      Finds a leaf.
 *
 * @param      word  The word to find
 * @param      ptr   The pointer to traverse the tree
 *
 * @return     returns word and definition if found
 */
char** BST::findLeaf(char *word, Node* ptr)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (strcmp(word, ptr->word) < 0) {      //When we integrate words we need to use string compare
		if (ptr->left != NULL) {
			findLeaf(word, ptr->left);
		}
		else {
			return NULL;
		}
	}
	else if (strcmp(word, ptr->word) > 0) { //When we integrate words we need to use string compare
		if (ptr->right != NULL) {
			findLeaf(word, ptr->right);
		}
		else {
			return NULL;
		}
	}
	else
	{
		char* vals[] = {ptr->word, ptr->def};
		return vals;
	}
}
/**
 * @brief      Gets the root.
 *
 * @return     The root.
 */
BST::Node* BST::getRoot(){
	return root;
}

/**
 * @brief      Prints in order.
 *
 * @param      ptr   The pointer to traverse for printing.
 */
void BST::printInOrder(Node* ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
		{
			printInOrder(ptr->left);
		}
		if (ptr->right != NULL)
		{
			printInOrder(ptr->right);
		}
	}
	else
	{
		cout << "The tree is empty\n";
	}
}
