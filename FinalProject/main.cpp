#include <iostream>
#include <string>

#include "QueueList.h"
#include "Queuelist.cpp"
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

		//throw "Window closed successfully";

		Map gamemap(FILENAMES, 20, 20, 0, 0);

	}
	catch (const char* c) {
		cerr << c << endl;
	}
	
	return 0;
}


// References : https://youtu.be/45MIykWJ-C4
// https://www.glfw.org/docs/3.3/input_guide.html#input_key
// https://bestofcpp.com/repo/ocornut-imgui-cpp-ui-lib