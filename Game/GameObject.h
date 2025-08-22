//--------------------------------------------------------------------------------------
// File: GameObject.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "TaskManager.h"
#include "Collision.h"

// ゲームオブジェクトクラス
class GameObject : public Imase::Task
{
protected:

	// 半径
	float m_radius;

	// 位置
	Vector2D m_position;

	// 速度
	Vector2D m_velocity;

public:

	// コンストラクタ
	GameObject(float radius);

	// 衝突判定用の円情報を取得する関数
	BoundingCircle GetBoundingCircle() const { return BoundingCircle{ m_position, m_radius }; }

	// 衝突判定の描画関数
	void DrawCollider(unsigned int color = GetColor(255, 255, 255)) const;

	// 位置を取得する関数
	Vector2D GetPosition() const { return m_position; }

	// 位置を設定する関数
	void SetPosition(Vector2D position) { m_position = position; }

};
