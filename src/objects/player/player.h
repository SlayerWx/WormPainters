#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "objects/object.h"
namespace worm_painters
{
enum Direction
{
	right,left,up,down
};
class Player
{
public:
	Player(Direction start);
	~Player();

	void Input();
	void Update();

private:
	static const int maxBody = 15;
	static const int difHeadPlayerInNext = 12;
	Object* body[maxBody];
	Direction myDirection;
};
}
#endif