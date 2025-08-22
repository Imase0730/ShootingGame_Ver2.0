//--------------------------------------------------------------------------------------
// File: BulletManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include <vector>
#include "Game/TaskManager.h"
#include "Game/GameMath.h"
#include "Bullet.h"

// 弾のマネージャークラス
class BulletManager
{
	// データメンバの宣言 -----------------------------------------------
private:

	// 弾へのポインタの配列
	std::vector<Bullet*> m_bullets;

	// グラフィックハンドル
	int m_ghTexture;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	BulletManager(Imase::TaskManager* pTaskManager, int bulletMax, int ghTexture);

	// 弾を発射する関数
	void ShootBullet(Vector2D position, Vector2D velocity, Bullet::Type type);

	// 弾を取得する関数
	const std::vector<Bullet*>& GetBullets() { return m_bullets; }

};
