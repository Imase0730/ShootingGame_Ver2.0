//--------------------------------------------------------------------------------------
// File: Bullet.cpp
//
//--------------------------------------------------------------------------------------
#include "Bullet.h"
#include "Game/Screen.h"

// コンストラクタ
Bullet::Bullet()
	: GameObject{ Bullet::RADIUS }
	, m_ghTexture{ -1 }
	, m_type{ Type::None }
{
	// 非アクティブにする
	SetActive(false);
}

// 更新関数
bool Bullet::Update(float elapsedTime)
{
	if (!IsActive()) return true;

	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// 画面外に弾が出たか？
	if ( (m_position.y < -Bullet::SIZE)		// 画面外に出たら（上部）
	  || (m_position.y > Screen::HEIGHT)	// 画面外に出たら（下部）
	   )
	{
		// 非アクティブにする
		SetActive(false);
	}

	return true;
}

// 描画関数
void Bullet::Render()
{
	if (!IsActive()) return;

	// 弾のタイプ毎に描画する弾を変える
	switch (m_type)
	{
	case Type::Player:
		DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
			, 64, 32, 16, 16, SIZE / 16, 0.0f, m_ghTexture, TRUE);
		break;
	case Type::Enemy:
		DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
			, 64 + 16, 32, 16, 16, SIZE / 16, 0.0f, m_ghTexture, TRUE);
		break;
	default:
		break;
	}
}

// 弾を発射する関数
void Bullet::Shoot(Vector2D position, Vector2D velocity, int ghTexture, Type type)
{
	SetActive(true);
	m_position = position;
	m_velocity = velocity;
	m_ghTexture = ghTexture;
	m_type = type;
}
