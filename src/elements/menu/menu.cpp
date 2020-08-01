#include "menu.h"

Menu::Menu()
{
	choose = nothing;
	bckground = LoadTexture("assets/texture/ui/menu.png");
	bckground.width = GetScreenWidth();
	bckground.height = GetScreenHeight();
	plyColor = colorInSelection;
	crditColor = noSelection;
	exitColor = noSelection;
	currentOption = play;
}

Menu::~Menu()
{
	UnloadTexture(bckground);
}

void Menu::Input()
{
	if (IsKeyReleased(myKey.up) && choose != credits)
	{
		if (currentOption == play)
		{
			currentOption = exit;
		}
		else
		{
			currentOption--;
		}
	}
	if (IsKeyReleased(myKey.down) && choose != credits)
	{
		if (currentOption == exit)
		{
			currentOption = play;
		}
		else
		{
			currentOption++;
		}
	}
	if (IsKeyReleased(myKey.enter) && choose == credits)
	{
		choose = nothing;
	}
	else if (IsKeyReleased(myKey.enter) && choose != credits)
	{
		switch (currentOption)
		{
		case play:
			choose = play;
			break;
		case credits:
			choose = credits;
			break;
		case exit:
			choose = exit;
			break;
		}
	}
	
}

void Menu::Update()
{
	switch (currentOption)
	{
	case play:
		plyColor = colorInSelection;
		crditColor = noSelection;
		exitColor = noSelection;
		break;
	case credits:
		plyColor = noSelection;
		crditColor = colorInSelection;
		exitColor = noSelection;
		break;
	case exit:
		plyColor = noSelection;
		crditColor = noSelection;
		exitColor = colorInSelection;
		break;
	}

}

void Menu::Draw()//asAS
{
	int rememberPos = GetScreenHeight() / theHalf - fontSize;
	DrawTexture(bckground,0,0,WHITE);

	DrawText("Play", GetScreenWidth()/theHalf - sizeof("Play")- fontSize, rememberPos, fontSize, plyColor);
	rememberPos += fontSize + distanceOptions;
	DrawText("Credits", GetScreenWidth() / theHalf - sizeof("Credits")- fontSize, rememberPos, fontSize, crditColor);
	rememberPos += fontSize + distanceOptions;
	DrawText("Exit", GetScreenWidth() / theHalf - sizeof("Exit")- fontSize, rememberPos, fontSize, exitColor);
	DrawText("controls Player 1: Arrows UP,LEFT,DOWN,RIGHT           Controls Player 2:W,A,S,D",
		GetScreenWidth()/theHalf - (sizeof("controls Player 1: W,A,S,D           Controls Player 2:Arrows UP,LEFT,DOWN,RIGHT")/theHalf)* 
		(controlsSizeFont/theHalf),GetScreenHeight() - controlsSizeFont,controlsSizeFont, BLACK);
	DrawText("Pause: P",GetScreenWidth()/theHalf - (sizeof("Pause: P")* controlsSizeFont/theHalf),GetScreenHeight() - 
		controlsSizeFont * theHalf,controlsSizeFont,BLACK);
	if (choose == credits)
	{
		DrawCredits();
	}
}
bool Menu::RequestExit()
{
	return (choose == exit);
}
bool Menu::RequestPlay()
{
	return (choose == play);
}
void Menu::myRestart()
{
	choose = nothing;
}
void Menu::DrawCredits()
{
	int rememberPos = GetScreenHeight() / theHalf - fontSize;
	DrawTexture(bckground, 0, 0, WHITE);
	DrawText("By:Maxi Ruffo", GetScreenWidth() / theHalf - sizeof("By:Maxi Ruffo") - fontSize, rememberPos, fontSize / theHalf, noSelection);
	rememberPos += fontSize + distanceOptions;
	DrawText("Programs : Gimp 2, Visual studio", GetScreenWidth() / four - sizeof("Programs: Gimp2, Visual studio") -
		fontSize / 2, rememberPos, fontSize / theHalf, noSelection);
	rememberPos += fontSize + distanceOptions;
	DrawText("BACK", GetScreenWidth() / theHalf - sizeof("BACK") - fontSize, rememberPos, fontSize, colorInSelection);
}