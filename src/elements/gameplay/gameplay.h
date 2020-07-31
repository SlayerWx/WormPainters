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
	static const int maxPlayers = 1;
	Player* p[maxPlayers];
private:
	float timeGameplayScale = 1.0f;
	void CheckCollision();
	Texture2D playerHead;
	Texture2D playerBody;
};
}
#endif