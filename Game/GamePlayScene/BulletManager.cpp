//--------------------------------------------------------------------------------------
// File: BulletManager.cpp
//
//--------------------------------------------------------------------------------------
#include "BulletManager.h"
#include "Bullet.h"

// コンストラクタ
BulletManager::BulletManager(Imase::TaskManager* pTaskManager, int bulletMax, int ghTexture)
	: m_ghTexture{ ghTexture }
{
	// 配列を最大数確保する
	m_bullets.resize(bulletMax);

	// 弾のタスクを生成する
	for (int i = 0; i < bulletMax; i++)
	{
		m_bullets[i] = pTaskManager->AddTask<Bullet>();
	}
}

// 弾を発射する関数
void BulletManager::ShootBullet(Vector2D position, Vector2D velocity, Bullet::Type type)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		// 弾が非アクティブなら
		if (!m_bullets[i]->IsActive())
		{
			// 弾を発射する
			m_bullets[i]->Shoot(position, velocity, m_ghTexture, type);
			return;
		}
	}
}

