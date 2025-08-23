//--------------------------------------------------------------------------------------
// File: Explosion.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/Common/GameMath.h"
#include "Game/Common/TaskManager.h"

// �����N���X
class Explosion : public Imase::Task
{
private:

	// �����̃A�j���[�V�����X�e�[�g
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, Anim02, Anim03, Anim04,
	};

private:

	// �����A�j���[�V�����̊Ԋu
	static constexpr int ANIMATION_INTERVAL = 4;

	// �����̕\���̑傫��
	static constexpr float SIZE = 64.0f;

	// �����̃X�v���C�g�V�[�g��̊G�̈ʒu
	static constexpr POINT EXPLOSION_SPRITES[] =
	{
		{ 96 + 16 * 0, 32 },		// �p�^�[���P
		{ 96 + 16 * 1, 32 },		// �p�^�[���Q
		{ 96 + 16 * 2, 32 },		// �p�^�[���R
		{ 96 + 16 * 3, 32 },		// �p�^�[���S
	};

private:

	// �\���ʒu
	Vector2D m_position;

	// �O���t�B�b�N�n���h��
	int m_ghTexture;

	// �A�j���[�V�����X�e�[�g
	AnimationState m_animationState;

	// �����̃A�j���[�V�����J�E���^�[
	int m_animationCounter;

public:

	// �R���X�g���N�^
	Explosion(Vector2D position, int ghTexture);

	// �X�V����
	bool Update(float elapsedTime) override;

	// �`�揈��
	void Render() override;

};

