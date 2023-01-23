#pragma once
class Enemy
{
public:	// �����o�֐�


	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="posX">X���W</param>
	/// <param name="posY">Y���W</param>
	/// <param name="speedX">�ړ����xX</param>
	/// <param name="speedY">�ړ����xY</param>
	Enemy(int posX, int posY, int speedX, int speedY);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
	void Kill();


	int GetPosX() { return posX_; };
	int GetPosY() { return posY_; };
	int GetSpeedX() { return speedX_; };
	int GetSpeedY() { return speedY_; };
	int GetRadius() { return radius_; };
	bool GetisAlive() { return isAlive; };


	void SetSpeedX(int speed) { speedX_ = speed; };
	void SetSpeedY(int speed) { speedY_ = speed; };

private:	// �����o�ϐ�
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	static bool isAlive;
};