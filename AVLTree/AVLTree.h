#ifndef AVLTREE_H
#define AVLTREE_H

#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void insert(const string &);
	int balanceFactor(Node*);
	void printBalanceFactors();
	void visualizeTree(const string &);
	void treeBalance();
//	void inOrder();
//	void insert(const string&);
private:
	Node* findUnbalancedNode(Node*);
	void rotate(Node*);
	void rotateLeft(Node*);
	void rotateRight(Node*);
	void printBalanceFactors(Node*);
	void visualizeTree(ofstream &, Node*);
	int heightCheck(Node*) const;
	void treeBalance(Node* );
//	void inOrder(Node*);
	Node* root;
};

#endif // AVLTREE_H
