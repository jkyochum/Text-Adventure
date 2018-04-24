#include <iostream>
#include <string>
#include "map.h"
#include "player.h"

using namespace std;

int main()
{
	string talk;

	bool tables = false;
	bool ready = false;

	//item1s
	bool money = false;
	bool katana = false;
	bool flashlight = false;
	bool chain = false;
	bool gun = false;
	bool foodWater = false;
	bool chxfilaKEY = false;
	bool fire = false;
	bool bag = false;
	//item2s
	bool carKEY = false;
	bool chainKEY = false;
	bool note = false;
	//do-or-die
	bool killed = false;
	bool vend = false;
	bool cutWeb = false;

	cout << "WELCOME TO THE NEW WORLD." << endl;
	cout << "You have landed in a survival story with mild violence and gore." << endl << "If you are faint-hearted then type 'quit' any time you have had enough." << endl << "If you don't remember where you are just 'look around'." << endl << "If you want something just 'take' it." << endl << "Enjoy your journey through my mind." << endl << endl;

	Map map;

	Player* player = new Player();

	player->pLoc = map.pStart;

	do
	{
		string room = player->pLoc->name;
		cout << "What do you want to do? ";
		getline(cin, talk);
		//LOOK AROUND--------------------------------
		if (talk == "look around" || talk == "look")
		{
			if (room == "UNDERGROUND ENTRANCE" && flashlight == true)
			{
				cout << endl;
				player->pLoc->pRoomDesc2();
				cout << endl << endl;
			}
			else if (room == "FOOD COURT" && tables == true)
			{
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl;
			}
			else if (room == "CHICKEN RESTAURANT" && foodWater == true)
			{
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl;
			}
			else if (room == "CANDY STORE" && vend == true)
			{
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl;
			}
			else if (room == "SECRET ROOM")
			{
				if (flashlight == true)
				{
					if (player->pLoc->haveItem == true)
					{
						cout << endl;
						player->pLoc->pRoomAltDesc();
						cout << endl << endl;
					}
					else
					{
						cout << endl;
						player->pLoc->pRoomAltDesc();
						player->pLoc->pRoomItem();
						cout << endl << endl;
					}
				}
				else
				{
					cout << "\nIt's too dark to see.\n\n";
				}
			}
			else if (room == "SHOE STORE" && killed == true)
			{
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl;
			}
			else if (room == "DEPARTMENT STORE" && fire == true)
			{
				cout << "\nThe whole room is on fire. Get out!\n\n";
			}
			else
			{
				cout << endl;
				player->pLoc->pRoomDesc();
				if (player->pLoc->haveItem == false)
					player->pLoc->pRoomItem();
				if (player->pLoc->haveItem2 == false)
					player->pLoc->pRoomItem2();
				cout << endl << endl;
			}


		}
		//NORTH-----------------------------------
		else if (talk == "north" || talk == "go north")
		{
			if (room == "UNDERGROUND ENTRANCE" && flashlight == false)
			{
				cout << "\nYou walk straight into something sharp and impale yourself. GAME OVER\n\n";
				break;
			}

			else if (room == "FOOD COURT")
			{
				if (tables == false)
				{
					cout << "\nThere is a pile of tables and chairs in front of you.\n\n";
					cout << endl;
					player->pLoc->pRoomDesc2();
					cout << endl << endl;
				}
				else
					cout << "\nThe hole is covered by tables and chairs.\n\n";
			}
			else if (room == "CANDY STORE" && vend == false)
			{
				cout << "\nLock the gate!\n\n";
			}
			else if (room == "CENTER OF MALL" && vend == true)
			{
				player->pLoc = player->pLoc->pNorth;
				cout << endl << endl;
				player->pLoc->pRoomName();
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl << endl;
			}
			else if (room == "JEWELRY STORE")
			{
				player->pLoc = player->pLoc->pNorth;
				if (flashlight == true)
				{
					if (chxfilaKEY == false)
					{
						cout << endl << endl;
						player->pLoc->pRoomAltDesc();
						player->pLoc->pRoomItem();
						cout << endl << endl << endl;
					}
					else
					{
						cout << endl << endl;
						player->pLoc->pRoomAltDesc();
						cout << endl << endl;
					}
				}
				else
				{
					cout << endl;
					player->pLoc->pRoomDesc();
					cout << endl << endl;
				}
			}
			else if (player->pLoc->pNorth == 0)
			{
				cout << "\nI didn't say you could go that direction.\n\n";
			}
			else if (room == "SHOE STORE")
			{
				if (gun == false)
				{
					cout << "\nIt's too late to turn back. They saw you and you didn't have a gun... GAME OVER.\n\n";
					break;
				}
				else
				{
					if (killed == false)
						cout << "\nWhat are you doing? You have to kill them.\n\n";
					else
					{
						player->pLoc = player->pLoc->pNorth;
						cout << endl;
						player->pLoc->pRoomName();
						cout << endl << endl;
					}
				}
			}
			else
			{
				player->pLoc = player->pLoc->pNorth;
				cout << endl << endl << endl << endl;
				player->pLoc->pRoomName();
				cout << endl;
				if (room == "PARKING LOT" && tables == true)
				{
					cout << endl;
					player->pLoc->pRoomAltDesc();
					cout << endl << endl;
				}
				else
				{
					cout << endl;
					player->pLoc->pRoomDesc();
					cout << endl << endl;
				}
				if (player->pLoc->haveItem == false)
					player->pLoc->pRoomItem();
				if (player->pLoc->haveItem2 == false)
					player->pLoc->pRoomItem2();
				cout << endl << endl;
			}
		}
		//SOUTH---------------------------------------
		else if (talk == "south" || talk == "go south")
		{
			if (player->pLoc->pSouth == 0)
			{
				cout << "\nYou have to choose an actual path.\n\n";
			}
			else if (room == "UNDERGROUND CAVERN")
			{
				if (flashlight == true)
				{
					player->pLoc = map.pFallInHole;
					cout << endl;
					player->pLoc->pRoomAltDesc();
					cout << endl << endl;
				}
			}
			else if (room == "CANDY STORE" && vend == false)
			{
				cout << "\nYou have to lock the gate!\n\n";
			}
			else if (room == "CENTER OF MALL" && killed == true)
			{
				player->pLoc = player->pLoc->pSouth;
				cout << endl;
				player->pLoc->pRoomAltDesc();
				cout << endl << endl;
			}
			else
			{
				player->pLoc = player->pLoc->pSouth;
				cout << endl << endl << endl << endl;
				player->pLoc->pRoomName();
				cout << endl;
				player->pLoc->pRoomDesc();
				if (player->pLoc->haveItem == false)
					player->pLoc->pRoomItem();
				if (player->pLoc->haveItem2 == false)
					player->pLoc->pRoomItem2();
				cout << endl << endl;
			}
		}
		//EAST----------------------------------------
		else if (talk == "east" || talk == "go east")
		{
			if (room == "FOOD COURT")
			{
				if (chxfilaKEY == false)
				{
					cout << "\nYou need a key to get in.\n\n";
				}
				else
				{
					player->pLoc = map.pChx;
					cout << endl;
					player->pLoc->pRoomAltDesc();
					if (foodWater == false)
					{
						cout << endl;
						player->pLoc->pRoomItem();
						cout << endl << endl;
					}
					cout << endl << endl;
				}
			}
			else if (room == "EAST OF MALL")
			{
				if (tables == true)
				{
					cout << "\nThe tables are covering the hole.\n\n";
				}
				else
				{
					if (flashlight == true)
					{
						cout << "\nYou have fallen into a large hole in the ground.\n\n";
						player->pLoc = map.pFallInHole;
						cout << endl;
						player->pLoc->pRoomAltDesc();
						cout << endl << endl;
					}
					else
					{
						player->pLoc = map.pFallInHole;
						player->pLoc->pRoomDesc();
					}
				}
			}
			else if (room == "SPIDER'S DEN")
			{
				if (katana == false)
				{
					cout << "\nYou have no way to cut through the web. The spiders overwhelm you and string you up in web. GAME OVER.\n\n";
					break;
				}
				else
				{
					cout << "\nYou need to cut through the web!\n\n";
				}
			}
			else if (room == "DEPARTMENT STORE" && fire == true)
			{
				cout << "\nYou don't want to go that way. Get out of the mall!\n\n";
			}
			else if (player->pLoc->pEast == 0)
				cout << "\nYou can't go there!\n\n";
			else
			{
				player->pLoc = player->pLoc->pEast;
				cout << endl << endl << endl << endl;
				player->pLoc->pRoomName();
				cout << endl;
				if (tables == true)
					player->pLoc->pRoomAltDesc();
				else
					player->pLoc->pRoomDesc();
				if (player->pLoc->haveItem == false)
					player->pLoc->pRoomItem();
				if (player->pLoc->haveItem2 == false)
					player->pLoc->pRoomItem2();
				cout << endl << endl;
			}
		}
		//WEST-------------------------------------------
		else if (talk == "west" || talk == "go west")
		{
			if (player->pLoc->pWest == 0 && talk == "west")
			{
				cout << "\nWhy would you go that way?\n\n";
			}
			else if (room == "DEPARTMENT STORE" && fire == false)
			{
				cout << "\nYou have unfinished business in the mall. Maybe you should check out everything in this room first.\n\n\n";
			}
			else
			{
				player->pLoc = player->pLoc->pWest;
				cout << endl << endl << endl << endl;
				player->pLoc->pRoomName();
				cout << endl;
				if (room == "CHICKEN RESTAURANT" && tables == true)
					player->pLoc->pRoomAltDesc();
				else
					player->pLoc->pRoomDesc();
				if (player->pLoc->haveItem == false)
					player->pLoc->pRoomItem();
				if (player->pLoc->haveItem2 == false)
					player->pLoc->pRoomItem2();
				cout << endl << endl;
			}
		}
		//QUIT-----------------------------------------
		else if (talk == "quit")
		{
			cout << "\nI guess you've had enough...\n\n\n";
		}
		//TAKE------------------------------------------
		else if (talk == "take")
		{
			if (room == "PARKING LOT")
			{
				if (money == false)
				{
					money = true;
					player->pLoc->haveItem = true;
					cout << "\nYou took the money.\n\n";
				}
				else
					cout << "\nYou already have the money.\n\n";

			}
			else if (room == "CHICKEN RESTAURANT")
			{
				if (foodWater == false)
				{
					cout << "\nYou took the food and water.\n\n";
					player->pLoc->haveItem = true;
					foodWater = true;
				}
				else
					cout << "\nYou already have the food and water.\n\n";

			}
			else if (room == "FOOD COURT WITH CHINESE RESTAURANT")
			{
				if (katana == false)
				{
					katana = true;
					player->pLoc->haveItem = true;
					cout << "\nYou took the katana.\n\n";
				}
				else
					cout << "\nYou already have the katana.\n\n";

			}
			else if (room == "FOOD COURT WITH SUB SHOP")
			{
				cout << "Take what? ";
				getline(cin, talk);
				if (talk == "flashlight")
				{
					if (flashlight == false)
					{
						flashlight = true;
						player->pLoc->haveItem = true;
						cout << "You took the flashlight.\n\n";
					}
					else
						cout << "\nYou already have the flashlight.\n\n";

				}
				else if (talk == "car keys" || talk == "keys")
				{
					if (carKEY == false)
					{
						carKEY = true;
						player->pLoc->haveItem2 = true;
						cout << "You took the car keys.\n\n";
					}
					else
						cout << "\nYou already have the keys.\n\n";
				}
				else
					cout << "That's not an option.\n\n";
			}
			else if (room == "WOMEN'S RESTROOM")
			{
				cout << "Take what? ";
				getline(cin, talk);
				if (talk == "bag" || talk == "the bag")
				{
					if (bag == false)
					{
						bag = true;
						gun = true;
						player->pLoc->haveItem = true;
						cout << "\nYou took the bag. You look in the bag and see a loaded revolver at the bottom.\n\n";
					}
					else
						cout << "\nYou already have the bag.\n\n";

				}
				else if (talk == "note" || talk == "the note")
				{
					if (note == false)
					{
						note = true;
						player->pLoc->haveItem2 = true;
						cout << "\nYou took the note.\n\n";

					}
					else
						cout << "\nYou already have the note.\n\n";
				}
				else
					cout << "That's not an option.\n\n";
			}
			else if (room == "MEN'S RESTROOM")
			{
				cout << "Take what? ";
				getline(cin, talk);
				if (talk == "key" || talk == "the key")
				{
					if (chainKEY == false)
					{
						chainKEY = true;
						player->pLoc->haveItem2 = true;
						cout << "\nYou took the key.\n\n";
					}
					else
						cout << "\nYou already have the key.\n\n";

				}
				else if (talk == "chain" || talk == "the chain")
				{
					if (chain == false)
					{
						if (chainKEY == true)
						{
							chain = true;
							player->pLoc->haveItem = true;
							cout << "\nYou took the chain.\n\n";
							player->pLoc->pRoomDesc2();
							cout << endl << endl;
						}
						else
							cout << "\nYou need a key for this...\n\n";

					}
					else
						cout << "\nYou already have the chain.\n\n";
				}
				else
					cout << "That's not an option.\n\n";
			}
			else if (room == "SECRET ROOM")
			{
				if (flashlight == false)
				{
					cout << "\nYou can't see anything.\n\n";
				}
				else
				{
					if (chxfilaKEY == false)
					{
						chxfilaKEY = true;
						player->pLoc->haveItem = true;
						cout << "\nYou took the key.\n\n";
					}
					else
						cout << "\nThere's nothng to take here.\n\n";
				}

			}

		}
		//CLIMB OVER------------------------------------
		else if (talk == "climb" || talk == "go over" || talk == "climb over")
		{
			if (room == "FOOD COURT")
			{
				if (tables == false)
				{
					cout << "\nYou climb up the stack of tables and chairs. As you get to the top the pile falls over and you fall into a large hole in the ground.\n\n";
					player->pLoc = map.pFallInHole;
					tables = true;
				}
				else
					cout << "\nThe tables are covering the hole.\n\n";

			}
			else
			{
				cout << "\nYou can't do that here.\n\n";
			}


		}
		else if (talk == "lock" || talk == "lock gate")
		{
			if (room == "CANDY STORE")
			{
				if (chain == true)
				{
					if (money == true)
					{
						if (vend == true)
						{
							cout << "\nYou don't need to do that anymore.\n\n";
						}
						else
						{
							cout << "\nYou have locked the gate.\n\n";
							player->pLoc->pRoomDesc2();
							cout << endl << endl;
							while (vend != true)
							{
								cout << "\nWhat will you do? ";
								getline(cin, talk);
								if (talk == "use vending machine" || talk == "vend" || talk == "vending machine")
								{
									cout << "\nYou are not going to starve and the monsters seem to have left. Congratulations.\n\n";
									vend = true;
									player->pLoc->pSouth->name = "CENTER OF MALL";
								}
								else
								{
									cout << endl;
									player->pLoc->pRoomDesc2();
									cout << endl << endl;
								}
							}

						}

					}
					else
					{
						cout << "\nYou have locked yourself in the store withouth any way of eating and you starved to death. GAME OVER.\n\n";
						break;
					}
				}
				else
				{
					cout << "\nYou closed the gate without any way of locking it and the monsters got in. You were eaten alive. GAME OVER.\n\n";
					break;
				}
			}
			else
			{
				cout << "\nYou can't do that here.\n\n";
			}
		}
		else if (talk == "talk" || talk == "go to girl" || talk == "talk to girl")
		{
			if (room == "SECRET ROOM")
			{
				if (flashlight == true)
				{
					cout << endl << endl;
					player->pLoc->pRoomDesc2();
					cout << endl << endl << endl;
				}
			}
			else
			{
				cout << "\nThere's nobody to talk to here.\n\n";
			}
		}
		else if (talk == "cut" || talk == "cut web" || talk == "cut through")
		{
			if (room == "SPIDER'S DEN")
			{
				if (katana == true)
				{
					player->pLoc = map.pUnderground;
					cout << endl;
					player->pLoc->pRoomName();
					cout << endl << endl << endl;
				}
				else
				{
					cout << "\nYou have nothing to cut the web with. You were taken by the spiders and nobody saw you again. GAME OVER.\n\n";
					break;
				}
			}
			else
			{
				cout << "\nYou can't do that here.\n\n";
			}
		}
		else if (talk == "shoot" || talk == "kill" || talk == "use gun")
		{
			if (room == "SHOE STORE")
			{
				if (killed == false)
				{
					if (gun == true)
					{
						killed = true;
						cout << endl;
						player->pLoc->pRoomDesc2();
						cout << endl << endl;
					}
					else
					{
						cout << "\nWhat are you going to shoot them with? You don't have a gun and they do. You died. GAME OVER.\n\n";
						break;
					}
				}
				else
				{
					cout << "\nYou already murdered everyone.\n\n";
				}

			}
			else
			{
				if (gun == true)
				{
					cout << "\nYou don't really want to shoot your gun here do you?\n\n";
				}
				else
				{
					cout << "\nYou don't have anything to shoot.\n\n";
				}
			}
		}
		else if (talk == "go to monsters" || talk == "go to zombies")
		{
			if (room == "DEPARTMENT STORE")
			{
				cout << "\nYou look at the horde of monsters behind the fence. Was this the same group you saw earlier?\n\n";
			}
			else
			{
				cout << "\nThat doesn't make sense.\n\n";
			}
		}
		else if (talk == "go to fire")
		{
			if (room == "DEPARTMENT STORE")
			{
				if (fire == false)
				{
					cout << "\nYou see a small fire burning. It looks new.\n\n";
					cout << "You should burn this place to the ground. But when you do there's no going back, you have to leave or you will burn with the mall.\n\n" << endl;
					if (foodWater == true)
					{
						if (carKEY == true)
						{
							ready = true;
						}
						else
						{
							cout << "\nYou need the car keys to proceed.\n\n";
						}
					}
					else
					{
						cout << "\nYou need the food and water to proceed.\n\n";
					}
				}
				else
				{
					cout << "\nThe mall is on fire. Get Out!\n\n";
				}
			}
			else
			{
				cout << "\nThere's no fire here...\n\n";
			}
		}
		else if (talk == "set fire" || talk == "burn" || talk == "burn mall" || talk == "fire")
		{
			if (room == "DEPARTMENT STORE")
			{
				if (fire == false)
				{
					if (ready == true)
					{
						fire = true;
						cout << endl;
						player->pLoc->pRoomDesc2();
						cout << endl << endl << endl;
					}
					else
					{
						cout << "\nYou aren't ready.\n\n";
					}
				}
				else
				{
					cout << "\nThe mall is already on fire. Get out!\n\n";
				}

			}
			else
			{
				cout << "\nNo.\n\n";
			}
		}
		else if (talk == "drive" || talk == "get in car" || talk == "drive car" || talk == "leave")
		{
			if (room == "PARKING LOT 2")
			{
				cout << endl;
				player->pLoc->pRoomDesc2();
				cout << endl << endl;
				cout << "\t\t\t\n\nCongratulations, you have just won the game and escaped the mall.\n\n\n\n";
				break;
			}
		}
		else if (talk == "read" || talk == "read note")
		{
			if (note == true)
			{
				cout << "\n'To anyone still alive take this bag and survive longer than I did.'\n\n";
			}
			else
			{
				cout << "\nYou don't have anything to read.\n\n";
			}
		}
		else
		{
			cout << "\nSay that again?\n\n\n";
		}
	} while (talk != "quit");






	system("pause");
	return 0;
}
