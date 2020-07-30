#include "map.h"
namespace worm_painters
{
Map::Map()
{
	platesBakground = LoadTexture("assets/texture/backgroundplates/backgroundplates.png");
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			plates[i][t] = new PressurePlate(t * (GetScreenWidth() / columnPlatesMax),
				(i * (GetScreenHeight()-top)/rowPlatesMax)+top, GetScreenWidth() / columnPlatesMax,
				(GetScreenHeight() - top) / rowPlatesMax, platesBakground);
		}
	}
}

Map::~Map()
{
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
void Map::CheckCollision(Rectangle player,Color playerColor)
{
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			if (CheckCollisionRecs(player, plates[i][t]->GetBody()))
			{
				plates[i][t]->SetColor(playerColor);
			}
		}
	}
}
}