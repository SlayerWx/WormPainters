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
	if (choose == credits)
	{
		UpdateCredits();
	}
}

void Menu::Draw()//asAS
{
	int rememberPos = GetScreenHeight() / 2 - fontSize;
	DrawTexture(bckground,0,0,WHITE);

	DrawText("Play", GetScreenWidth()/2 - sizeof("Play")- fontSize, rememberPos, fontSize, plyColor);
	rememberPos += fontSize + distanceOptions;
	DrawText("Credits", GetScreenWidth() / 2 - sizeof("Credits")- fontSize, rememberPos, fontSize, crditColor);
	rememberPos += fontSize + distanceOptions;
	DrawText("Exit", GetScreenWidth() / 2 - sizeof("Exit")- fontSize, rememberPos, fontSize, exitColor);
	DrawText("controls Player 1: W,A,S,D           Controls Player 2:Arrows UP,LEFT,DOWN,RIGHT",
		GetScreenWidth()/2 - (sizeof("controls Player 1: W,A,S,D           Controls Player 2:Arrows UP,LEFT,DOWN,RIGHT")/2)* 
		(controlsSizeFont/2),GetScreenHeight() - controlsSizeFont,controlsSizeFont, BLACK);
	if (choose == credits)
	{
		DrawCredits();
	}
}
void Menu::DrawCredits()
{
	int rememberPos = GetScreenHeight() / 4 - fontSize;
	DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);	
	DrawText("By:Maxi Ruffo", GetScreenWidth() / 2 - sizeof("By:Maxi Ruffo") - fontSize, rememberPos, fontSize, noSelection);
	rememberPos += fontSize + distanceOptions;
	DrawText("Programs : Gimp 2, Visual studio", GetScreenWidth() / 2 - sizeof("Programs: Gimp2, Visual studio") -
		fontSize, rememberPos, fontSize, noSelection);
	rememberPos += fontSize + distanceOptions;
	DrawText("BACK", GetScreenWidth() / 2 - sizeof("BACK") - fontSize, rememberPos, fontSize, colorInSelection);
}
bool Menu::RequestExit()
{
	return (choose == exit);
}
