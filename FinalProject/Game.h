#pragma once
#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <iostream>
#include <string>

#include "LocStatsItem.h"
#include "Player.h"
//#include "Map.h"

using namespace std;

/**
	Game class - Used to store necessicary elements to the game, 
	that dont need to be acessed in the main cpp file

	contains character setup and maintins the User Interface
	forms the link between the player and map class
*/
class Game {
private:
	

public:
	Game();
	~Game();
	// command system
	void displayFormattedMessage(string message);
	void commandParser(string& action, string& item);
	void displayHelp();
	// character setup
	bool setupCharacter(int& playerStrength, int& playerDexterity, int& playerIntelligence, string& userName);
	string displayStat(int strength, int dexterity, int intelligence);
	void increase(int& remainingPoints, string userName, string upgrade, int& strength, int& dexterity, int& intelligence);
	void red(int remainingPoints, int& strength, int& dexterity, int& intelligence, string userName);
};


#endif // !GAME_CLASS_H
