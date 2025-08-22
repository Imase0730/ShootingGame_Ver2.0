//--------------------------------------------------------------------------------------
// File: Explosion.cpp
//
//--------------------------------------------------------------------------------------
#include "Explosion.h"

// �R���X�g���N�^
Explosion::Explosion(Vector2D position, int ghTexture)
	: m_position{ position }
	, m_ghTexture{ ghTexture }
	, m_animationState{ AnimationState::Anim01 }
	, m_animationCounter{ 0 }
{
}

// �X�V����
bool Explosion::Update(float elapsedTime)
{
	// �A�j���[�V�����J�E���^�[�����Z
	m_animationCounter++;

	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// �A�j���[�V�����J�E���^�[�����Z�b�g����
		m_animationCounter = 0;

		// �����̍Ō�̊G�Ȃ�A�j���[�V�������I������
		if (m_animationState == AnimationState::Anim04)
		{
			// �G�t�F�N�g������
			return false;
		}
		else
		{
			// ���̊G�ɕύX����
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);
		}
	}

	return true;
}

// �`�揈��
void Explosion::Render()
{
	// �X�v���C�g�V�[�g��̊G�̈ʒu���擾
	int x = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].x;
	int y = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].y;

	// �����̕`��
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, x, y, 16, 16, SIZE / 16, 0.0f, m_ghTexture, TRUE);
}

