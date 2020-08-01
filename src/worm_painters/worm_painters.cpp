#include "worm_painters.h"

#include <iostream>

#include "raylib.h"

#include "elements/gameplay/gameplay.h"
#include "elements/menu/menu.h"
using namespace std;
namespace worm_painters
{
	WormPainters::WormPainters()
	{
		InitWindow(initialWindowsSizeWidth, initialWindowSizeHeight, (title + ' ' + version).c_str());
		InitAudioDevice();
		stream = LoadMusicStream("assets/sound/music.ogg");
		currentStage = Stage_Menu;
		gameplay = new Gameplay();
		menu = new Menu();
		firstTime = true;
		PlayMusicStream(stream);
		SetMasterVolume(volume);
		
	}
	WormPainters::~WormPainters()
	{
		if (menu) delete menu;
		if (gameplay)delete gameplay;
		StopMusicStream(stream);
		UnloadMusicStream(stream);
		CloseAudioDevice();
		CloseWindow();
	}
	void WormPainters::Play()
	{
		while (!WindowShouldClose() && !menu->RequestExit())
		{
			Input();
			Update();
			Draw();
		}
	}
	void WormPainters::Input()//asAS
	{
		SetVolume();
		if (menu->RequestPlay() && firstTime)
		{
			currentStage = Stage_Gameplay;
			menu->myRestart();
			gameplay->myRestart();
			firstTime = false;
		}
		if (gameplay->GoToMenu())
		{
			currentStage = Stage_Menu;
			firstTime = true;
		}
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			menu->Input();
			break;
		case Stage_Gameplay:
			gameplay->Input();
			break;
		}
	}
	void WormPainters::Update()
	{
		UpdateMusicStream(stream);
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			menu->Update();
			break;
		case Stage_Gameplay:
			gameplay->Update();
			break;

		}
	}
	void WormPainters::Draw()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			menu->Draw();
			break;
		case Stage_Gameplay:
			gameplay->Draw();
			break;
		}
		EndDrawing();
		
	}
	void WormPainters::SetVolume()
	{
		if (IsKeyReleased(KEY_F1))
		{
			volume += modfV;
			if (volume > mx)
			{
				volume = mx;
			}
			SetMasterVolume(volume);
		}
		if (IsKeyReleased(KEY_F2))
		{
			volume -= modfV;
			if (volume < min) {
				volume = min;
			}
			SetMasterVolume(volume);
		}
	}
}