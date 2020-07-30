#ifndef MAP_H
#define MAP_H
#include "raylib.h"
#include "objects/pressure_plate/pressure_plate.h"
namespace worm_painters
{
class Map
{
public:
	Map();
	~Map();
	Vector2 GetWidthHeightPlate();
	void draw();
	void CheckCollision(Rectangle player,Color playerColor);
	int GetTop();
private:
	static const int top = 100;
	static const int rowPlatesMax = 20;
	static const int columnPlatesMax = 20;
	PressurePlate* plates[rowPlatesMax][columnPlatesMax];
	Texture2D platesBakground;
	Texture2D platesSplash;
};
}
#endif