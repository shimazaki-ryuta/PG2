#pragma once
#include<Vector2.h>

struct Transform
{
	Vector2 position;
	int radius;
};

class Player
{
public:
	Player(int ,int );
	void Move(char []);
	void Draw();
private:
	Transform transform;
	int speed;
};

