#include <iostream>
#include <string>

#include "Player.h"
#include "Game.h"

using namespace std;

int main() {

	Game game;





	try {
		throw "Window closed successfully";
	}
	catch (const char* c) {
		cerr << c << endl;
	}
	
	return 0;
}


// References : https://youtu.be/45MIykWJ-C4
// https://www.glfw.org/docs/3.3/input_guide.html#input_key
// https://bestofcpp.com/repo/ocornut-imgui-cpp-ui-lib