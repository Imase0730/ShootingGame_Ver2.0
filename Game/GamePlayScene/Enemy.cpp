//--------------------------------------------------------------------------------------
// File: Enemy.cpp
//
//--------------------------------------------------------------------------------------
#include "Enemy.h"
#include "Game/Screen.h"
#include "BulletManager.h"

// コンストラクタ
Enemy::Enemy(BulletManager* pBulletManager)
	: GameObject{ Enemy::RADIUS }
	, m_ghTexture{ -1 }
	, m_pBulletManager{ pBulletManager }
	, m_shootCounter{ 0 }
{
	// 非アクティブにする
	SetActive(false);
}

// 更新処理
bool Enemy::Update(float elapsedTime)
{
	if (!IsActive()) return true;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 画面外出たら
	if (m_position.y > Screen::HEIGHT + Enemy::RADIUS)
	{
		// 敵を非アクティブにする
		SetActive(false);
	}
	
	// 弾の発射用カウンターを加算
	m_shootCounter++;
	if (m_shootCounter > SHOOT_INTERVAL)
	{
		m_shootCounter = 0;
		// 弾を発射する
		m_pBulletManager->ShootBullet(m_position, Vector2D{ 0.0f, 10.0f }, Bullet::Type::Enemy);
	}

	return true;
}

// 描画処理
void Enemy::Render()
{
	if (!IsActive()) return;

	// 敵の描画
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 96, 0, 32, 32, SIZE / 32, 0.0f, m_ghTexture, TRUE);
}

// 出現関数
void Enemy::Spawn(Vector2D position, int ghTexture)
{
	SetActive(true);
	m_position = position;
	m_velocity = Vector2D{ 0.0f, 5.0f };
	m_ghTexture = ghTexture;
}

