#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "raylib.h"

#include "elements/map/map.h"
#include "objects/player/player.h"
#include "objects/fruit/fruit.h"
namespace worm_painters
{
enum playerNumber
{
	playerOne,playerTwo,playerTree,playerFour
};
class Gameplay
{
public:
	Gameplay();
	~Gameplay();
	void Restart();
	void Input();
	void Update();
	void Draw();
	bool GoToMenu();
	Map* map;
	static const int maxPlayers = 2;
	Player* p[maxPlayers];
	Fruit* fruit;
private:
	void RequestMenu();
	float timeGameplayScale = 1.0f;
	const float defaultGamePlayScale = 1.0f;
	void CheckCollision();
	void DrawHud();
	void WinCondition();
	void DrawWinner();
	void Timing();
	void DrawTime();
	static const int startTimeMinute = 3;
	const float mxSeconds = 60.0f;
	const int decimal = 10;
	const int theHalf = 2;
	int timer = 0;
	float seconds = 0;
	int timeSizeFont = 30;
	Texture2D playerHead;
	Texture2D playerBody;
	Texture2D hud;
	const Color winColor = BLACK;
	int sizeFontWin;
	const Color playerOneColor = BLUE;
	const Color playerTwoColor = RED;
	const Color playerTreeColor = YELLOW;
	const Color playerFourColor = VIOLET;
	int checkPlayerWin = 0;
	bool endGame;
	bool goToMenu;
	float timerToMenu;
	const float timerMxToMenu = 2.0f;
	const int four = 4;
	const int eight = 8;
	int mxPlayersInGame;
};
}
#endif