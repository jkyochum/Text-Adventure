#pragma once
#include <string>

using namespace std;

class Room
{
public:
	Room(string n, string desc, string itemDesc, string itemDesc2, string desc2, string alternateDesc);
	void pRoomName();
	void pRoomDesc();
	void pRoomItem();
	void pRoomItem2();
	void pRoomDesc2();
	void pRoomAltDesc();

	Room* pNorth;
	Room* pSouth;
	Room* pEast;
	Room* pWest;

	bool haveItem = false;
	bool haveItem2 = false;

	string name;
	string Desc;
	string item;
	string item2;
	string Desc2;
	string altDesc;

};
