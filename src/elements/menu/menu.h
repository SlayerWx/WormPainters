#ifndef MENU_H
#define MENU_H
#include "raylib.h"
class Menu
{
	enum Choose
	{
		play,credits,exit,nothing
	};
	struct Key
	{
		KeyboardKey up = KEY_UP;
		KeyboardKey down = KEY_DOWN;
		KeyboardKey enter = KEY_ENTER;
	};
public:
	Menu();
	~Menu();
	void Input();
	void Update();
	void Draw();
	bool RequestExit();
	bool RequestPlay();
	void myRestart();
private:
	void DrawCredits();
	Choose choose;
	Key myKey;
	int currentOption;
	int fontSize = 50;
	int controlsSizeFont = 10;
	int distanceOptions = 10;
	Color colorInSelection = RED;
	Color noSelection = BLACK;
	Color plyColor;
	Color crditColor;
	Color exitColor;
	Texture2D bckground;
	const int theHalf = 2;
	const int four = 4;

};
#endif