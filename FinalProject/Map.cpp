#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "LocStatsItem.h"
#include "Map.h"
//#include "LinkedListStack.h"
//#include "LinkedListStack.cpp"
//#include "QueueList.h"
//#include "QueueList.cpp"

using namespace std;

Map::Map(const char* files[3], const int backpacksize, 
	uint8_t start_x, uint8_t start_y) {
	p_backpack = QueueList<item>(backpacksize);
	g_backpack = QueueList<item>(backpacksize);

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
			string locnum, itemid = "255", delim = "|";
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

	ifstream locinfo_FileStream(locations_filename);
	if (locinfo_FileStream.fail() == true)
		throw ("Unable to open: " + locations_filename).c_str();
	
	line.clear();
	while (getline(locinfo_FileStream, line)) {
		istringstream strm(line);
		location temp;
		string locnum, itemRequired;
		strm >> locnum >> temp.loc_name >> temp.loc_info >> itemRequired;
		temp.loc_num = (uint8_t)stoi(locnum);
		temp.item_req = (uint8_t)stoi(itemRequired);
		locations.push_back(temp);
	}
}

Map::~Map() {
	delete currPlayerLoc;
}

loc* Map::initLoc(uint8_t l_num, uint8_t item) {
	loc* temp = new loc;
	temp->loc_num = l_num;
	temp->item_pres = item == 255 ? false : true;
	temp->itemid = item;
	return temp;
}

loc* Map::getLoc(uint8_t x_coord, uint8_t y_coord) {
	return maparr[y_coord][x_coord];
}

bool Map::isValidMove(uint8_t new_x, uint8_t new_y) {
	if (new_x < 0 || new_x > maparr[0].size() ||
		new_y < 0 || new_y > maparr.size()) {
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
		cout << "You cannot go off the map..." << endl;
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl << endl;
		return false;
	}
	//check if the player has the correct item to enter the area
	else if (locations[maparr[new_y][new_x]->loc_num].item_req == p_backpack.peek().id) {
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
		cout << "You do not have the item required to enter this area..." << endl;
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl << endl;
		return false;
	}
	return true;
}

bool Map::movePlayerLoc(bool dir_x, bool dir_y, uint8_t amt) {
	if (dir_x) {
		if (isValidMove(p_x_loc + amt, p_y_loc)) {
			p_x_loc += amt;
		}
		else {
			return false;
		}
	}
	if (dir_y) {
		if (isValidMove(p_x_loc, p_y_loc + amt)) {
			p_y_loc += amt;
		}
		else {
			return false;
		}
	}
	return true;
}

bool Map::movePlayerLoc(uint8_t new_x, uint8_t new_y) {
	if (isValidMove(new_x, new_y)) {
		p_x_loc = new_x, p_y_loc = new_y;
		return true;
	}
	else {
		return false;
	}	
}

void Map::updateAndDisplay(loc newloc) {
	// 3 cases 
	// if the player is entering a space that doesnt have an item or doesnt require one
	if (newloc.loc_num == currPlayerLoc->loc_num) {
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl << "[" << p_x_loc << ", " << p_y_loc << "]" << endl;
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
	}
	else if (newloc.loc_num) {

	}
	// if the player is entering a space that has an item
	else if (newloc.item_pres) {
		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl << "[" << p_x_loc << ", " << p_y_loc << "]" << endl;



		for (int i = 0; i < 75; i++) { cout << "-"; }
		cout << endl;
	}
	
	if ()


	if (!alreadyHave) {
		getItemInfo(iId, itemName, statName, upgradeNumber);
		for (int i = 0; i < itemName.size(); i++) {
			if (itemName[i] == '_') {
				itemName[i] = ' ';
			}
		}
		cout << "Item collected: " << itemName;
		if (statName != "NULL") {
			cout << " and this will upgrade your: " << statName << " to level " << upgradeNumber << endl;
		}
		else { cout << endl; }
	}
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
			//tempitem.stat = stats();
		}
		else if (statusName == "Strength") {
			tempitem.stat_increase = true;
			tempitem.stat = new stats((uint8_t)stoi(statuAmount), 0, 0);
		}
		else if (statusName == "Dexterity") {
			tempitem.stat_increase = true;
			tempitem.stat = new stats(0, (uint8_t)stoi(statuAmount), 0);
		}
		else if (statusName == "Intelligence") {
			tempitem.stat_increase = true;
			tempitem.stat = new stats(0, 0, (uint8_t)stoi(statuAmount));
		}

		// moves the first item in the file to the front of the queue
		// and adds later items to the back of the queue, FIFO
		g_backpack.enqueue(tempitem);
	}

}

QueueList<item> Map::getGameBackpack() {
	return g_backpack;
}

QueueList<item> Map::getPlayerBackpack() {
	return p_backpack;
}
