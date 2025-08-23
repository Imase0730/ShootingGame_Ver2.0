//--------------------------------------------------------------------------------------
// File: GameObject.cpp
//
//--------------------------------------------------------------------------------------
#include "GameObject.h"

// コンストラクタ
GameObject::GameObject(float radius)
    : m_radius{ radius }
    , m_position{}
    , m_velocity{}
{
}

// 衝突判定の描画関数
void GameObject::DrawCollider(unsigned int color) const
{
    DrawCircleAA(m_position.x, m_position.y, m_radius, 16, color, FALSE);
}
