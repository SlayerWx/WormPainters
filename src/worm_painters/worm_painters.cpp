#include "worm_painters.h"

#include "raylib.h"
namespace worm_painters
{
	WormPainters::WormPainters()
	{
		InitWindow(initialWindowsSizeWidth, initialWindowSizeHeight, (title + ' ' + version).c_str());
		currentStage = Stage_Gameplay;
		gameplay = new Gameplay();
	}
	WormPainters::~WormPainters()
	{
		if (gameplay)delete gameplay;
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
			gameplay->Input();
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
			gameplay->Update();
			break;

		}
	}
	void WormPainters::Draw()
	{
		BeginDrawing();
		ClearBackground(BLUE);
		switch (currentStage)
		{
		case Stage_SplashScreen:
			break;
		case Stage_Menu:
			break;
		case Stage_Gameplay:
			gameplay->Draw();
			break;
		}
		EndDrawing();
	}
}