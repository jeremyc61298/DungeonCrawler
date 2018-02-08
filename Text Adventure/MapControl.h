/* MapControl.h */
#pragma once
#ifndef MAPCONTROL_H
#define MAPCONTROL_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <map>

using std::vector;
using std::cout;
using std::string;
using std::map;
using std::pair;
using std::endl;
using std::ifstream;

struct MapObject
{
	vector<vector<char>> mapVector;
	pair<int, int> playerStart;
	string name;
	map<pair<int, int>, string> roomList;
};

class MapControl
{
	public:
		MapControl();
		~MapControl();
		void initializeDungeon();
		void buildMaps();
		void updatePlayerPosition(const string);
		void printMap(MapObject) const;
		void clearMap(vector<vector<char>>&) const;
	private: 
		pair <int, int> playerPos;
		MapObject currentMap;
		map<string, MapObject> masterMapsList;
		ifstream maps;
		void showConsoleCursor(bool) const;
		bool moveUp(bool);
		bool moveDown(bool);
		bool moveLeft(bool);
		bool moveRight(bool);
};

#endif MAPCONTROL_H