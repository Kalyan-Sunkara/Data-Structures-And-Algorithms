#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
	T min = vals.at(index);
	unsigned minLoc = index;
	for(unsigned i = index; i < vals.size(); i++)
	{
		if(vals.at(i) < min)
		{
			min = vals.at(i);
			minLoc = i;
		}
	}
//	cout << "Minimum: " << min << endl;
	return minLoc;
}


template<typename T>
void printVector(vector<T> &vals)
{
	for(unsigned i = 0; i < vals.size(); i++)
	{
		cout << vals.at(i) << " ";
	}
}

template<typename T>
void selection_sort(vector<T> &vals)
{
	unsigned minLoc = 0;
//	int minLoc = 0;
    if(vals.size() == 0)
    {
        
    }
    else
    {
			for(unsigned i = 0; i < vals.size(); i++)
			{
//		min = vals.at(i);
//		for(unsigned j = i; j < vals.size(); j++)
//		{
//			if(min > vals.at(j))
//			{
//				min = vals.at(j);
//				minLoc = j;
//			}
//		}
			minLoc = min_index(vals, i);
			if(vals.at(i) != vals.at(minLoc))
			{
			swap(vals.at(i), vals.at(minLoc));
			}
		}
	}
}

template<typename T>
T getElement(vector<T> vals, int index)
{
	return vals.at(index);
}

int main()
{
	vector<int> unsorted;
	unsorted.push_back(3);
	unsorted.push_back(2);
	unsorted.push_back(7);
	unsorted.push_back(12);
	unsorted.push_back(1);
	unsorted.push_back(10);
	//3 2 7 12 1 10
	printVector(unsorted);
	cout << endl;
	selection_sort(unsorted);
	//1 2 3 7 10 12
	printVector(unsorted);
	
	try
	{
		unsigned index1 = 0;
		cout << endl;
		cout << "enter index you want to find" << endl;
		cin >> index1;
		if(index1 >= unsorted.size() || index1 < 0)
		{
			throw out_of_range("out of range exception occurred");
		}
		cout << getElement(unsorted, index1);
		
	}
	catch(out_of_range &excpt)
	{
		cout << excpt.what() << endl;
	}
	
	return 0;
}
