#include "gameplay.h"
#include "raylib.h"
namespace worm_painters
{
Gameplay::Gameplay()
{
	timer = startTimeMinute;
	endGame = false;
	timeGameplayScale = defaultGamePlayScale;
	playerBody = LoadTexture("assets/texture/worm/body.png");
	playerHead = LoadTexture("assets/texture/worm/head.png");
	hud = LoadTexture("assets/texture/ui/hud.png");
	int mp = maxPlayers;
	map = new Map();
	hud.width = GetScreenWidth();
	hud.height = map->GetTop();
	sizeFontWin = static_cast<int>(map->GetWidthHeightPlate().x * 2);
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i] = new Player(right, map->GetWidthHeightPlate().x, { 0.0f,static_cast<float>(map->GetTop()) }, playerOneColor,playerHead,playerBody);
		p[i]->SetActive(false);
	}
	if (!(playerOne >= mp))
	{
		p[playerOne]->SetControls(KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);
		p[playerOne]->SetActive(true);
	}
	if (!(playerTwo >= mp))
	{
		p[playerTwo]->SetColor(playerTwoColor);
		p[playerTwo]->SetControls(KEY_R, KEY_F, KEY_D, KEY_G);
		p[playerTwo]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,static_cast<float>(map->GetTop()) }, down);
		p[playerTwo]->SetActive(true);
	}
	if (!(playerTree >= mp))
	{
		p[playerTree]->SetColor(playerTreeColor);
		p[playerTree]->SetControls(KEY_U, KEY_J, KEY_H, KEY_K);
		p[playerTree]->SetPositionAndDirection({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
		p[playerTree]->SetActive(true);
	}
	if(!(playerFour >= mp))
	{ 
		p[playerFour]->SetColor(playerFourColor);
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
	Timing();
	WinCondition();;
}
void Gameplay::Draw()
{
	map->draw();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->Draw();
	}
	DrawHud();
	DrawWinner();
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
	DrawTime();
}
void Gameplay::WinCondition()
{
	if (timeGameplayScale != 0.0f)
	{
		int check = 0;
		checkPlayerWin = 0;
		for (int i = 0; i < maxPlayers; i++)
		{
			if (p[i]->GetDead())
			{
				check++;
			}
			else
			{
				checkPlayerWin = i++;
			}
		}
		if (check == maxPlayers)
		{
			timeGameplayScale = 0.0f;
			endGame = true;
		}
		else if (check == maxPlayers - 1)
		{
			timeGameplayScale = 0.0f;
			endGame = true;
			
		}
	}
}
void Gameplay::DrawWinner()//asAS
{
	if (endGame)
	{
		const char* w = FormatText("Winner Player %i", checkPlayerWin);

		DrawText(w, (GetScreenWidth() / 2) - (sizeof(w) * sizeFontWin), GetScreenHeight() / 2, sizeFontWin, winColor);
	}
}
void Gameplay::Timing()
{
	if (timer >= 0 && 0.0f != timeGameplayScale)
	{
		seconds -= GetFrameTime() * timeGameplayScale;
		if (seconds < 0.0f)
		{
			seconds = mxSeconds;
			timer--;
		}
	}
	else
	{
		for (int i = 0; i < maxPlayers; i++)
		{
			p[i]->SetDead(true);
		}
		timer = 0;
		seconds = 0.0f;
	}
}
void Gameplay::DrawTime()
{
	if (seconds < 10)
	{
		const char* w = FormatText("%i:0%i", timer, static_cast<int>(seconds));
		DrawText(w, (hud.width/2) - (sizeof(w) / 2) * ((timeSizeFont / 2)), (hud.height/2) - timeSizeFont/2, timeSizeFont, WHITE);
	}
	else
	{
		const char* w = FormatText("%i:%i", timer, static_cast<int>(seconds));
		DrawText(w, (GetScreenWidth()/2) - (sizeof(w)/2) * ((timeSizeFont/2)), (hud.height/2)-timeSizeFont/2, timeSizeFont, WHITE);
	}
}
}