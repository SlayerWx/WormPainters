#include "fruit.h"
#include <ctime>
#include <cstdlib>

#include "raylib.h"

#include "objects/player/player.h"
namespace worm_painters
{ 
Fruit::Fruit(float width, float height)//asAS
{
	body.width = width;
	body.height = height;
	srand(static_cast<unsigned int>(time(NULL)));
	show = false;
	mytexture = LoadTexture("assets/texture/fruit/fruit.png");
	mytexture.width = static_cast<int>(width);
	mytexture.height = static_cast<int>(height);
}
Fruit::~Fruit()
{
	UnloadTexture(mytexture);
}
void Fruit::RestartPosition(int top)
{
	float x = static_cast<float>(rand()%GetScreenWidth());
	float y = static_cast<float>(rand()%GetScreenHeight()+top);
	x += body.width;
	y += body.height;
	if (x >= GetScreenWidth())
	{
		x -= (body.width * 2);
	}
	if (y >= GetScreenHeight())
	{
		y = GetScreenHeight() - body.height;
	}
	body.x = x;
	body.y = y;
}
void Fruit::SetPointsInPlayer(Player* p,int top)
{
	p->SetPoints(p->GetPoints()+valor);
	RestartPosition(top);
}
void Fruit::Update()
{
}
void Fruit::Draw()
{
#if DEBUG
	DrawRectangle(static_cast<int>(body.x), static_cast<int>(body.y),
		static_cast<int>(body.width), static_cast<int>(body.height),GRAY);
#endif
	DrawTexture(mytexture, static_cast<int>(body.x), static_cast<int>(body.y),WHITE);
}
Rectangle Fruit::GetBody()
{
	return body;
}
}