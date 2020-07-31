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
struct Key
{
	KeyboardKey up;
	KeyboardKey down;
	KeyboardKey left;
	KeyboardKey right;
};
class Player
{
public:
	Player(Direction start,float newDistanceToMove,Vector2 startPosition,Color color,Texture2D tHead,Texture2D tBody);
	~Player();

	void Input(float timeScale);
	void Update(float timeScale);
	void Draw();
	Vector2 moveToDirection();
	Rectangle GetHead();
	Color GetColor();
	void SetActive(bool active);
	void SetColor(Color newColor);
	void SetPositionAndDirection(Vector2 pos, Direction dir);
	void SetControls(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right);
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
	bool canChange;
	bool imActive;
	Vector2 originPosition;
	Direction originDir;
	Key controls;
};
}
#endif