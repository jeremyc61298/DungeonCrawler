/* Character.cpp */
#include "Character.h"
#include <string> 

Character::Character(int type, string name) :name(name) {

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



int Character::getStr() const{
	return str;
}

int Character::getVit() const{
	return vit;
}

int Character::getDef() const{
	return def;
}

int Character::getAtk() const{
	return atk; 
}

int Character::getSpd() const{
	return spd;
}

int Character::getSmt() const{
	return smt;
}

int Character::getMna() const{
	return mna;
}

string Character::getName() const{
	return name;
}


bool Character::addExp(int const xp) {
	exp = xp + exp;
	return checkLvl();
}

bool Character::checkLvl() {
	if (exp >= requiredExp) {
		lvl++;
		requiredExp += (requiredExp * lvl);
		return true;
	}
	
	return false;
}

void Character::setStr(const int inc) {
	str += inc;
}

void Character::setVit(const int inc) {
	vit += inc;
}

void Character::setAtk(const int inc) {
	atk += inc;
}

void Character::setDef(const int inc) {
	def += inc;
}
void Character::setSpd(const int inc) {
	spd += inc;
}

void Character::setSmt(const int inc) {
	smt += inc;
}

void Character::setMna(const int inc) {
	mna += inc;
}

void Character::setName(string inc) {
	name = inc;
}
