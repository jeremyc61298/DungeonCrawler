#include <iostream>
#include <string>
#include "Warrior.h"

using namespace std;

Warrior::Warrior()
{
	setAtk(4);
	setDef(5);
	setMna(1);
	setSmt(2);
	setSpd(2);
	setStr(4);
	setVit(4);

};

Warrior::~Warrior() {};