//ncurese library still needs to be added to optimize printMap
//possibly pdcurses? ncurses may not exist on windows



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Character.h"
#include <Windows.h>
#include<map>

using namespace std;



struct MapObject
{
	vector<vector<char>> mapVector;
	pair<int, int> playerStart;
	string name;
	map<pair<int, int>, string> roomList;
};

MapObject currentMap; 



void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void clearMap(vector<vector<char>> &mapVector)
{
	mapVector.resize(0);
}

void printMap(MapObject mapObject)
{
	system("cls");
	for (int i = 0; i < mapObject.mapVector.size(); i++)
	{
		for (int j = 0; j < mapObject.mapVector[i].size(); j++)
		{
			cout << mapObject.mapVector[i][j];

		}
		cout << endl;
	}
}

void buildMaps(ifstream &maps, map<string, MapObject> &masterMapsList)		//Uses a 2-d vector to create a 2-d map space in the console 
{
	vector<vector<char>> mapVector;
	string firststr;
	string secondstr;
	int first, second;
	pair<int, int> playerPos;
	char current = ' ';
	string line = "";
	string mapName;
	vector<char> row;
	MapObject tempMapObj;
	string roomName = "";
	

	while (!maps.eof())
	{
		getline(maps, mapName);		//read name of map
		getline(maps, firststr);
		getline(maps, secondstr);
		playerPos.first = stoi(firststr);
		playerPos.second = stoi(secondstr);
		getline(maps, line);									//This retrievs the line of the map from the maps.txt file 
		while (line != "`")
		{
			for (int i = 0; i < line.length(); i++)
			{
				row.push_back(line[i]);

			}
			mapVector.push_back(row);
			row.clear();
			getline(maps, line);
		}
		while (roomName != "~")
		{
			getline(maps, roomName);  //room name
			if (roomName != "~")
			{
				getline(maps, firststr);//x
				getline(maps, secondstr);//y
				tempMapObj.roomList[make_pair(stoi(firststr), stoi(secondstr))] = roomName;
			}
		}
		roomName = "";
		//printMap(mapVector);
		tempMapObj.mapVector = mapVector;
		tempMapObj.name = mapName;
		tempMapObj.playerStart = playerPos;
		tempMapObj.mapVector[playerPos.first][playerPos.second] = '@';
		masterMapsList[mapName] = tempMapObj;
		tempMapObj.roomList.clear();
		tempMapObj.mapVector.resize(0);
		mapVector.resize(0);
	}
	
}

void updatePlayerPosition(MapObject &currentMap, string direction, pair<int, int> &playerPos, map<string, MapObject> masterMapsList)
{
	bool didMove = false;
	currentMap.mapVector[playerPos.first][playerPos.second] = ' ';
	if (direction == "up")
	{
		if (playerPos.first > 0)
		{
			if (currentMap.mapVector[playerPos.first - 1][playerPos.second] == ' ')
			{
				playerPos.first--;
				didMove = true;
			}
			else if (currentMap.mapVector[playerPos.first - 1][playerPos.second] == '_')
			{
				playerPos.first--;
				clearMap(currentMap.mapVector);
				currentMap = masterMapsList[currentMap.roomList[playerPos]];
				playerPos = currentMap.playerStart;
				didMove = true;
			}
			
		}
	}
	else if (direction == "down")
	{
		if (playerPos.first < currentMap.mapVector.size() - 1)
		{
			if (currentMap.mapVector[playerPos.first + 1][playerPos.second] == ' ')
			{
				playerPos.first++;
				didMove = true;
			}
			else if (currentMap.mapVector[playerPos.first + 1][playerPos.second] == '_')
			{
				
				playerPos.first++;
				clearMap(currentMap.mapVector);
				currentMap = masterMapsList[currentMap.roomList[playerPos]];
				playerPos = currentMap.playerStart;
				didMove = true;
			}
			
		}
	}
	else if (direction == "left")
	{
		if (playerPos.second > 0)
		{
			if (currentMap.mapVector[playerPos.first][playerPos.second - 1] == ' ')
			{
				playerPos.second--;
				didMove = true;
			}
			else if (currentMap.mapVector[playerPos.first][playerPos.second - 1] == '|')
			{
				playerPos.second--;
				clearMap(currentMap.mapVector);
				currentMap = masterMapsList[currentMap.roomList[playerPos]];
				playerPos = currentMap.playerStart;
				didMove = true;
			}
			
		}
	}
	else if (direction == "right")
	{
		if (playerPos.second < currentMap.mapVector[0].size() - 1)
		{
			if (currentMap.mapVector[playerPos.first][playerPos.second + 1] == ' ')
			{
				playerPos.second++;
				didMove = true;
			}
			else if (currentMap.mapVector[playerPos.first][playerPos.second + 1] == '|')
			{
				playerPos.second++;
				clearMap(currentMap.mapVector);
				currentMap = masterMapsList[currentMap.roomList[playerPos]];
				playerPos = currentMap.playerStart;
				didMove = true;
			}
			
		}
	}
	
	currentMap.mapVector[playerPos.first][playerPos.second] = '@';
	if (didMove == true)
	{
		printMap(currentMap);
		cout << playerPos.first << " " << playerPos.second;
	}
}





void main()
{
	ifstream maps("maps.txt"); 
	Character *player;
	string name;
	int selection;
	pair <int, int> playerPos;
	vector <vector<char>> mapVector;
	map<string, MapObject> masterMapsList;

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
	buildMaps(maps, masterMapsList);
	printMap(masterMapsList["start"]);
	currentMap = masterMapsList["start"];
	playerPos = masterMapsList["start"].playerStart;

		while (true)
		{
			if (GetAsyncKeyState(VK_UP))
			{
				updatePlayerPosition(currentMap, "up", playerPos, masterMapsList);
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				updatePlayerPosition(currentMap, "down", playerPos, masterMapsList);
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				updatePlayerPosition(currentMap, "left", playerPos, masterMapsList);
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				updatePlayerPosition(currentMap, "right", playerPos, masterMapsList);
			}
			Sleep(100);
		}

		

}