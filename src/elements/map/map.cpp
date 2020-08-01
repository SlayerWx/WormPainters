#include "map.h"

#include "raylib.h"

#include "objects/pressure_plate/pressure_plate.h"
namespace worm_painters
{
Map::Map()
{
	platesBakground = LoadTexture("assets/texture/backgroundplates/backgroundplates.png");
	platesSplash = LoadTexture("assets/texture/backgroundplates/splash.png");
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			plates[i][t] = new PressurePlate(t * (GetScreenWidth() / columnPlatesMax),
				(i * (GetScreenHeight() - top) / rowPlatesMax) + top, GetScreenWidth() / columnPlatesMax,
				(GetScreenHeight() - top) / rowPlatesMax, platesBakground, platesSplash);
		}
	}
}

Map::~Map()
{
	UnloadTexture(platesSplash);
	UnloadTexture(platesBakground);
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			if (plates[i][t]) delete plates[i][t];
		}
	}
}
Vector2 Map::GetWidthHeightPlate()
{
	return plates[0][0]->getWidthHeight();
}
void Map::draw()//asAS
{
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			plates[i][t]->draw();
		}
	}
}
bool Map::CheckCollision(Rectangle player, Color playerColor)//asAS
{
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			if (CheckCollisionRecs(player, plates[i][t]->GetBody()) &&
				(playerColor.a != plates[i][t]->GetColor().a ||
					playerColor.b != plates[i][t]->GetColor().b ||
					playerColor.g != plates[i][t]->GetColor().g))
			{
				plates[i][t]->SetColor(playerColor);
				plates[i][t]->SetSplashed(true);
				return true;
			}
		}
	}
	return false;
}
int Map::GetTop()
{
	return top;
}
int Map::GetValor()
{
	return plateValor;
}
void Map::Reset()
{
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			plates[i][t]->SetSplashed(false);
		}
	}
}
}