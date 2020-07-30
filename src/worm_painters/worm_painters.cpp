#include "worm_painters.h"

#include "raylib.h"
namespace worm_painters
{
	WormPainters::WormPainters()
	{
		InitWindow(initialWindowsSizeWidth, initialWindowSizeHeight, (title + ' ' + version).c_str());
		currentStage = Stage_Gameplay;
	}
	WormPainters::~WormPainters()
	{
		CloseWindow();
	}
	void WormPainters::Play()
	{
		while (!WindowShouldClose())
		{
			Input();
			Update();
			Draw();
		}
	}
	void WormPainters::Input()
	{
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			break;
		case Stage_Gameplay:
			break;
		}
	}
	void WormPainters::Update()
	{
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			break;
		case Stage_Gameplay:
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
			break;
		case Stage_Gameplay:
			break;
		}
		EndDrawing();
	}
}