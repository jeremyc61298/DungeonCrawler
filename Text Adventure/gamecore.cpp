//ncurese library still needs to be added to optimize printMap
//possibly pdcurses? ncurses may not exist on windows

/* gamecore.cpp */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Character.h"
#include <Windows.h>
#include <map>
#include "MapControl.h"

using std::cout;
using std::cin;
using std::endl;


void main()
{
	ifstream maps("maps.txt");
	Character *player;
	string name;
	int selection;
	

	// For the new MapControl Class
	MapControl Dungeon;

	cout << "Please enter your name traveler: ";
	cin >> name; 
	cout << "What is your profession? " << endl;
	cout << "1.) Warrior" << endl << "2.) Mage" << endl << "3.) Rogue" << endl << "4.) Barren" << endl;
	cout << "Selection: ";
	cin >> selection;

	while (selection != 1 && selection != 2 && selection != 3 && selection != 4)
	{
		cout << "Please pick something you see here dingus. " << endl; 
		cout << "What is your profession? " << endl << "Selection: ";
		cout << "1.) Warrior" << endl << "2.) Mage" << endl << "3.) Rogue" << endl << "4.) Barren" << endl;
		cin >> selection;
	}

	switch (selection)
	{
	case 1:
		player = new Character(1, name);
		break;
	case 2:
		player = new Character(2, name);
		break;
	case 3:
		player = new Character(3, name);
		break;
	case 4:
		player = new Character(4, name);
			break;
	default:
		player = new Character(4, name);
	}
	
	Dungeon.initializeDungeon();

		while (true)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				Dungeon.updatePlayerPosition("up");
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				Dungeon.updatePlayerPosition("down");
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				Dungeon.updatePlayerPosition("left");
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				Dungeon.updatePlayerPosition("right");
			}
		}
}