#include "Character.h"
#include <string> 

Character::Character(int type) {

	switch (type) 
	{
	case 1:
		str = 4;
		atk = 4;
		def = 5;
		spd = 2;
		vit = 4;
		smt = 2;
		mna = 1;
			isWarrior = true;
			break;
	case 2:
		str = 2;
		atk = 2;
		def = 2;
		spd = 3;
		vit = 2;
		smt = 5;
		mna = 5;
			isMage = true;
			break;
	case 3:
		str = 3;
		atk = 3;
		def = 2;
		spd = 5;
		vit = 4;
		smt = 3;
		mna = 2;
			isRogue = true;
			break;
	case 4:
		str = 1;
		atk = 1;
		def = 1;
		spd = 1;
		vit = 1;
		smt = 1;
		mna = 1;
			isBarren = true;
			break;
	}
	

	requiredExp = 100; 
}

Character:: ~Character() {

}



int Character::getStr() {
	return str;
}

int Character::getVit() {
	return vit;
}

int Character::getDef() {
	return def;
}

int Character::getAtk() {
	return atk; 
}

int Character::getSpd() {
	return spd;
}

int Character::getSmt() {
	return smt;
}

int Character::getMna() {
	return mna;
}

string Character::getName() {
	return name;
}


bool Character::addExp(int xp) {
	exp = xp + exp;
	return checkLvl();
}

bool Character::checkLvl() {
	if (exp >= requiredExp) {
		lvl++;
		requiredExp += (requiredExp * lvl);
		return true;
	}
	else {
		return false;
	}
}

void Character::setStr(int inc) {
	str += inc;
}

void Character::setVit(int inc) {
	vit += inc;
}

void Character::setAtk(int inc) {
	atk += inc;
}

void Character::setDef(int inc) {
	def += inc;
}
void Character::setSpd(int inc) {
	spd += inc;
}

void Character::setSmt(int inc) {
	smt += inc;
}

void Character::setMna(int inc) {
	mna += inc;
}

void Character::setName(string inc) {
	name = inc;
}
