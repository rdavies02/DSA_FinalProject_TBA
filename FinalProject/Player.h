#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <vector>
#include <string>

#include "Map.h"

using namespace std;

struct stats {
	uint8_t strength,
		dexterity, 
		intelligence;
	stats() {
		strength = 0, dexterity = 0, intelligence = 0;
	}
	stats(uint8_t str, uint8_t dex, uint8_t intel) {
		strength = str, dexterity = dex, intelligence = intel;
	}
};

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