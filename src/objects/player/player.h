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
	Player(Direction start,float newDistanceToMove,Vector2 startPosition);
	~Player();

	void Input();
	void Update();

private:
	static const int maxBody = 2;
	static const int difHeadPlayerInNext = 12;
	Object* body[maxBody];
	Direction myDirection;
	float distanceToMove;
	void SetNewMoveInBody(float x, float y);
};
}
#endif