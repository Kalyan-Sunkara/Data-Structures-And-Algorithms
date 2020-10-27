#include "Node.h"

Node::Node()
{
	counter = 0;
	data = "";
	height = 0;
	right = nullptr;
	left = nullptr;
}
Node::Node(int c, string d, int e):counter(c), data(d), height(e)
{
	right = nullptr;
	left = nullptr;
}
int Node::setNodeCounter(int num)
{
	counter = num;
	return counter;
}

Node* Node::getRight()
{
	return right;
}
Node* Node::getLeft()
{
	return left;
}
string Node::getNodeData()
{
	return data;
}
void Node::setRight(Node* temp)
{
	right = temp;
}
void Node::setLeft(Node* temp)
{
	left = temp;
}
int Node::getNodeCounter()
{
	return counter;
}
void Node::setNodeData(string temp)
{
	data = temp;
}
void Node::updateNodeCounter()
{
	counter = 1 + counter;
}
void Node::decrementNodeCounter()
{
	counter = counter - 1;
}
int Node::getHeight()
{
	return height;
}
void Node::updateHeight()
{
	height = height + 1;
}
Node::~Node()
{
}

