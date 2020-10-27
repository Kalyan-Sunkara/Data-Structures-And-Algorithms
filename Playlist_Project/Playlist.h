#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>

using namespace std;

class PlaylistNode
{
public:
	PlaylistNode();
	PlaylistNode(string, string, string, int);
	~PlaylistNode();
	void InsertAfter(PlaylistNode* &);
	void SetNext(PlaylistNode*);
	string GetID();
	string GetSongName();
	string GetArtistName();
	int GetSongLength();
	PlaylistNode* GetNext();
	void PrintPlaylistNode();
private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;
	
};

#endif // PLAYLIST_H
