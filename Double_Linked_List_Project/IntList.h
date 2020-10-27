#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <string>

using namespace std;

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(nullptr), next(nullptr) {}
};

class IntList
{
public:
	IntList();
	~IntList();
	void push_front(int);
	void pop_front();
	void push_back(int);
	void pop_back();
	bool empty() const;
	void printReverse() const;
	friend ostream & operator<<(ostream &, const IntList &);
private:
	IntNode* dummyHead;
	IntNode* dummyTail;
};

#endif // INTLIST_H
