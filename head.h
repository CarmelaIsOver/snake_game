#pragma once
#include<iostream>
#include<windows.h>
#include<random>
#include<conio.h>
#include <cstdlib> 
#include <ctime>

using namespace std;

void gamebegin();
void movement();
void drawbody(int, int);
void drawspace(int, int);
void drawfood(int,int);
void HideCursor();
void build_a_wall();
void create_a_snake();
void create_a_food();
void body_refresh(int,int);
void gameover();
void gamestart();
bool ban_opposite_direction(char, char);
