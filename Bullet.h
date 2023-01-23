#pragma once
#include<Vector2.h>
class Bullet
{
public:
	Vector2 position;
	int radius;
	int speed;
	int isShot;
	Bullet();
	void Update();
	void Draw();
private:
};

