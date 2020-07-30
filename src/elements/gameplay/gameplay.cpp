#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	map = new Map();
	p = new Player(right, map->GetWidthHeightPlate().x, { 0.0f, 0.0f },RED);
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
	p->Input(timeGameplayScale);
}
void Gameplay::Update()
{
	p->Update(timeGameplayScale);
	CheckCollision();
}
void Gameplay::Draw()
{
	map->draw();
	p->Draw();
}
void Gameplay::CheckCollision()
{
	map->CheckCollision(p->GetHead(),p->GetColor());
}
}