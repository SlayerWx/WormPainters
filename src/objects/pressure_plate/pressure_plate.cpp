#include "pressure_plate.h"
#include "raylib.h"
#include <iostream>
using namespace std;
namespace worm_painters
{
PressurePlate::PressurePlate(int x,int y,int width,int height,Texture2D texture,Texture2D splash)
{
	isSplashed = false;
	body.x = static_cast<float>(x);
	body.y = static_cast<float>(y);
	body.width = static_cast<float>(width);
	body.height = static_cast<float>(height);
	myColor = WHITE;
	mytexture = texture;
	mySplashTexture = splash;
	mytexture.height = static_cast<int>(body.height);
	mytexture.width = static_cast<int>(body.width);
	mySplashTexture.height = static_cast<int>(body.height);
	mySplashTexture.width = static_cast<int>(body.width);
	
}
PressurePlate::~PressurePlate()
{
}
Vector2 PressurePlate::getWidthHeight()
{
	return {body.width,body.height};
}
void PressurePlate::draw()
{
#if DEBUG
	DrawRectangle(static_cast<int>(body.x), 
				  static_cast<int>(body.y), 
				  static_cast<int>(body.width), 
				  static_cast<int>(body.height), myColor);
#endif
	DrawTexture(mytexture, static_cast<int>(body.x), static_cast<int>(body.y),WHITE);
	if (isSplashed)
	{
		DrawTexture(mySplashTexture, static_cast<int>(body.x), static_cast<int>(body.y),myColor);
	}
}
Rectangle PressurePlate::GetBody()
{
	return body;
}
void PressurePlate::SetColor(Color color)
{
	myColor = color;
}
void PressurePlate::SetSplashed(bool restart)
{
	isSplashed = restart;
}
}