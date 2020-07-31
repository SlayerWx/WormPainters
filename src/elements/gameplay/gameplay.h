#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "raylib.h"
#include "elements/map/map.h"
#include "objects/player/player.h"
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
	Map* map;
	static const int maxPlayers = 2;
	Player* p[maxPlayers];
private:
	float timeGameplayScale = 1.0f;
	const float defaultGamePlayScale = 1.0f;
	void CheckCollision();
	void DrawHud();
	void WinCondition();
	void DrawWinner();
	Texture2D playerHead;
	Texture2D playerBody;
	Texture2D hud;
	static const int startTimeMinute = 3;
	const Color winColor = BLACK;
	int sizeFontWin;
	const Color playerOneColor = BLUE;
	const Color playerTwoColor = RED;
	const Color playerTreeColor = YELLOW;
	const Color playerFourColor = VIOLET;
	int checkPlayerWin = 0;
	bool endGame;
};
}
#endif