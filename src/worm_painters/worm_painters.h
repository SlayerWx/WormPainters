#ifndef WORM_PAINTERS_H
#define WORM_PAINTERS_H
#include <iostream>

#include "raylib.h"

#include "elements/gameplay/gameplay.h"
#include "elements/menu/menu.h"
using namespace std;
namespace worm_painters
{
using namespace std;
enum GameStage
{
	Stage_SplashScreen, Stage_Menu, Stage_Gameplay
};
class WormPainters
{
public:
	WormPainters();
	~WormPainters();
	void Play();
private:
	const int initialWindowSizeHeight = 700;
	const int initialWindowsSizeWidth = 600;
	const string title = "Worm Painters";
	const string version = "V0.1";
	GameStage currentStage;
	Gameplay* gameplay;
	Menu* menu;
	void Input();
	void Update();
	void Draw();
	bool firstTime;
	Music stream;
	float volume = 0.5f;
	const float modfV = 0.1f;
	const float mx = 1.0f;
	const float min = 0.0f;
	void Volume();
};
}
#endif