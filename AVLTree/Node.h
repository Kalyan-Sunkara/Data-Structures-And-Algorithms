#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
	Node();
	Node(int, string, int);
	Node* getRight();
	Node* getLeft();
	Node* getParent();
	void setParent(Node*);
	~Node();
	string getNodeData();
	int getNodeCounter();
	void setNodeData(string);
	void updateNodeCounter();
	void decrementNodeCounter();
	int getHeight();
	void updateHeight();
	void setRight(Node*);
	void setLeft(Node*);
	int setNodeCounter(int);
	int getBalanceFactor();
	void setBalanceFactor(int);
private:
	int counter;
	string data;
	int height;
	int balanceFactor;
	Node* right;
	Node* left;
	Node* parent;
};

#endif // NODE_H
