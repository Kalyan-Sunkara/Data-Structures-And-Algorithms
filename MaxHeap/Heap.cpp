#include "Heap.h"
#include <iostream>

using namespace std;


Heap::Heap()
{
	
	numItems = 0;
}

void Heap::trickleDown(int num1)
{
	while((arr[2*num1+1] != nullptr && arr[2*num1+2] != nullptr) && (2*num1+2) < numItems)
	{
		if(arr[2*num1+1]->getPriority() > arr[2*num1+2]->getPriority())
		{
			arr[num1] = arr[2*num1+1];
			if((2*num1+1) < numItems)
			{
				num1 = 2*num1+1;
			}
		}
		else
		{
			arr[num1] = arr[2*num1+2];
			if((2*num1+2) < numItems)
			{
				num1 = 2*num1+2;
			}
		}
	}
	if(arr[2*num1+1] == nullptr && arr[2*num1+2] != nullptr)
	{
		arr[num1] = arr[2*num1+2];
		arr[2*num1+2] = nullptr;
		numItems--;
	}
	else if(arr[2*num1+1] != nullptr && arr[2*num1+2] == nullptr)
	{
		arr[num1] = arr[2*num1+1];
		arr[2*num1+1] = nullptr;
		numItems--;
	}
	else
	{
		arr[num1] = arr[numItems-1];
//		arr[numItems-1] = nullptr;
//		delete arr[num1];
//		arr[num1] = arr[numItems-1];
//		delete arr[numItems-1];
		numItems--;
	}
}
void Heap::dequeue()
{
	if(numItems == 1)
	{
		numItems--;
		arr[0] = nullptr;
		return;
	}
	else
	{
		trickleDown(0);
	}
}

//void Heap::printList()
//{
//	for(unsigned i = 0; i < numItems; i++)
//	{
//		cout << "Index " << i << ": ";
//		cout << arr[i]->getPriority() << endl;
//	}
//}
void Heap::enqueue(PrintJob* g)
{
	if(numItems == 0)
	{
		arr[0] = g;
		numItems++;
		return;
	}
	int nodeIndex = 0;
	PrintJob* temp1 = arr[0];
//	unsigned i = 0;
	while(temp1 != nullptr && nodeIndex < numItems)
	{
//		cout << "Priority: " << arr[nodeIndex]->getPriority() << endl;
		nodeIndex++;
		temp1 = arr[nodeIndex];
//
	}
//	nodeIndex = i;
	arr[nodeIndex] = g;
//	cout << "NodeIndex: " << nodeIndex << endl;
//	int nodeIndex = numItems;
	while(arr[(nodeIndex-1)/2]->getPriority() < arr[nodeIndex]->getPriority() && nodeIndex > 0)
	{
//		cout << "Enter while loop" << endl;
		PrintJob* temp;
		temp = arr[(nodeIndex-1)/2];
		arr[(nodeIndex-1)/2] = arr[nodeIndex];
		arr[nodeIndex] = temp;
		if((nodeIndex-1)/2 > 0)
		{
			nodeIndex = (nodeIndex-1)/2;
		}
	}
	numItems++;
}

PrintJob* Heap::highest()
{
	return arr[0];
}

void Heap::print()
{
	PrintJob* temp = highest();
	cout << "Priority: " << temp->getPriority() << ", Job Number: " << temp->getJobNumber() << ", Number of Pages: " << temp->getPages() << endl;
}


