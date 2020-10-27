#include "WordLadder.h"
#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <stdexcept>
#include "stdlib.h"

using namespace std;

WordLadder::WordLadder(const string &fileName)
{
	ifstream inFS;
	inFS.open(fileName);
	if(!inFS.is_open())
		{
			exit(1);
		}
	else
	{
		string words = "";
		while(getline(inFS,words))
		{
			if(words.size() != 5)
			{
				exit(1);
			}
			dict.push_back(words);
		}
	}
//	for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it)
//	{
//		cout << *it << endl;
//	}
	inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{
	int counter1 = 0;
	ofstream outFS;
		outFS.open(outputFile);
		if(!outFS.is_open())
			{
				exit(1);
			}
	for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it)
	{
		if(start == *it || end == *it)
		{
			counter1++;
		}
	}
	if(counter1 == 0) //checks if words are in the dictionary
	{
		return;
	}
	int counter = 0;
	queue<stack<string> > q1;
	stack<string> s1;
	s1.push(start);
	q1.push(s1);
	if(start == end)
	{
		outFS << q1.front().top() << endl;
		return;
	}
	while(!(q1.empty())) //while queue is not empty
	{
		string topWord = q1.front().top();
		
			for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it) //iterates through words in dictionary
			{
				if(checkWords(topWord, *it)) //function tells if the words are off by one letter
					{
						stack<string> s2 = q1.front(); //copies over elements from other stack
						s2.push(*it); //pushes the matched word into the stack
////					cout << s2.top() << endl;
						if(*it == end)
							{
								counter++;
								q1.push(s2);
								break;
							}
						q1.push(s2); //adds the new stack to the queue
						dict.erase(it);
						it--;
					}
				}
			if(counter > 0)
				{
					break;
				}
			q1.pop();
		}
		if(counter == 0)
			{
				outFS << "No Word Ladder Found." << endl;
			}
			else
			{
				stack <string>s3;
				while(!q1.back().empty())
				{
				s3.push(q1.back().top());
				q1.back().pop();
				}
				while(!s3.empty())
				{
					outFS << s3.top() << endl;
					s3.pop();
				}
//				cout << "Updated dictionary!" << endl;
//					for(list<string>::iterator it = dict.begin(); it != dict.end(); ++it)
//						{
//						cout << *it << endl;
//						}
			}
			outFS.close();
	}
//	cout << q1.front().top() << endl;
//	create a Stack containing just the first word in the ladder
//	enqueue this Stack on to a Queue of Stacks
//	while this Queue of Stacks is not empty
//		get the word on top of the front Stack of this Queue
//		for each word in the dictionary
//			if the word is off by just one letter from the top word
//			create a new Stack that is a copy of the front Stack and push on this off-by-one word found
//			if this off-by-one word is the end word of the ladder, this new Stack contains the entire word ladder. You are done!
//			otherwise, enqueue this new Stack and remove this word from the dictionary
//		dequeue this front stack
//if the Queue is empty and you didn't find the word ladder, a word ladder does not exist for these 2 words



bool WordLadder::checkWords(const string &word1, const string &word2)
{
	unsigned counter = 0; 
	for(unsigned i = 0; i < word1.size(); i++)
	{
		if(word1.at(i) != word2.at(i))
		{
			counter++;
		}
	}
	if(counter == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}