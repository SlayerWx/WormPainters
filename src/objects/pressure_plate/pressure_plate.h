#ifndef PRESSURE_PLATE_H
#define PRESSURE_PLATE_H
#include "raylib.h"
namespace worm_painters
{
class PressurePlate
{
public:
	PressurePlate(int x, int y, int width, int height);
	~PressurePlate();
	void draw();
private:
	Rectangle body;
};
}
#endif
