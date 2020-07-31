#ifndef FRUIT_H
#define FRUIT_H
#include <ctime>
#include <cstdlib>

#include "raylib.h"

#include "objects/player/player.h"
namespace worm_painters
{ 
class Fruit
{
public:
	Fruit(float width,float height);
	~Fruit();
	void RestartPosition(int top);
	void SetPointsInPlayer(Player * p, int top);
	void Update();
	void Draw();
	Rectangle GetBody();
private:
	bool show;
	Rectangle body;
	int valor = 50;
	Texture2D mytexture;
	
};
}
#endif 