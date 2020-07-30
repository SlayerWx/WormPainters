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
private:
	static const int top = 100;
	static const int rowPlatesMax = 10;
	static const int columnPlatesMax = 10;
	PressurePlate* plates[rowPlatesMax][columnPlatesMax];
	Texture2D platesBakground;
};
}
#endif