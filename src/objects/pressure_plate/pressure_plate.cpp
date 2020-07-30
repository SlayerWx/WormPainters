#include "pressure_plate.h"
#include "raylib.h"
namespace worm_painters
{
PressurePlate::PressurePlate(int x,int y,int width,int height)
{
	body.x = static_cast<float>(x);
	body.y = static_cast<float>(y);
	body.width = static_cast<float>(width);
	body.height = static_cast<float>(height);
}
PressurePlate::~PressurePlate()
{
}
void PressurePlate::draw()
{
	DrawRectangle(static_cast<int>(body.x), 
				  static_cast<int>(body.y), 
				  static_cast<int>(body.width), 
				  static_cast<int>(body.height), WHITE);
}
}