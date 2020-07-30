#include "pressure_plate.h"
#include "raylib.h"
namespace worm_painters
{
PressurePlate::PressurePlate(float x,float y,float width,float height)
{
	body.x = x;
	body.y = y;
	body.width = width;
	body.height = height;
}
PressurePlate::~PressurePlate()
{
}
}