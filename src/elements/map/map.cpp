#include "map.h"
namespace worm_painters
{
Map::Map()
{
	for (int i = 0; i < rowPlatesMax; i++)
	{
		for (int t = 0; t < columnPlatesMax; t++)
		{
			plates[i][t] = new PressurePlate(t * (GetScreenWidth() / columnPlatesMax),
				(i * (GetScreenHeight()-top)/rowPlatesMax)+top, GetScreenWidth() / columnPlatesMax,
				(GetScreenHeight() - top) / rowPlatesMax);
		}
	}
}

Map::~Map()
{
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
}