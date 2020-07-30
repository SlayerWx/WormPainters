#ifndef PRESSURE_PLATE_H
#define PRESSURE_PLATE_H
#include "raylib.h"
namespace worm_painters
{
class PressurePlate
{
public:
	PressurePlate(int x, int y, int width, int height,Texture2D texture);
	~PressurePlate();
	Vector2 getWidthHeight();
	void draw();
	Rectangle GetBody();
	void SetColor(Color color);
private:
	Rectangle body;
	Color myColor = WHITE;
	Texture2D mytexture;
};
}
#endif
