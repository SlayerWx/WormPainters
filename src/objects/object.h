#ifndef OBJECT_H
#define OBJECT_H
#include "raylib.h"
namespace worm_painters
{
enum BodyPart
{
	head = 0,next
};
class Object
{
public:
	Object(float x, float y, float width, float height);
	~Object();
	void SetX(float newX);
	float GetX();
	void SetY(float newY);
	float GetY();
	void SetPosition(float x, float y);
	Vector2 GetPosition();
	void SetHeightAndWidth(float height, float width);
	void SetHeight(float height);
	float GetHeight();
	void SetWidth(float width);
	float GetWidth();
	void SetColor(Color color);
	Color GetColor();
	void changeShow(bool chng);
	bool getShow();
	void SetNewPos(float nextX, float nextY);
	void Update(float timer);
	void Lerp(float timer)
	{

	}
	void Draw();
protected:
	Color myColor = BLUE;
	Rectangle body;
	Vector2 startPosition;
	Vector2 endPosition;
	bool imShowing = true;
};
}
#endif 