//--------------------------------------------------------------------------------------
// File: EnemyManager.cpp
//
//--------------------------------------------------------------------------------------
#include "EnemyManager.h"
#include "Game/Screen.h"
#include "Enemy.h"

// �R���X�g���N�^
EnemyManager::EnemyManager(Imase::TaskManager* pTaskManager, int enemyMax, int ghTexture, BulletManager* pBulletManager)
	: m_spawnCounter{ 0 }
	, m_ghTexture{ ghTexture }
{
	// �z����ő吔�m�ۂ���
	m_enemies.resize(enemyMax);

	// �G�̃^�X�N�𐶐�����
	for (int i = 0; i < enemyMax; i++)
	{
		m_enemies[i] = pTaskManager->AddTask<Enemy>(pBulletManager);
	}
}

// �X�V����
bool EnemyManager::Update(float elapsedTime)
{
	// �G�̏o���p�̃J�E���^�[�̉��Z
	m_spawnCounter++;

	// ���̊Ԋu�œG���o��������
	if (m_spawnCounter >= SPAWN_INTERVAL)
	{
		m_spawnCounter = 0;

		// �G���o��������
		SpawnEnemy(Vector2D{ static_cast<float>(GetRand(Screen::WIDTH)), -Enemy::RADIUS });
	}

	return true;
}

// �G���o��������֐�
void EnemyManager::SpawnEnemy(Vector2D position)
{
	for (int i = 0; i < m_enemies.size(); i++)
	{
		// �G����A�N�e�B�u�Ȃ�
		if (!m_enemies[i]->IsActive())
		{
			// �G���o��������
			m_enemies[i]->Spawn(position, m_ghTexture);
			return;
		}
	}
}

