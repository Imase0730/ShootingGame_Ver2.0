//--------------------------------------------------------------------------------------
// File: BulletManager.cpp
//
//--------------------------------------------------------------------------------------
#include "BulletManager.h"
#include "Bullet.h"

// �R���X�g���N�^
BulletManager::BulletManager(Imase::TaskManager* pTaskManager, int bulletMax, int ghTexture)
	: m_ghTexture{ ghTexture }
{
	// �z����ő吔�m�ۂ���
	m_bullets.resize(bulletMax);

	// �e�̃^�X�N�𐶐�����
	for (int i = 0; i < bulletMax; i++)
	{
		m_bullets[i] = pTaskManager->AddTask<Bullet>();
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

