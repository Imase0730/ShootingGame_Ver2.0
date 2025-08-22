//--------------------------------------------------------------------------------------
// File: Enemy.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/GameObject.h"

// �O���錾
class BulletManager;

// �G�N���X
class Enemy : public GameObject
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr float SIZE = 64.0f;

	// ���a
	static constexpr float RADIUS = SIZE / 2.0f;

	// �e�̔��ˊԊu
	static constexpr int SHOOT_INTERVAL = 60;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �O���t�B�b�N�n���h��
	int m_ghTexture;

	// �e�̃}�l�[�W���[�ւ̃|�C���^
	BulletManager* m_pBulletManager;

	// �e�̔��˗p�J�E���^�[
	int m_shootCounter;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Enemy(BulletManager* pBulletManager);

	// �X�V�֐�
	bool Update(float elapsedTime) override;

	// �`��֐�
	void Render() override;

	// �o���֐�
	void Spawn(Vector2D position, int ghTexture);

};
