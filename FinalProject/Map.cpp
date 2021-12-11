#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Map.h"
//#include "LinkedListStack.h"
//#include "LinkedListStack.cpp"
//#include "QueueList.h"
//#include "QueueList.cpp"

using namespace std;

Map::Map(const char* files[3],
	const int max_x, const int max_y, uint8_t start_x, uint8_t start_y) {
	map_filename = files[0];
	itemlist_filename = files[1];
	locations_filename = files[2];

	// open necessicary files
	ifstream map_FileStream(map_filename);
	if (map_FileStream.fail() == true)
		throw ("Unable to open: " + map_filename).c_str();

	string line, token;
	while (getline(map_FileStream, line))
	{
		istringstream strm(line);
		vector<loc*> rowVect;
		
		while (getline(strm, token, ',')) {
			string locnum, itemid, delim = "|";
			istringstream strm(token);
			strm >> locnum >> delim >> itemid;
			rowVect.push_back(initLoc((uint8_t)stoi(locnum), (uint8_t)stoi(itemid)));
		}
		maparr.push_back(rowVect);
		rowVect.clear();
	}
	map_FileStream.close();

	// initialize starting location
	currPlayerLoc = getLoc(start_x, start_y);
}

Map::~Map() {
	delete currPlayerLoc;
}

Map::loc* Map::initLoc(vector<uint8_t> locinfo_v) {
	loc* temp = new loc;
	temp->loc_num = locinfo_v[0];
	temp->item_pres = locinfo_v[1] == 256 ? false : true;
	temp->itemid = locinfo_v[1];
	return temp;
}

Map::loc* Map::initLoc(uint8_t l_num, uint8_t item) {
	loc* temp = new loc;
	temp->loc_num = l_num;
	temp->item_pres = item == 256 ? false : true;
	temp->itemid = item;
	return temp;
}

Map::loc* Map::getLoc(uint8_t x_coord, uint8_t y_coord) {
	return maparr[y_coord][x_coord];
}

bool Map::movePlayerLoc(uint8_t new_x, uint8_t new_y) {
	return true;
}

void Map::dispMap() {
	for (int i = 0; i < maparr.size(); i++) {
		for (int j = 0; j < maparr[i].size(); j++)
			cout << maparr[i][j]->loc_num << " ";
		cout << endl;
	}
}

/**
	Map::initGameBackpack initializes the game backpack, 
	the items the user can aqquire in the order that they are 
	listed in the file and enqueues these items into the game backpack
	which is a queue of type: item
*/
void Map::initGameBackpack() {
	// open necessicary files
	ifstream item_FileStream(itemlist_filename);
	if (item_FileStream.fail() == true)
		throw ("Unable to open: " + itemlist_filename).c_str();

	string line, token;
	while (getline(item_FileStream, line)) {
		istringstream strm(line);
		
		item tempitem;
		string statusName, statuAmount;
		strm >> tempitem.id >> tempitem.name >> statusName >> statuAmount;

		if (statusName == "NULL") {
			tempitem.stat_increase = false;
			tempitem.stat = Player::stats();
		}
		else if (statusName == "Strength") {
			tempitem.stat_increase = true;
			tempitem.stat = Player::stats((uint8_t)stoi(statuAmount), 0, 0);
		}
		else if (statusName == "Dexterity") {
			tempitem.stat_increase = true;
			tempitem.stat = Player::stats(0, (uint8_t)stoi(statuAmount), 0);
		}
		else if (statusName == "Intelligence") {
			tempitem.stat_increase = true;
			tempitem.stat = Player::stats(0, 0, (uint8_t)stoi(statuAmount));
		}

		// moves the first item in the file to the front of the queue
		// and adds later items to the back of the queue, FIFO
		g_backpack.enqueue(tempitem);
	}

}

QueueList<Map::item> Map::getGameBackpack() {
	return g_backpack;
}

QueueList<Map::item> Map::getPlayerBackpack() {
	return p_backpack;
}
