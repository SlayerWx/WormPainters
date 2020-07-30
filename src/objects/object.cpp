#include "object.h"
#include "raylib.h"
namespace worm_painters
{
Object::Object(float x,float y,float width, float height)
{
	body.x = x;
	body.y = y;
	body.width = width;
	body.height = height;
	startPosition = {0.0f,0.0f};
	endPosition = {0.0f,0.0f};
}
Object::~Object()
{
}
void Object::SetX(float x)
{
body.x = x;
}
float Object::GetX()
{
	return body.x;
}
void Object::SetY(float y)
{
	body.y = y;
}
float Object::GetY()
{
	return body.y;
}
void Object::SetPosition(float x, float y)
{
	body.x = x;
	body.y = y;
}
Vector2 Object::GetPosition()
{
	Vector2 aux;
	aux.x = body.x;
	aux.y = body.y;
	return aux;
}
void Object::SetHeightAndWidth(float height, float width)
{
	body.height = height;
	body.width = width;
}
void Object::SetHeight(float height)
{
	body.height = height;
}
float Object::GetHeight()
{
	return body.height;
}
void Object::SetWidth(float width)
{
	body.width = width;
}
float Object::GetWidth()
{
	return body.width;
}
void Object::SetColor(Color color)
{
	myColor = color;
}
Color Object::GetColor()
{
	return myColor;
}
void Object::changeShow(bool chng)
{
	imShowing = chng;
}
bool Object::getShow()
{
	return imShowing;
}
void Object::SetNewPos(float nextX,float nextY)
{
	if (nextX == 0.0f)
	{
		nextX = body.x;
	}
	if (nextY == 0.0f)
	{
		nextY = body.y;
	}
	startPosition = {body.x,body.y};
	endPosition = {nextX,nextY};
}
void Object::Update(float timer)
{
	timer = timer;
}
void Object::Lerp(float timer)
{
	timer = timer;
}
void Object::Draw()
{
#if DEBUG
	DrawRectangle(static_cast<int>(body.x), static_cast<int>(body.y),
		static_cast<int>(body.width), static_cast<int>(body.height), myColor);
#endif
}
}