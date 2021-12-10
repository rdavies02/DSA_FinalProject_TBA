#include <string>
#include <fstream>
#include <sstream>
#include "Game.h"
#include "Map.h"

using namespace std;

Map::Map(string filename, const int max_x, const int max_y, uint8_t start_x, uint8_t start_y) {
	ifstream map_FileStream;
	map_FileStream.open(filename);
	if (map_FileStream.fail() == true)
		throw ("Unable to open: " + filename).c_str();

	// update the dynamic array with the map size
	// maparr = new loc * [max_y];
	// for (int i = 0; i < max_x; i++)
	//	 maparr[i] = new loc[max_x];

	string line, token;
	uint8_t xcurr = 0, ycurr = 0;
	while (getline(map_FileStream, line))
	{
		istringstream strm(line);
		vector<loc*> rowVect;
		while (getline(strm, token, ',')) {
			rowVect.push_back(getLoc(xcurr++, ycurr, getItem(token)));
		}

		maparr.push_back(rowVect);
		rowVect.clear();
		xcurr = 0, ycurr++;
	}
	map_FileStream.close();

	currPlayerLoc = getLoc(start_x, start_y);

}

Map::~Map() {

}

Map::loc* Map::getLoc(uint8_t x_coord, uint8_t y_coord, item i) {
	loc* temp;
	temp->x_loc = x_coord;
	temp->y_loc = y_coord;
	temp->item = i;
	return temp;
}

Map::item Map::getItem(std::string csvtoken) {
	// split the token into item info, later can be expanded 
	// to store more information at a location
	istringstream strm(csvtoken);
	item temp;
	strm >> temp.id;
	return temp;
}


bool Map::movePlayerLoc(uint8_t new_x, uint8_t new_y) {

}



