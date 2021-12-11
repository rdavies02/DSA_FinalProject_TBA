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
	uint8_t xcurr = 0, ycurr = 0;
	while (getline(map_FileStream, line))
	{
		istringstream strm(line);
		vector<loc*> rowVect;
		
		while (getline(strm, token, ',')) {
			/*istringstream strm2(token);
			vector<uint8_t> locinfovect;
			string t_locinfo;
			while (getline(strm, t_locinfo, '|')) {
				locinfovect.push_back((uint8_t)stoi(t_locinfo));
			}*/

			rowVect.push_back(initLoc(token, ));
			locinfovect.clear();
		}
		maparr.push_back(rowVect);
		rowVect.clear();
		xcurr = 0, ycurr++;
	}
	map_FileStream.close();

	// initialize starting location
	currPlayerLoc = getLoc(start_x, start_y);

	// intialize game backpack
}

Map::~Map() {
	delete currPlayerLoc;
}

Map::loc* Map::initLoc(vector<uint8_t> locinfo_v) {
	loc* temp = new loc;
	temp->loc_num = locinfo_v[0];
	temp->item_pres = locinfo_v[1] == 256 ? false : true;
	temp->item.id = locinfo_v[1];

	return temp;
}

Map::loc* Map::initLoc(uint8_t l_num, uint8_t item) {
	loc* temp = new loc;
	temp->loc_num = l_num;
	temp->item_pres = item == 256 ? false : true;
	temp->item.id = item;
	
	return temp;
}

Map::loc* Map::getLoc(uint8_t x_coord, uint8_t y_coord) {
	return maparr[y_coord][x_coord];
}


Map::item Map::getItem(string csvtoken) {
	// split the token into item info, later can be expanded 
	// to store more information at a location
	istringstream strm(csvtoken);
	item temp;
	strm >> temp.id;
	return temp;
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


