//--------------------------------------------------------------------------------------
// File: GameObject.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TaskManager.h"
#include "Collision.h"

// �Q�[���I�u�W�F�N�g�N���X
class GameObject : public Imase::Task
{
protected:

	// ���a
	float m_radius;

	// �ʒu
	Vector2D m_position;

	// ���x
	Vector2D m_velocity;

public:

	// �R���X�g���N�^
	GameObject(float radius);

	// �Փ˔���p�̉~�����擾����֐�
	BoundingCircle GetBoundingCircle() const { return BoundingCircle{ m_position, m_radius }; }

	// �Փ˔���̕`��֐�
	void DrawCollider(unsigned int color = GetColor(255, 255, 255)) const;

	// �ʒu���擾����֐�
	Vector2D GetPosition() const { return m_position; }

	// �ʒu��ݒ肷��֐�
	void SetPosition(Vector2D position) { m_position = position; }

};
