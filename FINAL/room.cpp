#include "room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room(string n, string desc, string itemDesc, string itemDesc2, string desc2, string alternateDesc)
{
	name = n;
	Desc = desc;
	item = itemDesc;
	item2 = itemDesc2;
	Desc2 = desc2;
	altDesc = alternateDesc;
}

void Room::pRoomName()
{
	cout << name << endl;
}

void Room::pRoomDesc()
{
	cout << Desc << endl;
}

void Room::pRoomItem()
{
	cout << item << endl;
}

void Room::pRoomItem2()
{
	cout << item2 << endl;
}

void Room::pRoomDesc2()
{
	cout << Desc2 << endl;
}

void Room::pRoomAltDesc()
{
	cout << altDesc << endl;
}