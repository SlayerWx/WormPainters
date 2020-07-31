#include "object.h"
#include "raylib.h"
namespace worm_painters
{
Object::Object(float width, float height,Color color,Texture2D texture)
{
	myColor = color;
	myTexture = texture;
	myTexture.width = static_cast<int>(width);
	myTexture.height = static_cast<int>(height);
	
}
Object::~Object()
{
}
void Object::Restart(float x,float y, float width, float height)
{
	body.x = x;
	body.y = y;
	body.width = width;
	body.height = height;
	startPosition = { x,y };
	endPosition = { x,y };
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
	startPosition = {body.x,body.y};
	endPosition = {nextX,nextY};
}
void Object::Update(float timer)
{
	Lerp(timer);
}
void Object::Lerp(float timer)
{
	 body.x = startPosition.x + timer * (endPosition.x - startPosition.x),
     body.y = startPosition.y + timer * (endPosition.y - startPosition.y);
}
void Object::Draw()
{
#if DEBUG
	DrawRectangle(static_cast<int>(body.x), static_cast<int>(body.y),
		static_cast<int>(body.width), static_cast<int>(body.height), myColor);
#endif
	if (imActive)
	{
		DrawTexture(myTexture, static_cast<int>(body.x - (myTexture.width / centrerTextureInCubeModif)),
			static_cast<int>(body.y - (myTexture.height / centrerTextureInCubeModif)), myColor);
	}
}
Rectangle Object::GetBody()
{
	return body;
}
void Object::SetActive(bool ctive)
{
	imActive = ctive;
}
bool Object::GetActive()
{
	return imActive;
}
}