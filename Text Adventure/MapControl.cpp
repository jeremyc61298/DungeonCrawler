/* MapControl.cpp */
#include "MapControl.h"
using std::make_pair;


MapControl::MapControl() :maps("maps.txt")
{
	if (!maps.is_open())
	{
		std::cerr << "File cannot be properly opened." << endl;
	}
}


MapControl::~MapControl()
{
}

void MapControl::ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void MapControl::initializeDungeon()
{
	ShowConsoleCursor(false);
	buildMaps();
	printMap(masterMapsList["start"]);
	currentMap = (masterMapsList["start"]);
	playerPos = masterMapsList["start"].playerStart;
}

void MapControl::buildMaps()		//Uses a 2-d vector to create a 2-d map space in the console 
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
		getline(maps, line);				//This retrievs the line of the map from the maps.txt file 
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

void MapControl::printMap(MapObject mapObject) const
{
	system("cls");
	for (auto i = mapObject.mapVector.begin(); i < mapObject.mapVector.end(); i++)
	{
		for (auto j = i->begin(); j < i->end(); j++)
		{
			cout << *j;
		}
		cout << endl;
	}
}

void MapControl::clearMap(vector<vector<char>> &mapVector)
{
	mapVector.resize(0);
}


void MapControl::updatePlayerPosition(string direction)
{
	bool didMove = false;
	currentMap.mapVector[playerPos.first][playerPos.second] = ' ';
	if (direction == "up")
	{
		didMove = moveUp(didMove);
	}
	else if (direction == "down")
	{
		didMove = moveDown(didMove);
	}
	else if (direction == "left")
	{
		didMove = moveLeft(didMove);
	}
	else if (direction == "right")
	{
		didMove = moveRight(didMove);
	}

	currentMap.mapVector[playerPos.first][playerPos.second] = '@';
	if (didMove == true)
	{
		printMap(currentMap);
		cout << playerPos.first << " " << playerPos.second;
	}
}

bool MapControl::moveUp(bool didMove)
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
	return didMove;
}

bool MapControl::moveDown(bool didMove)
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
	return didMove;
}

bool MapControl::moveLeft(bool didMove)
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
	return didMove;
}

bool MapControl::moveRight(bool didMove)
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
	return didMove;
}
