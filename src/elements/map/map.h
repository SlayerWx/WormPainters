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
	void draw();
private:
	static const int top = 100;
	static const int rowPlatesMax = 2;
	static const int columnPlatesMax = 2;
	PressurePlate* plates[rowPlatesMax][columnPlatesMax];
};
}
#endif