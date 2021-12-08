#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <vector>
#include <string>

class Player {
private:
	std::string username;
	float p_loc_x;
	float p_loc_y;
	
	struct item {
		float id;
		std::string name;
	};

	std::vector<item> backpack;

	struct stats {
		float strength,
			dexterity, 
			intelligence;
	};

public:
	Player();
};



#endif // PLAYER_CLASS_H