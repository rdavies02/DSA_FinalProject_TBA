#pragma once
#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include "Player.h"

#include "QueueList.h"
#include "QueueList.cpp"

using namespace std;



class Map {
public:
	typedef struct item {
		uint8_t id;
		string name;
		bool stat_increase;
		Player::stats stat;
		item() {
			id = (uint8_t)0; name = ""; stat_increase = false;
			stat = Player::stats();
		}
	};
private:
	string map_filename,
		itemlist_filename,
		locations_filename;
	
	

	//stores the current coordinates and info for the map location
	struct loc {
		//uint8_t x_loc;
		//uint8_t y_loc;
		uint8_t loc_num;
		bool item_pres;
		uint8_t itemid;
	};

	//pointer to point at the location in the vector
	loc* currPlayerLoc; 
	vector<vector<loc*>> maparr;
	QueueList<item> p_backpack;
	QueueList<item> g_backpack;
	//LinkedListStack<item> p_backpack;
	//LinkedListStack<item> g_backpack;

public:
	Map(const char* map_filename[3], int max_x, int max_y,
		uint8_t start_x, uint8_t start_y);
	~Map();
	loc* initLoc(vector<uint8_t> locinfo_v);
	loc* initLoc(uint8_t l_num, uint8_t item);
	loc* getLoc(uint8_t x_coord, uint8_t y_coord);
	bool movePlayerLoc(uint8_t new_x, uint8_t new_y);
	void dispMap();

	//backpack stuff
	void initGameBackpack();
	QueueList<item> getGameBackpack();
	QueueList<item> getPlayerBackpack();

};


#endif // !__MAP_H__
