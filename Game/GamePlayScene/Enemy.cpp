//--------------------------------------------------------------------------------------
// File: Enemy.cpp
//
//--------------------------------------------------------------------------------------
#include "Enemy.h"
#include "Game/Screen.h"
#include "BulletManager.h"

// �R���X�g���N�^
Enemy::Enemy(BulletManager* pBulletManager)
	: GameObject{ Enemy::RADIUS }
	, m_ghTexture{ -1 }
	, m_pBulletManager{ pBulletManager }
	, m_shootCounter{ 0 }
{
	// ��A�N�e�B�u�ɂ���
	SetActive(false);
}

// �X�V����
bool Enemy::Update(float elapsedTime)
{
	if (!IsActive()) return true;

	// �ʒu�ɑ��x�𑫂�
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;

	// ��ʊO�o����
	if (m_position.y > Screen::HEIGHT + Enemy::RADIUS)
	{
		// �G���A�N�e�B�u�ɂ���
		SetActive(false);
	}
	
	// �e�̔��˗p�J�E���^�[�����Z
	m_shootCounter++;
	if (m_shootCounter > SHOOT_INTERVAL)
	{
		m_shootCounter = 0;
		// �e�𔭎˂���
		m_pBulletManager->ShootBullet(m_position, Vector2D{ 0.0f, 10.0f }, Bullet::Type::Enemy);
	}

	return true;
}

// �`�揈��
void Enemy::Render()
{
	if (!IsActive()) return;

	// �G�̕`��
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, 96, 0, 32, 32, SIZE / 32, 0.0f, m_ghTexture, TRUE);
}

// �o���֐�
void Enemy::Spawn(Vector2D position, int ghTexture)
{
	SetActive(true);
	m_position = position;
	m_velocity = Vector2D{ 0.0f, 5.0f };
	m_ghTexture = ghTexture;
}

