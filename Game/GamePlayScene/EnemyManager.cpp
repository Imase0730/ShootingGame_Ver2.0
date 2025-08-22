//--------------------------------------------------------------------------------------
// File: EnemyManager.cpp
//
//--------------------------------------------------------------------------------------
#include "EnemyManager.h"
#include "Game/Screen.h"
#include "Enemy.h"

// コンストラクタ
EnemyManager::EnemyManager(Imase::TaskManager* pTaskManager, int enemyMax, BulletManager* pBulletManager)
	: m_spawnCounter{ 0 }
	, m_ghTexture{ -1 }
{
	// 配列を最大数確保する
	m_enemies.resize(enemyMax);

	// 敵のタスクを生成する
	for (int i = 0; i < enemyMax; i++)
	{
		m_enemies[i] = pTaskManager->AddTask<Enemy>(pBulletManager);
	}
}

// 初期化関数
void EnemyManager::Initialize(int ghTexture)
{
	// 絵のグラフィックハンドルを設定
	m_ghTexture = ghTexture;

	// 全ての敵を非アクティブ化する
	for (int i = 0; i < m_enemies.size(); i++)
	{
		m_enemies[i]->SetActive(false);
	}
}

// 更新処理
bool EnemyManager::Update(float elapsedTime)
{
	// 敵の出現用のカウンターの加算
	m_spawnCounter++;

	// 一定の間隔で敵を出現させる
	if (m_spawnCounter >= SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;

		// 敵を出現させる
		SpawnEnemy(Vector2D{ static_cast<float>(GetRand(Screen::WIDTH)), -Enemy::RADIUS });
	}

	return true;
}

// 敵を出現させる関数
void EnemyManager::SpawnEnemy(Vector2D position)
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		// 敵が非アクティブなら
		if (!m_enemies[i]->IsActive())
		{
			// 敵を出現させる
			m_enemies[i]->Spawn(position, m_ghTexture);
			return;
		}
	}
}

