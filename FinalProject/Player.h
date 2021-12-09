#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <vector>
#include <string>

#include "Game.h"

class Player {
private:
	std::string username;
	
	

	std::vector<Game::item> backpack;

	struct stats {
		float strength,
			dexterity, 
			intelligence;
	};

public:
	Player();

	// character setup
	bool setupCharacter(int& playerStrength, int& playerDexterity, int& playerIntelligence, std::string& userName);
	void finalDisplay(int strength, int dexterity, int intelligence);
	std::string displayStat(int strength, int dexterity, int intelligence);
	void increase(int& remainingPoints, std::string userName, std::string upgrade, int& strength, int& dexterity, int& intelligence);
	void red(int remainingPoints, int& strength, int& dexterity, int& intelligence, std::string userName);

	//Backpack
	void addItemToBackpack(struct item);
	void emptyBackpack();
};



#endif // PLAYER_CLASS_H