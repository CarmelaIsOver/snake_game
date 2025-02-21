#include"head.h"

int main() {
	srand(time(0));
	gamestart();
	HideCursor();
	build_a_wall();
	gamebegin();
	movement();
	gameover();
	return 0;
}