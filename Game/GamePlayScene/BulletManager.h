//--------------------------------------------------------------------------------------
// File: BulletManager.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include <vector>
#include "Game/TaskManager.h"
#include "Game/GameMath.h"
#include "Bullet.h"

// �e�̃}�l�[�W���[�N���X
class BulletManager
{
	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �e�ւ̃|�C���^�̔z��
	std::vector<Bullet*> m_bullets;

	// �O���t�B�b�N�n���h��
	int m_ghTexture;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	BulletManager(Imase::TaskManager* pTaskManager, int bulletMax, int ghTexture);

	// �e�𔭎˂���֐�
	void ShootBullet(Vector2D position, Vector2D velocity, Bullet::Type type);

	// �e���擾����֐�
	const std::vector<Bullet*>& GetBullets() { return m_bullets; }

};
