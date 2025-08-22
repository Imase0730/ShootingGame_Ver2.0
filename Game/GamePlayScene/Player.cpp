//--------------------------------------------------------------------------------------
// File: Play.cpp
//
//--------------------------------------------------------------------------------------
#include "Player.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Player::Player(int ghTexture)
	: GameObject{ Player::RADIUS }
	, m_ghTexture{ ghTexture }
{
}

// �X�V����
bool Player::Update(float elapsedTime)
{
	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// �v���C���[����ʊO�֏o�Ȃ��悤�Ɉʒu�𒲐�
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

// �`�揈��
void Player::Render()
{
	// �v���C���[�̕`��
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 0, 0, 32, 32, SIZE / 32, 0.0f, m_ghTexture, TRUE);
}

// �ړ����~����֐�
void Player::MoveStop()
{
	m_velocity = Vector2D{ 0.0f, 0.0f };
}

// ���Ɉړ�����֐�
void Player::MoveLeft()
{
	m_velocity = Vector2D{ -Player::SPEED, 0.0f };
}

// �E�Ɉړ�����֐�
void Player::MoveRight()
{
	m_velocity = Vector2D{ Player::SPEED, 0.0f };
}

