#include "gameplay.h"

#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	playerBody = LoadTexture("assets/texture/worm/body.png");
	playerHead = LoadTexture("assets/texture/worm/head.png");
	hud = LoadTexture("assets/texture/ui/hud.png");
	int mp = maxPlayers;
	map = new Map();
	hud.width = GetScreenWidth();
	hud.height = map->GetTop();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i] = new Player(right, map->GetWidthHeightPlate().x, { 0.0f,static_cast<float>(map->GetTop()) }, BLUE,playerHead,playerBody);
		p[i]->SetActive(false);
	}
	if (!(playerOne >= mp))
	{
		p[playerOne]->SetControls(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
		p[playerOne]->SetActive(true);
	}
	if (!(playerTwo >= mp))
	{
		p[playerTwo]->SetColor(RED);
		p[playerTwo]->SetControls(KEY_R, KEY_F, KEY_D, KEY_G);
		p[playerTwo]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,static_cast<float>(map->GetTop()) }, down);
		p[playerTwo]->SetActive(true);
	}
	if (!(playerTree >= mp))
	{
		p[playerTree]->SetColor(YELLOW);
		p[playerTree]->SetControls(KEY_U, KEY_J, KEY_H, KEY_K);
		p[playerTree]->SetPositionAndDirection({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
		p[playerTree]->SetActive(true);
	}
	if(!(playerFour >= mp))
	{ 
		p[playerFour]->SetColor(VIOLET);
		p[playerFour]->SetControls(KEY_C,KEY_SPACE,KEY_X,KEY_V);
		p[playerFour]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,GetScreenHeight() - map->GetWidthHeightPlate().y }, left);
		p[playerFour]->SetActive(true);
	}
}
Gameplay::~Gameplay()
{
	UnloadTexture(hud);
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
		p[i]->Update(timeGameplayScale,map->GetTop());
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
	DrawHud();
}
void Gameplay::CheckCollision()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		if (p[i]->GetActive())
		{
			map->CheckCollision(p[i]->GetHead(), p[i]->GetColor());
		}
		for (int t = 0; t < maxPlayers; t++)
		{	
			if (t!=i)
			{
				if (p[i]->CheckEnemyCollision(p[t]->GetHead()))
				{
					p[t]->SetDead(true);
				}
			}
		}
	}
}
void Gameplay::DrawHud()
{
	DrawTexture(hud, 0, 0, WHITE);
}
}