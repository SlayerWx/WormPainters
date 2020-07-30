#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	map = new Map();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i] = new Player(right, map->GetWidthHeightPlate().x, { 0.0f,static_cast<float>(map->GetTop()) }, BLUE);
	}
	p[1]->SetColor(RED);
	p[1]->SetPositionAndDirection({ GetScreenWidth() -map->GetWidthHeightPlate().x,static_cast<float>(map->GetTop()) },down);
	p[2]->SetColor(YELLOW);
	p[2]->SetPositionAndDirection({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
	p[3]->SetColor(VIOLET);
	p[3]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,GetScreenHeight() - map->GetWidthHeightPlate().y }, left);
}
Gameplay::~Gameplay()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		if (p[i]) delete p[i];
	}
	if(map)delete map;
	
}
void Gameplay::Restart()
{
}
void Gameplay::Input()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->Input(timeGameplayScale);
	}
}
void Gameplay::Update()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->Update(timeGameplayScale);
	}
	CheckCollision();
}
void Gameplay::Draw()
{
	map->draw();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->Draw();
	}
}
void Gameplay::CheckCollision()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		map->CheckCollision(p[i]->GetHead(), p[i]->GetColor());
	}
}
}