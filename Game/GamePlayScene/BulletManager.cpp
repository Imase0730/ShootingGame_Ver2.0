//--------------------------------------------------------------------------------------
// File: BulletManager.cpp
//
//--------------------------------------------------------------------------------------
#include "BulletManager.h"
#include "Bullet.h"

// �R���X�g���N�^
BulletManager::BulletManager(Imase::TaskManager* pTaskManager, int bulletMax)
	: m_ghTexture{ -1 }
{
	// �z����ő吔�m�ۂ���
	m_bullets.resize(bulletMax);

	// �e�̃^�X�N�𐶐�����
	for (int i = 0; i < bulletMax; i++)
	{
		m_bullets[i] = pTaskManager->AddTask<Bullet>();
	}
}

// �f�X�g���N�^
BulletManager::~BulletManager()
{
	// �e�̃^�X�N����������
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->Kill();
	}
}

// �������֐�
void BulletManager::Initialize(int ghTexture)
{
	// �G�̃O���t�B�b�N�n���h����ݒ�
	m_ghTexture = ghTexture;

	// �S�Ă̒e���A�N�e�B�u������
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->SetActive(false);
	}
}

// �e�𔭎˂���֐�
void BulletManager::ShootBullet(Vector2D position, Vector2D velocity, Bullet::Type type)
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		// �e����A�N�e�B�u�Ȃ�
		if (!m_bullets[i]->IsActive())
		{
			// �e�𔭎˂���
			m_bullets[i]->Shoot(position, velocity, m_ghTexture, type);
			return;
		}
	}
}

