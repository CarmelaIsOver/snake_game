#include"prepare.h"
#include"head.h"

void gamebegin() {
	create_a_snake();
	create_a_food();
	drawfood(food.x,food.y);
}

void create_a_snake() {
	srand(time(0));
	snake.cursize = 4;
	snake.body[0].x = LENGTH/2;
	snake.body[0].y = HEIGHT/2;
	for (int i = 0; i < snake.cursize - 1; i++) {
		snake.body[i + 1].x = snake.body[i].x - 1;
		snake.body[i + 1].y = snake.body[i].y;
	}
}

void create_a_food() {
	int x, y;
	bool overlap ;
	do {
		x = rand() % (LENGTH - 2) + 1; 
		y = rand() % (HEIGHT - 2) + 1;
		overlap = false;
		for (int i = 0; i < snake.cursize; i++) {
			if (snake.body[i].x == x && snake.body[i].y == y) {
				overlap = true;
				break;
			}
		}
	} while (overlap); 
	food.x = x;
	food.y = y;
	drawfood(food.x,food.y);
}

void movement() {
	char curdirection, newdirection;
	int headx, heady, tailx, taily;

	headx = snake.body[0].x;
	heady = snake.body[0].y;
	tailx = snake.body[snake.cursize - 1].x;
	taily = snake.body[snake.cursize - 1].y;
	curdirection = 'd';
	newdirection = 'd';

	
	while (true) {
		if (_kbhit()) 
		newdirection = _getch();
		if ((curdirection == 'a' && newdirection != 'd') ||
			(curdirection == 'd' && newdirection != 'a') ||
			(curdirection == 'w' && newdirection != 's') ||
			(curdirection == 's' && newdirection != 'w')) {
			curdirection = newdirection;
		}
			switch (curdirection) {
			case 's':heady++; break;
			case 'a':headx--; break;
			case 'w':heady--; break;
			case 'd':headx++; break;
			}
		
		for (int i = 1; i < snake.cursize; i++) {
			if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
				return;
			}
		}

		if (snake.body[0].x < 0 || snake.body[0].x >= LENGTH || snake.body[0].y < 0 || snake.body[0].y >= HEIGHT)
			return;

		 else if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
			snake.cursize++;
			SCORE += 10;
			create_a_food();
		}


		body_refresh( headx, heady);
		for (int i = 0; i < snake.cursize; i++)
			drawbody(snake.body[i].x, snake.body[i].y);
		drawspace(tailx, taily);
		tailx = snake.body[snake.cursize - 1].x;
		taily = snake.body[snake.cursize - 1].y;
		
		Sleep(100);
	}
}

void drawbody(int x, int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "*";
}

void drawspace(int x, int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
}

void drawfood(int x,int y) {
	COORD coord = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	cout << "#";
}

void HideCursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void build_a_wall() {
	system("cls");
	for (int i = 0; i <= HEIGHT; i++) {
		for (int j = 0; j <= LENGTH; j++) {
			if (j == LENGTH )  
				printf("|");
			else if (i == HEIGHT) 
				printf("-");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void body_refresh(int x,int y) {
	for (int i = snake.cursize; i > 0; i--) {
		snake.body[i].x = snake.body[i - 1].x;
		snake.body[i].y = snake.body[i - 1].y;
	}
	snake.body[0].x = x;
	snake.body[0].y = y;
}

void gameover() {
	system("cls");
    printf
		("             ____   \n"
			"Game over!  / . .\\ \n"
			"            \\  ---<\n"
			"             \\  /  \n"
			"   __________/ /    \n"
			"-=:___________/\n");
    printf("\nYour scores:%d\n", SCORE );
}
void gamestart() {
	printf(
		"             ____   \n"
		"Hello       / . .\\ \n"
		"player!     \\  ---<\n"
		"             \\  /  \n"
		"   __________/ /    \n"
		"-=:___________/\n");
	printf("\nPress 'w/a/s/d' to change the direction.\n");
	printf("\nDo not eat yourself or touch the wall.\n");
	printf("\nAnyway,remember to switch your input method to English in advance.\n");
	printf("\nPress 'Enter' to start the game!");
	char input = _getch();
	if (input == '\n') {
		system("cls");
		return;
	}
}

bool ban_opposite_direction(char curdirection, char newdirection) {
	if ((curdirection == 's' && newdirection == 'w') ||
		(curdirection == 'w' && newdirection == 's') ||
		(curdirection == 'a' && newdirection == 'd') ||
		(curdirection == 'd' && newdirection == 'a')) {
		return true;
	}
	return false;
}



