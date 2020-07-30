#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	map = new Map();
	p = new Player(right, 20.0f, { 400.0f, 400.0f });
}
Gameplay::~Gameplay()
{
	if (p) delete p;
	if(map)delete map;
	
}
void Gameplay::Restart()
{
}
void Gameplay::Input()
{
	p->Input();
}
void Gameplay::Update()
{
	p->Update();
}
void Gameplay::Draw()
{
	map->draw();
	p->Draw();
}
}