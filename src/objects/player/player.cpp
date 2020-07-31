#include "player.h"
namespace worm_painters
{
const float Player::timerMX = 1.0f;
float Player::timer = 0.0f;
Player::Player(Direction start,float newDistanceToMove,Vector2 startPosition,Color color,Texture2D tHead,Texture2D tBody )//asAS
{
	imActive = false;
	canChange = true;
	myColor = color;
	timer = 0.0f;
	myDirection = start;
	distanceToMove = newDistanceToMove;
	for (int i = 0; i < maxBody; i++)
	{
		if (i == head)
		{
			body[i] = new Object(newDistanceToMove, newDistanceToMove, color,tHead);
		}
		else
		{
			body[i] = new Object(newDistanceToMove, newDistanceToMove, color, tBody);

		}
	}
	SetPositionAndDirection(startPosition, start);
}
Player::~Player()
{
	for (int i = 0; i < maxBody; i++)
	{
		if (body[i]) delete body[i];
	}
}
void Player::Input(float timeScale)//asAS
{
	if (timeScale != 0.0f && canChange)
	{
		if (IsKeyDown(controls.right) && myDirection != left)
		{
			myDirection = right;
		}
		else if (IsKeyDown(controls.down) && myDirection != up)
		{
			myDirection = down;
		}
		else if (IsKeyDown(controls.left) && myDirection != right)
		{
			myDirection = left;
		}
		else if (IsKeyDown(controls.up) && myDirection != down)
		{
			myDirection = up;
		}
		canChange = false;
	}
}
void Player::Update(float TimeScale)
{
		if (timer > timerMX)
		{
			for (int i = 0; i < maxBody; i++)
			{
				body[i]->Update(timerMX);
			}
			SetNewMoveInBody();
			timer = 0;
			canChange = true;
		}
		for (int i = 0; i < maxBody; i++)
		{
			body[i]->Update(timer);
		}
		timer += (GetFrameTime() * speed) * TimeScale;
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
Rectangle Player::GetHead()
{
	return body[head]->GetBody();
}
Color Player::GetColor()
{
	return myColor;
}
void Player::SetActive(bool active)
{
	imActive = active;
}
void Player::SetColor(Color newColor)
{
	myColor = newColor;
	for (int i = 0; i < maxBody; i++)
	{
		body[i]->SetColor(newColor);
	}
}
void Player::SetPositionAndDirection(Vector2 pos, Direction dir)
{
	myDirection = dir;
	body[head]->Restart(pos.x + (distanceToMove / 4), pos.y + (distanceToMove / 4),
		distanceToMove / 2, distanceToMove / 2);
	originPosition.x = body[head]->GetX();
	originPosition.y = body[head]->GetY();
	originDir = dir;
	for (int i = 1; i < maxBody; i++)
	{
		if (myDirection == right)
		{
			body[i]->Restart(body[i - 1]->GetX() - distanceToMove, body[i - 1]->GetY(),
				distanceToMove / 2, distanceToMove / 2);
		}
		else if (myDirection == down)
		{
			body[i]->Restart(body[i - 1]->GetX(), body[i - 1]->GetY() - distanceToMove,
				distanceToMove / 2, distanceToMove / 2);
		}
		else if (myDirection == left)
		{
			body[i]->Restart(body[i - 1]->GetX() + distanceToMove, body[i - 1]->GetY(),
				distanceToMove / 2, distanceToMove / 2);
		}
		else if (myDirection == up)
		{
			body[i]->Restart(body[i - 1]->GetX(), body[i - 1]->GetY() + distanceToMove,
				distanceToMove / 2, distanceToMove / 2);
		}
	}
}
void Player::SetControls(KeyboardKey up, KeyboardKey down, KeyboardKey left, KeyboardKey right)
{
	controls.up = up;
	controls.down = down;
	controls.left = left;
	controls.right = right;
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