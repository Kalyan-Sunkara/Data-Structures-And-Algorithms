#include <iostream>
#include <string>

#include "IntList.h"

using namespace std;

IntList::IntList()
{
	this->dummyHead = new IntNode(0);
    this->dummyTail = new IntNode(0);
}

IntList::~IntList()
{
	IntNode* tempList;
    while(dummyHead->next)
    {
        tempList = dummyHead->next;
        dummyHead->next = dummyHead->next->next;
        delete tempList;
    }
}

void IntList::push_front(int num)
{
	IntNode *newNode = new IntNode(num);
    if(this->dummyHead->next == nullptr)
    {
    this->dummyHead->next = newNode;
    this->dummyTail->prev = newNode; 
    }
    else
    {
//      newNode->next = this->head;
//      this->head = newNode;
		IntNode* temp = dummyHead->next;
		dummyHead->next = newNode;
		dummyHead->next->next =  temp;
		temp->prev = dummyHead->next;
    }
}
	void IntList::pop_front()
	{
		if(!empty())
		{
		IntNode* temp = dummyHead->next;
		dummyHead->next = dummyHead->next->next;
		delete temp;
		}
	}
	void IntList::push_back(int num)
	{
		IntNode *newNode = new IntNode(num);
		if(this->dummyHead->next == nullptr)
		{
		this->dummyHead->next = newNode;
		this->dummyTail->prev = newNode; 
		}
		else
		{
			IntNode* temp = dummyTail->prev;
			dummyTail->prev = newNode;
			dummyTail->prev->prev = temp;
			temp->next =  dummyTail->prev;
		}
	}
	void IntList::pop_back()
	{
		if(!empty())
		{
		if(dummyHead->next->next != nullptr && dummyHead->next != nullptr)
		{
		IntNode* temp = dummyTail->prev;
		
		dummyTail->prev = dummyTail->prev->prev;
		dummyTail->prev->next = nullptr;
		delete temp;
		}
		else
		{
			dummyHead->next = nullptr;
			dummyTail->prev = nullptr;
		}
		}
	}
	bool IntList::empty() const
	{
		if(this->dummyHead->next ==nullptr)
		{
        return true;
		}
		else
		{
        return false;
		}
	}
	void IntList::printReverse() const
	{
		IntNode *curNode  = this->dummyTail->prev;
		while(curNode != nullptr)
		{
			if(curNode->prev != nullptr)
			{
			cout << curNode->data << " ";
			}
			else
			{
            cout << curNode->data;
			}
        curNode = curNode->prev;
		}
	}
	ostream & operator<<(ostream &out, const IntList &list)
	{
		if(!list.empty())
		{
			IntNode *curNode = list.dummyHead->next;
//			curNode =  curNode->next;
			while(curNode != nullptr)
			{
				if(curNode->next != nullptr)
				{
					out << curNode->data << " ";
				}
				else
				{
				out << curNode->data;
				}
			curNode = curNode->next;
    }
    return out;
	}
	return out;
}
	
//	#include <iostream>
//#include <string>
//
//#include "IntList.h"
//
//using namespace std;
//
//IntList::IntList()
//{
//	this->dummyHead = nullptr;
//    this->dummyTail = nullptr;
//}
//
//IntList::~IntList()
//{
//	IntNode* tempList;
//    while(dummyHead)
//    {
//        tempList = dummyHead;
//        dummyHead = dummyHead-> next;
//        delete tempList;
//    }
//}
//
//void IntList::push_front(int num)
//{
//	IntNode *newNode = new IntNode(num);
//    if(this->dummyHead == nullptr)
//    {
//    this->dummyHead = newNode;
//    this->dummyTail = newNode; 
//    }
//    else
//    {
////      newNode->next = this->head;
////      this->head = newNode;
//		IntNode* temp = dummyHead;
//		dummyHead = newNode;
//		dummyHead->next =  temp;
//		temp->prev = dummyHead;
//    }
//}
//	void IntList::pop_front()
//	{
//		IntNode* temp = dummyHead;
//		dummyHead = dummyHead->next;
//		delete temp;
//	}
//	void IntList::push_back(int num)
//	{
//		IntNode *newNode = new IntNode(num);
//		if(this->dummyHead == nullptr)
//		{
//		this->dummyHead = newNode;
//		this->dummyTail = newNode; 
//		}
//		else
//		{
//			IntNode* temp = dummyTail;
//			dummyTail = newNode;
//			dummyTail->prev = temp;
//			temp->next =  dummyTail;
//		}
//	}
//	void IntList::pop_back()
//	{
//		if(dummyHead->next != nullptr && dummyHead != nullptr)
//		{
//		IntNode* temp = dummyTail;
//		
//		dummyTail = dummyTail->prev;
//		dummyTail->next = nullptr;
//		delete temp;
//		}
//		else
//		{
//			dummyHead = nullptr;
//			dummyTail = nullptr;
//		}
//	}
//	bool IntList::empty() const
//	{
//		if(this->dummyHead ==nullptr)
//		{
//        return true;
//		}
//		else
//		{
//        return false;
//		}
//	}
//	void IntList::printReverse() const
//	{
//		IntNode *curNode  = this->dummyTail;
//		while(curNode != nullptr)
//		{
//			if(curNode->prev != nullptr)
//			{
//			cout << curNode->data << " ";
//			}
//			else
//			{
//            cout << curNode->data;
//			}
//        curNode = curNode->prev;
//		}
//	}
//	ostream & operator<<(ostream &out, const IntList &list)
//	{
//		IntNode *curNode = list.dummyHead;
////		curNode =  curNode->next;
//    while(curNode != nullptr)
//    {
//        if(curNode->next != nullptr)
//        {
//        out << curNode->data << " ";
//        }
//        else
//        {
//            out << curNode->data;
//        }
//        curNode = curNode->next;
//    }
//    return out;
//	}