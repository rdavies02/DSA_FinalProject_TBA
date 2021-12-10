#pragma once
#ifndef __MAP_H__
#define __MAP_H__

class Map {
private:
	/*float p_loc_x;
	float p_loc_y;*/

	struct item {
		float id;
		std::string name;
	};

	//stores the current coordinates and info for the map location
	struct loc {
		uint8_t x_loc;
		uint8_t y_loc;
		item item;
		//~loc();
	};

	loc* currPlayerLoc;
	vector<vector<loc*>> maparr;
	vector<item> p_backpack;

public:
	Map(std::string filename, int max_x, int max_y, 
		uint8_t start_x, uint8_t start_y);
	~Map();
	loc* getLoc(uint8_t x_coord, uint8_t y_coord, item i);
	item getItem(std::string csvtoken);
	bool movePlayerLoc(uint8_t new_x, uint8_t new_y);

	item getItem();

};


#endif // !__MAP_H__
