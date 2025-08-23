//--------------------------------------------------------------------------------------
// File: EnemyManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include <vector>
#include "Game/Common/TaskManager.h"
#include "Game/Common/GameMath.h"

// 前方参照
class Enemy;
class BulletManager;

// 敵のマネージャークラス
class EnemyManager : public Imase::Task
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 敵の出現間隔
	static constexpr int SPAWN_INTERVAL = 10;

	// データメンバの宣言 -----------------------------------------------
private:

	// 敵へのポインタの配列
	std::vector<Enemy*> m_enemies;

	// 絵のグラフィックハンドル
	int m_ghTexture;

	// 敵の出現用カウンター
	int m_spawnCounter;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	EnemyManager(Imase::TaskManager* pTaskManager, int enemyMax, BulletManager* pBulletManager);

	// 初期化関数
	void Initialize(int ghTexture);

	// 更新処理
	bool Update(float elapsedTime) override;

	// 敵を出現させる関数
	void SpawnEnemy(Vector2D position);

	// 敵を取得する関数
	const std::vector<Enemy*>& GetEnemies() { return m_enemies; }

};
