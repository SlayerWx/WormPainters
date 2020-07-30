#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	map = new Map();
}
Gameplay::~Gameplay()
{
}
void Gameplay::Restart()
{
}
void Gameplay::Input()
{
	
}
void Gameplay::Update()
{
}
void Gameplay::Draw()
{
	map->draw();
}
}