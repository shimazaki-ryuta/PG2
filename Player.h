#pragma once
#include<Vector2.h>
#include"Bullet.h"

struct Transform
{
	Vector2 position;
	int radius;
};

class Player
{
private:
	Transform transform;
	int speed;
	Bullet* bullet = new Bullet();
public:
	Player(int, int);
	~Player();
	void Update(char[], char[]);
	void Draw();
	int GetBulletPosX() { return bullet->position.x; };
	int GetBulletPosY() { return bullet->position.y; };
	int GetBulletRadius() { return bullet->radius; };

};
