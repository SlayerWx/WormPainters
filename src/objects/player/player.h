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
	Player(Direction start,float newDistanceToMove,Vector2 startPosition,Color color);
	~Player();

	void Input(float timeScale);
	void Update(float timeScale);
	void Draw();
	Vector2 moveToDirection();
	Rectangle GetHead();
	Color GetColor();
private:
	static const int maxBody = 20;
	Object* body[maxBody];
	Direction myDirection;
	float distanceToMove;
	void SetNewMoveInBody();
	static float timer;
	static const float timerMX;
	float speed = 10.0f;
	Color myColor = GRAY;
};
}
#endif