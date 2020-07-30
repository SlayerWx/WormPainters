#include "player.h"
namespace worm_painters
{
Player::Player(Direction start,float newDistanceToMove,Vector2 startPosition)
{
	
	myDirection = start;
	distanceToMove = newDistanceToMove;
	body[head] = new Object(startPosition.x, startPosition.y,
		newDistanceToMove ,newDistanceToMove);
	for (int i = 1; i < maxBody; i++)
	{
		if (myDirection == right)
		{
			body[i] = new Object(body[i-1]->GetX() - distanceToMove, body[i-1]->GetY(),
				newDistanceToMove, newDistanceToMove);
		}
		else if (myDirection == down)
		{
			body[i] = new Object(body[i - 1]->GetX(), body[i - 1]->GetY() - distanceToMove,
				newDistanceToMove, newDistanceToMove);
		}
		else if (myDirection == left)
		{
			body[i] = new Object(body[i - 1]->GetX() + distanceToMove, body[i - 1]->GetY(),
				newDistanceToMove, newDistanceToMove);
		}
		else if (myDirection == up)
		{
			body[i] = new Object(body[i - 1]->GetX(), body[i - 1]->GetY() + distanceToMove,
				newDistanceToMove, newDistanceToMove);
		}
	}
}
Player::~Player()
{
	for (int i = 0; i < maxBody; i++)
	{
		if (body[i]) delete body[i];
	}
}
void Player::Input()//asAS
{
	if (IsKeyDown(KEY_RIGHT) && myDirection != right)
	{
		myDirection = right;
		SetNewMoveInBody(distanceToMove,0);
	}
	else if (IsKeyDown(KEY_DOWN) && myDirection != down)
	{
		myDirection = down;
		SetNewMoveInBody(0, distanceToMove);
	}
	else if (IsKeyDown(KEY_LEFT) && myDirection != left)
	{
		myDirection = left;
		SetNewMoveInBody(-distanceToMove,0);
	}
	else if (IsKeyDown(KEY_UP) && myDirection != up)
	{
		myDirection = up;
		SetNewMoveInBody(0,-distanceToMove);
	}
}
void Player::Update()
{
	for (int i = 0; i < maxBody; i++)
	{
		body[i]->Update(0.0f);
	}
}
void Player::Draw()
{
	for (int  i = 0; i < maxBody; i++)
	{
		body[i]->Draw();
	}
}
void Player::SetNewMoveInBody(float x, float y)//asAS
{
	body[head]->SetNewPos(body[head]->GetX() + x, body[head]->GetY() + y);
	for (int i = 1; i < maxBody; i++)
	{
		body[i]->SetNewPos(body[i-1]->GetX(),body[i-1]->GetY());
		
	}
}
}