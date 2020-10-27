#include <iostream>
#include <string>

using namespace std;

#include "Playlist.h"

PlaylistNode::PlaylistNode()
{
	uniqueID  = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) :
	uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr)
	{}
	
PlaylistNode::~PlaylistNode()
{
}

string PlaylistNode::GetID()
{
	return this->uniqueID;
}

string PlaylistNode::GetSongName()
{
	return this->songName;
}

string PlaylistNode::GetArtistName()
{
	return this->artistName;
}

int PlaylistNode::GetSongLength()
{
	return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
	return this->nextNodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* newNode)
{
	this->nextNodePtr = newNode;
}

void PlaylistNode::InsertAfter(PlaylistNode* &newNode)
{
	PlaylistNode* tmpNext = newNode->GetNext();
	newNode->SetNext(this);
	this->nextNodePtr  =  tmpNext;
	//PlaylistNode* tmpNext = nullptr;
   
   //tmpNext = this->nextNodePtr;    
   //this->nextNodePtr = newNode;    
   //newNode->nextNodePtr = tmpNext;
}

void PlaylistNode::PrintPlaylistNode()
{
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl; 
	cout << "Song Length (in seconds): " << songLength << endl;
}

