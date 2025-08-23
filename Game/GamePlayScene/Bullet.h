//--------------------------------------------------------------------------------------
// File: Bullet.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "GameObject.h"

// �e�N���X
class Bullet : public GameObject
{
	// �񋓌^�̒�` -----------------------------------------------------
public:

	// �e�̃^�C�v
	enum class Type { None, Player, Enemy, TypeMax };

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �傫��
	static constexpr float SIZE = 16.0f;

	// ���a
	static constexpr float RADIUS = SIZE / 2.0f;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �O���t�B�b�N�n���h��
	int m_ghTexture;

	// �^�C�v
	Type m_type;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	Bullet();

	// �X�V�֐�
	bool Update(float elapsedTime) override;

	// �`��֐�
	void Render() override;

	// �e�𔭎˂���֐�
	void Shoot(Vector2D position, Vector2D velocity, int ghTexture, Type type);

};
