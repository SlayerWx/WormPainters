#ifndef PRESSURE_PLATE_H
#define PRESSURE_PLATE_H
#include "raylib.h"
namespace worm_painters
{
class PressurePlate
{
public:
	PressurePlate(float x, float y, float width, float height);
	~PressurePlate();

private:
	Rectangle body;
};
}
#endif
