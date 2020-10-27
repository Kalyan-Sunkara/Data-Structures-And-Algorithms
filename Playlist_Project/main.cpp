#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

void PrintMenu(string &);
void AddSong(string &, string &, string &, int &, PlaylistNode* &, PlaylistNode* &);
void outputSpecifcArtist(string &, PlaylistNode* &);
void changePosition(int, int, PlaylistNode* &, PlaylistNode* &);
int main()
{
	string playlistTitle = "";
	cout << "Enter playlist's title:" << endl;
	getline(cin, playlistTitle);
	cout << endl;
	PrintMenu(playlistTitle);
	return 0;
}

void AddSong(string &id, string &song, string &artist, int &length, PlaylistNode* &begin, PlaylistNode* &end)
{
	PlaylistNode *newNode = new PlaylistNode(id, song, artist, length);
    if(begin == nullptr)
    {
    begin = newNode;
    end = newNode;   
    }
    else
    {
//		newNode->InsertAfter(end);
//		newNode->SetNext(nullptr);
        end->SetNext(newNode);
        end = newNode;
    }
}

void outputSpecifcArtist(string &artist, PlaylistNode* &begin)
{
	if(begin == nullptr)
			{
				cout << "Playlist is empty" << endl;
			}
		else
			{
			int counter = 1;
			PlaylistNode* currNode = begin;
			while(currNode != nullptr)
			{
				if(currNode->GetArtistName() == artist)
					{
					cout << counter << "." << endl;
					currNode->PrintPlaylistNode();
					cout << endl;
					}
				currNode = currNode->GetNext();
				counter++;
			}
			cout << endl;
		}
	}
void changePosition(int originalPosition, int newPosition, PlaylistNode* &begin, PlaylistNode* &end)
{
	if(begin == nullptr){
         cout << "Playlist is empty" << endl;
       }
	else
	{
		int counter = 1; // used to find where the current node is
		int counter1 = 1;
		PlaylistNode* currNode = begin;
		PlaylistNode* newNode = begin;
		while(counter != originalPosition && currNode->GetNext()->GetNext() != nullptr) // finds node before the one we are looking for
		{
			if(counter+1 == originalPosition)
			{
				counter++;
			}
			else
			{
			currNode = currNode->GetNext();
			counter++;
			}
		}
//		cout << "counter: " << counter;
//		cout << endl;
//		currNode->PrintPlaylistNode();
//		cout << endl;
		while(counter1 != newPosition && newNode->GetNext()->GetNext() != nullptr && newPosition > 0) // finds where u want to put the node
		{
			if(counter1+1 == newPosition)
			{
				counter1++;
			}
			else
			{
				newNode = newNode->GetNext();
				counter1++;
			}
		}
//		cout << "counter1: " << counter1;
//		cout << endl;
//		newNode->PrintPlaylistNode();
//		cout << endl;
		if(counter == 1 && counter1 > 1) //if trying to move head, makes sure counter1 is not the same
		{
		PlaylistNode* temp = begin;
		PlaylistNode* temp2 = newNode->GetNext()->GetNext();
		begin = begin->GetNext();
		newNode->GetNext()->SetNext(temp);
		temp->SetNext(temp2);
		cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << 		counter1 << endl;
		}
		else if(newPosition <= 1 && counter != 1) //if trying to move node to the head
		{
			PlaylistNode* temp = currNode->GetNext();
			PlaylistNode* temp2 = begin;
//			if(currNode->GetNext() != end)
//			{
			currNode->SetNext(currNode->GetNext()->GetNext());
//			}
//			else
//			{
//				end = currNode;
//			}
			begin = temp;
			begin->SetNext(temp2);
			cout << "\"" << temp->GetSongName() << "\"" << " moved to position 1" << endl;
		}
		else if(newNode->GetNext()->GetNext() == nullptr) // moving to tail
		{
			end = newNode->GetNext();
			PlaylistNode* temp = currNode->GetNext();
			currNode->SetNext(currNode->GetNext()->GetNext());
			end->SetNext(temp);
			temp->SetNext(nullptr);
			cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << counter1 << endl;
		}
		else if(currNode->GetNext()->GetNext() == nullptr) //if moving the tail
		{
			PlaylistNode* temp = currNode->GetNext();
			PlaylistNode* temp2 = newNode->GetNext();
			currNode->SetNext(currNode->GetNext()->GetNext());
			newNode->SetNext(temp);
			temp->SetNext(temp2);
			cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << counter1 << endl;
		}
		else if(counter < counter1)//moving up the list
		{
			PlaylistNode* temp = currNode->GetNext();
			PlaylistNode* temp2 = newNode->GetNext();
			currNode->SetNext(currNode->GetNext()->GetNext());
			temp->InsertAfter(temp2);
			cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << counter1 << endl;
		}
		else if(counter > counter1)//moving down the list
		{
			PlaylistNode* temp = currNode->GetNext();
			currNode->SetNext(currNode->GetNext()->GetNext());
			temp->InsertAfter(newNode);
			cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << counter1 << endl;
		}
		else //if the old position and new position are the same
		{
			cout <<  endl;
			cout << "NO CHANGE" <<  endl;
			cout << endl;
		}
	}
}
void PrintMenu(string &playlistTitle)
{
	PlaylistNode* head = nullptr;
	PlaylistNode* tail = nullptr;
	 char selection;
    
    do {
        // Display menu
		cout << playlistTitle << " PLAYLIST MENU";
        cout << "\na - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)"<< endl;
		 cout <<  "o - Output full playlist" << endl;
        cout << "q - Quit" << endl;
        cout << "\nChoose an option:" << endl;
        cin >> selection;

        
        if (selection == 'a' || selection == 'A') {
			string id1 = "";
			string songName = "";
			string artistName = "";
			int length = 0;
			cout << "ADD SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin.ignore();
			getline(cin, id1);
			cout << "Enter song's name:" << endl;
			getline(cin,songName);
			cout << "Enter artist's name:" << endl;
			getline(cin,artistName);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> length;
			AddSong(id1, songName, artistName, length, head, tail);
			cout << endl;
            
        } else if (selection == 'd' || selection == 'D') {
			string id2 = "";
			PlaylistNode* currNode2 = head;
			int counter = 0;
			int counter1 = 0; //special counter for size of 2 case
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			cin.ignore();
			getline(cin,id2);
			while(counter == 0)
			{
				if(head->GetID() == id2)
				{
					counter++;
				}
				else if(currNode2->GetNext()->GetID() == id2)
				{
					counter++;
					if(currNode2 == head)
					{
						counter1++;
					}
				}
				else
				{
					currNode2 = currNode2->GetNext();
				}
			}
			if(currNode2 == head && counter1 == 0)
			{
				PlaylistNode* remove = head;
				head = head->GetNext();
				cout << endl;
				cout << "\"" << remove->GetSongName() << "\"" << " removed";
				cout << endl;
				delete remove;
			}
			else
			{
			PlaylistNode* remove = currNode2->GetNext();
			currNode2->SetNext(currNode2->GetNext()->GetNext());
			if(remove == tail)
			{
				tail = currNode2;
			}
			cout << "\"" << remove->GetSongName() << "\"" << " removed." << endl;
			cout << endl;
			delete remove;
			}
		   //if u delete last then u cannot add a new one
        } else if (selection == 'c' || selection == 'C') {
			int original = 0;
			int newP = 0;
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;
			cin >> original;
			cout << "Enter new position for song:" << endl;
			cin >> newP;
            changePosition(original, newP, head, tail);
			cout << endl;
			
        } else if (selection == 'S' || selection == 's') {
			string artist1;
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
			cout << "Enter artist's name:";
			cin.ignore();
			getline(cin, artist1);
			outputSpecifcArtist(artist1, head);
			
			
        } else if (selection == 't' || selection == 'T') {
			//Made by Adrian Ramos
            if(head == 0){
 
         cout << "Playlist is empty" << endl;
       }
 
       else{
 
         int total = 0;
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)";
         PlaylistNode* currNode1 = head;
 
         while(currNode1 != 0){
 
           total = total + currNode1->GetSongLength();
           currNode1 = currNode1->GetNext();
         }
 	cout << endl;
         cout << "Total time: " << total << " seconds" << endl;
	cout << endl;
       }
			
    } 
	else if (selection == 'o' || selection == 'O') {
			if(head == nullptr)
			{
			cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
				cout << "Playlist is empty" << endl;
				cout << endl;
			}
			else
			{
			int counter = 1;
			cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
			PlaylistNode* currNode = head;
			while(currNode != nullptr)
			{
				cout << counter << "." << endl;
				currNode->PrintPlaylistNode();
				cout << endl;
				currNode = currNode->GetNext();
				counter++;
			}
		}
		//cout << endl;
	}
	}while (selection != 'q' && selection != 'Q');
}
