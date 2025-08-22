//--------------------------------------------------------------------------------------
// File: Bullet.cpp
//
//--------------------------------------------------------------------------------------
#include "Bullet.h"
#include "Game/Screen.h"

// �R���X�g���N�^
Bullet::Bullet()
	: GameObject{ Bullet::RADIUS }
	, m_ghTexture{ -1 }
	, m_type{ Type::None }
{
	// ��A�N�e�B�u�ɂ���
	SetActive(false);
}

// �X�V�֐�
bool Bullet::Update(float elapsedTime)
{
	if (!IsActive()) return true;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ��ʊO�ɒe���o�����H
	if ( (m_position.y < -Bullet::SIZE)		// ��ʊO�ɏo����i�㕔�j
	  || (m_position.y > Screen::HEIGHT)	// ��ʊO�ɏo����i�����j
	   )
	{
		// ��A�N�e�B�u�ɂ���
		SetActive(false);
	}

	return true;
}

// �`��֐�
void Bullet::Render()
{
	if (!IsActive()) return;

	// �e�̃^�C�v���ɕ`�悷��e��ς���
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

// �e�𔭎˂���֐�
void Bullet::Shoot(Vector2D position, Vector2D velocity, int ghTexture, Type type)
{
	SetActive(true);
	m_position = position;
	m_velocity = velocity;
	m_ghTexture = ghTexture;
	m_type = type;
}
