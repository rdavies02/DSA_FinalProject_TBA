
#include <string>

#include "Game.h"

class Map {
private:
	float p_loc_x;
	float p_loc_y;

	struct item {
		float id;
		std::string name;
	};

	//stores the current coordinates of the mab location
	struct loc {
		uint8_t x_loc;
		uint8_t y_loc;
		//uint8_t locNum;
		item item;
		~loc();
	};

public:
	Map(std::string filename);
	~Map();


};

Map::loc::~loc()
{

}
