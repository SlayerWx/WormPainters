#ifndef OBJECT_H
#define OBJECT_H
#include "raylib.h"
namespace worm_painters
{
enum ObstacleID
{
	
};
class Object
{
public:
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
	void Draw();
protected:
	Color myColor = WHITE;
	Rectangle body;
};
}
#endif 