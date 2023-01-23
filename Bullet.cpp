#include "Bullet.h"
#include<Novice.h>

Bullet::Bullet()
{
	radius = 16;
	speed = 10;
	isShot=0;
}

void Bullet::Update()
{
	position.y -= speed;
	if(position.y-radius<0)
	{
		isShot = 0;
	}
}

void Bullet::Draw()
{
	if (isShot)
	{
		Novice::DrawEllipse(int(position.x),int( position.y),
			radius, radius, 0.0f, 0xffffffFF, kFillModeSolid);
	}
}