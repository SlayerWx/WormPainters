#ifndef PRESSURE_PLATE_H
#define PRESSURE_PLATE_H
#include "raylib.h"
namespace worm_painters
{
class PressurePlate
{
public:
	PressurePlate(int x, int y, int width, int height,Texture2D texture,Texture2D splash);
	~PressurePlate();
	Vector2 getWidthHeight();
	void draw();
	Rectangle GetBody();
	void SetColor(Color color);
	Color GetColor();
	void SetSplashed(bool restart);
private:
	Rectangle body;
	Color myColor = WHITE;
	const Color originColor = WHITE;
	Texture2D mytexture;
	bool isSplashed = false;
	Texture2D mySplashTexture;
};
}
#endif
