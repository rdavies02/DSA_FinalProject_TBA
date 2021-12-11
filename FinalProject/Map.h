#pragma once
#ifndef __MAP_H__
#define __MAP_H__

#include <vector>

//#include "LinkedListStack.h"
//#include "LinkedListStack.cpp"

using namespace std;

class Map {
private:
	/*float p_loc_x;
	float p_loc_y;*/
	string map_filename,
		itemlist_filename,
		locations_filename;

	struct item {
		uint8_t id;
		string name;
		item() {
			id = 0; name = "";
		}
	};

	//stores the current coordinates and info for the map location
	struct loc {
		//uint8_t x_loc;
		//uint8_t y_loc;
		uint8_t loc_num;
		bool item_pres;
		item item;
	};

	loc* currPlayerLoc;
	vector<vector<loc*>> maparr;
	//vector<item> p_backpack;
	//vector<item> g_backpack;
	//LinkedListStack<item> p_backpack;
	//LinkedListStack<item> g_backpack;

public:
	Map(const char* map_filename[3], int max_x, int max_y,
		uint8_t start_x, uint8_t start_y);
	~Map();
	loc* initLoc(vector<uint8_t> locinfo_v);
	loc* initLoc(uint8_t l_num, uint8_t item);
	loc* getLoc(uint8_t x_coord, uint8_t y_coord);
	item getItem(string csvtoken);
	bool movePlayerLoc(uint8_t new_x, uint8_t new_y);


	void dispMap();

};


#endif // !__MAP_H__
