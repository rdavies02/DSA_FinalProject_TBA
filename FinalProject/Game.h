#pragma once
#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <iostream>
#include <string>

#include "Player.h"
#include "Map.h"

/**
	Game class - Used to store necessicary elements to the game, 
	that dont need to be acessed in the main cpp file
*/
class Game : public Map {
private:
	

public:
	Game();
	~Game();

};


#endif // !GAME_CLASS_H
