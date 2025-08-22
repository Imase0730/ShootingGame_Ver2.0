//--------------------------------------------------------------------------------------
// File: Enemy.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/GameObject.h"

// 前方宣言
class BulletManager;

// 敵クラス
class Enemy : public GameObject
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr float SIZE = 64.0f;

	// 半径
	static constexpr float RADIUS = SIZE / 2.0f;

	// 弾の発射間隔
	static constexpr int SHOOT_INTERVAL = 60;

	// データメンバの宣言 -----------------------------------------------
private:

	// グラフィックハンドル
	int m_ghTexture;

	// 弾のマネージャーへのポインタ
	BulletManager* m_pBulletManager;

	// 弾の発射用カウンター
	int m_shootCounter;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Enemy(BulletManager* pBulletManager);

	// 更新関数
	bool Update(float elapsedTime) override;

	// 描画関数
	void Render() override;

	// 出現関数
	void Spawn(Vector2D position, int ghTexture);

};
