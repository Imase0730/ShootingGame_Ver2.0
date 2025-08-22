//--------------------------------------------------------------------------------------
// File: Play.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/GameObject.h"

// �v���C���[�N���X
class Player : public GameObject
{
	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr float SIZE = 64.0f;

	// ���a
	static constexpr float RADIUS = SIZE / 2.0f;

	// �ړ��̑���
	static constexpr float SPEED = 5.0f;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �O���t�B�b�N�n���h��
	int m_ghTexture;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Player(int ghTexture);

	// �X�V�֐�
	bool Update(float elapsedTime) override;

	// �`��֐�
	void Render() override;

	// �ړ����~����֐�
	void MoveStop();

	// ���Ɉړ�����֐�
	void MoveLeft();

	// �E�Ɉړ�����֐�
	void MoveRight();

};
