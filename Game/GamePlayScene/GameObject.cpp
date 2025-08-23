//--------------------------------------------------------------------------------------
// File: GameObject.cpp
//
//--------------------------------------------------------------------------------------
#include "GameObject.h"

// �R���X�g���N�^
GameObject::GameObject(float radius)
    : m_radius{ radius }
    , m_position{}
    , m_velocity{}
{
}

// �Փ˔���̕`��֐�
void GameObject::DrawCollider(unsigned int color) const
{
    DrawCircleAA(m_position.x, m_position.y, m_radius, 16, color, FALSE);
}
