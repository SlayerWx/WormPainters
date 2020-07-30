#include "player.h"
namespace worm_painters
{
Player::Player(Direction start)
{
	myDirection = start;
}
Player::~Player()
{
}
void Player::Input()
{
	if (IsKeyDown(KEY_RIGHT) && myDirection != right)
	{
		myDirection = right;
	}
	if (IsKeyDown(KEY_DOWN) && myDirection != down)
	{
		myDirection = down;
	}
	if (IsKeyDown(KEY_LEFT) && myDirection != left)
	{
		myDirection = left;
	}
	if (IsKeyDown(KEY_UP) && myDirection != up)
	{
		myDirection = up;
	}
}
void Player::Update()
{

}
}