#include "player.h"
namespace worm_painters
{
const float Player::timerMX = 1.0f;
float Player::timer = 0.0f;
Player::Player(Direction start,float newDistanceToMove,Vector2 startPosition)
{
	timer = 0.0f;
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
	if (IsKeyDown(KEY_RIGHT) && myDirection != left)
	{
		myDirection = right;
	}
	else if (IsKeyDown(KEY_DOWN) && myDirection != up)
	{
		myDirection = down;
	}
	else if (IsKeyDown(KEY_LEFT) && myDirection != right)
	{
		myDirection = left;
	}
	else if (IsKeyDown(KEY_UP) && myDirection != down)
	{
		myDirection = up;
	}
}
void Player::Update()
{
	if (timer > timerMX)
	{
		for (int i = 0; i < maxBody; i++)
		{
			body[i]->Update(timerMX);
		}
		SetNewMoveInBody();
		timer = 0;
	}
	for (int i = 0; i < maxBody; i++)
	{
		body[i]->Update(timer);
	}
	timer += 0.02f;
}
void Player::Draw()
{
	for (int  i = 0; i < maxBody; i++)
	{
		body[i]->Draw();
	}
}
Vector2 Player::moveToDirection()
{
	Vector2 ux = {0,0};
	if (myDirection == left)
	{
		ux = {-distanceToMove,0};
	}
	else if (myDirection == up)
	{
		ux = { 0,-distanceToMove };
	}
	else if (myDirection == right)
	{
		ux = { distanceToMove,0 };
	}
	else if (myDirection == down)
	{
		ux = { 0,distanceToMove };
	}
	return ux;
}
void Player::SetNewMoveInBody()//asAS
{
	Vector2 ux = moveToDirection();
	body[head]->SetNewPos(body[head]->GetX() + ux.x, body[head]->GetY() + ux.y);
	for (int i = 1; i < maxBody; i++)
	{
		body[i]->SetNewPos(body[i-1]->GetX(),body[i-1]->GetY());
		
	}
}
}