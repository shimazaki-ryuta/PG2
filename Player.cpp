#include "Player.h"
#include<Novice.h>
Player::Player(int x, int y)
{
	transform.position = { float(x),float(y) };
	transform.radius = 16;
	speed = 10;
}

Player::~Player()
{
	delete bullet;
}

void Player::Update(char keys[], char preKeys[])
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

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE])
	{
		if (!bullet->isShot)
		{
			bullet->position = transform.position;
			bullet->isShot = 1;
		}
	}
	bullet->Update();
}

void Player::Draw()
{
	Novice::DrawEllipse(transform.position.x, transform.position.y,
		transform.radius, transform.radius, 0.0f, 0xffffffFF, kFillModeSolid);
	bullet->Draw();
}