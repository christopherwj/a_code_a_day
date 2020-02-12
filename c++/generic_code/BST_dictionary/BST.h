#ifndef BST_H
#define BST_H

class BST{

private:
	struct Node{
		char *word;
		char *def; //change to word after compile 
		Node *left;
		Node *right;
	};

	Node *root;
	Node *createLeaf(char*, char*);
public:
	BST();
	int addLeaf(char*, char*, Node*);
	char** findLeaf(char*, Node*);
	Node* getRoot(void);
	void printInOrder(Node*);
};

#endif
