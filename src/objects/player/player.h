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
	void restart(bool ctive);
	void Input(float timeScale);
	void Update(float TimeScale, int topMap);
	void Draw();
	Vector2 moveToDirection();
	Rectangle GetHead();
	Color GetColor();
	void SetActive(bool active);
	bool GetActive();
	void SetColor(Color newColor);
	void SetPositionAndDirection(Vector2 pos, Direction dir);
	int GetPoints();
	void SetPoints(int p);
	void SetControls(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right);
	void SetDead(bool d);
	bool GetDead();
	bool CheckEnemyCollision(Rectangle eHead);
private:
	static const int maxBody = 20;
	Object* body[maxBody];
	Direction myDirection;
	float distanceToMove;
	void SetNewMoveInBody();
	float timer;
	static const float timerMX;
	float speed = 10.0f;
	Color myColor = GRAY;
	bool canChange;
	bool imActive;
	bool imDead;
	Vector2 originPosition;
	Direction originDir;
	Key controls;
	static const int correctorScaleXPosition = 4;
	static const int theHalf = 2;
	int myPoints = 0;
	void CheckSelfCollision();
};
}
#endif