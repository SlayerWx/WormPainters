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
	void UpdateCredits();
	void DrawCredits();
	bool RequestExit();
private:
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

};
#endif