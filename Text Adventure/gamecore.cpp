//ncurese library still needs to be added to optimize printMap



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Character.h"
#include <Windows.h>

using namespace std;

void buildMap(vector<vector<char>> &map, ifstream &maps, pair<int, int> &playerPos);



void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void clearMap(vector<vector<char>> &map)
{
	for (int i = 0; i < map.size(); i++)
	{
		map[i].clear();

	}
}

void printMap(vector<vector<char>> map)
{
	system("cls");
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			cout << map[i][j];

		}
		cout << endl;
	}
}

void updatePlayerPosition(vector<vector<char>> &map, string direction, pair<int, int> &playerPos)
{
	bool didMove = false;
	map[playerPos.first][playerPos.second] = ' ';
	if (direction == "up")
	{
		if (playerPos.first > 0)
		{
			if (map[playerPos.first - 1][playerPos.second] == ' ')
			{
				playerPos.first--;
			}
			else if (map[playerPos.first - 1][playerPos.second] == '|')
			{
				ifstream newMap("map2.txt");
				clearMap(map);
				buildMap(map, newMap, playerPos);
			}
			didMove = true;
		}
	}
	else if (direction == "down")
	{
		if (playerPos.first < map.size() - 1)
		{
			if (map[playerPos.first + 1][playerPos.second] == ' ')
			{
				playerPos.first++;
			}
			else if (map[playerPos.first + 1][playerPos.second] == '|')
			{
				//to new map
				ifstream newMap("map2.txt");
				clearMap(map);
				buildMap(map, newMap, playerPos);
			}
			didMove = true;
		}
	}
	else if (direction == "left")
	{
		if (playerPos.second > 0)
		{
			if (map[playerPos.first][playerPos.second - 1] == ' ')
			{
				playerPos.second--;
			}
			else if (map[playerPos.first][playerPos.second - 1] == '|')
			{
				//to new map
				ifstream newMap("map2.txt");
				clearMap(map);
				buildMap(map, newMap, playerPos);
			}
			didMove = true;
		}
	}
	else if (direction == "right")
	{
		if (playerPos.second < map[0].size() - 1)
		{
			if (map[playerPos.first][playerPos.second + 1] == ' ')
			{
				playerPos.second++;
			}
			else if (map[playerPos.first][playerPos.second + 1] == '|')
			{
				//to new map
				ifstream newMap("map2.txt");
				clearMap(map);
				buildMap(map, newMap, playerPos);
			}
			didMove = true;
		}
	}

	map[playerPos.first][playerPos.second] = '@';
	if (didMove == true)
	{
		printMap(map);
		cout << playerPos.first << " " << playerPos.second;
	}
}

void buildMap(vector<vector<char>> &map, ifstream &maps, pair<int, int> &playerPos)		//Uses a 2-d vector to create a 2-d map space in the console 
{
	string firststr;
	string secondstr;
	int first, second;
	char current = ' ';
	string line = ""; 
	vector<char> row;


	getline(maps, firststr);
	getline(maps, secondstr);

	first = stoi(firststr);
	second = stoi(secondstr);

	while (!maps.eof())
	{
		getline(maps, line);									//This retrievs the line of the map from the maps.txt file 
		for (int i = 0; i < line.length(); i++)
		{
			row.push_back(line[i]);
			
		}
		map.push_back(row); 
		row.clear();
	}

	playerPos.first = first;
	playerPos.second = second;
	map[playerPos.first][playerPos.second] = '@';


}



void main()
{
	ifstream maps("maps.txt"); 
	Character *player;
	string name;
	int selection;
	pair <int, int> playerPos;
	vector <vector<char>> map;

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
		player = new Character(1);
		break;
	case 2:
		player = new Character(2);
		break;
	case 3:
		player = new Character(3);
		break;
	case 4:
		player = new Character(4);
			break;
	default:
		player = new Character(4);

		
	}
	ShowConsoleCursor(false); 
	playerPos = pair <int, int>(1, 1);
	buildMap(map, maps, playerPos);
	printMap(map);


		while (true)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				updatePlayerPosition(map, "up", playerPos);
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				updatePlayerPosition(map, "down", playerPos);
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				updatePlayerPosition(map, "left", playerPos);
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				updatePlayerPosition(map, "right", playerPos);
			}
			Sleep(100);
		}

		

}