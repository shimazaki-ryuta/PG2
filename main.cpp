#include <Novice.h>
#include"Player.h"
#include"Enemy.h"
const char kWindowTitle[] = "LC1A_11";
const int ENEMYMAX=2;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };
	Player* player = new Player(100, 100);
	Enemy* enemy[ENEMYMAX];
	for (int i=0;i<ENEMYMAX;i++)
	{
		enemy[i] = new Enemy(100*(i+1),200*(i+1),2,0);
	}
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Update(keys, preKeys);
		for (int i = 0; i < ENEMYMAX; i++)
		{
			enemy[i]->Update();
			float distX = enemy[i]->GetPosX() - player->GetBulletPosX();
			float distY = enemy[i]->GetPosY() - player->GetBulletPosY();
			float dist = (distX * distX) + (distY * distY);
			int radius = enemy[i]->GetRadius() + player->GetBulletRadius();
			if (dist <= radius * radius) {
				enemy[i]->Kill();
			}
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		for (int i = 0; i < ENEMYMAX; i++)
		{
			if (enemy[i]->GetisAlive())
			{
				enemy[i]->Draw();
			}
		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}