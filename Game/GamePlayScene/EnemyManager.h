//--------------------------------------------------------------------------------------
// File: EnemyManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include <vector>
#include "Game/Common/TaskManager.h"
#include "Game/Common/GameMath.h"

// �O���Q��
class Enemy;
class BulletManager;

// �G�̃}�l�[�W���[�N���X
class EnemyManager : public Imase::Task
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �G�̏o���Ԋu
	static constexpr int SPAWN_INTERVAL = 10;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �G�ւ̃|�C���^�̔z��
	std::vector<Enemy*> m_enemies;

	// �G�̃O���t�B�b�N�n���h��
	int m_ghTexture;

	// �G�̏o���p�J�E���^�[
	int m_spawnCounter;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	EnemyManager(Imase::TaskManager* pTaskManager, int enemyMax, BulletManager* pBulletManager);

	// �������֐�
	void Initialize(int ghTexture);

	// �X�V����
	bool Update(float elapsedTime) override;

	// �G���o��������֐�
	void SpawnEnemy(Vector2D position);

	// �G���擾����֐�
	const std::vector<Enemy*>& GetEnemies() { return m_enemies; }

};
