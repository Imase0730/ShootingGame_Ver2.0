//--------------------------------------------------------------------------------------
// File: Play.cpp
//
//--------------------------------------------------------------------------------------
#include "Player.h"
#include "Game/Screen.h"

// コンストラクタ
Player::Player(int ghTexture)
	: GameObject{ Player::RADIUS }
	, m_ghTexture{ ghTexture }
{
}

// 更新処理
bool Player::Update(float elapsedTime)
{
	// 位置に速度を足す
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// プレイヤーが画面外へ出ないように位置を調整
	if (m_position.x < Player::RADIUS)
	{
		m_position.x = Player::RADIUS;
	}
	if (m_position.x > Screen::WIDTH - Player::RADIUS)
	{
		m_position.x = Screen::WIDTH - Player::RADIUS;
	}

	return true;
}

// 描画処理
void Player::Render()
{
	// プレイヤーの描画
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 0, 0, 32, 32, SIZE / 32, 0.0f, m_ghTexture, TRUE);
}

// 移動を停止する関数
void Player::MoveStop()
{
	m_velocity = Vector2D{ 0.0f, 0.0f };
}

// 左に移動する関数
void Player::MoveLeft()
{
	m_velocity = Vector2D{ -Player::SPEED, 0.0f };
}

// 右に移動する関数
void Player::MoveRight()
{
	m_velocity = Vector2D{ Player::SPEED, 0.0f };
}

