/*
	Data Structures & Algorithms Final Project
	Author: Rhys Davies
	Github Repo: https://github.com/rdavies02/DSA_FinalProject_TBA

	Text Based Adventure Game
	class structure:
		main -> Game 
			 -> Player 
			 -> Map
*/


#include <iostream>
#include <string>

#include "Map.h"

//#include "QueueList.hpp"
//#include "Player.h"
//#include "Game.h"

using namespace std;

const char* FILENAMES[3] = {
	"map_file.csv",
	"itemlist.txt",
	"locations.txt"
};

int main() {

	//Game game;
	try {
		//QueueList<string> queue(5);

		//queue.enqueue("bannana");
		//queue.displayQueue();
		//queue.enqueue("apple");
		//queue.displayQueue();
		//queue.enqueue("pear");
		//queue.displayQueue();
		//queue.enqueue("grapes");
		//queue.displayQueue();
		//queue.enqueue("raspberry");
		//queue.displayQueue();
		//queue.enqueue("strawberry");
		//queue.displayQueue();
		//cout << "dequeue_back = " << queue.dequeue_back() << endl;
		////cout << "dequeue = " << queue.dequeue() << endl;
		//
		//queue.displayQueue();

		Map gamemap(FILENAMES, 16, (uint8_t)0, (uint8_t)0);
		gamemap.dispMap();
	}
	catch (const char* c) {
		cerr << c << endl;
	}
	
	return 0;
}
