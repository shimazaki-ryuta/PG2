#include "Player.h"
#include<Novice.h>
Player::Player(int x,int y)
{
	transform.position = {float(x),float(y)};
	transform.radius = 16;
	speed = 10;
}

void Player::Move(char keys[])
{
	if (keys[DIK_W])
	{
		transform.position.y -= speed;
	}
	if (keys[DIK_S])
	{
		transform.position.y += speed;
	}
	if (keys[DIK_A])
	{
		transform.position.x -= speed;
	}
	if (keys[DIK_D])
	{
		transform.position.x += speed;
	}
}

void Player::Draw()
{
	Novice::DrawEllipse(transform.position.x,transform.position.y,
		transform.radius,transform.radius,0.0f,0xffffffFF,kFillModeSolid);
}