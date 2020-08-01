#include "gameplay.h"

#include "raylib.h"

#include "elements/map/map.h"
#include "objects/player/player.h"
#include "objects/fruit/fruit.h"
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
	sizeFontWin = static_cast<int>(map->GetWidthHeightPlate().x * 2);
	fruit = new Fruit(map->GetWidthHeightPlate().x, map->GetWidthHeightPlate().y);
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i] = new Player(right, map->GetWidthHeightPlate().x, { 0.0f,static_cast<float>(map->GetTop()) }, playerOneColor, playerHead, playerBody);
		p[i]->SetActive(false);
		mxPlayersInGame++;
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
		p[playerTwo]->ChangeOrigin({ GetScreenWidth() - map->GetWidthHeightPlate().x,static_cast<float>(map->GetTop()) }, down);
		p[playerTwo]->SetActive(true);
	}
	if (!(playerTree >= mp))
	{
		p[playerTree]->SetColor(playerTreeColor);
		p[playerTree]->SetControls(KEY_U, KEY_J, KEY_H, KEY_K);
		p[playerTree]->SetPositionAndDirection({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
		p[playerTree]->ChangeOrigin({ 0.0f,GetScreenHeight() - map->GetWidthHeightPlate().y }, up);
		p[playerTree]->SetActive(true);
	}
	if (!(playerFour >= mp))
	{
		p[playerFour]->SetColor(playerFourColor);
		p[playerFour]->SetControls(KEY_C, KEY_SPACE, KEY_X, KEY_V);
		p[playerFour]->SetPositionAndDirection({ GetScreenWidth() - map->GetWidthHeightPlate().x,GetScreenHeight() - map->GetWidthHeightPlate().y }, left);
		p[playerFour]->ChangeOrigin({ GetScreenWidth() - map->GetWidthHeightPlate().x,GetScreenHeight() - map->GetWidthHeightPlate().y }, left);
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
	if (fruit) delete fruit;
	
}
void Gameplay::Input()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->Input(timeGameplayScale);
	}
	if (IsKeyReleased(KEY_ENTER) && timeGameplayScale != 0.0f)
	{
		timeGameplayScale = 0.0f;
	}
	else if (IsKeyReleased(KEY_ENTER) && 0.0f == timeGameplayScale )
	{
		timeGameplayScale = defaultGamePlayScale;
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
	fruit->Draw();
	DrawWinner();
}
bool Gameplay::GoToMenu()
{
	return goToMenu;
}
void Gameplay::myRestart()
{
	
	overDeadTime = false;
	overDead = mxOverDead;
	draw = true;
	timerToMenu = timerMxToMenu;
	goToMenu = false;
	timer = startTimeMinute;
	endGame = false;
	timeGameplayScale = defaultGamePlayScale;
	map->Reset();
	for (int i = 0; i < maxPlayers; i++)
	{
		p[i]->restart(true);
	}
	fruit->RestartPosition(map->GetTop());
}
void Gameplay::RequestMenu()
{
	timerToMenu -= GetFrameTime();
	if (timerToMenu < 0.0f)
	{
		goToMenu = true;
	}
}
void Gameplay::CheckCollision()
{
	for (int i = 0; i < maxPlayers; i++)
	{
		if (p[i]->GetActive())
		{
			if (map->CheckCollision(p[i]->GetHead(), p[i]->GetColor()) && !p[i]->GetDead())
			{
				p[i]->SetPoints(p[i]->GetPoints()+ map->GetValor());
			}
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
		if (CheckCollisionRecs(p[i]->GetHead(), fruit->GetBody()))
		{
			fruit->SetPointsInPlayer(p[i],map->GetTop());
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
			if (!p[i]->GetDead())
			{
				check++;
			}
			else
			{
				checkPlayerWin = i;
			}
		}
		if (check == 0)
		{
			timeGameplayScale = 0.0f;
			endGame = true;
			int rememberPoint = 0;
			for (int i = 0; i < maxPlayers; i++)
			{
				if(p[i]->GetPoints() > rememberPoint)
				checkPlayerWin = i;
				rememberPoint = p[i]->GetPoints();
			}
		}
		if (check == 1)
		{
			draw = false;
			overDeadTime = true;
		}
		if (overDeadTime)
		{
			overDead -= GetFrameTime() * timeGameplayScale;
			if (overDead < 0.0f)
			{
				timeGameplayScale = 0.0f;
				endGame = true;
				for (int i = 0; i < maxPlayers; i++)
				{
					if (!p[i]->GetDead())
					{
						checkPlayerWin = i;
					}
				}
				int rememberPoint = 0;
				for (int i = 0; i < maxPlayers; i++)
				{
					if (p[i]->GetPoints() > rememberPoint)
						checkPlayerWin = i;
					rememberPoint = p[i]->GetPoints();
				}
			}
		}
	}
	if (endGame)
	{
		RequestMenu();
	}
}
void Gameplay::DrawWinner()//
{
	if (endGame)
	{
		if (draw)
		{
			const char* w = FormatText("Draw!", (checkPlayerWin + 1));
			DrawText(w, (GetScreenWidth() / theHalf) - (sizeof(w) * sizeFontWin/2), GetScreenHeight() / theHalf, sizeFontWin, winColor);
		}
		else if (!draw)
		{
			const char* w = FormatText("Winner Player %i", (checkPlayerWin + 1));
			DrawText(w, (GetScreenWidth() / theHalf) - (sizeof(w) * sizeFontWin), GetScreenHeight() / theHalf, sizeFontWin, winColor);
		}
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
	else if (timer < 0)
	{
		for (int i = 0; i < maxPlayers; i++)
		{
			p[i]->SetDead(true);
		}
		timer = 0;
		seconds = 0.0f;
	}
}
void Gameplay::DrawTime()//asAS
{
	if (mxPlayersInGame > playerOne)
	{
		DrawText(FormatText("%i", p[playerOne]->GetPoints()), hud.width / eight, hud.height / eight, timeSizeFont, WHITE);
	}
	if (mxPlayersInGame > playerTwo)
	{
		DrawText(FormatText("%i", p[playerTwo]->GetPoints()), hud.width - timeSizeFont * four, hud.height / eight, timeSizeFont, WHITE);
	}
	if (mxPlayersInGame > playerTree)
	{
		DrawText(FormatText("%i", p[playerTree]->GetPoints()), hud.width / eight, hud.height / theHalf +(timeSizeFont/theHalf) , timeSizeFont, WHITE);
	}
	if (mxPlayersInGame > playerFour)
	{
		DrawText(FormatText("%i", p[playerFour]->GetPoints()), hud.width - timeSizeFont * four, (hud.height / theHalf)+ (timeSizeFont/theHalf), timeSizeFont, WHITE);
	}
	if (seconds < ten)
	{
		const char* w = FormatText("%i:0%i", timer, static_cast<int>(seconds));
		DrawText(w, (hud.width/theHalf) - (sizeof(w) / theHalf) * ((timeSizeFont / theHalf)), (hud.height/ theHalf) - 
			timeSizeFont/ theHalf, timeSizeFont, WHITE);
	}
	else
	{
		const char* w = FormatText("%i:%i", timer, static_cast<int>(seconds));
		DrawText(w, (GetScreenWidth()/ theHalf) - (sizeof(w)/ theHalf) * ((timeSizeFont/ theHalf)), 
			(hud.height/ theHalf)-timeSizeFont/ theHalf, timeSizeFont, WHITE);
	}
}
}