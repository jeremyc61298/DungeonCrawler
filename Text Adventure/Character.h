/* Character.h */
#pragma once
#include <string>

using namespace std;

class Character {
public:
	Character(int, string);
	~Character();

	int getStr();
	int getVit();
	int getDef();
	int getAtk();
	int getSpd();
	int getSmt();
	int getMna();
	string getName();

	void setStr(int);
	void setVit(int);
	void setDef(int);
	void setAtk(int);
	void setSpd(int);
	void setSmt(int);
	void setMna(int);
	void setName(string);
	
	bool addExp(int); 
	
private: 
	int str;
	int vit;
	int def;
	int atk;
	int spd;
	int mna;
	int smt;
	int lvl; 
	int exp; 
	string name; 
	int requiredExp;
	bool isWarrior;
	bool isMage;
	bool isRogue;
	bool isBarren;

	bool checkLvl();
};