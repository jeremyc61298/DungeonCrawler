#include <iostream>
#include <string>
#include "Mage.h"

using namespace std;

Mage ::Mage() {
	setAtk(2);
	setDef(2);
	setMna(5);
	setSmt(5);
	setSpd(3);
	setStr(2);
	setVit(2);
}

Mage::~Mage() {};