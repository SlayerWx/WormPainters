#ifndef MAP_H
#define MAP_H
#include "raylib.h"
namespace worm_painters
{
class Map
{
public:
	Map();
	~Map();

private:
	static const int top = 100;
	int rowPlates = 10;
	int columnPlates = 10;
};
}
#endif