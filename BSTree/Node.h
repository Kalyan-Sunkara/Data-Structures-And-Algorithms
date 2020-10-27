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
private:
	int counter;
	string data;
	int height;
	Node* right;
	Node* left;
};

#endif // NODE_H
