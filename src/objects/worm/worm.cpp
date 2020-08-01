#include "worm.h"
#include "raylib.h"
namespace worm_painters
{
Worm::Worm(float width, float height,Color color,Texture2D texture)
{
	myColor = color;
	myTexture = texture;
	myTexture.width = static_cast<int>(width);
	myTexture.height = static_cast<int>(height);
	
}
Worm::~Worm()
{
}
void Worm::myRestart(float x,float y, float width, float height)
{
	body.x = x;
	body.y = y;
	body.width = width;
	body.height = height;
	startPosition = { x,y };
	endPosition = { x,y };
}
void Worm::SetX(float x)
{
body.x = x;
}
float Worm::GetX()
{
	return body.x;
}
void Worm::SetY(float y)
{
	body.y = y;
}
float Worm::GetY()
{
	return body.y;
}
void Worm::SetPosition(float x, float y)
{
	body.x = x;
	body.y = y;
}
Vector2 Worm::GetPosition()
{
	Vector2 aux;
	aux.x = body.x;
	aux.y = body.y;
	return aux;
}
void Worm::SetHeightAndWidth(float height, float width)
{
	body.height = height;
	body.width = width;
}
void Worm::SetHeight(float height)
{
	body.height = height;
}
float Worm::GetHeight()
{
	return body.height;
}
void Worm::SetWidth(float width)
{
	body.width = width;
}
float Worm::GetWidth()
{
	return body.width;
}
void Worm::SetColor(Color color)
{
	myColor = color;
}
Color Worm::GetColor()
{
	return myColor;
}
void Worm::changeShow(bool chng)
{
	imShowing = chng;
}
bool Worm::getShow()
{
	return imShowing;
}
void Worm::SetNewPos(float nextX,float nextY)
{
	startPosition = {body.x,body.y};
	endPosition = {nextX,nextY};
}
void Worm::Update(float timer)
{
	Lerp(timer);
}
void Worm::Lerp(float timer)
{
	 body.x = startPosition.x + timer * (endPosition.x - startPosition.x),
     body.y = startPosition.y + timer * (endPosition.y - startPosition.y);
}
void Worm::Draw()
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
Rectangle Worm::GetBody()
{
	return body;
}
void Worm::SetActive(bool ctive)
{
	imActive = ctive;
}
bool Worm::GetActive()
{
	return imActive;
}
}