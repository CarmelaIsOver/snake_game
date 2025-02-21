#pragma once
#define LENGTH 50
#define HEIGHT 25

int SCORE = 0;

struct Body {
	int x, y;
};
struct Snake {
	Body body[LENGTH * HEIGHT];
	int cursize;
}snake;
struct Food {
	int x, y;
}food;

