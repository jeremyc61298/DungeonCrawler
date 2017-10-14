//#include <iostream>
//#include <string>
//#include <fstream>
//#include <unordered_map> 
//#include "Character.h"
//
//using namespace std;
//
//void output_stats(Character character) {
//	cout << "Name: " << character.getName() << endl;
//	cout << "Str: " << character.getStr() << endl;
//	cout << "Vit: " << character.getVit() << endl;
//	cout << "Def: " << character.getDef() << endl;
//	cout << "Atk: " << character.getAtk() << endl;
//	cout << "Spd: " << character.getSpd() << endl;
//	cout << "Smt: " << character.getSmt() << endl;
//	cout << "Mna: " << character.getMna() << endl;
//}
//
//void toUpper(string& input) {
//	for (int i = 0; i < input.size(); i++)
//	{
//		input[i] = toupper(input[i]);
//	}
//}
//
//void main() {
//	string choice;
//	ifstream story("Story.txt");
//	string storyline;
//	size_t found;
//	unordered_map<string, string> choices;
//	unordered_map<string, string>::iterator choiceit;
//	string option;
//	string result; 
//	Character* player;
//	bool recycle = false;
//
//
//
//
//	while (!story.eof())
//	{
//		if (recycle == false) {
//			getline(story, storyline);
//		}
//		else {
//			recycle = false;
//		}
//
//		if (storyline[0] == '*')
//		{
//			cout << storyline.substr(1) << endl;
//				getline(story, storyline);
//				while (!story.eof() && storyline[0] == '$') 
//				{
//					found = storyline.find('=');
//					option = storyline.substr(1, found - 1);
//					
//					toUpper(option);
//
//					result = storyline.substr(found + 1);
//					choices.insert(make_pair(option, result)); 
//					getline(story, storyline);
//					recycle = true;
//				};
//
//				choiceit = choices.begin();
//
//				for (int i = 0; i < choices.size(); i++)
//				{
//					cout << "   -> " << choiceit->first << endl;
//					choiceit++; 
//				}
//
//				cout << "Type your choice here: " << endl;
//			cin >> choice;
//
//			toUpper(choice);
//
//			if (choices.find(choice) != choices.end())
//			{
//				cout << choices[choice] << endl;
//			}
//			else
//			{
//				while (choices.find(choice) == choices.end())
//				{
//					cout << "Please select a valid choice ya dingus." << endl;
//					cout << "Type your choice here: " << endl;
//					cin >> choice;
//					
//					toUpper(choice);
//
//					if (choices.find(choice) != choices.end())
//					{
//						cout << choices[choice] << endl;
//					}
//				} 
//			}
//
//		}
//		else if (storyline[0] == '%') {												//Character Creation
//			cout << "Choose your class. " << endl;
//			cout << "Warrior" << endl << "Mage" << endl << "Rogue" << endl << "Barren" << endl;
//			cin >> choice;
//
//			toUpper(choice);
//
//
//			if (choice != "WARRIOR" && choice != "MAGE" && choice != "ROGUE" && choice != "BARREN") {
//				do {
//					cout << "Please select a valid choice ya dingus." << endl;
//					cout << "Type your choice here: " << endl;
//					cin >> choice;
//
//					toUpper(choice);
//					
//				} while (choice != "WARRIOR" && choice != "MAGE" && choice != "ROGUE" && choice != "BARREN");
//			}
//
//			if (choice == "WARRIOR")
//			{
//				player = new Character(1);
//			}
//			else if (choice == "MAGE")
//			{
//				player = new Character(2);
//			}
//			else if (choice == "ROGUE")
//			{
//				player = new Character(3);
//			}
//			else if (choice == "BARREN")
//			{
//				player = new Character(4);
//			}
//
//			Character playerT = *player;
//
//			cout << "What is your name? " << endl;
//			cin >> choice;
//
//			playerT.setName(choice);
//
//			output_stats(playerT);
//		}
//		else
//		{
//			cout << storyline << endl;
//		}
//	}
//}