#pragma once

#ifndef __LOC_ITEM_STATS_STRUCT_H__
#define __LOC_ITEM_STATS_STRUCT_H__

#include <string>
using namespace std;

//stores the current coordinates and info for the map location
struct loc {
	//uint8_t x_loc;
	//uint8_t y_loc;
	uint8_t loc_num;
	bool item_pres;
	uint8_t itemid;
};

typedef struct stats {
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

struct item {
	uint8_t id;
	string name;
	bool stat_increase;
	stats* stat;
	item() {
		id = (uint8_t)0; name = ""; stat_increase = false;
		stat = new stats();
	}
};


#endif // !__LOC_ITEM_STATS_STRUCT_H__
