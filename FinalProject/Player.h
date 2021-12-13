#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <vector>
#include <string>

#include "LocStatsItem.h"
#include "Map.h"

using namespace std;

class Player {
private:
	string username;
	vector<item> backpack;
	stats playerStats;

public:
	Player();
	
	string displayStats();
	void increase(int& remainingPoints, std::string userName, std::string upgrade, int& strength, int& dexterity, int& intelligence);
	void red(int remainingPoints, int& strength, int& dexterity, int& intelligence, std::string userName);

	//Backpack
	void addItemToBackpack(struct item);
	void emptyBackpack();
};



#endif // PLAYER_CLASS_H