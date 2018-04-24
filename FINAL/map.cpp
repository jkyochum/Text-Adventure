#include "map.h"
#include "room.h"
#include <iostream>

using namespace std;
Map::~Map()
{

}

Map::Map()
{
	Room* p1 = new Room("PARKING LOT", "You are in a parking lot SOUTH of an abandoned mall.", "You see trash and money blowing in the wind. 'The world is dead, why would anyone need money?'", "", "", "");
	pStart = p1;

	Room* p2 = new Room("FOOD COURT", "You are in a food court. Everything around you has been turned upside down. To the EAST there is a fast food chicken restaurant with a locked security gate around it. To the WEST there is another section of the food court. To the NORTH there is a large pile of tables and chairs but it looks like you can get over it.", "", "", "", "You are in a food court. To the EAST there is a fast food chicken restaurant. To the WEST there is another section of the food court.");

	Room* p3 = new Room("CHICKEN RESTAURANT", "You are standing in front of a chicken restaurant. The gate is shut tight and you need a key to get in, but you look through and you see food and water on one of the tables. To the WEST is the Food Court entrance.", "There is a supply of food and water on one of the tables inside.", "", "", "You are standing in front of a chicken restaurant. To the WEST is the Food Court entrance.");
	pChx = p3;
	//need key to open gate
	Room* p4 = new Room("FOOD COURT WITH CHINESE RESTAURANT", "You are in a section of the food court with a Chinese restaurant in it. To the WEST you see another area of the food court. To the EAST is the main food court entrance.", "You see a katana on a sword display behind the counter.", "", "", "");

	Room* p5 = new Room("FOOD COURT WITH SUB SHOP", "You are in the food court and there is a sub shop in front of you. To the WEST there is a door leading to an unknown location. To the EAST is the food court with Chinese restaurant. Behind the counter you see someone laying on the ground with a gash in their forehead.", "You see a flashlight strapped to their belt.", "You notice a set of car keys on their belt.", "", "");

	Room* p6 = new Room("HALLWAY", "You are standing in the middle of a hallway. To the NORTH is another doorway. To the SOUTH is a Women's restroom. To the WEST is a Men's restroom. To the EAST is the doorway to the food court.", "", "", "", "");

	Room* p7 = new Room("WOMEN'S RESTROOM", "You are in a rank smelling Women's restroom and there is a pile of bodies where the stalls used to be. The exit is to the NORTH.", "There is a bag under the sink.", "There is a note on the ground.", "", "");
	//read the note and describe the bag

	Room* p8 = new Room("MEN'S RESTROOM", "You are in a Men's restroom. The exit is to the EAST.", "The stall at the end looks to be chained shut.", "There is a key on the sink.", "You take the chain and open the door. On the other side of the door is a rotted corpse on the toilet. It has a large wound on it's head. You have never seen anything like this before.", "");
	//describe encounter with zombie and take chain


	Room* p9 = new Room("EAST OF MALL", "You are in the East portion of the mall. To the NORTH there is a jewelry store. To the WEST there is another section of the mall. To the EAST there is a large hole in the ground.", "", "", "", "");
	//the hole leads to the underground entrance which is another pointer described later

	Room* p10 = new Room("JEWELRY STORE", "You are in a jewelry store that has broken glass everywhere. There are blood stains on the ground leading to the counter on the other side of the store. To the NORTH it looks like there is a secret passageway behind the counter.", "", "", "", "");

	Room* p11 = new Room("SECRET ROOM", "It is too dark to see anything.", "There is a key in the far left corner.", "", "You notice the girl has a large wound on her bicep. It looks almost like someone took a bite out of her. She warns you of a large group of monsters roaming aroun the mall.", "You are crouched in a small room with the exit to the SOUTH. You see a girl in the far right corner of the room.");
	//describe the encounter with the girl

	Room* p12 = new Room("CENTER OF MALL", "You are in the Center of the Mall. There is a candy store to the NORTH. To the SOUTH there is a shoe store. To the WEST there is a department store.", "", "", "", "");

	Room* p13 = new Room("SHOE STORE", "You are in front of a shoe store. To the NORTH is the center of the mall. You hear screams and you see three people trying to kill each other. It would probably be a good idea to grab your gun.", "", "", "You killed all three before they could kill you.", "You are in front of a shoe store. To the NORTH is the center of the mall.");
	//describe the encounter and create another scenario where there is nobody in the store

	Room* p14 = new Room("CANDY STORE", "You are standing in front of an empty candy store. To the SOUTH is the center of the mall. You see a group of monsters coming right at you. Get inside and get away from the monsters!", "", "", "If you don't get food then you will perish. You see a vending machine in the back of the store. If you had money you could get some food.", "You are standing in front of an empty candy store. To the SOUTH is the center of the mall.");
	//go in store and lock the gate closed with the chain. Then get food from the vending machine

	Room* p15 = new Room("DEPARTMENT STORE", "You are in a department store. The center of the mall is to the EAST. To the WEST there is a boarded up exit with a small hole to get through. To the left you see a group of monsters behind a fence. To the right you see a small, controlled fire.", "", "", "The mall is now on fire. You should leave before you get hurt.", "");
	//describe the fenced monsters and ensure that you have all the items you need before leaving. Now set the mall on fire and leave before you die

	Room* p16 = new Room("PARKING LOT 2", "You make it out of the mall and you see a single car in the parking lot and an open fence at the end of the lot. ", "", "", "You go to the car and start it up. It is like someone was helping you the whole time. You drive the car away through the open fence and leave the mall behind for good.", "");
	//GAME OVER

	Room* p17 = new Room("UNDERGROUND ENTRANCE", "You are in a cold, dark area and you can't see anything.", "", "", "You are underground. You see wooden spikes coming out of the walls pointed toward you. To the NORTH you see a larger underground area.", "");
	pFallInHole = p17;

	Room* p18 = new Room("UNDERGROUND CAVERN", "You are in a large underground passageway. To the SOUTH is the underground entrance. To the WEST is a small hole in the wall to another room. To the NORTH is an even smaller tunnel.", "", "", "", "");
	pUnderground = p18;

	Room* p19 = new Room("SPIDER'S DEN", "You are in a large room filled with mutated spiders, each the size of a basketball. They drop down as soon as you enter and cover the exit which is to the EAST.", "", "", "", "");
	//describe the encounter with the spiders

	Room* p20 = new Room("CAVERN EXIT", "You are in a small tunnel and you notice an old ladder to the North. The underground passageway is to the South.", "", "", "", "");
	//leads to pStart

	p1->pNorth = p2;
	p1->pSouth = 0;
	p1->pEast = 0;
	p1->pWest = 0;
	//
	p2->pNorth = 0;
	p2->pSouth = p1;
	p2->pEast = 0;
	p2->pWest = p4;
	//
	p3->pNorth = 0;
	p3->pSouth = 0;
	p3->pEast = 0;
	p3->pWest = p2;
	//
	p4->pNorth = 0;
	p4->pSouth = 0;
	p4->pEast = p2;
	p4->pWest = p5;
	//
	p5->pNorth = 0;
	p5->pSouth = 0;
	p5->pEast = p4;
	p5->pWest = p6;
	//
	p6->pNorth = p9;
	p6->pSouth = p7;
	p6->pEast = p5;
	p6->pWest = p8;
	//
	p7->pNorth = p6;
	p7->pSouth = 0;
	p7->pEast = 0;
	p7->pWest = 0;
	//
	p8->pNorth = 0;
	p8->pSouth = 0;
	p8->pEast = p6;
	p8->pWest = 0;
	//
	p9->pNorth = p10;
	p9->pSouth = p6;
	p9->pEast = p17;
	p9->pWest = p12;
	//
	p10->pNorth = p11;
	p10->pSouth = p9;
	p10->pEast = 0;
	p10->pWest = 0;
	//
	p11->pNorth = 0;
	p11->pSouth = p10;
	p11->pEast = 0;
	p11->pWest = 0;
	//
	p12->pNorth = p14;
	p12->pSouth = p13;
	p12->pEast = p9;
	p12->pWest = p15;
	//
	p13->pNorth = p12;
	p13->pSouth = 0;
	p13->pEast = 0;
	p13->pWest = 0;
	//
	p14->pNorth = 0;
	p14->pSouth = p12;
	p14->pEast = 0;
	p14->pWest = 0;
	//
	p15->pNorth = 0;
	p15->pSouth = 0;
	p15->pEast = p12;
	p15->pWest = p16;
	//
	p16->pNorth = 0;
	p16->pSouth = 0;
	p16->pEast = 0;
	p16->pWest = 0;
	//
	p17->pNorth = p18;
	p17->pSouth = 0;
	p17->pEast = 0;
	p17->pWest = 0;
	//
	p18->pNorth = p20;
	p18->pSouth = p17;
	p18->pEast = 0;
	p18->pWest = p19;
	//
	p19->pNorth = 0;
	p19->pSouth = 0;
	p19->pEast = 0;
	p19->pWest = 0;
	//
	p20->pNorth = p1;
	p20->pSouth = p18;
	p20->pEast = 0;
	p20->pWest = 0;

}