#include <iostream>
#include <string>
#include "IntList.h"

using namespace std;

int main()
{
	IntList list1;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	list1.push_front(5);
	list1.push_back(20);
	cout << list1;
	list1.pop_front();
	cout << endl;
	cout << list1;
	list1.pop_back();
	list1.pop_back();
	list1.pop_back();
//	list1.pop_front();
	list1.pop_back();
	list1.pop_front();
	cout << endl;
	cout  << list1;
	cout << endl;
	cout << "........" << endl;
	list1.push_back(100);
	cout << list1;
	cout << endl;
	list1.push_front(1);
	list1.push_front(2);
	list1.push_front(3);
	list1.push_front(4);
	list1.push_front(5);
	list1.push_back(20);
	list1.printReverse();
	return 0;
}
