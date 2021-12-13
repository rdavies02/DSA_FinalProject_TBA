#pragma once
#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Player.h"

#include "LocStatsItem.h"
#include "QueueList.h"
#include "QueueList.cpp"

using namespace std;

class Map {
private:
	struct location {
		uint8_t loc_num;
		string loc_name;
		string loc_info;
		uint8_t item_req;
	};

	string map_filename,
		itemlist_filename,
		locations_filename;
	
	uint8_t p_x_loc;
	uint8_t p_y_loc;
	//pointer to player location in the vector
	loc* currPlayerLoc; 
	vector<vector<loc*>> maparr;
	vector<location> locations;
	QueueList<item> p_backpack;
	QueueList<item> g_backpack;
	//LinkedListStack<item> p_backpack;
	//LinkedListStack<item> g_backpack;

	bool isValidMove(uint8_t new_x, uint8_t new_y);
public:
	Map(const char* files[3], const int backpacksize,
		uint8_t start_x, uint8_t start_y);
	~Map();
	loc* initLoc(uint8_t l_num, uint8_t item);
	loc* getLoc(uint8_t x_coord, uint8_t y_coord);
	bool movePlayerLoc(bool dir_x, bool dir_y, uint8_t amt);
	bool movePlayerLoc(uint8_t new_x, uint8_t new_y);
	void updateAndDisplay(loc newLoc);
	void dispMap();

	//backpack stuff
	void initGameBackpack();
	QueueList<item> getGameBackpack();
	QueueList<item> getPlayerBackpack();

};


#endif // !__MAP_H__
