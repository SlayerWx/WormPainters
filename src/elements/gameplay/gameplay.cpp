#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	playerBody = LoadTexture("assets/texture/worm/body.png");
	playerHead = LoadTexture("assets/texture/worm/head.png");
	int mp = maxPlayers;
	map = new Map();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i] = new Player(right, map->GetWidthHeightPlate().x, { 0.0f,static_cast<float>(map->GetTop()) }, RED,playerHead,playerBody);
	}
	p[playerOne]->SetControls(KEY_UP,KEY_DOWN,KEY_LEFT,KEY_RIGHT);
	if (!(playerTwo >= mp))
	{
		p[playerTwo]->SetColor(RED);
		p[playerTwo]->SetControls(KEY_R, KEY_F, KEY_D, KEY_G);
		p[playerTwo]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,static_cast<float>(map->GetTop()) }, down);
	}
	if (!(playerTree >= mp))
	{
		p[playerTree]->SetColor(YELLOW);
		p[playerTree]->SetControls(KEY_U, KEY_J, KEY_H, KEY_K);
		p[playerTree]->SetPositionAndDirection({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
	}
	if(!(playerFour >= mp))
	{ 
	p[playerFour]->SetColor(VIOLET);
	p[playerFour]->SetControls(KEY_C,KEY_SPACE,KEY_X,KEY_V);
	p[playerFour]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,GetScreenHeight() - map->GetWidthHeightPlate().y }, left);
	}
}
Gameplay::~Gameplay()
{
	UnloadTexture(playerHead);
	UnloadTexture(playerBody);
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